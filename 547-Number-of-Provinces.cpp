class Solution {
public:

void dfs(int node, vector<bool>&vis, vector<int>adj[]){
    vis[node] = true;

    for(int nei : adj[node]){
        if(!vis[nei]){
            dfs(nei, vis, adj);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();

    vector<int> adj[n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(isConnected[i][j] == 1 && i != j){
                adj[i].push_back(j);
            }
        }
    }

    vector<bool> vis(n, false);

    int count = 0;

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            count++;
            dfs(i, vis, adj);
        }
    }

    return count;
    }
};