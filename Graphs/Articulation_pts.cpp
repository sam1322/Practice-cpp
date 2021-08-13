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
#define nl cout<<endl;
typedef pair<int,int> pii; 
// sieve , binomial coeff , pascal 

// only for undirected edges 

void DFS(int u , vector<vector<int>> &adj,vector<int> &disc, vector<int> &low,vector<int> &parent ,vector<bool> &ap){
	static int time = 0 ; 
	disc[u] = low[u] = time++ ; 
	int children = 0 ; 
	for(int v:adj[u]){
		if(disc[v] == -1 ){
			children++;
			parent[v] = u ; 
			DFS(v,adj,disc,low,parent,ap) ;
			low[u] = min(low[u],low[v]) ;

			if(parent[u]==-1 && children>1)   // Case 1 : U is a root 
			{
				ap[u] = true ; 
			}
			if(parent[u]!=-1 && low[v]>=disc[u]){ // Case 2 : U is not root and atleast 1 component will be separated 
				ap[u] = true ; 
			}

		}
		else if(v!=parent[u]) //ignore the child edge
 		{
 			low[u] = min(low[u],disc[v]); 
		}
	}
}

void printArticulationPts(vector<vector<int>> &adj , int n )
{	
	vector<int> disc(n,-1), low(n,-1),parent(n,-1) ; 
	vector<bool> ap(n,0); //Articulation Points

	for(int i = 0 ; i < n ;++i){
		if(disc[i]==-1)
		DFS(i,adj,disc,low,parent,ap) ;
	}

	for(int i = 0 ; i < n ; ++i ){
		if(ap[i])
			cout<<i<<" " ;
	}
}

//int solve(){
void solve(){
	int f,s, n ,e ; 
	cin>>n >>e ;
	vector<vector<int>>adj(n) ; 
	vector<vector<int>> edge; 
	fr(i,e){
		cin>>f>>s; 
		edge.push_back({f,s}) ; 
	}
	for(auto x:edge){
		f = x[0] ; 
		s = x[1] ;
		adj[f].push_back(s); 
		adj[s].push_back(f); 
	}
	for(int i = 0 ; i < n ; ++i){
		cout<<i<<" : ";
		for(int x:adj[i])cout<<x<<" , ";nl;
	}

	printArticulationPts(adj,n) ; nl;nl;
}

int main()
{

   ios_base::sync_with_stdio(false);cin.tie(NULL);
 
        
  #ifndef ONLINE_JUDGE
   freopen("/home/sriram/Coding-files/codeforces/in", "r", stdin);
   freopen("/home/sriram/Coding-files/codeforces/err", "w", stderr);
   freopen("/home/sriram/Coding-files/codeforces/out", "w", stdout);
   #endif

    int tc;
    //scanf("%d", &tc) ; 
    cin>>tc; 

    while(tc--){
    	//cout<<solve()<<endl;
      solve();
      //cout<<endl;
    }
}

/*
2
5 5 
0 1
0 2
0 3
1 2
3 4

4 3
0 1
1 2
2 3




*/