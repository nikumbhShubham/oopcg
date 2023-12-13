#include <iostream>
#include <unordered_set>

// Node structure for linked list
struct Node {
    int rollNumber; // Assuming each student has a unique roll number
    bool likesVanilla; // Indicates whether the student likes Vanilla ice-cream
    bool likesButterscotch; // Indicates whether the student likes Butterscotch ice-cream
    Node* next;

    Node(int roll, bool vanilla, bool butterscotch) {
        rollNumber = roll;
        likesVanilla = vanilla;
        likesButterscotch = butterscotch;
        next = nullptr;
    }
};

class IceCreamSet {
private:
    Node* head; // Pointer to the head of the linked list

public:
    IceCreamSet() {
        head = nullptr;
    }

    // Function to add a student to the set
    void addStudent(int roll, bool vanilla, bool butterscotch) {
        Node* newNode = new Node(roll, vanilla, butterscotch);
        newNode->next = head;
        head = newNode;
    }

    // Function to check if a student likes either Vanilla or Butterscotch or both
    bool likesEither(int roll) {
        Node* current = head;
        while (current != nullptr) {
            if (current->rollNumber == roll) {
                return (current->likesVanilla || current->likesButterscotch);
            }
            current = current->next;
        }
        return false;
    }

    // Function to check if a student likes both Vanilla and Butterscotch
    bool likesBoth(int roll) {
        Node* current = head;
        while (current != nullptr) {
            if (current->rollNumber == roll) {
                return (current->likesVanilla && current->likesButterscotch);
            }
            current = current->next;
        }
        return false;
    }

    // Function to check if a student likes only Vanilla and not Butterscotch
    bool likesOnlyVanilla(int roll) {
        Node* current = head;
        while (current != nullptr) {
            if (current->rollNumber == roll) {
                return (current->likesVanilla && !current->likesButterscotch);
            }
            current = current->next;
        }
        return false;
    }

    // Function to check if a student likes only Butterscotch and not Vanilla
    bool likesOnlyButterscotch(int roll) {
        Node* current = head;
        while (current != nullptr) {
            if (current->rollNumber == roll) {
                return (!current->likesVanilla && current->likesButterscotch);
            }
            current = current->next;
        }
        return false;
    }

    // Function to count students who like neither Vanilla nor Butterscotch
    int likesNeither() {
        Node* current = head;
        int count = 0;
        while (current != nullptr) {
            if (!current->likesVanilla && !current->likesButterscotch) {
                count++;
            }
            current = current->next;
        }
        return count;
    }
};

int main() {
    IceCreamSet setA; // Set of students who like Vanilla
    IceCreamSet setB; // Set of students who like Butterscotch

    // Add students' ice-cream preferences to set A (Vanilla)
    setA.addStudent(101, true, false);
    setA.addStudent(102, false, true);
    setA.addStudent(103, true, true);
    setA.addStudent(104, false, false);
    setA.addStudent(105, true, false);

    // Add students' ice-cream preferences to set B (Butterscotch)
    setB.addStudent(101, true, false);
    setB.addStudent(102, false, true);
    setB.addStudent(103, true, true);
    setB.addStudent(104, false, false);
    setB.addStudent(105, false, true);

    // Set of students who like either Vanilla or Butterscotch or both
    std::cout << "Set of students who like either Vanilla or Butterscotch or both:\n";
    for (int i = 101; i <= 105; ++i) {
        if (setA.likesEither(i) || setB.likesEither(i)) {
            std::cout << "Roll Number: " << i << std::endl;
        }
    }

    // Set of students who like both Vanilla and Butterscotch
    std::cout << "\nSet of students who like both Vanilla and Butterscotch:\n";
    for (int i = 101; i <= 105; ++i) {
        if (setA.likesBoth(i) && setB.likesBoth(i)) {
            std::cout << "Roll Number: " << i << std::endl;
        }
    }

    // Set of students who like only Vanilla and not Butterscotch
    std::cout << "\nSet of students who like only Vanilla and not Butterscotch:\n";
    for (int i = 101; i <= 105; ++i) {
        if (setA.likesOnlyVanilla(i) && !setB.likesEither(i)) {
            std::cout << "Roll Number: " << i << std::endl;
        }
    }

    // Set of students who like only Butterscotch and not Vanilla
    std::cout << "\nSet of students who like only Butterscotch and not Vanilla:\n";
    for (int i = 101; i <= 105; ++i) {
        if (setB.likesOnlyButterscotch(i) && !setA.likesEither(i)) {
            std::cout << "Roll Number: " << i << std::endl;
        }
    }

    // Number of students who like neither Vanilla nor Butterscotch
    std::cout << "\nNumber of students who like neither Vanilla nor Butterscotch: " << setA.likesNeither() << std::endl;

    return 0;
}
