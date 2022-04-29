#include<bits/stdc++.h>
using namespace std ;

struct Edge{
    int src , dest , weight; 
};

class Graph{
    public:
    vector<vector<pair<int,int>>> adj; 

    Graph(vector<Edge> &edge,int n){
        adj.resize(n) ;

        for(auto &i : edge){
            adj[i.src].push_back(make_pair(i.dest,i.weight)) ;
            // cout<<"Src "<<i.src<<" Dest "<<adj[i.src].back().first<< " weight "<<adj[i.src].back().second<<endl; 
            // adj[i.dest].push_back(make_pair(i.src,i.weight)) ;
        } 
    }  


};

void Bellmanford(Graph &graph, int N , int src )
{
    vector<int>dist(N,INT_MAX) ; 
    dist[src]=0 ; 
    for(int i = 0 ;  ; i++){
        int f = 0 , u =0 ; 
        for(auto &x : graph.adj ){
            for(int j = 0 ; j<x.size() ; j++){
                if(dist[u] + x[j].second < dist[x[j].first]){
                    dist[x[j].first] = dist[u] + x[j].second  ; 
                    f= 1 ; 
                }
                // cout<<"u "<<dist[u]<<" uv weight "<<x[j].second<<" "<<x[j].first<<" "<<dist[x[j].first]<<endl;
            }
            u++;
        }
        if(!f)break;

        if(i>=N){
            cout<<"Negative weight cycle detected \n" ; return ; 
        }
    }
    cout<<"Vertex\tDistance from source vertex\n" ;
    for(int i = 0 ;i <dist.size() ;i++){
        cout<<i<<"\t " <<dist[i]<<endl;
    }

}

int main(){

    vector<Edge>  edge{
        {0,1,6},
        {0,2,5},
        { 0,3,5},
        {1,4,-1},
        {1,2,-2},
        {3,5,-1},
        {2,4,1},
        {5,6,3},
        {4,6,3}
    } ;
    int N = 7  ; 
    Graph graph(edge,N) ; 
    // cout<<"What should be the source \n" ; 
    int src = 0 ; 
    // cin>>src ;

    Bellmanford(graph , N ,src ) ; 
    
    

}