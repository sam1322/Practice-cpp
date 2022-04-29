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
int Time = 0 ;
vector<int> Start ; 
vector<int> End;
void dfs(vector<vector<int>>&adj,vector<bool>&vis, int src) {
    // static int time = 0 ;
    vis[src] = 1 ; 
    Start[src] = Time++ ; 
    for(auto v : adj[src]){
        if(!vis[v]){
            dfs(adj,vis,v) ; 
        }
    }
    End[src] = Time++ ;
}
bool check(int x ,int y){
    return (Start[x] < Start[y] && End[x] > End[y]) ;  
}
int main()
{ios::sync_with_stdio(false);cin.tie(0);
    int n ,f,s;
    cin>>n;
    vector<vector<int>> v(n+1); 
    fr(i,n-1){
        cin>>f>>s;
        v[f].pb(s) ; 
        v[s].pb(f) ; 
    }
    Start.assign(n+1,0) ; 
    End.assign(n+1,0); 
    vector<bool> vis(n+1) ; 
    dfs(v,vis,1) ; 
    int q ; 
    cin>>q; 
    while(q--){
        int c , x , y , f = 0 ; 
        cin>>c>>x>>y ; 
        if(!c){
            f = check(x,y); 
        }
        else{
                f = check(y, x)  ;
        }
        if(f){
            cout<<"YES" ;
        }
        else{
            cout<<"NO" ;
        }
        cout<<endl;
    }    
}


/*
9
1 2
1 3
2 6
2 7
6 9
7 8
3 4
3 5
5
0 2 8
1 2 8
1 6 5
0 6 5
1 9 1
*/
