#include <iostream>

// method to find node that is connected to and from user input node, and also weights
void findConnectedNode(int adjacency_matrix[10][10], int nodeSearch){
   
    // sizeof() returns the byte of the type, hence we divide by byte of int
    int matrixSize = sizeof(adjacency_matrix[0]) / sizeof (int);
    
    // if user input node is negative or larger than the graph size, then it is an invalid node
    if(nodeSearch < 0 || nodeSearch >= matrixSize){
        std::cout << "Invalid node!" << std::endl;
        return;
    }

    // traverse through the graph by accessing through every node first
    for(int node = 0; node < matrixSize; node++){

        // check if the node other than the user input node has a value at the user input node
        // return the node and its weights if there is a connection at the user input node
        if(adjacency_matrix[node][nodeSearch -1 ] > -1){
            std::cout << "Node " << nodeSearch << " is connected from node " << node + 1 << " with weights: " << adjacency_matrix[node][nodeSearch - 1] << std::endl;
        }

        // check if we traverse to the user input node
        // check all the connection in the user input node to see if it connects to any node and return the weightd
        else if(node == (nodeSearch - 1)){
            for(int connectedNode = 0; connectedNode < matrixSize; connectedNode++){
                if(adjacency_matrix[node][connectedNode] > -1){
                    std::cout << "Node " << nodeSearch << " is connected to node " << connectedNode + 1 << " with weights: " << adjacency_matrix[node][connectedNode] << std::endl;
                }
            }
        }
    }
    return;
}

int main(){

    int adjacency_matrix[10][10] ={{-1, 2, -1, 3, -1, -1, -1, -1, -1, -1}, // Edges for node 1
                                    {-1, -1, 4, 2, 7, -1, -1, -1, -1, -1}, // Edges for node 2
                                    {-1, -1, -1, -1, 3, 2, -1, -1, -1, 2}, // Edges for node 3
                                    {3, -1, -1, -1, 4, -1, -1, -1, -1, -1}, // Edges for node 4
                                    {1, -1, -1, -1, -1, -1, -1, -1, 8, -1}, // Edges for node 5
                                    {-1, -1, -1, -1, -1, -1, -1, -1, -1, 1}, // Edges for node 6
                                    {-1, -1, -1, 2, 6, -1, -1, -1, -1, -1}, // Edges for node 7
                                    {-1, -1, -1, -1, -1, 3, -1, -1, 2, -1}, // Edges for node 8
                                    {-1, -1, 6, -1, -1, 3, 10, -1, -1, 4}, // Edges for node 9
                                    {-1, -1, -1, -1, -1, 1, -1, 1, -1, -1}, // Edges for node 10
                                    };

    int nodeSearch;
    std::cout << "Type a node you to search: "; // Type a number and press enter
    std::cin >> nodeSearch;          // Get user input from the keyboard

    findConnectedNode(adjacency_matrix, nodeSearch);

    return 0;
}