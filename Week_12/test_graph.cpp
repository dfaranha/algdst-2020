#include "graph.h"

// Driver code
int main() {

	Graph graph(5);
	vector<int> path(7), dist(7);

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.print();
	graph.dfs(0, path);
	graph.bfs(0, path, dist);

	for (int i = 0; i < 5; i++) {
		cout << "Distance from 0 to " << i << " is " << dist[i] << endl;
	}
	cout << graph.connectedComponents() << " connected component(s)" << endl;

	Graph digraph(7);
    digraph.addWeightedEdge(0, 1, 1);
	digraph.addWeightedEdge(0, 2, 5);
    digraph.addWeightedEdge(0, 3, 2);
    digraph.addWeightedEdge(1, 3, 4);
    digraph.addWeightedEdge(1, 4, 3);
    digraph.addWeightedEdge(2, 5, 0);
	digraph.addWeightedEdge(3, 2, 4);
	digraph.addWeightedEdge(3, 5, 2);
	digraph.addWeightedEdge(3, 6, 2);
	digraph.addWeightedEdge(4, 3, 1);
	digraph.addWeightedEdge(4, 6, 10);
    digraph.addWeightedEdge(6, 5, 8);
    digraph.print();
	cout << "Topological sort: ";
	digraph.topologicalSort(0);
	cout << endl;

	digraph.shortestPath(0, path, dist);
	for (int i = 0; i < 5; i++) {
		cout << "Distance from 0 to " << i << " is " << dist[i] << endl;
	}
	cout << digraph.connectedComponents() << " connected component(s)" << endl;

    return 0;
}
