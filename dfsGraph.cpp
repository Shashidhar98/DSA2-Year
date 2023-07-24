#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void dfs(int node,vector<int> adj[],bool vis[],vector<int>& ans)
{
    vis[node]=true;
    ans.push_back(node);
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            dfs(it,adj,vis,ans);
        }
    }
}
int main()
{
    int n,m;
    cout<< "Enter the number of nodes and edges" << endl;
    cin>> n >> m;
    int startNode=0;
    vector<int> adj[n];
    cout<< "Enter the edge pairs" <<endl;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<< "sf" << endl;
    bool vis[n]={false};
    vector<int> ans;
    dfs(startNode,adj,vis,ans);
    cout<< "DFS :" << endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<< ans[i] << " ";
    }

}