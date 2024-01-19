#include <bits/stdc++.h>
using namespace std;

// Function to sort the array
void sort(int arr[], int n)
{
    int i = 0;
    while (i < n)
    {

        // Finding the correct index
        int correct = arr[i] - 1;

        // Element index and value not match
        // then swapping
        if (arr[correct] != arr[i])
        {

            // Calling swap function
            swap(arr[i], arr[correct]);
        }
        else
        {
            i++;
        }
    }
}

// Function to swap values
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Driver Code
int main()
{
    int arr[] = {3, 2, 5, 6, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function call
    sort(arr, n);

    // Printing the answer
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}