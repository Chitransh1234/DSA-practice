// #include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;
// FOR UNWEIGHTED GRAPH
//  class Graph
//  {
//  public:
//      unordered_map<int, list<int>> adjList;
//      void addEdge(int u, int v, bool direction)
//      {
//          // direction ->0->undirected
//          // direction ->1->directed
//          if (direction == 1)
//          {
//              // u se v ki taraf ek edge list hai
//              // u ->v
//              adjList[u].push_back(v);
//          }
//          else
//          {
//              // direction == 0;
//              //u -- v
//              //u -> v
//              adjList[u].push_back(v);
//              //v -> u
//              adjList[v].push_back(u);
//          }
//          cout<<endl<<"printing adjList"<<endl;
//          printAdjList();
//          cout<<endl;
//      }
//      void printAdjList(){
//          for(auto i: adjList){
//              cout<<i.first<<" -> {";
//              for(auto neighbour: i.second){
//                  cout<<neighbour<<", ";
//              }
//              cout<<"}"<<endl;
//          }
//      }
//  };
//  FOR WEIGHTED GRAPH
template <typename T>
class Graph
{
public:
    unordered_map<T, list<pair<T, int>>> adjList;
    
    void addEdge(T u, T v, int wt, bool direction)
    {
        // direction ->0->undirected
        // direction ->1->directed
        if (direction == 1)
        {
            // u->v
            adjList[u].push_back(make_pair(v, wt));
        }
        else
        {
            // direction=0
            // u---v
            // u->v
            // v->u
            adjList[u].push_back(make_pair(v, wt));
            adjList[v].push_back({u, wt});
        }
        cout << endl
             << "Printing adjList" << endl;
        printAdjList();
        cout << endl;
    }
    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << " : {";
            for (pair<T, int> neighbour : i.second)
            {
                cout << "{" << neighbour.first << "," << neighbour.second << "},";
            }
            cout << "}" << endl;
        }
    }

    void bfsTraversal(T src, unordered_map<T, bool> &vis)
    {
        // adjList already data member me hai
        // visited

        // queue
        queue<T> q;

        // initial state
        q.push(src);
        vis[src] = true;
        while (!q.empty())
        {
            T frontNode = q.front();
            cout << frontNode << " ";
            q.pop();
            
            // go to  nbr
            for (auto nbr : adjList[frontNode])
            {
                T nbrData = nbr.first;
                if (!vis[nbrData])
                {
                    q.push(nbrData);
                    vis[nbrData] = true;
                }
            }
        }
    }
    void dfs(T src, unordered_map<T, bool> &vis)
    {
        vis[src] = true;
        cout << src << " ";
        for (auto nbr : adjList[src])
        {
            T nbrData = nbr.first;
            if (!vis[nbrData])
            {
                dfs(nbrData, vis);
            }
        }
    }
    int noOfDisconnectedComponents()
    {
        unordered_map<T, bool> vis;
        int count = 0;
        for (auto i : adjList)
        {
            T node = i.first;
            if (!vis[node])
            {
                dfs(node, vis);
                count++;
            }
        }
        return count;
    }
};

int main()
{
    // Graph g;
    // g.addEdge(0,1,1);
    // g.addEdge(1,2,1);
    // g.addEdge(1,3,1);
    // g.addEdge(2,3,1);
    Graph<char> g;
    // g.addEdge('a', 'b', 3, 0);
    // g.addEdge('a', 'c', 6, 0);
    // g.addEdge('b', 'c', 9, 0);
    // g.addEdge('c', 'd', 12, 0);
    // g.addEdge('c', 'e', 15, 0);
    // g.addEdge('e', 'f', 18, 0);
    g.addEdge('a', 'b', 5, 0);
    g.addEdge('a', 'c', 10, 0);
    g.addEdge('c', 'd', 20, 0);
    g.addEdge('e', 'e', 50, 0);
    g.addEdge('f', 'f', 50, 0);
    g.addEdge('g', 'g', 50, 0);
    cout<<endl;
    unordered_map<char, bool> vis;
    cout<<g.noOfDisconnectedComponents()<<endl;
    // g.dfs('a',vis);
    // for disconnected graph
    // for (char node = 'a'; node <= 'f'; node++)
    // {
    //     if (!vis[node])
    //     {
    //         g.dfs(node, vis);
    //     }
    // }
    // unordered_map<char,bool>vis;
    // //YAHIIN GALTI HOTI HAI
    // code for disconnected graph
    // for(char node='a';node<='f';node++){
    //     if(!vis[node]){
    //         g.bfsTraversal(node,vis);
    //     }
    // }
    return 0;
}