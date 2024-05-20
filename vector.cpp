#include <iostream>
#include <vector>


int main(){

    /*
        Iterator:
        -- begin()
        -- end()
        -- rbegin()
        -- rend()
    */

    // initialize a vector
    std::vector<int> vector = {1,2,3,4};

    // initialize a vector iterator 
    std::vector<int>::iterator iter;
    std::vector<int>::iterator iter1;
    std::vector<int>::iterator iter2;

    // add some value into the vectors
    vector.push_back(5);
    vector.push_back(6);

    // point to an address pointing to the first element in the vector
    iter1 = vector.begin();
    // point to an address to the element afte the final element
    iter2 = vector.end() - 1;

    // return the first element in the vector
    std::cout << "First element in vector: " << *iter1 << "\n";
    // return the last item in the vector
    std::cout << "Last element in vector: " << *iter2 << "\n";

    // print the entire vector using begin() and end() function
    std::cout << "Vector before reversed: ";
    for(iter = vector.begin(); iter != vector.end(); iter++){
        std::cout << *iter << " ";
    }

    // This line of code will rebuild a new vector that take the old vector end
    // as the head and the front as the tail
    // rbegin() points to the end of the vector and iterate backward
    // rend() points to the position before the first element
    std::vector<int> vectorReversed(vector.rbegin(), vector.rend());
    std::cout << "\n";

    // print the newly reversed vector
    std::cout << "Vector after reversed: ";
    for(iter = vectorReversed.begin(); iter != vectorReversed.end(); iter++){
        std::cout << *iter << " ";
    }

    /*
        Capacity:
        -- size()
        -- max_size()
        -- capacity()
        -- resize(n)
        -- empty()
    */
    std::cout << "\n";

    // size() return the length of the vector
    std::cout << "size of vector: " << vector.size() << "\n";

    // max_size() return the amount of elements a vector can hold
    std::cout << "max size of vector: " << vector.max_size() << "\n";
    
    // capacity() return the amount of storage allocated for the vector 
    // this amount can grow and shrink according to the modification of a vector
    std::cout << "storage space allocated for vector: " << vector.capacity() << "\n";

    // resize() resize the vector according to the current amount of element in the vector
    // if current amount is greater than than the resize value, then the vector will remove some element
    vector.resize(4);
    std::cout << "Vector after resize to 4 elements: ";
    for(iter = vector.begin(); iter != vector.end(); iter++){
        std::cout << *iter << " ";
    }

    // if current amount is lesserr than than the resize value, then the vector will add zeros to populate the vector
    vector.resize(10);
    std::cout << "\n";
    std::cout << "Vector after resize to 10 elements: ";
    for(iter = vector.begin(); iter != vector.end(); iter++){
        std::cout << *iter << " ";
    }

    // empty() return a boolean, if the vector is empty it returns 1 if not, it return 0
    std::cout << "\n";
    if(vector.empty()){
        std::cout << "Vector is empty!";
    }
    else{
        std::cout << "Vector is not empty!";
    }

    return 0;
}