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

int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        vector<vector<int>> v(W+1,vector<int>(N+1, INT_MAX)) ; 
        for(int i = 1 ; i <=N ; ++i){
            if(cost[i-1]!=-1)v[0][i] = 0 ; 
        }
        for(int i = 1 ; i <= W ; ++i ){
            for(int j = 1 ; j <= N ; ++j){
                if(cost[j-1]!=-1 && i >= j && v[i - j][j]!=INT_MAX){
                     v[i][j] = min(v[i][j-1] ,v[i - j ][j] + cost[j-1]  ) ;  
                }
                else{
                    v[i][j] = min(v[i][j-1],v[i][j]) ; 
                    
                }
            }
        }
        int m= INT_MAX ; 
        for(int i = 1 ; i <= N ; ++i){
            if(v[W][i]!=-1){
                m = min(m , v[W][i]) ;
            }
        }
        if( m!=INT_MAX){
            return m ;
        }
        return -1 ;
	}
int solve(){
    int n  , w  ;
    cin>>n>>w;
    int a[n] ;
    fr(i,n)cin>>a[i] ; 
    return minimumCost(a,n,w) ; 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin>>tc;
    while(tc--){
        cout<<solve()<<endl;
    //  solve();
    }
}

/*
2
5 5 
20 10 4 50 100
5 5 
-1 -1 4 3 -1

*/