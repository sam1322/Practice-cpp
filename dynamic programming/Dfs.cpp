#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define fr(i,a) for(int  i=0;i<a;i++)
#define forn(i,a,n) for(int i = a; i < n ;i++)
#define Sort(a) sort(a.begin(),a.end())
#define Rev(k)  reverse(k.begin(),k.end())
#define Sz(x) x.size()
#define Show(v) for(int i =0 ; i < v.size();i++) cout<<v[i] //only for sting and vector
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

struct edges{
    int src , dest ; 
};

class Graph{
    public:
    vector<vector<int>> adj; 

    Graph(vector<edges> &edge,int n){
        adj.resize(n) ;

        for(auto &i : edge){
            adj[i.src].pb(i.dest) ;
            adj[i.dest].pb(i.src) ;
        } 
    }  


};


void DFS(Graph const &graph , int v ,vector<bool>&vis){
        
        vis[v] = 1 ;
        cout<<v<<" ";

        for(int u : graph.adj[v])  
        {
            if(!vis[u]){
                DFS(graph ,u , vis) ;
            }
        }

    } 




int main()
{
    Ios;
    Tie;
    vector<edges> edge = {
        { 1, 2} , {2,3 }, {1,3} , {3,0}, {0,4}
    } ;

    int n = 5 ;

    vector<edges> edge2 = {
        {1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
		{3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}
    } ;
    int N= 13 ;

    Graph graph(edge2 ,N) ; 
    
    vector<bool> vis(n,0) ;

    int v = 1 ;
    cout<<"New Start :" <<v<<endl,DFS(graph ,v , vis) ,cout<<endl;
    
}
