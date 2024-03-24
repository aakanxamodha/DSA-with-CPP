//Implementation of Circular Queue using arrays.
//Aakanxa Modha
//230970031

#include <iostream>
using namespace std;

#define MAX_SIZE 100

class CircularQueue 
{
  private:
    int arr[MAX_SIZE];
    int front, rear;

  public:
    CircularQueue() 
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty() 
    {
        return (front == -1 && rear == -1);
    }

    bool isFull() 
    {
        return (rear + 1) % MAX_SIZE == front ? true : false;
    }

    void enqueue(int x) 
    {
        if (isFull()) 
        {
            cout << "Error: Queue is full\n";
            return;
        }
        if (isEmpty()) 
        {
            front = rear = 0;
        } 
        else 
        {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = x;
        cout << x << " enqueued into the circular queue\n";
    }

    void dequeue() 
    {
        if (isEmpty()) 
        {
            cout << "Error: Queue is empty\n";
            return;
        }
        else 
          if (front == rear) 
          {
              cout << arr[front] << " dequeued from the circular queue\n";
              front = rear = -1;
          } 
          else 
          {
              cout << arr[front] << " dequeued from the circular queue\n";
              front = (front + 1) % MAX_SIZE;
          }
    }

    int getFront() 
    {
        if (isEmpty()) 
        {
            cout << "Error: Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    void display() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Circular Queue elements are: ";
        int i = front;
        do 
        {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } 
        while (i != (rear + 1) % MAX_SIZE);
        cout << endl;
    }
};

int main() 
{
    CircularQueue cq;
    int choice, element;

    do 
    {
        cout << "\nCircular Queue Operations Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display front element\n";
        cout << "4. Display all elements\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter element to enqueue: ";
                cin >> element;
                cq.enqueue(element);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cout << "Front element: " << cq.getFront() << endl;
                break;
            case 4:
                cq.display();
                break;
            case 5:
                cout << "Exiting program\n";
                break;
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 5);
    return 0;
}
