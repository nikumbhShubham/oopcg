#include <iostream>
using namespace std;

// #define MAX_ORDERS 100 // Maximum number of orders

class CircularQueue {
private:
    int front, rear, size;
    int *orders;

public:
    CircularQueue(int capacity) {
        front = rear = -1;
        size = capacity;
        orders = new int[size];
    }

    ~CircularQueue() {
        delete[] orders;
    }

    bool isFull() {
        return (front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1));
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int order) {
        if (isFull()) {
            cout << "Queue is full. Cannot add more orders." << endl;
            return;
        }

        if (front == -1)
            front = 0;

        rear = (rear + 1) % size;
        orders[rear] = order;
        cout << "Order " << order << " added successfully." << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No orders to dequeue." << endl;
            return -1;
        }

        int order = orders[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;

        return order;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Orders in the queue are: ";
        int i = front;
        while (i != rear) {
            cout << orders[i] << " ";
            i = (i + 1) % size;
        }
        cout << orders[rear] << endl;
    }
};

int main() {
    int M; // Maximum number of orders
    cout << "Enter the maximum number of orders the pizza parlor can accept: ";
    cin >> M;

    CircularQueue ordersQueue(M);

    int choice, order;
    do {
        cout << "\n---- Pizza Parlor Menu ----" << endl;
        cout << "1. Place an order" << endl;
        cout << "2. Serve an order" << endl;
        cout << "3. Display orders in the queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (!ordersQueue.isFull()) {
                    cout << "Enter the order number: ";
                    cin >> order;
                    ordersQueue.enqueue(order);
                } else {
                    cout << "Sorry, the queue is full. Cannot accept more orders." << endl;
                }
                break;

            case 2:
                if (!ordersQueue.isEmpty()) {
                    int servedOrder = ordersQueue.dequeue();
                    if (servedOrder != -1)
                        cout << "Order " << servedOrder << " served and removed from the queue." << endl;
                } else {
                    cout << "No orders in the queue to serve." << endl;
                }
                break;

            case 3:
                ordersQueue.displayQueue();
                break;

            case 4:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 4);

    return 0;
}
