/*********************************************************
Written by:  Jenil J Gandhi
Subject:     Advanced Algorithms
Lab-no:      Lab-12
Description: Implement Approximate Vertex cover 
Guidance by: Prof Ashish K Gor
Date:        17/10/2021
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

void fin()
{
    freopen("approx_input.txt", "r", stdin);
    freopen("approx_output.txt", "w", stdout);
}

class Graph
{
public:
    map<int, vector<int>> graph;
    void addEdge(int src, int dest, bool is_bidir = true)
    {
        if (is_bidir)
        {
            graph[src].push_back(dest);
            graph[dest].push_back(src);
        }
        else
        {
            graph[src].push_back(dest);
        }
    }

    bool removeEdge(int src, int dest)
    {

        vector<int>::iterator it = find(this->graph[src].begin(), this->graph[src].end(), dest);
        vector<int>::iterator it1 = find(this->graph[dest].begin(), this->graph[dest].end(), src);
        if (it1 != this->graph[dest].end() && it != this->graph[src].end())
        {

            graph[src].erase(it);
            graph[dest].erase(it1);
            return true;
        }
        else
        {
            return false;
        }
    }
    void printGraph()
    {
        for (auto x : graph)
        {
            cout << x.first << "->";
            for (auto y : x.second)
            {
                cout << y << " ";
            }
            cout << endl;
        }
    }
    int getNextVertice()
    {
        for (auto x : graph)
        {
            if (x.second.size() > 0)
            {
                return x.first;
            }
        }
        return -1;
    }
};

void solveApproxVc(Graph g)
{
    vector<int> finalAnswer;
    while (true)
    {
        int u = g.getNextVertice();
        if (u == -1)
        {
            break;
        }
        int v = g.graph[u][0];
        finalAnswer.push_back(u);
        finalAnswer.push_back(v);
        vector<int> uList = g.graph[u];
        vector<int> vList = g.graph[v];

        for (auto u1 : uList)
        {
            g.removeEdge(u, u1);
        }

        for (auto v1 : vList)
        {
            g.removeEdge(v, v1);
        }
    }
    cout << "Final Selected Vertices\n";
    for (auto x : finalAnswer)
    {
        cout << x << " ";
    }
    cout << "\nFinal State of the graph\n";
    g.printGraph();
}

int main()
{
    fin();
    int tt;
    cin >> tt;
    int cc = 0;
    cout << "----------------------------------------------------------\n";
    while (tt--)
    {
        int n_edges;
        cin >> n_edges;
        Graph g;
        for (int i = 0; i < n_edges; i++)
        {
            int src, dest;
            cin >> src >> dest;
            g.addEdge(src, dest);
        }
        cout << "Case:#" << ++cc << endl;
        solveApproxVc(g);
        cout << "----------------------------------------------------------\n";
    }
}