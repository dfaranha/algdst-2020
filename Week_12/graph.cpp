using namespace std;
#include "graph.h"
#include <queue>
#include <climits>

void Graph::addEdge(int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph::addDirectedEdge(int u, int v) {
	adj[u].push_back(v);
}

void Graph::dfs(int vertex, vector<int>& path) {
	stack<int> sorting;
	vector<bool> visited(adj.size());

	for (int v = 0; v < adj.size(); ++v) {
		visited[v] = false;
	}
	dfs(vertex, visited, path, sorting);
}

void Graph::bfs(int s, vector<int>& path, vector<int>& dist) {
	queue<int> q;
	vector<bool> visited(adj.size());

	for (int v = 0; v < adj.size(); ++v) {
		dist[v] = INT_MAX;
		visited[v] = false;
	}
	dist[s] = 0;
	visited[s] = true;
	q.push(s);

	while (!q.empty()) {
		s = q.front();
		q.pop();
		for (auto w : adj[s]) {
			if (!visited[w]) {
				dist[w] = dist[s] + 1;
				visited[w] = true;
				path[w] = s;
				q.push(w);
			}
		}
	}
}

int Graph::connectedComponents() {
	int components = 0;
	stack<int> sorting;
	vector<int> path(adj.size());
	vector<bool> visited(adj.size());
	for (int v = 0; v < adj.size(); ++v) {
		visited[v] = false;
	}

	for (int v = 0; v < adj.size(); ++v) {
		if (!visited[v]) {
			++components;
			dfs(v, visited, path, sorting);
		}
	}

	return components;
}

void Graph::topologicalSort(int v) {
	stack<int> sorting;
	vector<int> path(adj.size());
	vector<bool> visited(adj.size());

	for (int v = 0; v < adj.size(); ++v) {
		visited[v] = false;
	}
	dfs(v, visited, path, sorting);
	while (sorting.empty() == false) {
		cout << sorting.top() << " ";
		sorting.pop();
	}
}

void Graph::addWeightedEdge(int u, int v, int w) {
	adj[u].push_back(v);
	weight[u][v] = w;
}

void Graph::shortestPath(int s, vector<int>& path, vector<int>& dist) {
	priority_queue<int> q;
	vector<bool> visited(adj.size());

	for (int v = 0; v < adj.size(); ++v) {
		dist[v] = INFINITY;
		visited[v] = false;
	}
	dist[s] = 0;
	for(int u, c = 0; c < adj.size(); c++) {
		int index, min = INFINITY;
		for (u = 0; u < adj.size(); u++) {
			if (!visited[u] && dist[u] <= min) {
				min = dist[u];
				index = u;
			}
		}
		u = index; // find minimum node
		visited[u] = true;
		for (auto v : adj[u]) {
			if(!visited[v] && weight[u][v] && dist[u] != INT_MAX
					&& dist[u] + weight[u][v] < dist[v]) {
				dist[v] = dist[u] + weight[u][v];
				path[v] = u;
			}
		}
	}
}

void Graph::print() {
	for (int v = 0; v < adj.size(); ++v) {
		cout << "Adjacency list of vertex "<< v;
		for (auto x : adj[v])
		   cout << " -> " << x;
		cout << endl;
	}
}
