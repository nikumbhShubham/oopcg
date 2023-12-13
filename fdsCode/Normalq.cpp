#include <iostream>

#define MAX_SIZE 100

class Queue
{
private:
    int queue[MAX_SIZE];
    int front, rear;
    int capacity;

public:
    Queue()
    {
        capacity = MAX_SIZE;
        front = rear = -1;
    }

    bool isFull()
    {
        return rear == capacity - 1;
    }

    bool isEmpty()
    {
        return front == -1 || front > rear;
    }

    void enqueue(int element)
    {
        if (isFull())
        {
            std::cout << "Queue is full. Cannot enqueue more elements.\n";
            return;
        }

        if (front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = element;
        std::cout << "Enqueued " << element << " to the queue.\n";
    }
    void dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        int *dequeuedValue = new int(queue[front]); // Allocate memory for the dequeued integer
        front++;
        std::cout << "Dequeued " << *dequeuedValue << " from the queue.\n";

        // Deallocate memory for the dequeued integer
        delete dequeuedValue;
    }

    int getFront()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty.\n";
            return -1; // Return some default value or handle this case according to your application
        }

        return queue[front];
    }
    void printQueue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty.\n";
            return;
        }

        std::cout << "Queue elements: ";
        for (int i = front; i <= rear; ++i)
        {
            std::cout << queue[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.dequeue();
    queue.enqueue(40);

    std::cout << "Front element: " << queue.getFront() << std::endl;

    return 0;
}
