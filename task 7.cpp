#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int V = 8; // I'm setting the number of vertices in the graph to 8
vector<vector<int>> adj(V); 
vector<vector<int>> adjTransposed(V);

// I'll use this function for a depth-first search and to fill the stack with vertices
void perform_DFS(int v, vector<bool>& visited, stack<int>& Stack) {
    visited[v] = true; 
    for (int i : adj[v]) 
        if (!visited[i]) 
            perform_DFS(i, visited, Stack); 
    Stack.push(v); 
}

// This function is used to print all reachable vertices from 'v'
void print_reachable_vertices(int v, vector<bool& visited) {
    visited[v] = true; 
    cout << v << " "; 
    for (int i : adjTransposed[v])
        if (!visited[i]) 
            print_reachable_vertices(i, visited); 
}

// This function adds an edge to the graph and its transpose.
void addEdge(int v, int w) {
    adj[v].push_back(w); 
    adjTransposed[w].push_back(v); 
}

// This function prints all strongly connected components.
void printSCCs() {
    stack<int> Stack; .
    vector<bool> visited(V, false); 

    for (int i = 0; i < V; i++) 
        if (!visited[i]) 
            perform_DFS(i, visited, Stack); 

    fill(visited.begin(), visited.end(), false); 

    while (!Stack.empty()) { 
        int v = Stack.top(); 
        Stack.pop(); 

        if (!visited[v]) { 
            print_reachable_vertices(v, visited); 
            cout << endl; 
        }
    }
}

int main() {
    // Here I define the edges of the graph
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(1, 3);
    addEdge(3, 4);
    addEdge(4, 5);
    addEdge(5, 3);
    addEdge(6, 5);
    addEdge(6, 7);
    addEdge(7, 6);

    
    cout << "Largest Groups of Connected Users Based on Mutual Interests:\n";
    printSCCs(); 

    return 0;
}
