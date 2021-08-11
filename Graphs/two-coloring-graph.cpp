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

//int solve(){
bool bfs(vector<vector<int>> &adj,int n , int u , vi &color){
  color[u] = 0 ; 
  queue<int> q; 
  q.push(u); 
  bool res = true  ;
  while(!q.empty()) {
    u = q.front() ; 
    q.pop() ;
    for(int v:adj[u]){
        if(color[v]==-1){
          color[v] = 1 - color[u] ; 
          q.push(v) ;
        }
        else if(color[v]==color[u])res = false ; 
    }
  }
return res ;
}

void solve(int argc,char* argv[]){
  int n , e; 
  srand(atoi(argv[1])) ; 

  vector<pair<int,int>> edges ; 
  for(int i = 0 ; i < e ; ++i){
    int f,s; cin>>f>>s ;
    edges.emplace_back(f,s); 
  }
  
}

void solve(){
  int n , e,f,s; 
  // cin>>n >>e ; 
  cin>>n ; 
  e = n - 1 ; 
  vector<pair<int,int>> edges; 
  fr(i,e){
    cin>>f>>s; 
    edges.emplace_back(f,s); 
  }
  vector<vector<int>> adj(n+1) ; 
  for(pair<int,int> x :edges){
    adj[x.first].pb(x.second) ; 
    adj[x.second].pb(x.first) ; 
  }

  vector<int> color(n+1,-1) ; 
  for(int i = 0 ; i <= n ; ++i){
    if(color[i]==-1){
      if(bfs(adj,n,i,color)){
        cout<<"graph starting from "<<i<<" is bipartite ";
      }
      else{
        cout<<"graph starting from "<<i<<" is not a bipartite ";
      }
      nl;
    }
  }
}

int main(int argc,char* argv[])
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
    
        
   #ifndef ONLINE_JUDGE
   freopen("/home/sriram/Coding-files/codeforces/in", "r", stdin);
   freopen("/home/sriram/Coding-files/codeforces/err", "w", stderr);
   freopen("/home/sriram/Coding-files/codeforces/out", "w", stdout);
   #endif


    	//cout<<solve()<<endl;
      // solve(argc,argv);
      solve() ; 
      //cout<<endl;
    // }
}