using namespace std;
#include "graph_class.h"
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
	for(int c = 0; c < adj.size(); c++) {
		int u, min = INFINITY; // find minimum node
		for (int v = 0; v < adj.size(); v++) {
			if (!visited[v] && dist[v] <= min) {
				min = dist[v];
				u = v;
			}
		}
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

void Graph::allPairs(Matrix<int>& path, Matrix<int>& dist) {
	int n = adj.size();
	// Initialize d and path
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			dist[i][j] = weight[i][j];
			path[i][j] = -1;
		}
	}

	for(int k = 0; k < n; ++k) {
		// Consider each vertex as an intermediate
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(dist[i][k] + dist[k][j] < dist[i][j]) {
					// Update shortest path
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = k;
				}
			}
		}
	}
}

int Graph::kruskalMST() {
    int mst_wt = 0; // Initialize result
	vector<pair<int, pair<int, int>>> edges;

	for (int i = 0; i < adj.size(); i++) {
		for (auto j : adj[i]) {
			edges.push_back({weight[i][j], {i, j}});
		}
	}

    // Sort edges in increasing order on basis of cost
    sort(edges.begin(), edges.end());

    // Create disjoint sets
    DisjSets ds(adj.size());

    // Iterate through all sorted edges
    vector<pair<int, pair<int, int>>>::iterator it;
    for (it = edges.begin(); it != edges.end(); it++) {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        // Check if the selected edge is creating
        // a cycle or not (Cycle is created if u
        // and v belong to same set)
        if (set_u != set_v) {
            // Current edge will be in the MST
            cout << u << " - " << v << ", ";

            // Update MST weight
            mst_wt += it->first;

            // Merge two sets
            ds.unionSets(set_u, set_v);
        }
    }

    return mst_wt;
}

int Graph::primMST() {
	int mst_wt = 0;                   // Initialize result
    vector<int> parent(adj.size());   // Array to store MST
	vector<int> key(adj.size());      // Values to pick minimum weight edge in cut
    vector<bool> visited(adj.size()); // To represent set of vertices included

    // Initialize all keys as INFINITE
    for (int i = 0; i < adj.size(); i++) {
        key[i] = INFINITY, visited[i] = false;
	}

    // Always include first 1st vertex in MST, make sure it is picked first.
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < adj.size(); count++) {
        // Pick the minimum key vertex not yet included in MST
	    int min = INFINITY, u;
	    for (int v = 0; v < adj.size(); v++) {
			if (visited[v] == false && key[v] < min) {
				min = key[v], u = v;
			}
		}
	    // Add the picked vertex to the MST Set
        visited[u] = true;
		if (u != 0) {
			mst_wt += min;
			cout << u << " - " << parent[u] << ", ";
		}

        // Update key/parent of the adjacent verticesof the picked vertex.
        for (int v = 0; v < adj.size(); v++) {
            if (weight[u][v] && visited[v] == false && weight[u][v] < key[v]) {
				parent[v] = u, key[v] = weight[u][v];
			}
		}
    }
	return mst_wt;
}

void Graph::print() {
	for (int v = 0; v < adj.size(); ++v) {
		cout << "Adjacency list of vertex "<< v;
		for (auto x : adj[v])
		   cout << " -> " << x;
		cout << endl;
	}
}
