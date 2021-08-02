#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define fr(i,a) for(int  i=0;i<a;i++)
#define forn(i,a,n) for(int i = a; i < n ;i++)
#define Sort(a) sort(a.begin(),a.end())
#define Rev(k)  reverse(k.begin(),k.end())
#define Sz(x) x.size()
#define Show(v) for(int i =0 ; i < v.size();i++) cout<<v[i]<<" "; //only for strings and vector
#define Mod 1000000007
#define Fi first
#define Sc second
#define pb push_back
#define Ios ios::sync_with_stdio(false);cin.tie(0);cout.setf(ios::fixed); cout.precision(0);
#define inf 0x3f3f3f3f
#define mk make_pair
template<typename T, typename V> inline void mn(T &x, V y) { if(y < x) x = y; }
template<typename T, typename V> inline void mx(T &x, V y) { if(x < y) x = y; }
//const int MAXN = 200100;
typedef long long  ll;
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pair<int,int>> 
typedef pair<int,int> pii; 
// sieve , binomial coeff , pascal 

//int solve(){

void dfs(vector<vector<int>> &adj ,vector<bool>&visited ,int v ){
	visited[v] = 1 ; 
	cout<<v<<" "; 
	for(int u : adj[v]) {
		if(!visited[u]){
			dfs(adj,visited,u) ;
		}
	}
}

void Print_adj_list(vector<vector<int>> &adj){
	for(int i = 0 ; i < adj.size() ; ++i){
		cout<<i <<" : "  ; 
		for(auto x:adj[i]){
			cout<<x<<" , "; 
		}
		cout<<endl;
	}
}

void solve(){
	vector<vector<int>>  edge = {
        { 1, 2} , {2,3 }, {1,3} , {3,4}
    } ;
    int n = 5 ; 
    vector<vector<int>>adj(n) ; 
    vector<bool> vis(n) ; 
    for(vi x : edge){
    	adj[x[0]].push_back(x[1]);
    	adj[x[1]].push_back(x[0]);

    }
    Print_adj_list(adj);
    for(int i = 0 ; i < n ;++i){
    	if(!vis[i]){
    		dfs(adj,vis,i) ;
    		cout<<endl;
    	}
    }

}

int main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
 
    
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("error.txt", "w", stderr);
   freopen("output.txt", "w", stdout);
   #endif

    // int tc;
    // //scanf("%d", &tc) ; 
    // cin>>tc; 

    // while(tc--){
    	//cout<<solve()<<endl;
      solve();
      //cout<<endl;
    // }
}