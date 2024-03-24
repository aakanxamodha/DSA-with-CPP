//Implementation of Queue using arrays.
//Aakanxa Modha
//230970031

#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Queue 
{
  private:
    int arr[MAX_SIZE];
    int front, rear;

  public:
    Queue() 
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
        cout << x << " enqueued into the queue\n";
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
            cout << arr[front] << " dequeued from the queue\n";
            front = rear = -1;
          } 
          else 
          {
            cout << arr[front] << " dequeued from the queue\n";
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
        cout << "Queue elements are: ";
        int i = front;
        while (i != rear) 
        {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << arr[rear] << endl;
    }
};

int main() 
{
    Queue q;
    int choice, element;

    do 
    {
        cout << "\nQueue Operations Menu:\n";
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
                q.enqueue(element);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << "Front element: " << q.getFront() << endl;
                break;
            case 4:
                q.display();
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
