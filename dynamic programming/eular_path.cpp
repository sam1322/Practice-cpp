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
void dfs(vector<vector<int>>&adj ,int u){
    
    for(int j = 0 ;j < adj[u].size();++j){
        int v = adj[u][j];
        if(v!=-1){
            cout<<u<<" -> "<<v<<endl;
            fr(i,adj[v].size()){
                if(adj[v][i]==u){
                    adj[v][i] = -1; 
                }
            }
            adj[u][j] = -1 ;
            dfs(adj,v) ;
        }
    }

}

int solve(){
    int n , e ,odd =-1 ;
    cin>>n>>e; 
    vector<vector<int>> adj(n) ;
    vector<int> degree(n) ; 
    fr(i,e)
    {
        int f , s ;
        cin>>f>>s;
        adj[f].pb(s) ;
        adj[s].pb(f) ;
        degree[f]++;
        degree[s]++;
    }

    int odddegree = 0  ;
    fr(i,n){
        if(degree[i]%2){odddegree++;
        odd = i ; 
    }
    }
    if(odddegree>2){
        cout<<"No eular path possible";
    }
    else{
        // cout<<odd<<endl;
        if(odd==-1)odd= 0 ; 
        dfs(adj,odd);
    }
    
    return 0;
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


/*
2
4 4
0 1
0 2
1 2
2 3

*/