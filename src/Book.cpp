#include "Book.h"
#include <iostream>

// Yapıcı fonksiyon: Kitap bilgilerini başlatır
Book::Book(const std::string& id, const std::string& t, const std::string& a, const std::string& g, bool borrowed)
    : LibraryItem(id, t, a), genre(g) {
    isBorrowed = borrowed;  // Ödünç durumunu ayarla
}

// Kitap bilgilerini göster
void Book::display() const {
    std::cout << "Book: " << itemID << " \"" << title << "\" by " << author << ", Genre: " << genre;
    if (isBorrowed) std::cout << " (Borrowed)";
    std::cout << std::endl;
}