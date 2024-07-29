#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Graph{    
    // instance variable for initialization of graph
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
        
        // depth=first-search algorithm
        void dfs(int start, int goal){
            
            // mark visited node 
            visited[start] = true;
            cout << start;
            
            // check if node is equal to the goal
            if(start == goal){
                cout << "\nFound vertex " << start << "\n";
                return;
            }
            
            else{
                cout << "->";
                // loop through all the edges of a node using recursion
                // the recursion will traverse until it hit a dead end and back-tracks to a junction
                for(int i = 0; i < vertices; i++){
                    // if theres an edge and it hasnt been visited, we go deeper into the graph
                    if(adjacencyMatrix[start][i] = 1 && !visited[i]){
                        dfs(i, goal);
                    }
                }
            }
            

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

    graph.dfs(0, 5);
 
    return 0;
}