class Solution {
  public:
     void topoOrderDfs(int src,stack<int>&topoOrder,
     vector<pair<int,int>>adj[N],vector<int>dist){
         visited[src]=true;
         for(auto nbr:adj[src]){
             int nbrNode=nbr.first;
             int nbrDist=nbr.second;
             if(!visited[nbrNode]){
                 dfs(nbrNode,topoOrder,visited,adj);
             }
         }
         topoOrder.push(src);
        int src=topoOrder.top();
        topoOrder.pop();
        dist[src]=0;
        for(auto nbr:adj[src]){
            int nbrNode=nbr.first;
            int nbrdist=nbr.second;
            if(dist[src]+nbrdist<dist[nbrNode]){
                dist[nbrNode]=dist[src]+nbrdist;
            }
        }
        while(!topoOrder.empty()){
            int src=topoOrder.top();
        topoOrder.pop();
        dist[src]=0;
        for(auto nbr:adj[src]){
                int nbrNode=nbr.first;
                int nbrdist=nbr.second;
                if(dist[src]+nbrdist<dist[nbrNode]){
                    dist[nbrNode]=dist[src]+nbrdist;
                }
            }
        }
        
     }
     void ShortPathDfs(stack<int>topoOrder,int N,
     unordered_map<int,bool>&visited,vector<pair<int,int>>adj[N]){
         int src=topoOrder.top();
        topoOrder.pop();
        dist[src]=0;
        for(auto nbr:adj[src]){
            int nbrNode=nbr.first;
            int nbrdist=nbr.second;
            if(dist[src]+nbrdist<dist[nbrNode]){
                dist[nbrNode]=dist[src]+nbrdist;
            }
        }
        while(!topoOrder.empty()){
            int src=topoOrder.top();
        topoOrder.pop();
        dist[src]=0;
        for(auto nbr:adj[src]){
                int nbrNode=nbr.first;
                int nbrdist=nbr.second;
                if(dist[src]+nbrdist<dist[nbrNode]){
                    dist[nbrNode]=dist[src]+nbrdist;
                }
            }
        }
     }
     
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        
        vector<pair<int,int>>adj[N];
        for(int i=0;i<N;i++){
            int u=edges[0][0];
            int v=edges[0][1];
            int w=edges[0][2];
            adj[u].push_back({v,w});
        }
        int src=0;
        stack<int>topoOrder;
        vector<int>dist(N,INT_MAX);
        unordered_map<int,bool>visited;
        topoOrderDfs(src,topOrder,visited,adj);
        ShortPathDfs(topoOrder,N,dist);
        vector<int>ans(N,-1);
        for(int i=0;i<N;i++){
            if(dist[i]!=INT_MAX){
                ans[i]=dist[i];
            }
        }
        return ans;
    }
};