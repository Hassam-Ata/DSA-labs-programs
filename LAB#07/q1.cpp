#include <iostream>
using namespace std;

class CircularQueue {
    int rear, front;
    int size;
    int *arr;

public:
    CircularQueue(int s) 
    {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }

    void enQueue(int value) {
        if ((front == 0 && rear == size - 1) || ((rear + 1) % size == front)) 
        {
            cout << "\nQueue is Full";
            return;
        } 
        else if (front == -1) 
        { /* Insert First Element */
            front = rear = 0;
            arr[rear] = value;
        }
         else if (rear == size - 1 && front != 0) 
        {
            rear = 0;
            arr[rear] = value;
        } else {
            rear++;
            arr[rear] = value;
        }
    }

    int deQueue() {
        if (front == -1) 
        {
            cout << "\nQueue is Empty";
            return -1;
        }

        int data = arr[front];
        arr[front] = -1;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }

        return data;
    }

    void displayQueue() 
    {
        if (front == -1) 
        {
            cout << "\nQueue is Empty";
            return;
        }
        cout << "\nElements in Circular Queue are: ";
        if (rear >= front) 
        {
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
        } 
        else 
        {
            for (int i = front; i < size; i++)
                cout << arr[i] << " ";

            for (int i = 0; i <= rear; i++)
                cout << arr[i] << " ";
        }
    }
};

/* Driver of the program */
int main() {
    CircularQueue q(5);
    // Inserting elements in Circular Queue
    q.enQueue(14);
    q.enQueue(22);
    q.enQueue(13);
    q.enQueue(-6);

    // Display elements present in Circular Queue
    q.displayQueue();

    // Deleting elements from Circular Queue
    cout << "\nDeleted value = " << q.deQueue();
    cout << "\nDeleted value = " << q.deQueue();

    q.displayQueue();

    q.enQueue(9);
    q.enQueue(20);
    q.enQueue(5);

    q.displayQueue();

    q.enQueue(20);

    return 0;
}
