#include <iostream>
#include <queue>
using namespace std;

void printBFS(int **edges, int V, int sv, bool *visited)
{
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;

    while (!pendingVertices.empty())
    {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout << currentVertex << " ";

        for (int i = 0; i < V; i++)
        {
            if (i == currentVertex)
            {
                continue;
            }

            if (edges[currentVertex][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(int **edges, int V)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            printBFS(edges, V, i, visited);
        }
    }

    delete[] visited;
}

int main()
{
    int V, E;
    cin >> V >> E;

    int **edges = new int *[V];
    for (int i = 0; i < V; i++)
    {
        edges[i] = new int[V];
        for (int j = 0; j < V; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < E; i++)
    {
        int f, s;
        cin >> f >> s;

        // Perform bounds checking for vertex indices
        if (f >= 0 && f < V && s >= 0 && s < V)
        {
            edges[f][s] = 1;
            edges[s][f] = 1;
        }
        else
        {
            cerr << "Invalid vertex indices: (" << f << ", " << s << ")" << endl;
        }
    }

    BFS(edges, V);

    // Deallocate dynamically allocated memory
    for (int i = 0; i < V; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}