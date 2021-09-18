#include <bits/stdc++.h>
using namespace std;
void fin()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
class Graph
{
    bool *visited;
    vector<int> tempL;

public:
    int source, sink;
    map<int, vector<pair<int, int>>> graph;
    Graph()
    {
    }
    Graph(map<int, vector<pair<int, int>>> graph)
    {
        this->graph = graph;
    }
    bool updateCapacity(int src, int dest, int capReduceBy)
    {
        vector<pair<int, int>> adjList = this->graph[src];
        for (int i = 0; i < adjList.size(); i++)
        {
            pair<int, int> p = adjList[i];
            if (p.first == dest)
            {
                this->graph[src][i].second -= capReduceBy;
                return true;
            }
        }
        return false;
    }
    void setSourceSink(int source, int sink)
    {
        this->sink = sink;
        this->source = source;
    }
    void addEdge(int from, int to, int capacity)
    {
        graph[from].push_back(make_pair(to, capacity));
    }
    void printGraph(string message = "")
    {
        cout << message << endl;
        for (auto x : this->graph)
        {
            cout << x.first << " -> ";
            for (auto y : x.second)
            {
                cout << "(" << y.first << " , " << y.second << ") ";
            }
            cout << endl;
        }
    }
    void printVec(vector<pair<int, int>> v)
    {
        for (auto x : v)
        {
            cout << x.first << " " << x.second << endl;
        }
    }
    bool dfsUtil(int src)
    {
        this->visited[src] = true;
        // if we reach to the sink node we stop
        if (src == this->sink)
        {
            return true;
        }
        else
        {
            // else we need to mark the src as visited in visited
            // and then traverse all connections of it

            for (auto connection : this->graph[src])
            {
                // now we check that if that vertex is already traversed
                int curVertex = connection.first;
                int capacity = connection.second;
                if (this->visited[curVertex] == false && capacity > 0)
                {
                    // if we get true in status means we found the root node;
                    bool status = dfsUtil(curVertex);
                    if (status == true)
                    {
                        this->tempL.push_back(curVertex);
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            return false;
        }
    }
    vector<int> dfs(int src)
    {
        this->tempL.clear();
        bool visited[this->graph.size()] = {false};
        this->visited = visited;
        bool status = dfsUtil(src);
        this->tempL.push_back(this->source);
        reverse(this->tempL.begin(), this->tempL.end());
        if (status == false)
        {
            vector<int> v;
            return v;
        }
        return this->tempL;
    }
};
void solveFordFulkerson(Graph g)
{
    int totalCapacity = 0;
    while (true)
    {
        vector<int> pth = g.dfs(g.source);

        if (pth.size() == 0)
        {
            break;
        }
        else
        {

            // here we iterate through augmenting path find max capacity of the path
            // now after we get all capacities we subtract that from the whole path

            // loop for finding max capacity.
            int capacity = INT_MAX;
            for (int i = 0; i < pth.size() - 1; i++)
            {
                // conns have the adjacency list of pth[i]
                // ex PHT = {0,1,3} for iter-1 conns = adjacencyList of 0
                vector<pair<int, int>> conns = g.graph[pth[i]];

                for (int j = 0; j < conns.size(); j++)
                {
                    pair<int, int> vertex = conns[j];
                    if (vertex.first == pth[i + 1])
                    {
                        capacity = min(capacity, vertex.second);
                    }
                }
            }

            // Loop to subtract capacities from the graph
            for (int i = 0; i < pth.size() - 1; i++)
            {
                // conns have the adjacency list of pth[i]
                // ex PHT = {0,1,3} for iter-1 conns = adjacencyList of 0
                g.updateCapacity(pth[i], pth[i + 1], capacity);
            }
            totalCapacity += capacity;
        }
    }
    cout << "totalcapacity: " << totalCapacity << endl;
}
int main()
{
    fin();
    int tt;
    cin >> tt;
    int cntr = 0;
    cout << "-------------------------------------------------------------\n";
    while (tt--)
    {
        int n_nodes;
        cin >> n_nodes;
        Graph g;
        while (n_nodes--)
        {
            int source, destination, capacity;
            cin >> source >> destination >> capacity;
            g.addEdge(source, destination, capacity);
        }
        int source, sink;
        cin >> source >> sink;
        g.setSourceSink(source, sink);
        cout << "Case #" << ++cntr << endl;
        solveFordFulkerson(g);
        cout << "-------------------------------------------------------------\n";
    }
    return 0;
}