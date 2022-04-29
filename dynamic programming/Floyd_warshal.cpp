#include<bits/stdc++.h>
using namespace std ;

struct Edge{
    int src , dest , weight; 
};

void Print(vector<vector<long long>> &graph , int N){
     
    for(int i = 0;i<N;i++){
       cout<<"Shortest distance from the source vertex "<<i+1<<endl;
       cout<<"Vertex\tDistance\n";
        for(int j = 0 ; j < N ; j++) {
            cout<<j+1<<"\t"; 
            if(graph[i][j]==INT_MAX){
                cout<<"inf ";
            }
            else{
                cout<<graph[i][j] <<" ";
            }
        cout<<endl;           
        }
        cout<<endl;
    }
}

void Floyd_warshall(vector<Edge> &edge , int N){
    vector<long long > p(N,INT_MAX) ; 
    vector<vector<long long >> graph(N,p) ; 

    for(auto x:edge){
        graph[x.src][x.dest] = x.weight ; 
    }
    for(int i = 0 ; i < N ; i++){
        graph[i][i] = 0 ;
    }
// Print(graph,N) ; 


    for(int k = 0 ; k < N ; k++){
        for(int i = 0 ; i < N ; i++ ){
            for(int j = 0 ; j < N ; j++){
                if(graph[i][k] + graph[k][j] < graph[i][j]){
                    graph[i][j] = graph[i][k] + graph[k][j] ; 
                }
            }
        }
    }
Print(graph,N) ; 
}


int main(){
    vector<Edge> edge = {
        {0,1,2} ,
        {0,3,7},
        {1,0,8} ,
        {1,2,2},
        {2,0,2},
        {2,3,1},
        {3,0,2}
    };

    int N = 4 ; 

    

    Floyd_warshall(edge,N) ; 
}