#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H
#include <string>
#include <iostream>

class LibraryItem {
protected:
    std::string itemID;  // Öğe kimliği
    std::string title;   // Öğe başlığı
    std::string author;  // Öğe yazarı
    bool isBorrowed;     // Ödünç alınmış mı?

public:
    // Yapıcı fonksiyon: Öğe bilgilerini alır
    LibraryItem(const std::string& id, const std::string& t, const std::string& a);
    
    // Saf sanal fonksiyon: Polimorfizm için
    virtual void display() const = 0;
    
    // Ödünç alma işlemi
    bool getBorrow();
    
    // Ödünç iade işlemi
    void returnBack();
    
    // Öğe kimliğini döndür
    std::string getItemID() const { return itemID; }
    
    // Ödünç durumunu döndür
    bool getIsBorrowed() const { return isBorrowed; }

    // Çıktı operatörü
    friend std::ostream& operator<<(std::ostream& os, const LibraryItem& item);
};

#endif // LIBRARY_ITEM_H