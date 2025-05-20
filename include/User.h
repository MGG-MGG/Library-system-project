#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include "LibraryItem.h"

// Kullanıcı sınıfı
class User {
private:
    std::string userID;  // Kullanıcı kimliği
    std::string name;  // Kullanıcı adı
    std::vector<LibraryItem*> borrowedItems;  // Ödünç alınan öğeler

public:
    // Yapıcı fonksiyon
    User(const std::string& id, const std::string& n);
    
    // Yıkıcı fonksiyon: Bellek temizliği için
    ~User();
    
    // Kullanıcı kimliğini döndür
    std::string getUserID() const { return userID; }
    
    // Kullanıcı adını döndür
    std::string getName() const { return name; }
    
    // Ödünç alma işlemi
    void borrowItem(LibraryItem* item);
    
    // İade işlemi
    void returnItem(LibraryItem* item);
    
    // Ödünç alınan öğeleri göster
    void displayBorrowedItems() const;
};

#endif // USER_H