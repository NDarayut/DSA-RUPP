#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Graph{    

    vector<vector<int>> adjacencyMatrix;
    int vertices;
    vector<bool> visited;

    public:
        // constructer that initialize the graph and its size
        Graph(int vertices){

            // initialize the vertices of the graph
            this->vertices = vertices;

            // the entire array is initialize as 0 
            adjacencyMatrix = vector<vector<int>>(vertices, vector<int>(vertices, 0));

            // initialize visited vector as false
            visited = vector<bool>(vertices, false);
            
        }

        // method to add edges
        void addEdge(int vertex, int edge){
            adjacencyMatrix[vertex][edge] = 1;
        }
        
        void dfs(int start, int goal){
            
            int current;
            visited[start] = true;
            stack<int> stack;

            if(start == goal){
                cout << "\nFound vertex " << start;
                return;
            }
            
            // push starting vertex to stack
            stack.push(start);

            // keeps checking as long as stack is not empty
            while(!stack.empty()){
            
                // pop the item from stack and store in current
                current = stack.top();
                cout << current;
                stack.pop();

                // check if current node equals to goal
                if(current == goal){
                    cout << "\nFound vertex " << current;
                    return;
                }
                
                // loop through all the edges of the current node and put them into a stack
                // add them to visited list to prevent them from being added to the stack again
                for(int i = 0; i < vertices; i++){
                    // push all connected node to a stack start from smallest to largest if it hasnt been visited
                    if(adjacencyMatrix[current][i] == 1 && !visited[i]){
                        // push adjacency vertex excluding itself
                        stack.push(i);
                        visited[i] = true;
                    }
                }
                cout << "->";
            }

            cout << "\nVertex not found!";
                
            }
        
        // print graph as matrix
        void print(){
            for(int row = 0; row < vertices; row++){
               for(int col = 0; col < vertices; col++){
                    cout << adjacencyMatrix[row][col] << " "; 
                }
                cout << "\n";
            }
        }
};

int main(){
    
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 0);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 0);
    graph.addEdge(3, 2);
    graph.addEdge(4, 2);
    graph.print();

    cout << "Breadth First Search: ";
    graph.dfs(0, 5);

 
    return 0;
}