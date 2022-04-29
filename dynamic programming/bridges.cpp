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
#define vp vector<pair<int,int>> 
typedef pair<int,int> pii; 
// sieve , binomial coeff , pascal 
// class Compare{
//     public:
//     bool operator() (foo,foo){
//         return expression
//     }
// };
void dfs(vector<vector<int>> &adj , int u ,vector<int> &desc,vector<int>&low,vector<int>&parent,vector<pair<int,int>> &bridges){
    static int time = 0 ; 
    desc[u] = low[u] = time ; 
    time++ ; 
    for(auto v :adj[u]){
        if(desc[v]==-1){
            parent[v] = u ; 
            dfs(adj,v,desc,low,parent,bridges) ;
           low[u] = min(low[u], low[v]) ;  
            if(low[v] > desc[u]){
                bridges.pb({u,v}) ;
            }
        }
        else if(v!=parent[u]){
           low[u] = min(low[u],desc[v] ) ; 

        }
    }
}
void FindBridgesTarjan(vector<vector<int>> &adj , int n ){
   vector<int> desc(n,-1),low(n,-1) ,parent(n,-1) ;
   vector<pair<int,int>> bridge;
   fr(i,n){
       if(desc[i]==-1)
        {
            dfs(adj,i,desc,low,parent,bridge) ;
        }
   }   
   Show(desc);cout<<endl;
   Show(low);cout<<endl;
   Show(parent);cout<<endl;
   cout<<"There are " <<bridge.size() <<" bridges " <<endl;
   fr(i,bridge.size()){
       cout<<bridge[i].first<<" "<<bridge[i].second <<endl;
   }
}

void solve(){
    int n,e ;
    cin>>n>>e; 
    vector<vector<int>>adj(n) ;
    fr(i,e){
        int a,b ;
        cin>>a>>b ;
        adj[a].pb(b) ;
        adj[b].pb(a) ;
    }
   FindBridgesTarjan(adj,n) ;

}

int main()
{
    solve() ;
}
/*
5 5
0 1
1 2 
2 0
0 3 
3 4 
*/