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

struct Edge {
    int src ,dest ;
};

class Graph {
    public:
    vector<vector<int>>adj ; 

    Graph (vector<Edge> edge , int n ){
        adj.resize(n) ; 
        for(auto &edges :edge)
        {   
            adj[edges.src].pb(edges.dest )  ;
            adj[edges.dest].pb(edges.src ) ; 
        }
    }


} ;

bool Dfs(Graph const &graph , int v ,vector<bool> &vis , vector<int> &color)
{
    for(int u : graph.adj[v]){
        if(!vis[u]){
            vis[u]=1;
            color[u] = !color[v] ; 
            if (!Dfs(graph, u, vis, color))
				return false;

        }
        else if(color[u] == color[v]){
            return 0 ;
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
		{5, 9}, {8, 9}/*, {2, 4} */ 
		// if we remove 2->4 edge, graph is becomes Bipartite
	};

	// Number of nodes in the graph
	int N = 10;

	// create a graph from edges
	Graph graph(edges, N);

	// stores vertex is discovered or not
	vector<bool> vis(N);

	// stores color 0 or 1 of each vertex in DFS
	vector<int> color(N);

	// mark source vertex as discovered and
	// set its color to 0
	vis[0] = true, color[0] = 0;

	// start DFS traversal from any node as graph
	// is connected and undirected
	if (Dfs(graph, 1,vis, color))
		cout << "Bipartite Graph";
	else
		cout << "Not a Bipartite Graph";
    //  cout<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 

	return 0;
}
