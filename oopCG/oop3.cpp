#include <iostream>
using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    Publication() : title(""), price(0.0) {}

    void getData() {
        cout << "Enter the title: ";
        cin >> title;

        cout << "Enter the price: ";
        cin >> price;
    }

    void displayData() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};

class Book : public Publication {
private:
    int pageCount;

public:
    Book() : pageCount(0) {}

    void getData() {
        Publication::getData(); // Call base class method to get title and price

        cout << "Enter the page count: ";
        cin >> pageCount;
    }

    void displayData() const {
        Publication::displayData(); // Call base class method to display title and price
        cout << "Page Count: " << pageCount << " pages" << endl;
    }
};

class Tape : public Publication {
private:
    float playingTime;

public:
    Tape() : playingTime(0.0) {}

    void getData() {
        Publication::getData(); // Call base class method to get title and price

        cout << "Enter the playing time (minutes): ";
        cin >> playingTime;
    }

    void displayData() const {
        Publication::displayData(); // Call base class method to display title and price
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};

int main() {
    Book book;
    Tape tape;

    try {
        cout << "Enter book information:" << endl;
        book.getData();

        cout << "\nEnter tape information:" << endl;
        tape.getData();

        cout << "\nBook information:" << endl;
        book.displayData();

        cout << "\nTape information:" << endl;
        tape.displayData();
    } catch (const exception& e) {
        cerr << "An exception occurred: " << e.what() << endl;
        cerr << "Setting all data members to zero." << endl;

        // Set all data members to zero in case of an exception
        book = Book();
        tape = Tape();
    }

    return 0;
}