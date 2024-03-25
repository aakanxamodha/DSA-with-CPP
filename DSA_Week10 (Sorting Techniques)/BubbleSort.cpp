//Bubble Sort
//Aakanxa Modha
//230970031

#include <iostream>
using namespace std;

void swap(int& a, in1t& b) 
{
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() 
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
}
