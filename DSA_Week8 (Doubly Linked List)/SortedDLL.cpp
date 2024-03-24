// Implement a sorted doubly linked list. Include the following options: inserting a node, deleting a node and displaying the list in both directions.
//Aakanxa Modha
//230970031

#include <iostream>
using namespace std;

class Node 
{
  public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) 
    {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class SortedDoublyLinkedList 
{
  private:
    Node* head;
    Node* tail;

  public:
    SortedDoublyLinkedList() 
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertNode(int value) 
    {
        Node* newNode = new Node(value);
        if (head == nullptr) 
        {
            head = tail = newNode;
        } 
        else 
          if (head->data >= value) 
          {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
          } 
          else 
            if (tail->data <= value) 
            {
              newNode->prev = tail;
              tail->next = newNode;
              tail = newNode;
            } 
            else 
            {
              Node* current = head;
              while (current->next != nullptr && current->next->data < value) 
              {
                current = current->next;
              }
              newNode->prev = current;
              newNode->next = current->next;
              current->next->prev = newNode;
              current->next = newNode;
            }
            cout << "Node with value " << value << " inserted into the sorted doubly linked list.\n";
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
            if (head != nullptr)
                head->prev = nullptr;
            delete temp;
            cout << "Node with value " << value << " deleted from the sorted doubly linked list.\n";
            return;
        }
        if (tail->data == value) 
        {
            Node* temp = tail;
            tail = tail->prev;
            if (tail != nullptr)
                tail->next = nullptr;
            delete temp;
            cout << "Node with value " << value << " deleted from the sorted doubly linked list.\n";
            return;
        }
        Node* current = head;
        while (current != nullptr && current->data != value) 
        {
            current = current->next;
        }
        if (current == nullptr) 
        {
            cout << "Node with value " << value << " not found in the list. Deletion failed.\n";
            return;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        cout << "Node with value " << value << " deleted from the sorted doubly linked list.\n";
    }

    void displayListForward() 
    {
        if (head == nullptr) 
        {
            cout << "List is empty.\n";
            return;
        }
        cout << "Elements in the list (forward direction): ";
        Node* current = head;
        while (current != nullptr) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void displayListBackward() 
    {
        if (tail == nullptr) 
        {
            cout << "List is empty.\n";
            return;
        }
        cout << "Elements in the list (backward direction): ";
        Node* current = tail;
        while (current != nullptr) 
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() 
{
    SortedDoublyLinkedList list;
    int choice, value;

    do 
    {
        cout << "\nSorted Doubly Linked List Operations Menu:\n";
        cout << "1. Insert a node\n";
        cout << "2. Delete a node\n";
        cout << "3. Display the list (forward direction)\n";
        cout << "4. Display the list (backward direction)\n";
        cout << "5. Exit\n";
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
                list.displayListForward();
                break;
            case 4:
                list.displayListBackward();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 5);
    return 0;
}
