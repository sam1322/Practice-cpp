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
#define vp vector<pair<int,int>> 

// can only be used for   undirected graph only

struct edge{
	int src , dest ; 
};

class Graph{
	public:
	int N ;
	vector<vector<int>> adj ;
	vector<int> parents ; 
	Graph(vector<edge> edges , int N ){
		vector<int> V ; 
		adj.assign(N,V) ;
		parents.assign(N,-1) ;
		this->N = N ; 
		for(auto &p : edges){
			adj[p.src].push_back(p.dest) ; 
			adj[p.dest].push_back(p.src) ; 
		}
	}
};

int find(Graph &g , int v){
	if(g.parents[v]==-1)
		return v ; 
	return g.parents[v] = find(g,g.parents[v]) ; 
	// return find(g,g.parents[v]) ; 
}


bool isCyclic(Graph &g,vector<edge> &Edges){
	for(auto &x:Edges){
		int a = find(g,x.src) ;
		int b = find(g,x.dest) ;
		if(a==b){
			return true ; 
		}

		g.parents[a] = b  ; // union operation

	}
	return false ;
}


int main()
{
	
   ios_base::sync_with_stdio(false);cin.tie(NULL);
 
        
  #ifndef ONLINE_JUDGE
   freopen("/home/sriram/Coding-files/codeforces/in", "r", stdin);
   freopen("/home/sriram/Coding-files/codeforces/err", "w", stderr);
   freopen("/home/sriram/Coding-files/codeforces/out", "w", stdout);
   #endif
	
    vector<edge> edges = {
    	{0,1} , {0,3} , {2, 3}  ,{1,2}  
    } ;

    Graph g(edges , 4) ; 

    if(isCyclic(g,edges) ){
    	cout<<"It is cyclic" ;
    }
    else{
    	cout<<"It is not cyclic " ;
    }
    cout<<endl; 
    for(int i = 0 ; i <  g.parents.size() ; ++i){
    	cout<<g.parents[i] <<" " ;
    }
    cout<<endl ; 
}