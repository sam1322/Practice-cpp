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
#define vp vector<pair<int,int>> 

typedef pair<int,int> pii  ; 
typedef pair<int,pair<int,int>> piii;

struct edge{
    int src , dest ,wt; 
};

class Graph{
    public:
    int N ;
    vector<vector<pair<int,int>>> adj ;
    Graph(vector<edge> edges , int N ){
        vector<pair<int,int>> V ; 
        adj.assign(N,V) ;
        this->N = N ; 
        for(auto &p : edges){
            adj[p.src].push_back(mk(  p.dest , p.wt ) ) ; 
            adj[p.dest].push_back(mk( p.src  , p.wt ) )  ; 
        }
    }
};


// typedef pair<int,pair<int,int>> piii
void prim(vector<vector<pair<int,int>>> &adj, int src,int N) {
    priority_queue<piii, vector<piii> , greater<piii> > q ;
    int minimumcost = 0 ; 
    vector<bool> vis(N) ; 
    vp parents(N) ; 
    parents[src] = {-1,0} ; 
    piii p;

    int x , par,wt,v;
    q.push({0,{src,-1}}) ; 

    while(!q.empty()){
        p = q.top() ;
        q.pop() ;

        x = p.second.first ; //vertex x 
        par = p.second.second; // parent of x 
        wt = p.first ; //weight between parent and x  edge
        
        if(vis[x] )continue ; 
        
        minimumcost += wt; 
        vis[x] = true  ;
        parents[x] = {par,wt} ;  

        for(auto &Y:adj[x]){ 
            wt = Y.second ; 
            v = Y.first ; 
            if(!vis[v]){ //if not visited 
                piii V= { wt , { v , x  } } ; 
                q.push(V) ;
            }
        }   
    }

    cout<<"ind : par : weight\n" ;
    for(int i = 0; i < N ; ++i){
        cout<<i<< "  \t   "<<parents[i].first<<" \t  \t"<<parents[i].second <<endl;
    }
    cout<<"Minimum Cost : "<<minimumcost<<endl;
}


int main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
 
        
  #ifndef ONLINE_JUDGE
   freopen("/home/sriram/Coding-files/codeforces/in", "r", stdin);
   freopen("/home/sriram/Coding-files/codeforces/err", "w", stderr);
   freopen("/home/sriram/Coding-files/codeforces/out", "w", stdout);
   #endif
    vector<edge> edges = { 
        { 0 , 1 , 4 } , 
        { 0 , 7 , 8 } , 
        { 1 , 7 , 11} , 
        { 1 , 2 , 8 } , 
        { 2 , 8 , 2 } , 
        { 2 , 5 , 4 } , 
        { 2 , 3 , 7 } ,  
        { 3 , 4 , 9 } , 
        { 3 , 5 ,14 } , 
        { 4 , 5 ,10 } , 
        { 5 , 6 , 2 } , 
        { 6 , 8 , 6 } , 
        { 6 , 7 , 1 } , 
        { 7 , 8 , 7 }
    } ; 
    int N = 9 ; 
    // int N , E ,src , dest, wt ;

    // cin>>N >>E; 

    // vector<edge> edges; 
    // fr(i,E){
    //     cin>>src >>dest>>wt ;
    //     edges.push_back({src ,dest,wt}) ; 
    // }

    Graph g(edges , N) ; 
    int src= 0; 
    prim(g.adj,src,N) ; 
}

/*

5
7
0 4 7
0 2 6
4 2 11
4 1 3
2 1 1
2 3 4 
1 3 5


*/