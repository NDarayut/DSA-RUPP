#include <array>
#include <iostream>

int Non_duplicate_search(int A[10], int KeySearch) {
  int i;
  //Loop through 10 elements in the array
  for (i = 0; i < 10; ++i) {
    //If the value at that specific index match keyword
    //break loop
    if (A[i] == KeySearch)
      break;
  }
  //if i loop through array less than 10 times
  if (i < 10) {
    //We found the key and print out the index in which we found
    std::cout << "Found";
    std::cout << " at index " << i;
  } 
  //if loop through the array then there's no keysearch
  else {
    std::cout << "There is no the KeySearch";
  }
  return 0;
}

int Duplicate_search(int A[10], int KeySearch) {
  int i;
  //initialize variable count to count duplicated key search
  int Count = 0;
  //if found key word we increase count by 1
  //and keep looping till the end
  for (i = 0; i < 10; ++i) {
    if (A[i] == KeySearch)
      Count++;
  }
  //if count is not 0 then key word is found
  if (Count != 0) {
    //print out amount of key word found
    std::cout << "\nFound KeySearch, " << Count << " times";
  } 
  //else key word not found
  else {
    std::cout << "Not Found";
  }

  return 0;
}

int find(int KeySearch, int A[10]) {
  int Count = 1;
  int nElement = 10;
  int lowerBound = 0;
  int upperBound = nElement - 1;
  int curIn;

  while (true) {
    //curIn is the mid point of the array
    curIn = (lowerBound + upperBound) / 2;
    //if Array at index curIn equal key word
    //We print which index it is found and the attempts
    if (A[curIn] == KeySearch) {
      std::cout << "\nFound at index " << curIn;
      std::cout << "\nAttempt: " << Count;
      return 0; // found it
    }
    //lower bound becomes higher than upper bound then theres no key 
    else if (lowerBound > upperBound) {
      return nElement; // can’t found it
      std::cout << "\nNot Found";
    } 

    else {
      //if the key is bigger than mid point 
      //then the lower bound is mid point plus 1
      if (A[curIn] < KeySearch) {
        lowerBound = curIn + 1; // it’s in upper half
        Count++;
      } 
      //if the key is smaller than mid point
      //then upper bound is mid point minus 1
      else {
        upperBound = curIn - 1; // it’s in lower half
        Count++;
      }
    } 
  }   
} 

int main() {
  //initialize array
  int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int KeySearch;

  std::cout << "Type a number: "; // Type a number and press enter
  std::cin >> KeySearch;          // Get user input from the keyboard
  //pass array and key to the function
  Non_duplicate_search(A, KeySearch);
  Duplicate_search(A, KeySearch);
  find(KeySearch, A);

  return 0;
}