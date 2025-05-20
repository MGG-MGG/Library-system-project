#include "LibrarySystem.h"
#include "Book.h"
#include "Magazine.h"
#include "User.h"
#include "LibraryException.h"
#include <iostream>
#include <string>

int main() {
    LibrarySystem library;  // Kütüphane sistemi nesnesi
    int choice;

    while (true) {
        // Menüyü göster
        std::cout << "\nLibrary Management System Menu:\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Add Magazine\n";
        std::cout << "3. Add User\n";
        std::cout << "4. Borrow Book\n";
        std::cout << "5. Return Book\n";
        std::cout << "6. View All Items\n";
        std::cout << "7. View All Users\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter your choice: ";

        // Kullanıcı girişini oku ve doğrula
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input! Please enter a number.\n";
            std::cin.clear();  // Hata durumunu temizle
            std::cin.ignore(10000, '\n');  // Buffer'ı temizle
            continue;
        }
        std::cin.ignore();  // Buffer'ı temizle

        try {
            if (choice == 1) { // Kitap ekle
                std::string id, title, author, genre;
                std::cout << "Enter Book ID: ";
                std::getline(std::cin, id);
                std::cout << "Enter Title: ";
                std::getline(std::cin, title);
                std::cout << "Enter Author: ";
                std::getline(std::cin, author);
                std::cout << "Enter Genre: ";
                std::getline(std::cin, genre);
                library.addItem(new Book(id, title, author, genre));
                std::cout << "Book added successfully!" << std::endl;

            } else if (choice == 2) { // Dergi ekle
                std::string id, title, author, month;
                int issue;
                std::cout << "Enter Magazine ID: ";
                std::getline(std::cin, id);
                std::cout << "Enter Title: ";
                std::getline(std::cin, title);
                std::cout << "Enter Author: ";
                std::getline(std::cin, author);
                std::cout << "Enter Issue Number: ";
                if (!(std::cin >> issue)) {
                    std::cout << "Invalid input! Please enter a number.\n";
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    continue;
                }
                std::cin.ignore();
                std::cout << "Enter Month: ";
                std::getline(std::cin, month);
                library.addItem(new Magazine(id, title, author, issue, month));
                std::cout << "Magazine added successfully!" << std::endl;

            } else if (choice == 3) { // Kullanıcı ekle
                std::string id, name;
                std::cout << "Enter User ID: ";
                std::getline(std::cin, id);
                std::cout << "Enter User Name: ";
                std::getline(std::cin, name);
                library.addUser(User(id, name));
                std::cout << "User added successfully!" << std::endl;

            } else if (choice == 4) { // Ödünç al
                // Önce mevcut öğeleri göster
                std::cout << "Available Items:\n";
                library.displayAllItems();

                std::string userID, itemID;
                std::cout << "Enter User ID: ";
                std::getline(std::cin, userID);
                std::cout << "Enter Item ID: ";
                std::getline(std::cin, itemID);
                library.borrowItem(userID, itemID);
                std::cout << "Item borrowed successfully!" << std::endl;

            } else if (choice == 5) { // İade et
                // Önce mevcut kullanıcıları ve ödünç alınan öğeleri göster
                std::cout << "Borrowed Items:\n";
                library.displayAllUsers();

                std::string userID, itemID;
                std::cout << "Enter User ID: ";
                std::getline(std::cin, userID);
                std::cout << "Enter Item ID: ";
                std::getline(std::cin, itemID);
                library.returnItem(userID, itemID);
                std::cout << "Item returned successfully!" << std::endl;

            } else if (choice == 6) { // Tüm öğeleri göster
                library.displayAllItems();

            } else if (choice == 7) { // Tüm kullanıcıları göster
                library.displayAllUsers();

            } else if (choice == 8) { // Çıkış
                std::cout << "Exiting program..." << std::endl;
                break;

            } else {
                std::cout << "Invalid choice! Please try again." << std::endl;
            }
        } catch (const LibraryException& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}