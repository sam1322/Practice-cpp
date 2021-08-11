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
	int src ,dest;
};

// only for dag

class Graph{
public:
	vector<vector<int>> adj ;

	Graph(vector<Edge> &edge ,int n){
		int N =  edge.size() ; 
		adj.resize(n) ; 
		for(int i = 0 ; i < N ; ++i){
			adj[edge[i].src].push_back(edge[i].dest)  ;
		}
	}	

} ;

void dfs(Graph &graph , vector<bool>&vis , int v ,vector<int>&st){
	
	vis[v] = 1 ;

	// cout<<v<<endl; 

	for(auto u : graph.adj[v]){
		if(!vis[u])	
		dfs(graph ,vis , u ,st) ;
	}
	st.push_back(v) ;
}

vector<int> topological_sort(Graph &graph ,int n){

	vector<int> stack ;
	vector<bool>vis(n) ; 
	for(int i = 0 ; i < n ;++i){
		if(!vis[i])
		dfs(graph , vis , i , stack) ;
	}
	return stack ; 

}

int main()
{
    Ios;
    Tie;
     vector<Edge> edge = {
        { 1, 2} , {2,3 }, {3,4} , {3,0}
    } ;
    int n = 5;
    
     vector<Edge> edge2 = {
        {1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
		{3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}
    } ;
    int N= 13 ;

    vector<Edge> edge3 = {
    	{3,1} , {4,1 } , { 4, 0 } , {5 , 0 } , { 5 , 2} , { 2 , 3 } 
    }; 
    int n3 = 6 ; 
    // Graph g(edge2 , N) ; 
    // Graph g(edge ,n );
    Graph g(edge3 ,n3 );

    vector<int> v  = topological_sort(g , n3) ; 
    Rev(v) ;

    for(auto i:v){
    	cout<<i<<" ";

    }
    cout<<endl;
}