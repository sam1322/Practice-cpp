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
void MinVertexCover(vector<vector<int>>&adj, int n ){
    vector<bool> vis(n) ;
    fr(i,n){
        if(!vis[i]){

        }
    }
    // I feel kinda lazy fro this but the main  logic for this is to find the maximum degree of vertex and include that vertex in the  soln and reduce the degree of all those vertex which are connected to the v of the vertex or somehting like that
}
int solve(){
    int n , e  ;
    cin>>n>>e; 
    vector<vector<int>> adj(n) ; 
    fr(i,e){
        int f ,s ;
        cin>>f>>s ;
        adj[f].pb(s) ; 
        adj[s].pb(f) ; 
    }
    MinVertexCover(adj,n) ; 
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
