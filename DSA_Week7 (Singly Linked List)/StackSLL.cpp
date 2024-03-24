//Implementing stack using Singly linked list
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

class Stack 
{
  private:
    Node* top;

  public:
    Stack() 
    {
        top = nullptr;
    }

    void push(int value) 
    {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << value << " pushed to the stack.\n";
    }

    void pop() 
    {
        if (isEmpty()) 
        {
            cout << "Stack is empty. Pop operation failed.\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << temp->data << " popped from the stack.\n";
        delete temp;
    }

    int peek() 
    {
        if (isEmpty()) 
        {
            cout << "Stack is empty.\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() 
    {
        return top == nullptr;
    }
};

int main() 
{
    Stack s;
    int choice, value;

    do 
    {
        cout << "\nStack Operations Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout << "Top element: " << s.peek() << endl;
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
