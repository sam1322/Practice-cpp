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
void dijkstra(int src ,vector<vector<pair<int,int>>> &adj, int n,vi &dist ){
    priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> q ;
    dist[src] = 0 ; 
    q.push({0 ,src}); 
    while(!q.empty()){
        pair<int,int> p = q.top() ;
        q.pop();
        int u = p.second ,d = p.first ; 
        if(d > dist[u]){
            continue;
        }
        for(auto V:adj[u]){
            int v = V.first ; 
            int newDist = d + V.second ; 
            if(newDist < dist[v]){
                dist[v] = newDist ; 
                q.push({newDist ,v}) ;
            } 
        }   
    }
}

void solve(){
    int n , e ,s,f,wt; 
    cin>> n>>e; 
    vector<vector<pair<int,int>>> adj(n) ; 
    vector<int> dist(n,inf) ; 

    fr(i,e)
    {    cin>>f>>s>>wt;
        adj[s].pb({f,wt}) ;
        adj[f].pb({s,wt}) ;
    }

    // dijkstra(0,adj,n,dist) ; 
        dijkstra(1,adj,n,dist) ; 
    cout<<"index weight\n";
    for(int i = 0 ;i < dist.size() ; ++i){
        cout<<i<< "\t" <<dist[i]<<endl;
    }
    
}

int main()
{
       ios_base::sync_with_stdio(false);cin.tie(NULL);
 
        
  #ifndef ONLINE_JUDGE
   freopen("/home/sriram/Coding-files/codeforces/in", "r", stdin);
   freopen("/home/sriram/Coding-files/codeforces/err", "w", stderr);
   freopen("/home/sriram/Coding-files/codeforces/out", "w", stdout);
   #endif

    solve() ; 
}

/*
9 14
0 1 4 
0 7 8 
1 7 11 
1 2 8
2 8 2    
2 5 4  
2 3 7 
3 4 9 
3 5 14
4 5 10
5 6 2
6 8 6 
6 7 1
7 8 7

*/
