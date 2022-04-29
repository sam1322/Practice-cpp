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

void dfs(vector<vector<int>> &adj  , int u ,vector<int> &disc , vector<int> &low,stack<int> &myStack ,vector<bool> &vis){
    static int time = 0 ; 
    disc[u] = low[u] = time ; 
    time++ ;
    vis[u] = 1 ; 
    myStack.push(u);
    for(int v : adj[u]){
        if(disc[v]==-1){
            dfs(adj,v,disc,low,myStack,vis) ;
            low[u] = min(low[u] , low[v]) ; 
        }
        else if(vis[v]) //back edge 
        {
            low[u] = min(low[u],disc[v]) ; 
        }
        //for cross edge nothing is required to be done
    }
    //head of the scc
    if(low[u]==disc[u]){
        cout<<"SCC is : ";
        while(!myStack.empty() && myStack.top()!= u ){
            cout<<myStack.top()<<" ";
            vis[myStack.top()] = 0 ; 
            myStack.pop() ; 
        }
        if(!myStack.empty()){
            cout<<myStack.top()<<" \n";
            vis[myStack.top() ] = 0 ; 
            myStack.pop() ;
        } 
    }
}

// for directed graph

void Tarjan(vector<vector<int>> &adj,int n ){
    vector<int> disc(n,-1),low(n,-1) ; 
    vector<bool> vis(n) ;
    stack<int> myStack ; 
    for(int i = 0 ; i < n ;++i){
        if(disc[i]==-1){
            dfs(adj,i,disc, low,myStack,vis)  ;
        }
    }
}

void solve(){
    int n , e ; 
    cin>>n>>e ;
    vector<vector<int>> adj(n);
    fr(i,e){
        int a, b;
        cin>>a>>b;
        adj[a].pb(b) ; 
    } 

    Tarjan(adj,n);

}

int main()
{
    // ios_base::sync_with_stdio(false);cin.tie(NULL);
 
        
  #ifndef ONLINE_JUDGE
   freopen("/home/sriram/Coding-files/codeforces/in", "r", stdin);
   freopen("/home/sriram/Coding-files/codeforces/err", "w", stderr);
   freopen("/home/sriram/Coding-files/codeforces/out", "w", stdout);
   #endif
     int tc;
    scanf("%d", &tc) ; 
    while(tc--){
        // cout<<solve()<<endl;
        solve();
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

*/