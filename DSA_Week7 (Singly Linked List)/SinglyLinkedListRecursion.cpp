//Reverse a singly-linked list using recursion.
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

class LinkedList 
{
  private:
    Node* head;

  public:
    LinkedList() 
    {
        head = nullptr;
    }

    void insertNode(int value) 
    {
        Node* newNode = new Node(value);
        if (head == nullptr) 
        {
            head = newNode;
        } 
        else 
        {
            Node* temp = head;
            while (temp->next != nullptr) 
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void displayList() 
    {
        if (head == nullptr) 
        {
            cout << "List is empty.\n";
            return;
        }
        cout << "Elements in the list are: ";
        Node* current = head;
        while (current != nullptr) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void reverseList(Node* node) 
    {
        if (node == nullptr)
            return;
        if (node->next == nullptr) 
        {
            head = node;
            return;
        }
        reverseList(node->next);
        node->next->next = node;
        node->next = nullptr;
    }

    void reverseListWrapper() 
    {
        reverseList(head);
    }
};

int main() 
{
    LinkedList list;
    int n, value;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) 
    {
        cin >> value;
        list.insertNode(value);
    }

    cout << "Original list:\n";
    list.displayList();

    list.reverseListWrapper();

    cout << "Reversed list:\n";
    list.displayList();
    return 0;
}
