#ifndef LIBRARY_EXCEPTION_H
#define LIBRARY_EXCEPTION_H
#include <string>

// Hata yönetimi için özel exception sınıfı
class LibraryException : public std::exception {
private:
    std::string message;  // Hata mesajı

public:
    // Yapıcı fonksiyon: Hata mesajını alır
    LibraryException(const std::string& msg);
    
    // Hata mesajını döndürür
    const char* what() const noexcept override;
};

#endif // LIBRARY_EXCEPTION_H