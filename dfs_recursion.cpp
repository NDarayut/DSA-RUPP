#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Graph{
    // instance variable
    vector<vector<int>> adjacencyMatrix;
    int vertices;
    vector<bool> visited;
    stack<int> stack;
   
    
    public:
        // boolean to mark if we found a node
        bool found;

        // constructor for creating adjacency matrix
        Graph(int vertices){
            // initialize the vertices
            this->vertices = vertices;

            // the entire array is initialize as 0 
            adjacencyMatrix = vector<vector<int>>(vertices, vector<int>(vertices, 0));

            // initialize visited vector as false
            visited = vector<bool>(vertices, false);
        }

        // method to add edge or connected node
        void addEdge(int node, int edge){
            adjacencyMatrix[node][edge] = 1;
        }

        // depth-first-search algorithm
        void dfs(int start, int goal){
            
            int current = start;
            // mark current node as visited
            visited[current] = true;
            cout << current;
           
            // if the current node is equal to goal we deem it as found
            if(start == goal){
                cout << "\nFound node " << start;
                found = true;
                return;
            }
           
            else{
                cout << "->";

                // loop through adjacent node or connected node of the current node
                // everytime we found a connection we go deeper into the graph
                // once we hit a dead-end we back-tracks to a junction and explore other unvisited node
                for(int i = 0; i < vertices; i++){
                    if(adjacencyMatrix[current][i] == 1 && !visited[i]){
                        dfs(i, goal); // recursion on adjacent node and unvisited
                    }
                }
            }
        }

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

    Graph graph(3);

    graph.addEdge(0, 1);
    graph.addEdge(1, 0);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.print();
    
    graph.dfs(0, 2);
    if(!graph.found){
        cout << "\nNode not found!";
    }

    return 0;
}