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

#define N 100

struct Edge
{
	int src ,dest  ; 

};

class Graph{
public:
	vector<int> adj[N+1] ; 

	Graph(vector<Edge> const &edges, ){
		int src = edges.src , dest = edges.dest ;

		adj[src].pb(dest) ; 
	}
};

struct Node 
{
	int ver  ;

	int Mindist ; 		
};

void Bfs(Graph const &graph , int s){

	queue<Node> q;

	vector<bool> vis(N + 1 ) ;
	vis[s] = 0 ; 

	Node node = { s , 0} ; 

	q.push(node) ;

	 while(!q.empty()){
	 	node = q.front() ; 

	 	q.pop() ;
	 	
	 	if(node.ver==N)
	 		return node.Mindist ; 


	 }
	 	for(int u : graph.adj[node.ver]){
	 		if(!vis[u]){

	 			vis[u] = 1;

	 			Node n = { u, node.Mindist + 1 };

	 			q.push(n) ; 


	 		}
	 	}



}


void soln(map<int,int> &ladder ,map<int,int> &snake){
	
}


int main()
{
    Ios;
    Tie;

     #ifndef ONLINE_JUDGE 
   freopen("input.txt", "r", stdin); 
   freopen("error.txt", "w", stderr); 
   freopen("output.txt", "w", stdout); 
   #endif 


    }

     cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
   return 0; 
}
