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
            adj[i.dest].pb(i.src) ;
        } 
    }  


};

bool Bfs(Graph const &graph , int  v , int N ){
    vector<int> vis(N) ;
    queue<int> q; 

    q.push(v) ; 
    vis[v] = 1 ;
    vector<int> level(N) ;

    level[v] = 0 ; 

    while(!q.empty()){
        v = q.front() ; 
        q.pop() ; 

        for(int u :graph.adj[v])  
        {
            if(!vis[u]){
                q.push(u)  ;
                level[u]  = level[v] + 1  ;
                vis[u] = 1 ;
            }
            else if(level[u]==level[v])
            return 0; 

        }
    }
    return 1 ; 

}


int main()
{
    Ios;
    Tie;
    vector<Edge> edges = {
		{1, 2}, {2, 3}, {2, 8}, {3, 4}, {4, 6}, {5, 7},
		{5, 9}, {8, 9}
		// if we add 2->4 edge, graph is becomes non-Bipartite
	};

	// Number of nodes in the graph
	int N = 10;

	// create a graph from edges
	Graph graph(edges, N);

	// Do BFS traversal starting from vertex 1
	if (Bfs(graph, 1, N))
		cout << "Bipartite Graph";
	else
		cout << "Not a Bipartite Graph";

	return 0;
}
