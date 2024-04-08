#include <iostream>
#include <stack> 

int main(){
    // create a stack of type int
    std::stack<int> stack;

    // add element into the stack 
    for(int i = 1; i<6; i++){
        stack.push(i);
    }

    // print the number that is on top of the stack
    std::cout << "Top of the stack is " << stack.top() << "\n";

    // print the size of the stack
    std::cout << "Size of the stack is " << stack.size() << "\n";

    // pop the stack
    stack.pop();

    // print the top of the stack again
    std::cout << "Top of stack after pop " <<  stack.top() << "\n";

    // perform pop operation until stack is empty 
    while(!stack.empty()){
        stack.pop();
    }

    // check if stack is empty after pop
    std::cout << "Stack is empty: " << stack.empty(); 

    return 0;
}