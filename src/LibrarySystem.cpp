#include "LibrarySystem.h"
#include "LibraryException.h"
#include <fstream>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <Book.h>

// Yıkıcı fonksiyon: Dinamik ayrılan belleği temizler
LibrarySystem::~LibrarySystem() {
    for (auto& pair : items) {
        delete pair.second;  // Öğe pointer'larını serbest bırak
    }
    for (auto& pair : users) {
        delete pair.second;  // Kullanıcı pointer'larını serbest bırak
    }
}

// Yeni bir öğe ekler
void LibrarySystem::addItem(LibraryItem* item) {
    if (items.find(item->getItemID()) != items.end()) {
        throw LibraryException("Item already exists");  // Öğe zaten varsa hata fırlat
    }
    items[item->getItemID()] = item;
}

// Yeni bir kullanıcı ekler
void LibrarySystem::addUser(const User& user) {
    if (users.find(user.getUserID()) != users.end()) {
        throw LibraryException("User already exists");  // Kullanıcı zaten varsa hata fırlat
    }
    users[user.getUserID()] = new User(user);
}

// Ödünç alma işlemi
void LibrarySystem::borrowItem(const std::string& userID, const std::string& itemID) {
    auto userIt = users.find(userID);
    if (userIt == users.end()) {
        throw LibraryException("Accessing nonexistent user");  // Kullanıcı yoksa hata fırlat
    }

    auto itemIt = items.find(itemID);
    if (itemIt == items.end()) {
        throw LibraryException("Accessing nonexistent item");  // Öğe yoksa hata fırlat
    }

    userIt->second->borrowItem(itemIt->second);  // Ödünç alma işlemini gerçekleştir
    logTransaction("borrowed", userID, itemID);  // İşlemi logla
}

// İade işlemi
void LibrarySystem::returnItem(const std::string& userID, const std::string& itemID) {
    auto userIt = users.find(userID);
    if (userIt == users.end()) {
        throw LibraryException("Accessing nonexistent user");  // Kullanıcı yoksa hata fırlat
    }

    auto itemIt = items.find(itemID);
    if (itemIt == items.end()) {
        throw LibraryException("Accessing nonexistent item");  // Öğe yoksa hata fırlat
    }

    userIt->second->returnItem(itemIt->second);  // İade işlemini gerçekleştir
    logTransaction("returned", userID, itemID);  // İşlemi logla
}

// Tüm öğeleri gösterir
void LibrarySystem::displayAllItems() const {
    if (items.empty()) {
        std::cout << "No items in the library." << std::endl;
        return;
    }
    std::cout << "Library Items:" << std::endl;
    for (const auto& pair : items) {
        pair.second->display();
    }
}

// Tüm kullanıcıları gösterir
void LibrarySystem::displayAllUsers() const {
    if (users.empty()) {
        std::cout << "No users in the system." << std::endl;
        return;
    }
    std::cout << "Library Users:" << std::endl;
    for (const auto& pair : users) {
        pair.second->displayBorrowedItems();
    }
}

void LibrarySystem::logTransaction(const std::string& action, const std::string& userID, const std::string& itemID) const {
    std::ofstream logFile("logs/transactions.txt", std::ios::app);  // Dosya yolunu logs/ klasörüne ayarla
    if (!logFile) {
        std::cerr << "Error opening transactions.txt for logging! Path: logs/transactions.txt" << std::endl;
        return;
    }

    auto userIt = users.find(userID);
    auto itemIt = items.find(itemID);
    if (userIt == users.end() || itemIt == items.end()) {
        std::cerr << "Error: User or item not found! UserID: " << userID << ", ItemID: " << itemID << std::endl;
        return;
    }

    // Zaman damgası oluştur: [YYYY-MM-DD HH:MM:SS]
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);
    logFile << "[" << std::put_time(localTime, "%Y-%m-%d %H:%M:%S") << "] User: " << userID << " (" << userIt->second->getName() << ") " << action << " ";

    if (dynamic_cast<Book*>(itemIt->second)) {
        logFile << "Book: ";
    } else {
        logFile << "Magazine: ";
    }
    logFile << *(itemIt->second) << std::endl;

    std::cout << "Transaction logged: " << userID << " " << action << " " << itemID << std::endl;

    logFile.close();
}