#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define fr(i,a) for(int  i=0;i<a;i++)
#define forn(i,a,n) for(int i = a; i < n ;i++)
#define Sort(a) sort(a.begin(),a.end())
#define Rev(k)  reverse(k.begin(),k.end())
#define Sz(x) x.size()
#define Show(v) for(int i =0 ; i < v.size();i++) cout<<v[i] //only for sting and vector
#define Mod 1000000007
#define Fi first
#define Sc second
#define pb push_back
#define Ios ios::sync_with_stdio(false)
#define Tie cin.tie(0);    cout.setf(ios::fixed); cout.precision(0);
#define inf 0x3f3f3f3f
#define mk make_pair
template<typename T, typename V> inline void mn(T &x, V y) { if(y < x) x = y; }
template<typename T, typename V> inline void mx(T &x, V y) { if(x < y) x = y; }
//const int MAXN = 200100;
typedef long long  ll;
#define vi vector<int>

struct Edge{
    int src , dest ; 
};

class Graph{
    public:
    vector<vector<int>> adj; 

    Graph(vector<Edge> &edge,int n){
        adj.resize(n) ;

        for(auto &i : edge){
            adj[i.src].pb(i.dest) ;
            // adj[i.dest].pb(i.src) ; directed graph
        } 
    
    }  
};
void DFS(Graph const &graph , int v ,vector<bool> &vis,vector<pair<int,int>> &a ,int &c){
        
        vis[v] = 1 ;
        // cout<<v<<" ";
        a[v].first= c ;
        for(int u : graph.adj[v])  
        {
            if(!vis[u]){
                c++;
                DFS(graph ,u , vis,a,c) ;
            }
        }
        c++ ;
        a[v].second = c ;
    } 


int main()
{
    Ios;
    Tie;
   

    // vector of graph Edge as per above diagram
	vector<Edge> edges = {
		{0, 1}, {0, 2}, {2, 3}, {2, 4}, {3, 1}, {3, 5},
		{4, 5}, {6, 7}
	};

	// Number of nodes in the graph
	int N = 8;
    int c =0 ;
    Graph graph(edges,N) ;
     vector<bool> vis(N) ; 
    vector<pair<int,int> > arr(N,{-1,-1}) ; 
    for(int i =  0;i<N;i++){
        if(!vis[i]){
        DFS(graph,i,vis,arr,c) ;
        c++;
        }
    }
    fr(i, N){
        cout<<"Vertex "<<i<<" ( "<<arr[i].Fi<<" , "<<arr[i].Sc<<" ) \n";
    }
}
