//Selection Sort
//Aakanxa Modha
//230970031

#include <iostream>
using namespace std;

void swap(int& a, int& b) 
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
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

    selectionSort(arr, n);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
