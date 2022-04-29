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

void dfs(vector<vector<int>> &adj ,vector<bool> &vis,vector<int> &st,int v)
{
    vis[v] = 1 ;
    // cout<<v<<" ";

    for(int u : adj[v])  
    {
        if(!vis[u]){
            dfs(adj , vis,st,u) ;
        }
    }
    st.push_back(v) ; 

}

void dfs(vector<vector<int>> &adj ,vector<bool> &vis,int v)
{
    vis[v] = 1; 
    for(int u : adj[v])  
    {
        if(!vis[u]){
            dfs(adj , vis,u) ;
        }
    }
}

vector<vector<int>> reverse(vector<vector<int>> &adj ,int n ){
    vector<vector<int>>rev(n) ;
    for(int i = 0 ; i < n ; i++){
        for( auto u : adj[i]){  
            rev[u].pb(i) ; 
        }
    }
    return rev ;
}

int countScc(vector<vector<int>> &adj,int n ){
    //first dfs and push all the nodes in a stack
    //then transpose or reverse the edges 
    // then repeat dfs and find the scc and pop the stack as you execute dfs for each and every node in the stack

    //1. dfs and stack
    vector<int> st; 
    vector<bool> vis(n) ;
    fr(i,n){
        if(!vis[i]){
            dfs(adj,vis,st,i);
        }
    }
    // reverse the edges 
    adj = reverse(adj,n) ; 

    int sum = 0 ;
    vis.assign(n,0);
    while(!st.empty()){
        int i = st.back() ; 
        if(!vis[i]){
            sum++;
            dfs(adj,vis,i);
        }
        st.pop_back();
        
    }

    printf("Total there are %d strongly connected components\n ",sum); 
    return sum ; 
}

int solve(){
    int n , e; 
    cin>>n>>e;
    vector<vector<int>> adj(n) ; 
    fr(i,e){
        int x,y ;
        cin>>x>>y; 
        adj[x].pb(y) ; 
    }
    
    return countScc(adj,n) ;
    }

int main()
{
     int tc;
    scanf("%d", &tc) ; 
    while(tc--){
        cout<<solve()<<endl;
    }
}


/*
1
8 10
0 1
1 2
2 0
2 3
3 4
4 5
4 7
5 6
6 4
6 7

*/