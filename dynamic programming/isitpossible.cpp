//from the gfg question https://www.geeksforgeeks.org/find-whether-it-is-possible-to-finish-all-tasks-or-not-from-given-dependencies/
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
            
        } 
    }  
};
 
bool dfs(Graph &g, int v,vector<int> &st ,vector<bool> &vis){
	if(!vis[v]){
		vis[v] = true ; 
		st[v] = 1 ;
		for(auto u : g.adj[v]){
			if((!vis[u] && dfs(g,u,st,vis))||(st[u]) )
				return true ;  
		}
	}
	st[v] = 0 ;
	return false; 
}

bool checkcycle(Graph &g,int n){//checks cycle if it exists then it is not possible else possible

	vector<bool > vis(n) ; 
	vector<int> st ;
	for(int i = 0 ; i < n ;++i ){
		if(!vis[i])
		{
			st.assign(n,0) ; 
			if(dfs(g,i,st,vis)){
				return false ;
			}

		}
	}
	return true ; 

}

int main()
{
    Ios;
    Tie;
    vector<Edge> edge = {
        { 1, 2} , {2,3 }, {3,1} , {3,4}
    } ;

    int n = 5 ;

    Graph graph(edge ,n) ; 

    vector<bool> vis(n,0) ;

    if(checkcycle(graph,n)){
    	cout<<"true";
    }
    else{
    	cout<<"false";
    }
    cout<<endl;
}