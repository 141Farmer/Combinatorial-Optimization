#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

string findParent(unordered_map<string, string> &parent, string vertex)
{
    if (parent[vertex] == "")
        return vertex;
    return findParent(parent, parent[vertex]);
}
void prim(vector<pair<pair<string, string>, int>>& edges, const unordered_map<string, vector<pair<string, int>>>& adjacencyList) {
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    unordered_map<string, bool> visited;
    string startVertex = edges[0].first.first; // Starting from the first vertex

    // Mark the starting vertex as visited
    visited[startVertex] = true;

    // Enqueue all edges incident to the starting vertex
    for (const auto& neighbor : adjacencyList.at(startVertex)) {
        pq.push({neighbor.second, neighbor.first});
    }

    // Process the remaining vertices
    cout << "Minimum Spanning Tree:\n";
    while (!pq.empty()) {
        auto currentEdge = pq.top();
        pq.pop();

        string currentVertex = currentEdge.second;
        int weight = currentEdge.first;

        if (visited[currentVertex]) {
            continue;
        }

        // Mark the current vertex as visited
        visited[currentVertex] = true;

        // Print the edge in the Minimum Spanning Tree
        cout << startVertex << " -- " << currentVertex << " : " << weight << "\n";

        // Enqueue all edges incident to the current vertex
        for (const auto& neighbor : adjacencyList.at(currentVertex)) {
            if (!visited[neighbor.first]) {
                pq.push({neighbor.second, neighbor.first});
            }
        }

        // Update the starting vertex for the next iteration
        startVertex = currentVertex;
    }
}


void unionSets(unordered_map<string, string> &parent, string x, string y)
{
    string rootX = findParent(parent, x);
    string rootY = findParent(parent, y);
    parent[rootX] = rootY;
}

void kruskal(vector<pair<pair<string, string>, int>> &edges)
{
    sort(edges.begin(), edges.end(), [](const auto &a, const auto &b)
         { return a.second < b.second; });

    unordered_map<string, string> parent;
    vector<pair<pair<string, string>, int>> result;

    for (const auto &edge : edges)
    {
        string sourceRoot = findParent(parent, edge.first.first);
        string destRoot = findParent(parent, edge.first.second);

        if (sourceRoot != destRoot)
        {
            result.push_back(edge);
            unionSets(parent, sourceRoot, destRoot);
        }
    }

    cout << "Minimum Spanning Tree:\n";
    for (const auto &edge : result)
    {
        cout << edge.first.first << " -- " << edge.first.second << " : " << edge.second << "\n";
    }
}

int main()
{
    if (freopen("CO_lab_final_input.txt", "r", stdin) == NULL)
    {
        cout << "Cannot open file\n";
        return 0;
    }
    int numberOfVertices, numberOfEdges;
    cin >> numberOfVertices >> numberOfEdges;

    vector<pair<pair<string, string>, int>> edges;
    unordered_map<string, vector<pair<string, int>>> adjacencyList;
    for (int i = 0; i < numberOfEdges; ++i)
    {
        string source, destination;
        int weight;
        cin >> source >> destination >> weight;
        edges.emplace_back(make_pair(source, destination), weight);
        adjacencyList[source].emplace_back(destination, weight);
        adjacencyList[destination].emplace_back(source, weight);
    }

    kruskal(edges);
    prim(edges,adjacencyList);

    return 0;
}
