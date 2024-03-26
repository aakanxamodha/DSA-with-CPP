//Implementation of Stack using arrays.
//Aakanxa Modha
//230970031

#include<iostream>
using namespace std;

#define MAX_SIZE 100

class Stack
{
  private:
    int arr[MAX_SIZE];
    int top;

  public:
    Stack()
    {
      top=-1;
    }

    bool isEmpty()
    {  
      return (top == -1);
    }

    bool isFull()
    {
      return (top == MAX_SIZE - 1);
    }

    void push(int data)
    {
      if(isFull())
      {
        cout<<"Stack overflow.\n";
        return;
      }
      arr[++top];
    }

    int pop()
    {
      if(isEmpty())
      {
        cout<<"Stack underflow.\n";
        return -1;
      }
      return arr[top--];
    }

    int peek()
    {
      if(isEmpty())
      {
        cout<<"Stack is empty.\n";
        return -1;
      }
      return arr[top];
    }
};

int main()
{
  Stack stack;
  int choice, data;

  do
  {
    cout<<"1. Push\n";
    cout<<"2. Pop\n";
    cout<<"3. Peek\n";
    cout<<"4. Exit\n";
    cout<<"Enter your choice: ";
    cin>>choice;

    switch(choice)
    {
      case 1: 
          cout<<"Enter data to push: ";
          cin>>data;
          stack.push(data);
          break;

      case 2:
          cout<<"Popped element: ";
          cout<<stack.pop()<<endl;
          break;

      case 3:
          cout<<"Top element: ";
          stack.peek()<<endl;
          break;

      case 4:
          cout<<"Exiting...";
          break;

      default:
          cout<<"Invalid choice\n";
    }
  }while(choice != 4);
}
