#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph{
    
    vector<vector<int>> adjacencyMatrix;
    int vertices;
    vector<bool> visited;

    public:
        Graph(int vertices){
            // initialize the vertices of the graph
            this->vertices = vertices;

            // the entire array is initialize as 0 
            adjacencyMatrix = vector<vector<int>>(vertices, vector<int>(vertices, 0));

            // initialize visited vector as false
            visited = vector<bool>(vertices, false);
        }

        void addEdge(int vertex, int edge){
            adjacencyMatrix[vertex][edge] = 1;
        }

        void bfs(int start, int goal){

            int current;
            queue<int> queue;
            visited[start] = true;

            if(start == goal){
                cout << "\nFound " << start;
                return;
            }

            queue.push(start);

            while(!queue.empty()){
                current = queue.front();
                cout << current;
                queue.pop();

                if(current == goal){
                    cout << "\nFound " << current;
                    return;
                }

                for(int i = 0; i < vertices; i++){
                    if(adjacencyMatrix[current][i] == 1 && !visited[i]){
                        queue.push(i);
                        visited[i] = true;

                    }
                }
                cout << "->";
            }

            cout << "\nGoal not found";
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
    graph.bfs(0, 1);

    return 0;
}