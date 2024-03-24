//Implementing queue using Singly linked list
//Aakanxa Modha
//230970031

#include <iostream>
using namespace std;

class Node 
{
  public:
    int data;
    Node* next;

    Node(int value) 
    {
        data = value;
        next = nullptr;
    }
};

class Queue 
{
  private:
    Node* front;
    Node* rear;

  public:
    Queue() 
    {
        front = rear = nullptr;
    }

    void enqueue(int value) 
    {
        Node* newNode = new Node(value);
        if (isEmpty()) 
        {
            front = rear = newNode;
        } 
        else 
        {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued into the queue.\n";
    }

    void dequeue() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty. Dequeue operation failed.\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        cout << temp->data << " dequeued from the queue.\n";
        delete temp;
    }

    int getFront() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty.\n";
            return -1;
        }
        return front->data;
    }

    bool isEmpty() 
    {
        return front == nullptr;
    }
};

int main() 
{
    Queue q;
    int choice, value;

    do 
    {
        cout << "\nQueue Operations Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Get front element\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << "Front element: " << q.getFront() << endl;
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 4);
    return 0;
}
