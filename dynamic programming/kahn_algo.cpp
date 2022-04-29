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


struct edge{
	int src , dest ; 
};

class Graph{
	public:
	int N ;
	vector<vector<int>> adj ;
	Graph(vector<edge> edges , int N ){
		vector<int> V ; 
		adj.assign(N,V) ;
		this->N = N ; 
		for(auto &p : edges){
			adj[p.src].push_back(p.dest) ; 
			// adj[p.dest].push_back(p.src) ; 
		}
	}
};
bool Kahn_algo(Graph &g ,vector<int> &v){
	vector<int> indegree(g.N) ;

	for(int i = 0 ; i < g.N ; ++i){
		for(int j = 0 ; j < g.adj[i].size() ;++j){
			indegree[g.adj[i][j]]++;
		}
	}
	vector<int>q ;

	for(int i = 0 ; i < g.N ; ++i){
		if(!indegree[i] ){
			q.push_back(i) ; 		
		}
		// cout<<i <<" : "<<indegree[i]<<endl;
	}

	int count = 0 ;

	while(!q.empty()){
		count++ ;
		v.push_back(q[0]) ; 
		int fr = q.front() ; 
		q.erase(q.begin()) ;  
		for(int j = 0 ; j < g.adj[fr].size() ; ++j ){
			// cout<<indegree[g.adj[fr][j]]<<" " ;

			indegree[g.adj[fr][j]]-- ;
			if(indegree[g.adj[fr][j]]==0)
				q.push_back(g.adj[fr][j]) ; 
		}
		// cout<<endl;


	}
	return count == g.N ; 

}

int main()
{
    Ios;
    Tie;
    vector<edge> edges={
    	{5,0} , {5,2} , {4, 0} , { 4 , 1 } , { 2 , 3 } , { 3 , 1 } 
    };

    int  N = 6 ; 

    // vector<edge> edges = {
    // 	{0 , 1} , { 1 , 2 } , { 2 , 1 }
    // };
    // int N = 3 ;
    Graph g(edges , N) ; 

    vector<int> v ;
    if(Kahn_algo(g , v)){
    	cout<<"It is DAG and the topological sorting is : "; 
    	fr(i,v.size()){
    		cout<<v[i]<<" " ; 
    	}
    } 
    else{
    	cout<<" It is a cyclic graph" ; 
    }
    	cout<<endl;


}