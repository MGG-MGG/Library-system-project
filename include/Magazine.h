#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "LibraryItem.h"

// Dergi sınıfı, LibraryItem'dan türetilmiştir
class Magazine : public LibraryItem {
private:
    int issueNumber;  // Dergi sayısı
    std::string month;  // Dergi ayı

public:
    // Yapıcı fonksiyon: Dergi bilgilerini alır
    Magazine(const std::string& id, const std::string& t, const std::string& a, int issue, const std::string& m);
    
    // Dergi bilgilerini gösterir
    void display() const override;
};

#endif // MAGAZINE_H