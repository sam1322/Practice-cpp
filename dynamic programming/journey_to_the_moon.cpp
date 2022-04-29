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
void dfs(int u , vector<vi> &adj , vi &vis,int &count ){
    vis[u] = 1 ;
    count++;
    for(auto  v: adj[u]){
        if(!vis[v]){
          dfs(v,adj,vis,count) ;
        }
    }

}
int solve(){
    int f,s,n , e ; 
    cin>>n>>e;
    vector<vi> adj(n) ;
    fr(i,e){
       cin>>f>>s ;
       adj[f].pb(s)  ;
       adj[s].pb(f) ; 
    } 
    vi a,vis(n) ;
    fr(i,n){
       if(!vis[i])
        { int count = 0 ;
           dfs(i,adj,vis,count) ;
           if(count>0)
                a.pb(count);
       } 
    }
    vector<ll> sum(a.size()+1);
    ll ans = 0 ;
    fr(i,a.size()){
        sum[i+1] = sum[i]+a[i] ; 
    }
    for(int i = a.size() - 1 ;i>=0 ; --i){
        ans+=sum[i]*a[i] ; 
    }
    return ans ; 
    
}

int main()
{
   cout<< solve() <<endl;
}
