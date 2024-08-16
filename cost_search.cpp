#include <iostream>
#include <queue>
#include <vector>
#include <iomanip> // For setw() to add padding

using namespace std;

class Graph{

    vector<vector<int>> adjacencyMatrix;
    int vertices;

    public:
        Graph(int vertices){
            this->vertices = vertices;
            // create a graph whose weights are all -1
            adjacencyMatrix = vector<vector<int>>(vertices, vector<int>(vertices, -1));
        }

        // add connected node to a specify vertex with weights.
        void addEdge(int vertex, int edge, int weight){
            adjacencyMatrix[vertex][edge] = weight;
        }

        void costSearch(int start, int goal){
            /*
                open = {5, 1} means node 1 has 5 cumulative cost, meaning from starting node to node 1 took 5 cost.
                costBetweenNode = [0, 2, 5] means, node 1 has a cumulative cost of 2, and node 2 has a cumulative cost of 5
                close = [true, true, false] means node 0 and 1 has been visited and node 2 has not been visited

                Note:
                    - The "open" queue stores a "cumulative" cost starting from the "start" node to any adjacent node.
                    Example: Node start -> Node 1 has 2 cost. Node 1 -> Node 2 has 5 cost. Therefore Node 2 stores in open will have 7 cost
                             rather than 5 cost. {7, 2} Node 2 with 7 cost
                    - The "costBetweenNode" vector keeps track of all the cumulative cost between the "start" Node to every other node.
                    - currentCost stores a cumulative cost of the current node.
                    Example: It takes 7 total cost to get from "start" Node to Node 2. So therefore, the currentCost of Node 2 is 7.
                    - The "path" vector keeps tracks of the shortest possible path.
            */

            // priority queue that sort all the node based on their cost. Min->Max cost
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> open; // {5, 1} meaning node 1 has 5 cost 
            
            // list that keeps track of all the cost from start node to every other node
            vector<int> costBetweenNode(vertices, INT_MAX); // [0, 1, 5] mean node 0 to node 2 has a cost of 5
            
            vector<bool> close(vertices, false); // list to store visited node

            vector<vector<int>> paths(vertices); // To store the path for each node

            costBetweenNode[start] = 0; // cost of starting node is 0
            paths[start] = {start}; // Start path with the starting node
            open.push({0, start}); // push the starting node to open list with cost 0

            while(!open.empty()){

                int currentCost = open.top().first; // select the least cost from the open list
                int currentVertex = open.top().second; // select the node with the least cost from the open list

                open.pop(); // remove the node after selecting it

                // rerun from top again if the current node already visited
                if(close[currentVertex]){
                    continue;
                }

                // mark current node as visited
                close[currentVertex] = true;

                // print out the cost if the current node is the goal
                if(currentVertex == goal){
                    cout << "Cost: " << currentCost << endl;
                }

                // check adjacent node of the current node and see if it's visited
                for(int i = 0; i < vertices; i++){
                    // if the adjacent node is not visited
                    if(adjacencyMatrix[currentVertex][i] > -1 && !close[i]){
                        // calculate the cost it takes to travel to the adjacent node
                        int cost = currentCost + adjacencyMatrix[currentVertex][i];
                        // if the current cost is smaller than previous cost, we add it to the list and add it to open
                        // when we perform the open sequence again, it will check for successor of the current node in open
                        if(cost < costBetweenNode[i]){
                            costBetweenNode[i] = cost;
                            paths[i] = paths[currentVertex]; // Copy the current path
                            paths[i].push_back(i); // Append the current node
                            open.push({cost, i});
                        }
                    }
                }

                // we run this while loop until there is no longer any element in the open list
            }

            // if the cost from start to goal node didn't change, then we assume the goal node doesn't exist
            if(costBetweenNode[goal] == INT_MAX){
                cout << "No path found" << endl;
            }
            // print the cost from start to goal
            else{
                cout << "Shortest path cost to goal node: " << costBetweenNode[goal] << endl;
                cout << "Path: ";
                for (int node : paths[goal]) {
                    cout << node;
                    if (node != goal) {
                        cout << " -> ";
                    }
                }
                cout << endl;
            }
        }

        // print graph as matrix
        void print(){
            for(int row = 0; row < vertices; row++){
               for(int col = 0; col < vertices; col++){         
                    cout << setw(3) << adjacencyMatrix[row][col] << " "; 
                }
                cout << "\n";
            }
        }
};

int main(){

    Graph graph(3);

    graph.addEdge(0, 1, 2);
    graph.addEdge(1, 0, 3);
    graph.addEdge(1, 2, 1);
    graph.addEdge(2, 0, 5);

    graph.print();

    graph.costSearch(0, 2);

    return 0;
}