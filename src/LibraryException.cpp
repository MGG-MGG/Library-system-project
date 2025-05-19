#include "LibraryException.h"

// Yapıcı fonksiyon: Hata mesajını ayarlar
LibraryException::LibraryException(const std::string& msg) : message(msg) {}

// Hata mesajını döndürür
const char* LibraryException::what() const noexcept {
    return message.c_str();
}