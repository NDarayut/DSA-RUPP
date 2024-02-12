#include <iostream>

// We pass in the array and lenght of the array
void bubble_sort_ascending(int arr[10], int length) {
  //initialize variable to store temporary value
  int tmp = 0;
 
   // Loop to the second to last index of the array not the end of the array
  for (int i = 0; i < length - 1; i++) {
    // Loop to the last index and stop the loop before we reach the sorted element
    for (int j = 0; j < (length - i - 1); j++) {
     //if the first value is greater than the second value
     //we swap them
      if (arr[j] > arr[j + 1]) {
        tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
  std::cout << "Ascending order\n";
  //print out the sorted array
  for (int i = 0; i < length; i++) {
    std::cout << arr[i] << ", ";
  }
}

void bubble_sort_descending(int arr[10], int length) {
  //initialize variable to temporary store a value
  int tmp = 0;
  // Loop to the second to last index of the array not the end of the      //array
  for (int i = 0; i < length - 1; i++) {
     // Loop to the last index and stop the loop before we reach the         //sorted element
    for (int j = 0; j < (length - i - 1); j++) {
     //if the first element is smaller than the second element, we             //perform a swap
      if (arr[j] < arr[j + 1]) {
        tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
  std::cout << "Descending order\n";
  //print out the sorted array
  for (int i = 0; i < length; i++) {
    std::cout << arr[i] << ", ";
  }
}

int main() {
  // Initialize array with the size of 10
  int arr[10] = {64, 34, 25, 12, 22, 11, 90, 13, 54, 77};
  // Find the length of array by using sizeof() function
  //size of return the byte of the int which is 4 
  int length = sizeof(arr) / sizeof(arr[0]);
  //we call the functions to be use 
  bubble_sort_ascending(arr, length);
  std::cout << "\n";
  bubble_sort_descending(arr,length);
}
