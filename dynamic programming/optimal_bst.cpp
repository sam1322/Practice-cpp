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

int optCost(vector<int> &prefix , int i , int j  ){

    if(i > j )return 0 ; 

    if(i==j)return prefix[i] - prefix[i-1] ; 
    int Min = INT_MAX ; 
    for(int k = i ; k <= j ;++k){
        Min = min(Min , optCost(prefix,i,k-1) + optCost(prefix , k+1 , j)) ; 
    }
    return prefix[j] - prefix[i-1] + Min ;  

}

//iteration 
int optCost(vector<int> &prefix , int n ){

    vector<vector<int>> dp(n+1,vector<int>(n+1)) ; 

    for(int i = 0 ; i  < n ;++i){
        dp[i][i]  = prefix[i+1] - prefix[i] ; 
    }

    for(int L = 2 ; L <= n ; L++){
        for(int i = 0 ; i <= n - L + 1 ; ++i){
            int j = i+L - 1 ;
            for(int k = i ;  k <= j ; ++k){
                int c = ( (i < k )? dp[i][k-1] : 0  + ( k < j )?dp[k+1][j] : 0 ) + prefix[j+1] - prefix[i];
                if(c < dp[i][j]){
                    dp[i][j] = c ;
                }
            }
        }
    }

    return dp[1][n] ; 

}

int solve(){
    int n ; 
    cin>>n ; 
    vi keys(n) ; 
    vi freq(n) ;

    fr(i,n)cin>>keys[i] ; 
    fr(i,n) cin>>freq[i] ; 
    vi prefix(n+1) ; 
    for(int i = 1; i <= n ; ++i){
        prefix[i] = prefix[i-1] + freq[i-1] ; 
    }
    // return optCost(prefix , 1, n )  ;
    return optCost(prefix ,  n )  ;

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
1
3
10 12 20
34 8 50

*/
