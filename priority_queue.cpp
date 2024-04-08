#include <iostream>
#include <queue>

int main() {

    // priority queue
    std::priority_queue<int> p_q;
    
    // unorganized array
    int array[10] = { 9, 1, 3, 4, 6, 2, 10, 11, 5, 100};

    // insert each element into the priority queue that store largest to smallest number
    for(int i = 0; i < 11; i++){
        p_q.push(array[i]);
    }

    // get every single element from the priority queue
    std::cout << "Priority queue max to min: ";
    while(!p_q.empty()){
        std::cout << p_q.top() << " ";
        p_q.pop();
    }

    // priority queue to store min to max
    std::priority_queue <int, std::vector<int>, std::greater<int>> pq;

    // insert each element into the priority queue that store smallest to largest number
    for(int i = 0; i < 11; i++){
        pq.push(array[i]);
    }

    // get every single element from the priority queue
    std::cout << "\n" << "Priority queue min to max: "; 
    while(!pq.empty()){
        std::cout  << pq.top() << " ";
        pq.pop();
    }

    return 0;
}