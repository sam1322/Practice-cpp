#include <iostream>
#include<climits>
using namespace std;


int findMinVertex(int *distance , bool *visited, int n ){
    int m = -1 ;
    for(int i = 0 ; i < n ; i++){
        if(!visited[i] && (m ==-1 || distance[i] < distance[m]))
            m=i ;
    }
    return m ;
}

void Dijkstra(int **edges ,int n ,int src){
    bool *visited = new bool[n] ;
    int *distance = new int[n] ;

    for(int i = 0 ; i < n ;i++)
    {
        visited[i] = false ;
        distance[i] = INT_MAX ;
    }

    distance[src] = 0 ;

        for(int i = 0 ; i < n ; i++ )
    {
        int minVertex = findMinVertex(distance , visited , n ) ;
        visited[minVertex]= true ;

        for(int j = 0 ; j < n ; j++ ){
            if(edges[minVertex][j]!=0 && !visited[j] ){
                int dist = distance[minVertex] + edges[minVertex][j] ;
                if(dist < distance[j] ){
                    distance[j] = dist ;
                }
            }
        }
    }
    cout<<"Vertex\tDistance from Source\n" ;
    for(int i = 0 ; i < n ; i++) {
        cout<<i<<" " << distance[i] <<endl ;
    }

    delete []visited ;
    delete []distance ;
}


int main()
{
  int V, E;
  cin >> V >> E;

    int **edges = new int*[V] ;
    for(int i =0 ; i < V ; i++ )
    {
        edges[i] = new int[V] ;
        for(int j = 0 ; j < V ; j++){
            edges[i][j] = 0 ;
        }
    }

    for(int i = 0 ; i < E ; i++ ){
        int f, s , d;
        cin>>f>>s>>d ;
        edges[f][s] = d ;
        edges[s][f] = d ;
    }
    cout<<"What should be the source vertex\n";
    int src ;
    cin>>src ;

    Dijkstra(edges , V,src)  ;
    for(int i = 0; i < V ;i++)
        delete []edges[i] ;
    delete []edges ;

}