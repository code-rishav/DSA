#include <iostream>
#include<vector>
#include <queue>
using namespace std;
void BFS(vector<int>adj[],int v,int s){
    bool visited[v];
    for(int i=0;i<v;i++)
    visited[i] = false;
    
    queue<int> q;
    visited[0] = true;
    q.push(s);
    while(q.empty()==false){
        int p = q.front();
        q.pop();
        cout<<p<<" ";
        for(int v:adj[p]){
            if(visited[v]==false){
                visited[v] == true;
                q.push(v);
            }
        }
    }
}

//when source is not given and the graphs may be disconnected
void BFS(vector<int>adj[],bool visited[],int s){
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while(q.empty()==false){
        int p = q.front();
        q.pop();
        cout<<p<<" ";
        for(int v:adj[p]){
            if(visited[v]==false){
                visited[v] == true;
                q.push(v);
            }
        }
    }
}

void BFSDis(vector<int> adj[], int v){
    bool visited[v];
    for(int i=0;i<v;i++)
    visited[i] = false;
    
    for(int i=0;i<v;i++){
        if(visited[i]==false)
        BFS(adj,visited,i);
    }
}

