#ifndef LIBRARY_SYSTEM_H
#define LIBRARY_SYSTEM_H
#include "LibraryItem.h"
#include "User.h"
#include <map>
#include <string>

class LibrarySystem {
private:
    std::map<std::string, LibraryItem*> items;  // Kütüphanedeki öğeleri saklar
    std::map<std::string, User*> users;  // Kayıtlı kullanıcıları saklar

public:
    // Yıkıcı fonksiyon: Dinamik ayrılan belleği temizler
    ~LibrarySystem();
    
    // Yeni bir öğe ekler
    void addItem(LibraryItem* item);
    
    // Yeni bir kullanıcı ekler
    void addUser(const User& user);
    
    // Ödünç alma işlemi
    void borrowItem(const std::string& userID, const std::string& itemID);
    
    // İade işlemi
    void returnItem(const std::string& userID, const std::string& itemID);
    
    // Tüm öğeleri gösterir
    void displayAllItems() const;
    
    // Tüm kullanıcıları gösterir
    void displayAllUsers() const;
    
    // İşlemi log dosyasına kaydeder
    void logTransaction(const std::string& action, const std::string& userID, const std::string& itemID) const;
};

#endif // LIBRARY_SYSTEM_H