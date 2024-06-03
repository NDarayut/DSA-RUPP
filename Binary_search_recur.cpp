#include <array>
#include <iostream>

// Binary search function
int binarySearch(int KeySearch, int A[10], int nElement, int lowerBound, int upperBound) {
    // Variable to check for midpoint in array
    int midPoint;

    // Check if there are existing element that matches the key
    if(lowerBound <= upperBound){
        // Calculate the index of midpoint in the array
        midPoint = (lowerBound + upperBound) / 2;

        /*
            Check if key is found. If yes then we return its index.
            - If the value at mid is larger than key, then we move the upper bound down
            - If the value at mid is smaller than key, then we move the lower bound up
        */
        if(A[midPoint] == KeySearch){
            std::cout << "Found at index " << midPoint;
            return 0;
        }

        else if (A[midPoint] > KeySearch){
            return binarySearch(KeySearch, A, nElement, lowerBound, midPoint -1);
        }
        else{
            return binarySearch(KeySearch, A, nElement, midPoint + 1, upperBound);
        }
    }  
    std::cout << "Not Found";
    return 0;
} 

int main() {

  int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int KeySearch;
  int length = sizeof(A) / sizeof(A[0]);
  int lowerBound = 0;
  int upperBound = length -1;

  std::cout << "Type a number: "; // Type a number and press enter
  std::cin >> KeySearch;          // Get user input from the keyboard

  binarySearch(KeySearch, A, length, lowerBound, upperBound);

  return 0;
}