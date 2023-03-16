#include <iostream>
#include <vector>
#include <queue>
#include <prims_min_heap.cpp>
using namespace std;

int minspan(vector<vector<int> > adj,int V){
    bool MST[V];
    fill(MST,MST+V,false);
    int res = 0;
    
    int key[V];
    fill(key,key+V,INT16_MAX);
    key[0] = 0;
    
    for(int i=0;i<V;i++){
        int u=-1;
        for(int i=0;i<V;i++){
            if(!MST[i] && (u==-1 || key[i]<key[u]))
            u = i;
        }
        MST[u] = true;
        res += key[u];

        for(int x:adj[u]){
            if(x!=0 && MST[u]==false)
            key[x] = min(key[x],adj[u][x]);
        }
    }
    return res;
}

//optimised Prim's Algorithm
int prims(vector<vector<int>> adj,int V){
    bool MST[V];
    fill(MST,MST+V,false);
    int res = 0;

    min_heap pq(V);
    pq.decreasekey(0,0);

    for(int i=0;i<V;i++){
        int u = pq.minimum();
        pq.extract();
        
    }
}