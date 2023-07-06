// Programmer: Christian Paterson

#include <iostream>
#include <algorithm>
using namespace std;

// Global variables & prototypes
const int MAX_SIZE = 20;
void displayArray(const int arr[], int size);
void split(int arr[], int size, int positive[], int& positiveSize, int negative[], int& negativeSize);

// Main function
int main()
{
    int arr[MAX_SIZE];
    int size;

    // Get user input
    do {
      cout << "Enter the size of the array (up to 20): ";
      cin >> size;
    } while (size < 1 || size > MAX_SIZE);

    cout << "Enter " << size << " (positive or negative) integer values, space separated: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    // Initialize variables necessary for sorting
    int positive[MAX_SIZE];
    int positiveSize;
    int negative[MAX_SIZE];
    int negativeSize;

    split(arr, size, positive, positiveSize, negative, negativeSize);
    sort(positive, positive + positiveSize);
    sort(negative, negative + negativeSize);

    // Display sorted arrays
    cout << "Positive numbers: ";
    displayArray(positive, positiveSize);

    cout << "Negative numbers: ";
    displayArray(negative, negativeSize);

    return 0;
}

// Place all numbers in appropriate array
void split(int arr[], int size, int positive[], int& positiveSize, int negative[], int& negativeSize)
{
    positiveSize = 0;
    negativeSize = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] >= 0) {
            positive[positiveSize] = arr[i];
            positiveSize++;
        } else {
            negative[negativeSize] = arr[i];
            negativeSize++;
        }
    }
}

// Display sorted arrays
void displayArray(const int arr[], int size)
{
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}