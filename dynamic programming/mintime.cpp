#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define fr(i,a) for(int  i=0;i<a;i++)
#define forn(i,a,n) for(int i = a; i < n ;i++)
#define Sort(a) sort(a.begin(),a.end())
#define Rev(k)  reverse(k.begin(),k.end())
#define Sz(x) x.size()
#define Show(v) for(int i =0 ; i < v.size();i++) cout<<v[i] <<" ";//only for sting and vector
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
    vector<int> mintime ;
    Graph(vector<Edge> &edge,int n){
        adj.resize(n) ;
        mintime.resize(n);
        for(auto &i : edge){
            adj[i.src].pb(i.dest) ;
            // adj[i.dest].pb(i.src) ;
        } 
    }  
};
 
//using kahn algorithm
void Kahn(Graph &g,int n){
    vector<int> indegree(n) ; 
    g.mintime.resize(n);
    for(int i = 0 ;i < n ;++i)
    {
        for(auto u:g.adj[i]){
            indegree[u]++;
        }
    }

    queue<int> q;

    for(int i = 0 ; i < n ;++i){
        if(!indegree[i]){
            g.mintime[i] = 1;
            q.push(i) ;
        }
    }   

    while(!q.empty()){
        int cur = q.front() ; 
        q.pop() ;

        for(auto u : g.adj[cur]){
            indegree[u]--;
            if(indegree[u]==0){
                g.mintime[u] = g.mintime[cur] + 1 ;
                q.push(u) ;
            }

        }

    } 
}

int main()
{
    Ios;
    Tie;
    vector<Edge> edge = {
        { 1, 2} , {2,3 }, {1,3} , {3,4}
    } ;
    vector<Edge> edge2 = {
        {1,3},{1,4},{1,5},
        {2,3},{2,8},{2,9},
        {3,6},
        {4,6},{4,8},
        {5,8},
        {6,7},
        {7,8},
        {8,10}
    };
    // int n = 5 ;
    int n= 11 ;
    Graph graph(edge2 ,n) ; 
    vector<bool> vis(n,0) ;

    Kahn(graph,n) ;

    Show(graph.mintime);
    cout<<endl;
}
