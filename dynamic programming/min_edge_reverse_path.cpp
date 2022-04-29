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

void dijkstra(vector<vector<pair<int,int>>>&adj ,int src,int dest, vector<int> &dist){
    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> >q; 
    q.push({0,src}) ; 
    while(!q.empty()){
        // auto [wt,u] = q.top() ; 
        int wt = q.top().first ;
        int u = q.top().second ; 
        q.pop() ;
        if(wt > dist[u])continue ;
        for(auto V : adj[u])
        {
            // auto [v,Wt] = V ; 
            int v = V.first ; 
            int Wt = V.second ; 
            if(wt + Wt < dist[v]){
                dist[v] = wt + Wt ; 
                q.push({dist[v], v}) ;
            }
        }
    }    
}

int minEdgeReverse(vector<vector<int>> edge , int n ,int src,int dest ){
    vector<vector<pair<int,int>>>adj(n) ; 
    vector<int> dist(n,inf) ;
    dist[src]= 0 ;
    vector<vector<int>>graph(n,vector<int>(n)) ; 
    for(auto e : edge){
        adj[e[0]].pb({e[1],0}) ; 
        graph[e[0]][e[1]] = 1 ; 

    }

    // converting all non existing edges into existing with weight one
    for(int i = 0 ; i < n ;++i ){
        for(pair<int,int> V : adj[i] ) {
            // auto [v,wt] = V ; it may work in c++20
            int v = V.first ; 
            int wt = V.second ; 
            if(!graph[v][i]){
                    adj[v].pb({i,1}) ; 
            }
        }
    }

    dijkstra(adj,src,dest,dist) ;
    
    cout<<"index weight\n";
    for(int i = 0 ;i < dist.size() ; ++i){
        cout<<i<< "\t" <<dist[i]<<endl;
    }
    return dist[dest] ; 
}

int  solve(){
    int n ,e ; 
    // cin>>n>>e;
    vector<vector<int>> edges = {{0, 1}, {2, 1}, {2, 3}, {5, 1},
                     {4, 5}, {6, 4}, {6, 3} };

    int E = 7 ; 
    int src = 0 ,dest =  6 ; 
    // cin>>src>>dest ;
     
    return minEdgeReverse(edges , E,src,dest);                     
    
    
}

int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
     int tc;
    scanf("%d", &tc) ; 
    while(tc--){
        cout<<solve()<<endl;
    }
}
