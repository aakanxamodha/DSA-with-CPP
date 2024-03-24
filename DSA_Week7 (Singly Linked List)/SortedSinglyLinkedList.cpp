//Implement a sorted singly linked list. Include the following options: inserting a node, deleting a node and displaying the list.
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

class SortedLinkedList 
{
  private:
    Node* head;

  public:
    SortedLinkedList() 
    {
        head = nullptr;
    }

    void insertNode(int value) 
    {
        Node* newNode = new Node(value);
        if (head == nullptr || head->data >= value) 
        {
            newNode->next = head;
            head = newNode;
        } 
        else 
        {
            Node* current = head;
            while (current->next != nullptr && current->next->data < value) 
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        cout << "Node with value " << value << " inserted into the sorted list.\n";
    }

    void deleteNode(int value) 
    {
        if (head == nullptr) 
        {
            cout << "List is empty. Deletion failed.\n";
            return;
        }
        if (head->data == value) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node with value " << value << " deleted from the sorted list.\n";
            return;
        }
        Node* current = head;
        while (current->next != nullptr && current->next->data != value) 
        {
            current = current->next;
        }
        if (current->next == nullptr) 
        {
            cout << "Node with value " << value << " not found in the list. Deletion failed.\n";
            return;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        cout << "Node with value " << value << " deleted from the sorted list.\n";
    }

    void displayList() 
    {
        if (head == nullptr) 
        {
            cout << "List is empty.\n";
            return;
        }
        cout << "Elements in the sorted list are: ";
        Node* current = head;
        while (current != nullptr) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() 
{
    SortedLinkedList list;
    int choice, value;

    do 
    {
        cout << "\nSorted Singly Linked List Operations Menu:\n";
        cout << "1. Insert a node\n";
        cout << "2. Delete a node\n";
        cout << "3. Display the list\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertNode(value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;
            case 3:
                list.displayList();
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
