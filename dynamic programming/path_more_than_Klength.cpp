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
bool pathMoreThanK(vector<vp>&adj,vector<bool> &path,int n , int src , int k){
    if(k<=0)return true; 

    for(auto V:adj[src]){
            int v  = V.first ; 
            int wt= V.second ; 
            
            if(path[v]){
                continue ; 
            }
            if(wt>=k){
                return true ; 
           }
           path[v] = true ; 
           if(pathMoreThanK(adj,path,n,v,k))
           {
               return true ; 
           }
           path[v] = false ;

    }
    return false ; 

}
void solve(){
    int n , e, f,s,wt ;
    cin>>n>>e; 
    
    vector<vector<pair<int,int>>> adj(n) ; 

    fr(i,e)
    {    cin>>f>>s>>wt;
        adj[s].pb({f,wt}) ;
        adj[f].pb({s,wt}) ;
    }
    int k ; 
    cin>>k;
    vector<bool>path ;  
bool ans = pathMoreThanK(adj,path,n,0,k) ; 
    if(ans)
    cout<<"Yes";
    else{
        cout<<"No" ; 
    }
    cout<<endl;
}

int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
     int tc;
    scanf("%d", &tc) ; 
    while(tc--){
        solve() ; 
    }
}
