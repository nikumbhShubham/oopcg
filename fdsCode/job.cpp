#include <iostream>

class JobQueue {
private:
    int *queue;
    int front, rear;
    int capacity;

public:
    JobQueue() {
        capacity = 10; // Initial capacity of the queue
        queue = new int[capacity];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    void resizeQueue() {
        int newCapacity = capacity * 2; // Double the capacity when resizing
        int *newQueue = new int[newCapacity];
        int i = 0;
        while (!isEmpty()) {
            newQueue[i++] = queue[front];
            dequeue();
        }
        front = 0;
        rear = i - 1;
        delete[] queue;
        queue = newQueue;
        capacity = newCapacity;
    }

    void addJob(int job) {
        if (isFull()) {
            std::cout << "Job queue is full. Resizing the queue...\n";
            resizeQueue();
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        queue[rear] = job;
        std::cout << "Added job " << job << " to the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Job queue is empty. No job to delete.\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        std::cout << "Deleted job from the queue.\n";
    }

    void printQueue() {
        if (isEmpty()) {
            std::cout << "Job queue is empty.\n";
            return;
        }

        std::cout << "Current Job Queue: ";
        int i = front;
        while (i != rear) {
            std::cout << queue[i] << " ";
            i = (i + 1) % capacity;
        }
        std::cout << queue[rear] << "\n";
    }

    ~JobQueue() {
        delete[] queue;
    }
};

int main() {
    JobQueue jobQueue;
    int choice, job;

    do {
        std::cout << "\nJob Queue Menu\n";
        std::cout << "1. Add Job\n";
        std::cout << "2. Delete Job\n";
        std::cout << "3. Print Job Queue\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter the job number to add: ";
                std::cin >> job;
                jobQueue.addJob(job);
                break;
            case 2:
                jobQueue.dequeue();
                break;
            case 3:
                jobQueue.printQueue();
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
