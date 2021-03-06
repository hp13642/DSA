#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

int getmin(vector<bool> &status,vector<int> &dist){
    int min_cost=INT_MAX;
    int min_vertex=-1;
    int nodes=status.size()-1;
    for(int i=1;i<=nodes;i++){
        if(!status[i] && dist[i]<min_cost){
            min_vertex=i;
            min_cost=dist[i];
        }
    }
    return min_vertex;
}

void print(vector<int> &vec){
    for(int i=1;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

void djikshtra(vector<list<P> > &graph, int start){
    int nodes=graph.size()-1;
    vector<bool> status(nodes+1,false);
    vector<int> dist(nodes+1,INT_MAX);
    vector<int> parent(nodes+1,-1);
    dist[start]=0;
    int unvisited=nodes;
    while(unvisited){
        int u=getmin(status,dist);
        status[u]=true;
        unvisited--;
        for(auto itr=graph[u].begin();itr!=graph[u].end();itr++){
            int v=(*itr).first;
            int w=(*itr).second;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                parent[v]=u;
            }
                
        }
    }
    cout<<"Parent Array:"<<endl;
    print(parent);
    cout<<"Shortest Distance Array:"<<endl;
    print(dist);
    
}

int main(){
    int nodes,edges,start;
    cin>>nodes>>edges;
    vector<list<P> >graph(nodes+1);
    for(int i=1;i<=edges;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    cin>>start;
    djikshtra(graph,start);
}
