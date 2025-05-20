#include "User.h"
#include "LibraryException.h"
#include <iostream>

// Yapıcı fonksiyon
User::User(const std::string& id, const std::string& n) : userID(id), name(n) {}

// Yıkıcı fonksiyon: Bellek sızıntısını önlemek için
User::~User() {
    borrowedItems.clear();  // Vektörü temizle
}

// Ödünç alma işlemi
void User::borrowItem(LibraryItem* item) {
    if (!item->getBorrow()) {
        throw LibraryException("Cannot borrow item");  // Ödünç alınamıyorsa hata fırlat
    }
    borrowedItems.push_back(item);  // Ödünç alınan öğeyi listeye ekle
}

// İade işlemi
void User::returnItem(LibraryItem* item) {
    bool found = false;
    for (auto it = borrowedItems.begin(); it != borrowedItems.end(); ++it) {
        if (*it == item) {
            borrowedItems.erase(it);  // Ödünç alınan öğeyi listeden çıkar
            found = true;
            break;
        }
    }
    if (!found) {
        throw LibraryException("User did not borrow this item");  // Öğe kullanıcıda değilse hata fırlat
    }
    item->returnBack();  // Ödünç iade işlemini gerçekleştir
}

// Ödünç alınan öğeleri göster
void User::displayBorrowedItems() const {
    std::cout << "Borrowed items by " << name << " (" << userID << "):" << std::endl;
    if (borrowedItems.empty()) {
        std::cout << "  None" << std::endl;
    } else {
        for (const auto& item : borrowedItems) {
            item->display();
        }
    }
}