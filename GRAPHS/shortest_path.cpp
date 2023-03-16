#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void shortest_path(vector<int> adj[], vector<int> weight[], int v,int s){
    int dist[v];
    for(int i=0;i<v;i++)
    dist[i] = INT16_MAX;

    vector<int> sort = topological_sort(adj,v);
    for(int v:sort){
        for(int u:adj[v]){
            if(dist[v]>dist[u]+weight[u][v])
            dist[v] = dist[u]+weight[u][v];
        }
    }
    for(int i=0;i<v;i++){
        cout<<dist[i]<<" ";
    }
}

vector<int> topological_sort(vector<int> adj[], int v){
     int indeg[v];
    for(int i=0;i<v;i++)
    indeg[i] = 0;

    for(int i=0;i<v;i++){
        for(int u:adj[i]){
            indeg[u]++;
        }
    }

    queue<int> q;
    for(int i=0;i<v;i++){
        if(indeg[i]==0)
        q.push(i);
    }
    vector<int> tp;
    while(!q.empty()){
        int v = q.front();
        tp.push_back(v);
        q.pop();
        for(int u:adj[v]){
            indeg[u]--;
            if(indeg[u]==0)
            q.push(u);
        }
    }
    return tp;
}