#include <bits/stdc++.h>
using namespace std;

void fin()
{
    freopen("greedy_input.txt", "r", stdin);
    freopen("greedy_output.txt", "w", stdout);
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
    int getNextMaxEdge()
    {
        int maxNum = 0;
        int idx = -1;
        for (auto x : graph)
        {
            if (x.second.size() > maxNum)
            {
                idx = x.first;
                maxNum = x.second.size();
            }
        }
        if (maxNum == 0)
        {
            return -1;
        }
        return idx;
    }
};

void solveGreedyVc(Graph g)
{
    vector<int> finalAnswer;
    while (true)
    {
        int x = g.getNextMaxEdge();
        if (x == -1)
        {
            break;
        }
        finalAnswer.push_back(x);
        vector<int> v = g.graph[x];
        for (auto con : v)
        {
            g.removeEdge(x, con);
        }
    }
    cout << "Final Selected Vertices\n";
    for (auto y : finalAnswer)
    {
        cout << y << " ";
    }
    cout << endl;
    cout << "Final State of the graph\n";
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
        solveGreedyVc(g);
        cout << "----------------------------------------------------------\n";
    }
}