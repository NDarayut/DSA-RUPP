#include <iostream>
#include <queue>

int main() {

    // create a queue
    std::queue<int> queue;
    std::queue<int> queue2;

    // adding element to queue2
    for(int i = 90; i < 101; i++){
        queue2.push(i);
    }



    // adding element to queue of type int
    for(int i = 1; i<11; i++){
        queue.push(i);
    }

    // print the size of queue after addibg all the element
    std::cout << "Size of queue1 is " << queue.size() << "\n";

    // get the element at the front of queue
    std::cout << "Element at the front of queue1 " << queue.front() << "\n";

    // get the element at the back of the queue
    std::cout << "Element at the back of the queue1 " << queue.back() << "\n";

    // swap queue1 with queue2
    queue.swap(queue2);

    // get the element at the front of queue
    std::cout << "Element at the front of queue1 " << queue.front() << "\n";

    // insert new element to queue1 but at the back
    queue.emplace(89);

    // get the element at the back of the queue
    std::cout << "Element at the back of the queue1 " << queue.back() << "\n";

    // pop every element in queue1 and check
    while(!queue.empty()){
        queue.pop();
    }

    if(queue.empty()){
        std::cout << "Queue is empty";
    }
    
    return 0;
}