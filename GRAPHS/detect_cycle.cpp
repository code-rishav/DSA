#include <vector>
using namespace std;
//to detect cycle in an undirected graph
bool findcycle(vector<int>adj[],int s,bool visited[],int parent){
    visited[s] = true;
    for(int u:adj[s]){
        if(visited[u]==false)
            if(findcycle(adj,u,visited,s)==true)
            return true;
        else if(u!=parent)
        return true;
    }
    return false;
}

bool DFSCycleUD(vector<int> adj[],int v){
    bool visited[v];
    for(int i=0;i<v;i++)
    visited[i] = false;
    
    for(int i=0;i<v;i++){
        if(visited[i]==false)
        if(findcycle(adj,i,visited,-1)==true)
        return true;
        else
        return false;
    }
}

//to detect cycle in a directed graph
bool DFSCycleD(vector<int> adj[],int v){
    bool visited[v];
    for(int i=0;i<v;i++)
    visited[i] = false;
    bool recst[v];
    for(int i=0;i<v;i++)
    recst[i] = false;

    for(int i=0;i<v;i++){
        if(visited[i]==false)
        if(findcycle(adj,i,visited,recst)==true)
        return true;
        else
        return false;
    }
}

bool findcycle(vector<int>adj[],int s,bool visited[],bool recst[]){
    visited[s]=true;
    recst[s] = true;
    for(int u:adj[s]){
        if(visited[u]==false){
            if(findcycle(adj,u,visited,recst)==true)
            return true;
        }
        else if(recst[u]==false)
        return true;
    }
    recst[s] = false;
    return true;
}