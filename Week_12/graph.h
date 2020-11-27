using namespace std;
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <climits>

#define INFINITY 1000000

class Graph {
  private:
	vector<vector<int>> adj;
	vector<vector<int>> weight;

	void dfs(int v, vector<bool>& visited, vector<int>& path, stack<int>& sorting) {
		visited[v] = true;
		for (auto w : adj[v]) {
			if (!visited[w]) {
				path[w] = v;
				dfs(w, visited, path, sorting);
			}
		}
		sorting.push(v);
	}

  public:
	Graph(int vertices = 1) : adj(vertices), weight(vertices) {
		for (int i = 0; i < vertices; i++) {
			weight[i].resize(vertices, INFINITY);
		}
	}

	void addEdge(int u, int v);
	void addDirectedEdge(int u, int v);
	void addWeightedEdge(int u, int v, int w);
	void dfs(int v, vector<int>& path);
	void bfs(int s, vector<int>& path, vector<int>& dist);
	void topsort(int v);
	int components();
	void dijkstra(int s, vector<int>& path, vector<int>& dist);
	void print();
};
