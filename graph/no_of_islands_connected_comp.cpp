class Solution {
  public:
    void dfs(int node, vector<int> adj[],vector<int> &vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> graph[V];
        for(int i=0; i<V;i++){
            for(int j=0; j<V; j++){
                if(adj[i][j]==1){
                    graph[i].push_back(j);
                }
            }
        }
        vector<int> vis(V,0);
        int cnt=0;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i,graph,vis);
                cnt++;
            }
        }
        return cnt;
    }
};
