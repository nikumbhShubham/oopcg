#include <iostream>
#include <string>

struct Node {
    int PRN;
    std::string name;

    Node* next;
};

class PinnacleClub {
public:
    Node* president; // Pointer to the president node
    Node* secretary; // Pointer to the secretary node
    int totalMembers; // Total count of members in the club

    // Constructor
    PinnacleClub() {
        president = nullptr;
        secretary = nullptr;
        totalMembers = 0;
    }

    // Function to add a member
    void addMember(int prn, std::string name) {
        Node* newNode = new Node;
        newNode->PRN = prn;
        newNode->name = name;
        newNode->next = nullptr;

        if (president == nullptr) {
            president = newNode;
            secretary = newNode;
        } else {
            secretary->next = newNode;
            secretary = newNode;
        }

        totalMembers++;
    }

    // Function to delete a member by PRN
    void deleteMember(int prn) {
        Node* current = president;
        Node* prev = nullptr;

        while (current != nullptr && current->PRN != prn) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Member not found.\n";
            return;
        }

        if (current == president) {
            president = president->next;
        } else {
            prev->next = current->next;
        }

        if (current == secretary) {
            secretary = prev;
        }

        delete current;
        totalMembers--;
    }

    // Function to compute total number of members
    int getTotalMembers() {
        return totalMembers;
    }

    // Function to display all members
    void displayMembers() {
        Node* current = president;

        if (current == nullptr) {
            std::cout << "No members in the club.\n";
            return;
        }

        std::cout << "Club Members:\n";
        while (current != nullptr) {
            std::cout << "PRN: " << current->PRN << ", Name: " << current->name << std::endl;
            current = current->next;
        }
    }

    // Function to display list in reverse using recursion
    void displayReverse(Node* node) {
        if (node == nullptr) {
            return;
        }
        displayReverse(node->next);
        std::cout << "PRN: " << node->PRN << ", Name: " << node->name << std::endl;
    }

    // Function to concatenate two lists
    void concatenateLists(PinnacleClub& otherList) {
        if (president == nullptr) {
            president = otherList.president;
            secretary = otherList.secretary;
        } else {
            secretary->next = otherList.president;
            secretary = otherList.secretary;
        }
        totalMembers += otherList.totalMembers;
    }

    // Destructor to free memory
    ~PinnacleClub() {
        Node* current = president;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        president = nullptr;
        secretary = nullptr;
    }
};

int main() {
    PinnacleClub club;

    int choice, prn;
    std::string name;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Member\n";
        std::cout << "2. Delete Member\n";
        std::cout << "3. Display Total Members\n";
        std::cout << "4. Display All Members\n";
        std::cout << "5. Display List in Reverse\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter PRN of the member: ";
                std::cin >> prn;
                std::cout << "Enter Name of the member: ";
                std::cin.ignore(); // Ignore newline character in buffer
                std::getline(std::cin, name);
                club.addMember(prn, name);
                break;
            case 2:
                std::cout << "Enter PRN of the member to delete: ";
                std::cin >> prn;
                club.deleteMember(prn);
                break;
            case 3:
                std::cout << "Total Members: " << club.getTotalMembers() << std::endl;
                break;
            case 4:
                club.displayMembers();
                break;
            case 5:
                std::cout << "Members in Reverse Order:\n";
                club.displayReverse(club.president);
                break;
            case 6:
                std::cout << "Exiting...";
                exit(0);
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}
