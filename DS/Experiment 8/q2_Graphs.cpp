/*
2. Write a program to create a graph and perform DFS and BFS?
*/
#include <iostream>
#include <vector>
#include <queue>

// Adjacency list representation of a graph
class Graph {
 public:
  Graph(int numVertices) : numVertices_(numVertices) {
    adjacencyLists_.resize(numVertices_);
  }

  // Add an edge from vertex u to vertex v
  void AddEdge(int u, int v) {
    adjacencyLists_[u].push_back(v);
  }

  // Perform a depth-first search starting from the given vertex
  void DFS(int startVertex) {
    // Mark all vertices as not visited
    std::vector<bool> visited(numVertices_, false);

    // Recursive DFS helper function
    DFSUtil(startVertex, visited);
  }

  // Perform a breadth-first search starting from the given vertex
  void BFS(int startVertex) {
    // Mark all vertices as not visited
    std::vector<bool> visited(numVertices_, false);

    // Create a queue for BFS
    std::queue<int> queue;

    // Mark the current vertex as visited and enqueue it
    visited[startVertex] = true;
    queue.push(startVertex);

    while (!queue.empty()) {
      // Dequeue a vertex from queue and print it
      int vertex = queue.front();
      queue.pop();
      std::cout << vertex << " ";

      // Get all the neighbors of the dequeued vertex
      // and mark them as visited
      for (int neighbor : adjacencyLists_[vertex]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          queue.push(neighbor);
        }
      }
    }
  }

 private:
  // Recursive helper function for DFS
  void DFSUtil(int vertex, std::vector<bool>& visited) {
    // Mark the current vertex as visited
    visited[vertex] = true;
    std::cout << vertex << " ";

    // Recurse on all the neighbors of the current vertex
    for (int neighbor : adjacencyLists_[vertex]) {
      if (!visited[neighbor]) {
        DFSUtil(neighbor, visited);
      }
    }
  }

  int numVertices_;
  std::vector<std::vector<int>> adjacencyLists_;
};
int main() {
  // Create a graph with 6 vertices and 6 edges
  Graph graph(6);
  graph.AddEdge(0, 1);
  graph.AddEdge(0, 2);
  graph.AddEdge(1, 2);
  graph.AddEdge(2, 0);
  graph.AddEdge(2, 3);
  graph.AddEdge(3, 3);

  // Perform a depth-first search starting from vertex 0
  std::cout << "DFS starting from vertex 0: ";
  graph.DFS(0);
  std::cout << std::endl;

  // Perform a breadth-first search starting from vertex 0
  std::cout << "BFS starting from vertex 0: ";
  graph.BFS(0);
  std::cout << std::endl;

  return 0;
}
