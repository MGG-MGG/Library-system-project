#include "Magazine.h"
#include <iostream>

// Yapıcı fonksiyon: Dergi bilgilerini başlatır
Magazine::Magazine(const std::string& id, const std::string& t, const std::string& a, int issue, const std::string& m)
    : LibraryItem(id, t, a), issueNumber(issue), month(m) {}

// Dergi bilgilerini göster
void Magazine::display() const {
    std::cout << "Magazine: " << itemID << " \"" << title << "\" by " << author << ", Issue: " << issueNumber << ", Month: " << month;
    if (isBorrowed) std::cout << " (Borrowed)";
    std::cout << std::endl;
}