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

void DFS(vector<vector<int>> &adj ,int u, vector<int> &disc,vector<int> &low,vector<int> &stack ,vector<bool> &presentInStack)
{
	static int time = 0 ; 
	disc[u] = low[u] = time++;
	stack.push_back(u) ;
	presentInStack[u]= true  ;
	// cout<<u<<" "<<low[u]<< " "<<disc[u]<<endl;
		for(int v:adj[u]){
		if(disc[v]==-1){
			DFS(adj,v,disc,low,stack,presentInStack)  ;
			low[u] = min(low[u],low[v]) ;
	}
		else if(presentInStack[v]){// if back edge
			low[u] = min(low[u],disc[v] ); 
		}
		// else if cross edge then do nothing and return 
	}	// cout<<u<<" "<<low[u]<< " "<<disc[u]<<endl;
	if(low[u]==disc[u]){
		cout<<"the head of strongly connected components is "<<u<<endl;
		while(!stack.empty() && stack.back() !=u )		
		{
			cout<<stack.back()<< " " ; 
			presentInStack[stack.back()] = false;
			stack.pop_back() ;
		}
		if(!stack.empty()){
			cout<<stack.back()<< " " ; 
			presentInStack[stack.back()] = false;
			stack.pop_back() ;	
		}
		cout<<endl; 
	}
}
void tarjan(vector<vector<int>> &adj, int n ){
	vector<int> disc(n,-1) , low(n,-1),stack; 
	vector<bool> presentInStack(n,false) ;//for avoiding cross edges
	for(int i = 0 ; i < n ; ++i ){
		if(disc[i]==-1){
			// cout<<i<<" "<<low[i]<< " "<<disc[i]<<endl;
			DFS(adj,i,disc,low,stack,presentInStack) ;
		}
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
		// adj[s].push_back(f); 
	}
	for(int i = 0 ; i < n ; ++i){
		cout<<i<<" : ";
		for(int x:adj[i])cout<<x<<" , ";nl;
	}

	tarjan(adj,n) ; 

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
1
7 9 
0 1 
1 2 
1 3
3 4
4 0
4 5
4 6
5 6
6 5

1
8 10
0 1
1 2
2 0
2 3
3 4
4 5
4 7
5 6
6 4
6 7

*/