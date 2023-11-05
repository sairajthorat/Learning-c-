#include <iostream>
#include <exception>

using namespace std;

class Publication {
protected:
  string title;
  float price;

public:
  Publication(string title, float price) : title(title), price(price) {}

  string getTitle() const { return title; }
  float getPrice() const { return price; }
};

class Book : public Publication {
private:
  int pageCount;

public:
  Book(string title, float price, int pageCount) : Publication(title, price), pageCount(pageCount) {}

  int getPageCount() const { return pageCount; }
};

class Tape : public Publication {
private:
  float playingTime;

public:
  Tape(string title, float price, float playingTime) : Publication(title, price), playingTime(playingTime) {}

  float getPlayingTime() const { return playingTime; }
};

int main() {
  try {
    // Instantiate a book and tape object.
    Book book("The Hitchhiker's Guide to the Galaxy", 12.99, 224);
    Tape tape("The Hitchhiker's Guide to the Galaxy", 14.99, 60);

    // Prompt the user to enter data.
    cout << "Enter the title of the book: ";
    cin >> book.title;

    cout << "Enter the price of the book: ";
    cin >> book.price;

    cout << "Enter the page count of the book: ";
    cin >> book.pageCount;

    cout << "Enter the title of the tape: ";
    cin >> tape.title;

    cout << "Enter the price of the tape: ";
    cin >> tape.price;

    cout << "Enter the playing time of the tape: ";
    cin >> tape.playingTime;

    // Display the data members.
    cout << endl << "Book:" << endl;
    cout << "Title: " << book.getTitle() << endl;
    cout << "Price: " << book.getPrice() << endl;
    cout << "Page count: " << book.getPageCount() << endl;

    cout << endl << "Tape:" << endl;
    cout << "Title: " << tape.getTitle() << endl;
    cout << "Price: " << tape.getPrice() << endl;
    cout << "Playing time: " << tape.getPlayingTime() << endl;
  } catch (exception& e) {
    // Handle the exception.
    cout << "Exception caught: " << e.what() << endl;
    cout << "Replacing all data member values with zero values." << endl;

    // Replace all data member values with zero values.
    Book::title = "";
    Book::price = 0.0;
    Book::pageCount = 0;

    Tape::title = "";
    Tape::price = 0.0;
    Tape::playingTime = 0.0;
  }

  return 0;
}
