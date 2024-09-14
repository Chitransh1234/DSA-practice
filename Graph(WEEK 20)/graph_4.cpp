#include <iostream>
#include <stack>
#include <unordered_map>
#include <map>
#include <list>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>
#include <set>
using namespace std;
// directed and weighted graph
class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight, bool direction)
    {
        // direction 0 undirected
        // direction 1 directed
        if (direction == 1)
        {
            adj[u].push_back({v, weight});
        }
        else
        {
            adj[u].push_back({v, weight});
            adj[v].push_back({u, weight});
        }
    }
    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << ": {";
            for (auto j : i.second)
            {
                cout << "(" << j.first << "," << j.second << "), ";
            }
            cout << "}" << endl;
        }
    }
    void topoOrderDfs(int src, stack<int> &topoOrder, unordered_map<int, bool> &visited)
    {
        visited[src] = true;
        for (auto nbrPair : adj[src])
        {
            int nbrNode = nbrPair.first;
            int nbrDist = nbrPair.second;
            if (!visited[nbrNode])
            {
                topoOrderDfs(nbrNode, topoOrder, visited);
            }
        }
        topoOrder.push(src);
    }
    void shortestPathDfs(stack<int> &topoOrder, int n)
    {
        vector<int> dist(n, INT_MAX);
        // initially , maintain src
        int src = topoOrder.top();
        topoOrder.pop();
        dist[src] = 0;
        // update nbr distance for this src node
        for (auto nbrPair : adj[src])
        {
            int nbrNode = nbrPair.first;
            int nbrDist = nbrPair.second;
            if (dist[src] + nbrDist < dist[nbrNode])
            {
                dist[nbrNode] = dist[src] + nbrDist;
            }
        }
        // apply the same above concept for all the remaining node
        // in the topo ordering
        while (!topoOrder.empty())
        {
            int src = topoOrder.top();
            topoOrder.pop();
            for (auto nbrPair : adj[src])
            {
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;
                if (dist[src] + nbrDist < dist[nbrNode])
                {
                    dist[nbrNode] = dist[src] + nbrDist;
                }
            }
        }
        // ab mera distance array ekdum tyaar hai
        cout << "printing the distance array:" << endl;
        for (auto i : dist)
        {
            cout << i << " ";
        }
    }
    void DijkstraShortestDistance(int src, int dest, int n)
    {
        vector<int> dist(n + 1, INT_MAX);
        set<pair<int, int>> st;
        // initial state maintain karni hai->{0,src}
        st.insert({0, src});
        dist[src] = 0;
        // distance updation logic
        while (!st.empty())
        {
            auto topElement = st.begin(); // reference mil gya starting ka
            pair<int, int> topPair = *topElement;
            int topDist = topPair.first;
            int topNode = topPair.second;
            // remove the top node
            st.erase(st.begin());

            // update distance of nbr
            for (pair<int, int> nbrPair : adj[topNode])
            {
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;
                if (topDist + nbrDist < dist[nbrNode])
                {
                    // found a new shorter distance
                    // now update:
                    //-> set ki entry
                    auto previousEntry = st.find({dist[nbrNode], nbrNode});
                    if (previousEntry != st.end())
                    {
                        st.erase(previousEntry);
                    }
                    //->dist ka array
                    dist[nbrNode] = topDist + nbrDist;
                    st.insert({dist[nbrNode], nbrNode});
                }
            }
        }
        cout << "shortest Distance from " << src << " Node to " << dest << " Node:"
             << dist[dest] << endl;
    }
};
int main()
{
    Graph g;
    // below graph for dijkstra
    g.addEdge(1, 6, 14, 0);
    g.addEdge(1, 3, 9, 0);
    g.addEdge(1, 2, 7, 0);
    g.addEdge(2, 3, 10, 0);
    g.addEdge(2, 4, 15, 0);
    g.addEdge(3, 4, 11, 0);
    g.addEdge(6, 3, 2, 0);
    g.addEdge(6, 5, 9, 0);
    g.addEdge(5, 4, 6, 0);

    // below graph for sssp algo
    // g.addEdge(0, 1, 5, 1);
    // g.addEdge(0, 2, 3, 1);
    // g.addEdge(1, 3, 3, 1);
    // g.addEdge(2, 1, 2, 1);
    // g.addEdge(2, 3, 5, 1);
    // g.addEdge(2, 4, 6, 1);
    // g.addEdge(4, 3, 1, 1);
    g.printAdjList();
    // int src = 0;
    int n=6;
    int src=6;
    int dest=4;
    g.DijkstraShortestDistance(src,dest,n);
    // stack<int> topoOrder;
    // unordered_map<int, bool> visited;
    // g.topoOrderDfs(src, topoOrder, visited);
    // // cout << "printing topo order:" << endl;
    // // while (!topoOrder.empty())
    // // {
    // //     int node = topoOrder.top();
    // //     topoOrder.pop();
    // //     cout << node << " ";
    // // }
    // int n=topoOrder.size();
    // cout<<"the size of size stack is "<<n<<endl;
    // g.shortestPathDfs(topoOrder,n);
    return 0;
}