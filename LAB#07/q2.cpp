#include <iostream>
#include <queue>
using namespace std;

class Queue {
    int size;
    queue<int> q;

public:
    Queue(int s) 
    {
        size = s;
    }

    void enQueue(int value) {
        if (q.size() == size) {
            cout << "\nQueue is Full";
            return;
        }
        q.push(value);
    }

    int deQueue() {
        if (q.empty()) {
            cout << "\nQueue is Empty";
            return -1;
        }

        int data = q.front();
        q.pop();
        return data;
    }

    void displayQueue() 
    {
        if (q.empty()) 
        {
            cout << "\nQueue is Empty";
            return;
        }

        cout << "\nElements in Queue are: ";
        queue<int> tempQ = q;
        while (!tempQ.empty()) 
        {
            cout << tempQ.front() << " ";
            tempQ.pop();
        }
    }
};

int main() {
    Queue q(5);

    // Inserting elements in the Queue
    q.enQueue(14);
    q.enQueue(22);
    q.enQueue(13);
    q.enQueue(-6);

    // Display elements present in the Queue
    q.displayQueue();

    // Deleting elements from the Queue
    cout << "\nDeleted value = " << q.deQueue();
    cout << "\nDeleted value = " << q.deQueue();

    q.displayQueue();

    q.enQueue(9);
    q.enQueue(20);
    q.enQueue(5);

    q.displayQueue();

    q.enQueue(20); // Trying to enqueue when the queue is full

    return 0;
}
