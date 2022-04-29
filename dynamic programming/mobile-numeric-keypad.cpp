#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define fr(i,a) for(long long  i=0;i<a;i++)
#define forn(i,a,n) for(long long i = a; i < n ;i++)
#define Sort(a) sort(a.begin(),a.end())
#define Rev(k)  reverse(k.begin(),k.end())
#define Sz(x) x.size()
#define Show(v) for(long long i =0 ; i < v.size();i++) cout<<v[i]<<" "; //only for strings and vector
#define Mod 1000000007
#define Fi first
#define Sc second
#define pb push_back
#define Ios ios::sync_with_stdio(false);cin.tie(0);cout.setf(ios::fixed); cout.precision(0);
#define inf 0x3f3f3f3f
#define mk make_pair
template<typename T, typename V> inline void mn(T &x, V y) { if(y < x) x = y; }
template<typename T, typename V> inline void mx(T &x, V y) { if(x < y) x = y; }
//const long long MAXN = 200100;
typedef long long  ll;
#define vi vector<long long>
#define vp vector<pair<long long,long long>> 
typedef pair<long long,long long> pii; 
// sieve , binomial coeff , pascal 
// class Compare{
//     public:
//     bool operator() (foo,foo){
//         return expression
//     }
// };

vector<long long> x = {0,-1 , 0 , 0 , 1 } ;
vector<long long> y = {0, 0 ,-1 , 1 , 0 } ;


long long dfs(vector<vector<long long>> &adj , long long i , long long n )
{
    if(n==1)return 10 ; 
    long long res = 0 ;

    for(auto x:adj[i]){
        res+=dfs(adj,x,n-1) ; 
    }
    return res ;
}
vector<vector<long long>>dp;
long long f(vector<vector<char>> &a ,long long i ,long long j ,long long n  ){
    if(dp[a[i][j] - '0'][n]!=-1)
        return dp[a[i][j] - '0'][n] ; 

    if(n<=0)return 0 ;
    if(n==1)return 1 ;
    long long ans = 0 ;
    for(long long k = 0 ; k < 5 ;++k){
        long long l = i + x[k] ;
        long long m = j + y[k] ; 
        if(l>=0&&l<4 && m>=0 && m<3 && a[l][m]!='*' && a[l][m]!='#'){
            long long z =f(a,l,m,n-1);
            ans+=z;
            // cout<<a[l][m]<<" "<<z<<" "<<ans<<endl;
        }
    }
    return dp[a[i][j] - '0'][n]=ans ; 
}

long long dfs(vector<vector<char>> &a, long long n ){
    if(n<=0)return 0 ; 
    if(n==1)return 10 ;
    dp.assign(10,vector<long long>(n+1,-1));
    long long ans = 0 , i = 0 , j = 0 ; 
    for( i = 0 ; i < 4 ; ++i){
        for( j =0  ; j < 3 ; ++j ){
            if(a[i][j]!='*'&&a[i][j]!='#'){
                ans+=f(a,i,j,n);
            }
        }
    }
    return ans ; 
}


long long solve(){
    long long n ; 
    cin >> n; 
    // vector<vector<long long>> adj = {
    //     {0,8} ,
    //     {1,2,4} ,
    //     {2,1,3,4}, 
    //     {3,2,6},
    //     {4,1,5,7} , 
    //     {5,2,4,6,8}, 
    //     {6,3,5,9},
    //     {7,4,8},
    //     {8,5,7,9,0},
    //     {9,6,8} 
    // };

    vector<vector<char>> keypad = {
        {'1','2','3'} , 
        {'4','5','6'} , 
        {'7','8','9'} , 
        {'*','0','#'} , 
    };
    
    return dfs(keypad,n) ;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tc;
    cin>>tc;
    while(tc--){
        cout<<solve()<<endl;
    //  solve();
    }
}
