#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"

// Kitap sınıfı, LibraryItem'dan türetilmiştir
class Book : public LibraryItem {
private:
    std::string genre;  // Kitabın türü

public:
    // Yapıcı fonksiyon: Kitap bilgilerini alır
    Book(const std::string& id, const std::string& t, const std::string& a, const std::string& g, bool borrowed = false);
    
    // Kitap bilgilerini gösterir
    void display() const override;
};

#endif // BOOK_H