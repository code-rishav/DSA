#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(vector<int> adj[],int s,bool visited[]){
    visited[s] = true;
    cout<<s<<" ";
    for(int u:adj[s]){
        if(visited[u]==false){
            DFS(adj,u,visited);
        }
    }
}

void DFST(vector<int> adj[],int v,int s){
    bool visited[v];
    for(int i=0;i<v;i++)
    visited[v] = false;
    DFS(adj,s,visited);
}

void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
}
int main() 
{ 
    int V = 4; 
    vector<int> adj[V]; 
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 2); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 

}

void sortest_unweighted(vector<int> adj[],int v,int s){
    int dist[v];
    for(int i=0;i<v;i++){
        dist[i] = INT16_MAX;
    }
    dist[s] = 0;
    queue<int> q;

    bool visited[v];
    for(int i=0;i<v;i++){
        visited[i] = false;
    }
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i:adj[u]){
            if(visited[i]==false){
                dist[i] = dist[u]+1;
                visited[i] = true;
                q.push(i);
            }

        }
    }


}