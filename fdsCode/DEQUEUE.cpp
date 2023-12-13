#include <iostream>

#define MAX_SIZE 100

class Deque {
private:
    int deque[MAX_SIZE];
    int front, rear;
    int capacity;

public:
    Deque() {
        capacity = MAX_SIZE;
        front = -1;
        rear = 0;
    }

    bool isFull() {
        return (front == 0 && rear == capacity - 1) || front == rear + 1;
    }

    bool isEmpty() {
        return front == -1;
    }

    void insertFront(int element) {
        if (isFull()) {
            std::cout << "Deque is full. Cannot insert at front.\n";
            return;
        }

        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = capacity - 1;
        } else {
            front--;
        }

        deque[front] = element;
        std::cout << "Inserted " << element << " at the front of the deque.\n";
    }

    void insertRear(int element) {
        if (isFull()) {
            std::cout << "Deque is full. Cannot insert at rear.\n";
            return;
        }

        if (front == -1) {
            front = rear = 0;
        } else if (rear == capacity - 1) {
            rear = 0;
        } else {
            rear++;
        }

        deque[rear] = element;
        std::cout << "Inserted " << element << " at the rear of the deque.\n";
    }

    void deleteFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty. Cannot delete from front.\n";
            return;
        }

        int deletedElement = deque[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            if (front == capacity - 1) {
                front = 0;
            } else {
                front++;
            }
        }

        std::cout << "Deleted " << deletedElement << " from the front of the deque.\n";
    }

    void deleteRear() {
        if (isEmpty()) {
            std::cout << "Deque is empty. Cannot delete from rear.\n";
            return;
        }

        int deletedElement = deque[rear];
        if (front == rear) {
            front = rear = -1;
        } else {
            if (rear == 0) {
                rear = capacity - 1;
            } else {
                rear--;
            }
        }

        std::cout << "Deleted " << deletedElement << " from the rear of the deque.\n";
    }

    void displayDeque() {
        if (isEmpty()) {
            std::cout << "Deque is empty.\n";
            return;
        }

        std::cout << "Deque elements: ";
        int i = front;
        while (true) {
            std::cout << deque[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % capacity;
        }
        std::cout << std::endl;
    }
};

int main() {
    Deque deque;

    int choice, element;

    do {
        std::cout << "\nDeque Menu\n";
        std::cout << "1. Insert at Front\n";
        std::cout << "2. Insert at Rear\n";
        std::cout << "3. Delete from Front\n";
        std::cout << "4. Delete from Rear\n";
        std::cout << "5. Display Deque\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter element to insert at front: ";
                std::cin >> element;
                deque.insertFront(element);
                break;
            case 2:
                std::cout << "Enter element to insert at rear: ";
                std::cin >> element;
                deque.insertRear(element);
                break;
            case 3:
                deque.deleteFront();
                break;
            case 4:
                deque.deleteRear();
                break;
            case 5:
                deque.displayDeque();
                break;
            case 0:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 0);

    return 0;
}
