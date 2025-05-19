#include "LibraryItem.h"
#include "LibraryException.h"

// Yapıcı fonksiyon: Yeni bir LibraryItem oluşturur
LibraryItem::LibraryItem(const std::string& id, const std::string& t, const std::string& a)
    : itemID(id), title(t), author(a), isBorrowed(false) {}

// Ödünç alma işlemini gerçekleştirir
bool LibraryItem::getBorrow() {
    if (isBorrowed) {
        throw LibraryException("Borrowing an already borrowed book");  // Zaten ödünç alınmışsa hata fırlat
    }
    isBorrowed = true;  // Ödünç alındı olarak işaretle
    return true;
}

// Ödünç iade işlemini gerçekleştirir
void LibraryItem::returnBack() {
    if (!isBorrowed) {
        throw LibraryException("Returning an unborrowed book");  // Ödünç alınmamışsa hata fırlat
    }
    isBorrowed = false;  // Ödünç iade edildi olarak işaretle
}

// Çıktı operatörü: Öğe bilgilerini yazdırır
std::ostream& operator<<(std::ostream& os, const LibraryItem& item) {
    os << item.itemID << " \"" << item.title << "\"";
    return os;
}