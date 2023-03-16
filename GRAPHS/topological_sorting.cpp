#include <vector>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;
void TopologicalSort(vector<int>adj[],int v){
    //to create an array for indegree
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

    while(!q.empty()){
        int v = q.front();
        q.pop();
        cout<<v<<" ";
        for(int u:adj[v]){
            indeg[u]--;
            if(indeg[u]==0)
            q.push(u);
        }

    }
}

bool detect_cycle(vector<int>adj[],int v){
     //to create an array for indegree
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

    int count=0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        cout<<v<<" ";
        for(int u:adj[v]){
            indeg[u]--;
            if(indeg[u]==0)
            q.push(u);
        }
        count++;

    }
    if(count!=v)
    return false;
    else
    return true;

}

//topological sorting using DFS
void topologivcal_sortDFS(vector<int>adj[],int v){
    bool visited[v];
    for(int i=0;i<v;i++)
    visited[i] = false;

    stack<int> s;
    for(int i=0;i<v;i++)
    DFS(adj,visited,v,s);
    while(s.empty()==false){
        cout<<s.top()<<" ";
        s.pop();
    }
}

void DFS(vector<int>adj[],bool visited[],int v,stack<int> &s){
    visited[v] = true;
    for(int u:adj[v]){
        if(visited[u]==false){
            DFS(adj,visited,u,s);
        }
    }
    s.push(v);
}