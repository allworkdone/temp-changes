#include <iostream>
#include <queue>
using namespace std;

void printBFS(int **edges, int V, int sv)
{
    if (V == 0)
    {
        return;
    }
    queue<int> pendingvertices;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    pendingvertices.push(sv);
    visited[sv] = true;
    while (!pendingvertices.empty())
    {
        int currentvertex = pendingvertices.front();
        pendingvertices.pop();
        cout << currentvertex << " ";
        for (int i = 0; i < V; i++)
        {
            if (i == currentvertex)
            {
                continue;
            }
            if (edges[currentvertex][i] == 1 && !visited[i])
            {
                pendingvertices.push(i);
                visited[i] = true;
            }
        }
    }
    delete[] visited;
}

int main()
{
    // Write your code here
    int V;
    int E;
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
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    printBFS(edges, V, 0);

    for (int i = 0; i < V; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}