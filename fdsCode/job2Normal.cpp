#include <iostream>

#define MAX_SIZE 100

class JobQueue {
private:
    int queue[MAX_SIZE];
    int front, rear;

public:
    JobQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    void addJob(int job) {
        if (isFull()) {
            std::cout << "Job queue is full. Cannot add more jobs.\n";
            return;
        } else if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }

        queue[rear] = job;
        std::cout << "Added job " << job << " to the queue.\n";
    }

    void deleteJob() {
        if (isEmpty()) {
            std::cout << "Job queue is empty. No job to delete.\n";
            return;
        } else if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }

        std::cout << "Deleted job from the queue.\n";
    }

    void printQueue() {
        if (isEmpty()) {
            std::cout << "Job queue is empty. Nothing to print.\n";
            return;
        }

        std::cout << "Current job queue:\n";
        std::cout << "-----------------\n";
        for (int i = front; i <= rear; ++i) {
            std::cout << queue[i] << " ";
        }
        std::cout << "\n";
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
                jobQueue.deleteJob();
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
