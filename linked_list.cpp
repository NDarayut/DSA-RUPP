#include <iostream>

// Class node is used to make each Node in a linked list
class Node{
    public:
        int Data; // initialize a public variable that store data of nodes
        Node *Next; // initialize a public variable that act as a pointer to point to the subsequent node

        // this constructor is called whenever a new node is created
        // it also takes integer as input
        Node(int data){
            this->Data = data;  // set the current data member variable to the provided input
            this->Next = nullptr; // initialize the pointer to the next node to null indicating it's probably the first or last node
        }
};

// Class linked list is used to add node, clear etc...
class LinkedList{

    private:
        Node *Head; // private pointer variable that hold the address of the first node
    public:
        // this constructor is called whenever a linked list is created
        LinkedList(){
            // initialize the head pointer to null upon creating the link list
            this->Head = nullptr;
        }
    
    // fucntion to add node to the tail of the list
    void add(int data){
        // Check if the Head pointer is empty, if so create a node
        if(Head == nullptr){
            // Create a node object
            Node *newNode = new Node(data);
            // Sets the current new node to be the head of the list
            newNode->Next = Head;
            Head = newNode;
        }

        else{
            Node *newNode = new Node(data);
            // Creats a temporary pointer that starts from the head
            Node *temporary = Head;
            // Iterate through the list as long as the temporary pointer is not empty
            while(temporary->Next != nullptr){
                // Moves the temporary pointer to the next node while looping
                temporary = temporary->Next;
            }
            // After reaching the end of the node, the last node pointer to a new node
            // successfully connecting the last node to a newly created node
            temporary->Next = newNode;
        }
    }

    // fucntion to add node to the tail of the list
    void addLast(int data){

        Node *newNode = new Node(data);
        // Creats a temporary pointer that starts from the head
        Node *temporary = Head;
        // Iterate through the list as long as the temporary pointer is not empty
        while(temporary->Next != nullptr){
            // Moves the temporary pointer to the next node while looping
            temporary = temporary->Next;
        }
        // After reaching the end of the node, the last node pointer to a new node
        // successfully connecting the last node to a newly created node
        temporary->Next = newNode;
        
    }
    // function to add a node to the head of the list
    void addFirst(int data){
        // Create a node object
        Node *newNode = new Node(data);
        // Sets the current new node to be the head of the list
        newNode->Next = Head;
        Head = newNode;
    }   

    // function to add node to the middle of the list
    void addMiddle(int data){
        int count = 0;
        int start = 0;
        Node *currentNode = Head;

        while(currentNode != nullptr){
          
            currentNode = currentNode->Next;
            count++;
        }

        Node *newNode = new Node(data);
        // Create a temporary pointer that starts from the head
        Node *temporary = Head;
        // temporary2 pointer start ahead of the head by 1
        Node *temporary2 = Head->Next;

        // Iterate until the middle of the list
        while(start < count/2){
            // temporary will contain the address of the current middle node
            temporary = temporary->Next;
            // temporary2 will contain the address ahead the middle node by 1
            temporary2 = temporary2->Next;
            start++;
        }
        // point the middle node pointer to a new node
        temporary->Next = newNode;
        // the new node point to the subsequent node connecting the list
        newNode->Next = temporary2;
     
    }

    // function to get the first value and delete it
    void getFirst(){

        // create an object that also contain the address of the Head pointer
        Node *First = Head;
        // print out the data of the head
        std::cout << "\n" << First->Data;
        Head = Head->Next;
        delete First;
    }

    // function to get the last value and delete it
    void getLast(){
     
        // Creats a Last pointer that starts from the head
        Node *Last = Head;
        // Iterate through the list as long as the Last pointer is not empty
        // The while loop will only look at the node after next node to ensure that 
        // the loop will end after reaching the second-to-last node
        while(Last->Next->Next != nullptr){
            // Moves the Last pointer to the next node while looping
            Last = Last->Next;
        }

        // print out the value of the Last node
        std::cout << "\n" << Last->Next->Data;
        // delete the last node
        delete Last->Next;
        // the second-to-last node now point to null
        Last->Next = nullptr;

    }

    // function to get the first value but not delete it
    void peekFirst(){
        Node *First = Head;
        std::cout << "\n" << First->Data;
    }

    // function to get the first value but not delete it
    void peekLast(){

        // Creats a Last pointer that starts from the head
        Node *Last = Head;

        // Iterate through the list as long as the Last pointer is not empty
        while(Last->Next != nullptr){

            // Moves the Last pointer to the next node while looping
            Last = Last->Next;
        }
        std::cout << "\n" << Last->Data;

    }

    // fucntion to delete all the address of the Node
    void clear(){
    
        while(Head != nullptr){
            Node *X = Head;
            Head = Head->Next;
            delete X;     
        }
        std::cout << "\nLinked list successfully deleted";
    }

    void print(){
        Node *temporary = Head;
        while(temporary != nullptr){
            std::cout << temporary->Data <<" ";
            temporary = temporary->Next;
        }
    }
};

int main(){

    /*
        By creating Node object and linking them together through Next pointers, we can build
        a linear sequence of data nodes.

        The LinkedList class manages the head pointers, which act as an entry point to access the linked list
    */

    // This loops will create 10 node all links to each other
   	LinkedList list;
    for(int i = 0; i < 10; i++){
        list.add(i+1);
    }

    list.addFirst(0);
    list.addLast(11);
    list.addMiddle(69);

    list.print();
    list.getFirst();
    list.getLast();
    list.peekFirst();
    list.peekLast();
    list.clear();
    list.print();
    
    return 0;
}