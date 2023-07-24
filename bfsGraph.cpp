#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(int n,vector<int> adj[],vector<int>& ans,int startNode)
{
    int vis[n]={0};
    queue<int> q;
    q.push(startNode);
    vis[startNode]=1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(int i=0;i<adj[node].size();i++)
        {
            if(!vis[adj[node][i]])
            {
                vis[adj[node][i]]=1;
                q.push(adj[node][i]);
            }
        }
    }
}

int main()
{
    int n,m;
    cout<< "Enter the number of nodes and edges" << endl;
    cin>> n >> m;
    vector<int> adj[n];               //    vector<int> *adj= new vector<int>[n]  we can also dynamically allocate memory
    cout<< "Enter the edge pair values" << endl;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans;
    int startNode;
    cout<< "Enter the starting node " << endl;
    cin>> startNode;
    bfs(n,adj,ans,startNode);
    cout<< "BFS: " << endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<< ans[i] << " ";
    }
}