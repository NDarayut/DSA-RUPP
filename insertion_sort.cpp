#include <iostream>;

//Insertion sort in ascending oder
void insertionSortAscending(int arr[10], int length){
    
    int tmp = 0;

    //loop through the whole array starting from index 1
    for(int i = 1; i < length; i++){
        tmp = arr[i]; 
        int j = i; 

        //While the left index is bigger than current index, we swap the current index with the left index
        while( j > 0 && arr[j-1] >= tmp){  

            //array at index 1 equal to array at left index (0)
            arr[j] = arr[j-1];
            j--;
        }
        //the left index which we store in tmp  equals the current index
        arr[j] = tmp;
    }

    //for every element in array, print them out
    for (int i = 0; i < length; i++) {
    std::cout << arr[i] << ", ";
  }
}

//Insertion sort in descending order
void insertionSortDescending(int arr[10], int length){
    int tmp = 0;

    //loop through the whole array starting from index 1
    for(int i = 1; i < length; i++){
        tmp = arr[i];
        int j = i;

         //While the left index is smaller than current index, we swap the current index with the left index
        while( j > 0 && arr[j-1] <= tmp){
            arr[j] = arr[j-1];
            j--;
        }

         //the left index which we store in tmp  equals the current index
        arr[j] = tmp;
    }

    //for every element in array, print them all out
    for (int i = 0; i < length; i++) {
    std::cout << arr[i] << ", ";
  }

}

//Main function 
int main(){

    // Initialize array with the size of 10
    int arr[10] = {64, 34, 25, 12, 22, 11, 90, 13, 54, 77};

    // Find the length of array by using sizeof() function
    int length = sizeof(arr) / sizeof(arr[0]);

    //Call the function to be use
    insertionSortAscending(arr, length);
    std::cout << "\n";
    insertionSortDescending(arr, length);

    return 0;
}