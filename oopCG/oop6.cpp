#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Item {
public:
    string name;
    int quantity;
    int cost;
    int code;

    bool operator==(const Item& i1) const {
        return code == i1.code;
    }

    bool operator<(const Item& i1) const {
        return code < i1.code;
    }
};

vector<Item> items;

void print(const Item &i1);
void display();
void insert();
void search();
void dlt();
bool compare(const Item &i1, const Item &i2);

int main() {
    int ch;
    do {
        cout << "\n*** Menu ***";
        cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Search";
        cout << "\n4. Sort";
        cout << "\n5. Delete";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                sort(items.begin(), items.end(), compare);
                cout << "\n\nSorted on Cost";
                display();
                break;
            case 5:
                dlt();
                break;
            case 6:
                exit(0);
            default:
                cout << "\nInvalid choice. Try again.";
                break;
        }
    } while (ch != 6);

    return 0;
}

void insert() {
    Item item;
    cout << "\nEnter Item Name: ";
    cin >> item.name;
    cout << "Enter Item Quantity: ";
    cin >> item.quantity;
    cout << "Enter Item Cost: ";
    cin >> item.cost;
    cout << "Enter Item Code: ";
    cin >> item.code;
    items.push_back(item);
}

void display() {
    for_each(items.begin(), items.end(), print);
}

void print(const Item &item) {
    cout << "\n";
    cout << "\nItem Name: " << item.name;
    cout << "\nItem Quantity: " << item.quantity;
    cout << "\nItem Cost: " << item.cost;
    cout << "\nItem Code: " << item.code;
}

void search() {
    Item item;
    cout << "\nEnter Item Code to search: ";
    cin >> item.code;
    auto it = find(items.begin(), items.end(), item);
    if (it == items.end()) {
        cout << "\nNot found.";
    } else {
        cout << "\nFound." << endl;
        cout << "Item Name: " << it->name << endl;
        cout << "Item Quantity: " << it->quantity << endl;
        cout << "Item Cost: " << it->cost << endl;
        cout << "Item Code: " << it->code << endl;
    }
}

void dlt() {
    Item item;
    cout << "\nEnter Item Code to delete: ";
    cin >> item.code;
    auto it = find(items.begin(), items.end(), item);
    if (it == items.end()) {
        cout << "\nNot found.";
    } else {
        items.erase(it);
        cout << "\nDeleted.";
    }
}

bool compare(const Item &i1, const Item &i2) {
    return i1.cost < i2.cost;
}
