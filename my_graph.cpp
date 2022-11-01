#include <iostream>
#include <vector>
#include <map>
#include <stdexcept>
#include <list>
using namespace std;
class Graph {
    public:
        //requires: two integer vectors: starts and ends
        //effects: Constructs a Graph with the given set of edges, where starts and ends represent the ordered list of edges’ start and endpoints.
        Graph(const vector<int> &starts, const vector<int> &ends) {

            if (starts.size() != ends.size()) throw invalid_argument("The two vectors are not the same length.");

            for (int i = 0; i < starts.size(); i++) adj[starts[i]].push_back(ends[i]);

        }
        //requires: Node's ID
        //effects: Returns the number of outgoing edges from nodeID – that is, edges with nodeID as the start point.
        int numOutgoing(const int nodeID) const {
            if (adj.find(nodeID) == adj.end()) throw invalid_argument("The nodeID does not exist in the graph.");

            return adj.at(nodeID).size();
        }
        //requires: Node's ID
        //effects: Returns a reference to the list of nodes to which nodeID has outgoing edges
        const vector<int> &adjacent(const int nodeID) const {
            if (adj.find(nodeID) == adj.end()) throw invalid_argument("The nodeID does not exist in the graph.");

            return adj.at(nodeID);
        }



        //requires: Node's ID - two int vectors
        //effects: check if the graph has a non-trivial cycle and returns it.
        vector<int> hasCycle(int nodeID, vector<bool> &visited, vector<int> &node_path) { //the functions works according to DFS
            visited[nodeID] = true;
            vector<int> List;
            node_path.push_back(nodeID);
            int i,j,k;
            for (i = 0; i < adj[nodeID].size(); i++) {

                if (!visited[adj[nodeID][i]]) List = hasCycle(adj[nodeID][i], visited, node_path);

                else {

                    for (j = 0; j < node_path.size(); j++) {
                        if (node_path[j] == adj[nodeID][i]) {
                            for (k = j; k < node_path.size(); k++) {
                                List.push_back(node_path[k]);
                            }
                            List.push_back(adj[nodeID][i]);//we add the first element that starts and ends the cycle because the for loop doesn't add it
                            if (List.size() <= 2) List.clear(); // clear the vector if the it detected a trivial cycle
                            return List;
                        }
                    }
                }
            }
            node_path.pop_back();
            if (List.size() <= 2) List.clear();
            return List;
        }
    private:
        map<int, vector<int>> adj;
};

int main() {
    /*vector<int> starts = {10, 11, 12};
    vector<int> ends = {11, 12, 10};
    Graph g(starts, ends);
    cout << g.numOutgoing(0) << endl; // prints 1


    vector<int> adj = g.adjacent(10);
    for (int i = 0; i < adj.size(); i++) cout << adj[i] << " "; // prints 1

    cout << endl;

    vector<bool> visited(5, false);
    vector<int> node_path;
    vector<int> List = g.hasCycle(10, visited, node_path);
    for (int i = 0; i < List.size(); i++) cout << List[i] << " ";
    cout << endl;//prints the cycle going from and to 10*/

    //test case for no cycle
    /*vector<int> starts = {0, 0, 0, 4, 4,3};
    vector<int> ends = {1,2,3,3,1,1};
    Graph g(starts, ends);
    cout << g.numOutgoing(0) << endl; // prints 3


    vector<int> adj = g.adjacent(0);
    for (int i = 0; i < adj.size(); i++) cout << adj[i] << " "; // prints 1 2 3 

    cout << endl;

    vector<bool> visited(5, false);
    vector<int> node_path;
    vector<int> List = g.hasCycle(0, visited, node_path);
    for (int i = 0; i < List.size(); i++) cout << List[i] << " ";
    cout << endl; //prints nothing*/

    //another test case for 2 vertices cycle
    /*vector<int> starts = {0,1};
    vector<int> ends = {1,0};
    Graph g(starts, ends);
    cout << g.numOutgoing(1) << endl; // prints 1


    vector<int> adj = g.adjacent(0);
    for (int i = 0; i < adj.size(); i++) cout << adj[i] << " "; // prints 1 

    cout << endl;

    vector<bool> visited(5, false);
    vector<int> node_path;
    vector<int> List = g.hasCycle(0, visited, node_path);
    for (int i = 0; i < List.size(); i++) cout << List[i] << " ";
    cout << endl; //prints 0 1 0*/

    //test case for trivial cycle
    /*vector<int> starts = {0};
    vector<int> ends = {0};
    Graph g(starts, ends);
    cout << g.numOutgoing(0) << endl; // prints 1


    vector<int> adj = g.adjacent(0);
    for (int i = 0; i < adj.size(); i++) cout << adj[i] << " "; // prints 0
    cout << endl;

    vector<bool> visited(5, false);
    vector<int> node_path;
    vector<int> List = g.hasCycle(0, visited, node_path);
    for (int i = 0; i < List.size(); i++) cout << List[i] << " ";
    cout << endl; //prints nothing*/

    //test case for empty starts and ends
    vector<int> starts = {};
    vector<int> ends = {};
    Graph g(starts, ends);
    cout << g.numOutgoing(0) << endl; // prints nothing


    vector<int> adj = g.adjacent(0);
    for (int i = 0; i < adj.size(); i++) cout << adj[i] << " "; // prints nothing
    cout << endl;

    vector<bool> visited(5, false);
    vector<int> node_path;
    vector<int> List = g.hasCycle(0, visited, node_path);
    for (int i = 0; i < List.size(); i++) cout << List[i] << " ";
    cout << endl; //prints nothing



    return 0;
}



    























