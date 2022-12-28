/*
2. Write a program to create a graph and perform DFS and BFS?
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// A graph node, which consists of an id and a list of neighboring nodes
struct Node {
    int id;
    vector<Node*> neighbors;
};

// A graph, which consists of a list of nodes
struct Graph {
    vector<Node*> nodes;
};

// A function to create a new graph
Graph* create_graph() {
    Graph* g = new Graph;
    return g;
}

// A function to create a new node
Node* create_node(int id) {
    Node* n = new Node;
    n->id = id;
    return n;
}

// A function to add an edge between two nodes
void add_edge(Node* a, Node* b) {
    a->neighbors.push_back(b);
    b->neighbors.push_back(a);
}

// A function to perform DFS on a graph
void dfs(Graph* g, Node* n, vector<bool>& visited) {
    // Mark the current node as visited
    visited[n->id] = true;

    // Print the node's id
    cout << n->id << " ";

    // Recursively visit the unvisited neighbors
    for (Node* neighbor : n->neighbors) {
        if (!visited[neighbor->id]) {
            dfs(g, neighbor, visited);
        }
    }
}

// A function to perform BFS on a graph
void bfs(Graph* g, Node* n) {
    queue<Node*> q;
    vector<bool> visited(g->nodes.size(), false);

    // Mark the current node as visited and enqueue it
    visited[n->id] = true;
    q.push(n);

    while (!q.empty()) {
        // Dequeue a node and print its id
        Node* node = q.front();
        q.pop();
        cout << node->id << " ";

        // Enqueue the unvisited neighbors
        for (Node* neighbor : node->neighbors) {
            if (!visited[neighbor->id]) {
                visited[neighbor->id] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    Graph* g = create_graph();

    // Create some nodes
    Node* a = create_node(0);
    Node* b = create_node(1);
    Node* c = create_node(2);
    Node* d = create_node(3);
    Node* e = create_node(4);
    Node* f = create_node(5);

    // Add the nodes to the graph
    g->nodes.push_back(a);
    g->nodes.push_back(b);
    g->nodes.push_back(c);
    g->nodes.push_back(d);
    g->nodes.push_back(e);
    g->nodes.push_back(f);

    // Add some edges
    add_edge(a, b);
    add_edge(a, c);
    add_edge(b, d);
    add_edge(c, d);
    add_edge(d, e);
    add_edge(e, f);

    // Perform DFS on the graph, starting from node 0
    cout << "DFS: ";
    vector<bool> visited(g->nodes.size(), false);
    dfs(g, a, visited);
    cout << endl;

    // Perform BFS on the graph, starting from node 0
    cout << "BFS: ";
    bfs(g, a);
    cout << endl;

    cout << "\nWritten By: Lakshay Sharma 02396402721";
    return 0;
}
