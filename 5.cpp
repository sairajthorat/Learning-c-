#include <iostream>
#include <string>

class Publication {
protected:
    std::string title;
    float price;

public:
    void getData() {
        std::cout << "Enter title: ";
        std::cin >> title;
        std::cout << "Enter price: $";
        std::cin >> price;
    }

    void displayData() {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Price: $" << price << std::endl;
    }
};

class Book : public Publication {
private:
    int pageCount;

public:
    void getData() {
        Publication::getData();
        std::cout << "Enter page count: ";
        std::cin >> pageCount;
    }

    void displayData() {
        Publication::displayData();
        std::cout << "Page count: " << pageCount << std::endl;
    }
};

class Tape : public Publication {
private:
    float playingTime;

public:
    void getData() {
        Publication::getData();
        std::cout << "Enter playing time (in minutes): ";
        std::cin >> playingTime;
    }

    void displayData() {
        Publication::displayData();
        std::cout << "Playing time: " << playingTime << " minutes" << std::endl;
    }
};

int main() {
    Book book;
    Tape tape;

    try {
        std::cout << "Enter book details:" << std::endl;
        book.getData();

        std::cout << "\nEnter tape details:" << std::endl;
        tape.getData();

        std::cout << "\nBook details:" << std::endl;
        book.displayData();

        std::cout << "\nTape details:" << std::endl;
        tape.displayData();
    } catch (...) {
        std::cout << "\nException caught! Resetting data members to zero." << std::endl;
        book = Book();
        tape = Tape();
    }

    return 0;
}
