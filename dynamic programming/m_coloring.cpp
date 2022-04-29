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
 bool safe(vector<vector<int>> &graph,vector<int>&col,int V,int v,int c){
     for(int i = 0 ; i < V; i++){
         if(col[i]==col[v] && graph[v][i]){
             return 0 ;
         }
     }
     return true ; 
 }
 
 bool soln(vector<vector<int>> &graph,vector<int>&col , vector<vector<int>> &vis,int m ,int V ,int v ){
     if(v == V ){
         return true ;
     }
     for(int i = 0 ; i < m ; ++i){
         if(safe(graph,col,V,v,i)){
             col[v] = i ; 
            
            if(soln(graph,col,vis,m,V,v+1)){
                return true ; 
            }
         }
     }
     return false; 
 }

bool graphColoring(vector<vector<int>>graph, int m, int V) {
    // your code here
    vector<vector<int>> vis(V,vector<int>(V)) ;
    vector<int> color(V,-1) ; 

    return soln(graph,color,vis,m,V,0) ; 
    
}


int solve(){
    int n , m ,e ; 
    cin>>n>> m>>e; 
    int i ; 
    vector<vector<int>> graph(n,vector<int>(n)) ; 
    fr(i,e){
        int a, b ; 
        cin>>a>>b; 
        graph[a-1][b-1] = graph[b-1][a-1] = 1 ;

    }
    cout<<graphColoring(graph,m,n)<<endl;
    return 0 ;
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
