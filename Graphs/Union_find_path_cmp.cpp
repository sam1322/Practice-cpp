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
	vector<int> rank ;
	Graph(vector<vector<int>> edges , int N ){
		vector<int> V ; 
		adj.assign(N,V) ;
		parents.assign(N,-1) ;
		rank.assign(N , 0); 

		this->N = N ; 
		for(auto &p : edges){
			adj[p[0]].push_back(p[1]) ; 
			adj[p[1]].push_back(p[0]) ; 
		}
	}
};

int find(vector<int> &parents,vector<int> &rank , int v){
	if(parents[v]==-1)
		return v ; 

	return parents[v] = find(parents,rank,parents[v]) ; 
	// return g.parents[v] ; 
}

void Union(vector<int> &parents,vector<int> &rank,int a,int b ){
	if(rank[a] > rank[b])  {
			parents[b] = a ;
		}
		else if(rank[a] < rank[b] ){
			parents[a] = b ;
		}
		else{
			parents[a] = b   ;
			rank[b]++ ;
		}
}

bool isCyclic(vector<int> &parents,vector<int> &rank ,vector<vector<int>> &Edges){
	for(auto &x:Edges){
		int a = find(parents,rank,x[0]) ;
		int b = find(parents,rank ,x[1]) ;
		if(a==b){
			return true ; 
		}
 // union operation
		Union(parents,rank,a,b) ; 

	}
	return false ;
}


int main()
{
    // vector<edge> edges = {
    // 	{0,1} , {0,3} , {2, 3}  ,{1,2}  
    // } ;
vector<vi> edges = {
    	{0,1} ,{2, 3}  ,{1,2} ,{0,4} ,  {4,3} 
    } ;

    Graph g(edges , 5) ; 

    if(isCyclic(g.parents,g.rank,edges) ){
    	cout<<"It is cyclic" ;
    }
    else{
    	cout<<"It is not cyclic " ;
    }
    cout<<endl; 
    for(int i = 0 ; i <  g.parents.size() ; ++i){
    	cout<<g.parents[i] <<" " ;
    }
    cout<<endl;
    for(int i = 0 ; i <  g.parents.size() ; ++i){
    	cout<<g.rank[i] <<" " ;
    }
    cout<<endl ; 
}