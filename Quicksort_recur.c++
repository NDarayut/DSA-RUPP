#include <array>
#include <iostream>

// Partition the array into the smaller side and the larger side
int partition(int array[10], int start, int end){

    // Take pivot to be at the end of the array
    int pivot = array[end];
    // i start before the first index
    int i = start - 1;

    // check if the number at index j is smaller than the pivot,
    // then we swap it with index i
    for(int j = start; j <= end; j++){
        if(array[j] < pivot){
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
	}
    
    /*  This code ensure that the pivot will be at the correct position.
        The end value will swap with the value at index of i.
        This will create a border between the smaller and larger value. With the pivot in the middle.
    */
    i++;
    int temp = array[i];
    array[i] = array[end];
    array[end] = temp;
   
		
	return i;

}

void quickSort(int array[10], int start, int end){

    // Return if array is sorted
    if(end <= start) return; //base case
	
    // Get the pivot position after every partitioning
    int pivot = partition(array, start, end);
    // Sort the left array
    quickSort(array, start, pivot - 1);
    // Sort the right array
    quickSort(array, pivot + 1, end);

}

int main(){
    // Initialize necessary variable
    int array[10] = {9, 2, 3, 4, 1, 10, 6, 8, 7, 5};
    int start = 0;
    int end =  sizeof(array) / sizeof(array[0]) -1;

    // call the quicsort function
    quickSort(array, start, end);

    // print sorted array
    for(int i = 0; i <= end; i++){
            std::cout << array[i] << " ";
        }
    return 0;
}