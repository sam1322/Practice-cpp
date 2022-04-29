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
// vector<vector<int>> dp ; 
// int  count_allpal_seq(string &x, int i , int j ){
//     if(dp[i][j]!=-1)return dp[i][j] ; 
//     if(i > j )return 0 ; 
//     if(i==j)return 1 ;
//     int res = 0 ; 
//     if(x[i]==x[j]){
//         res =1 + count_allpal_seq(x,i+1,j)  +  count_allpal_seq(x,i,j-1) ;  
//     }
//     else{
//         res = count_allpal_seq(x,i,j-1) + count_allpal_seq(x,i+1,j) - count_allpal_seq(x,i+1,j-1) ;
//     }
//     dp[i][j] = res ; 
//     return res ;
// }


    int  mod = 1000000007;

    /*You are required to complete below method */
    vector<vector<long long int>> dp ; 
long long int  count_allpal_seq(string &x, int i , int j ){
    if(dp[i][j]!=-1)return dp[i][j] ; 
    if(i > j )return 0 ; 
    if(i==j)return 1 ;
    long long int res = 0 ; 
    if(x[i]==x[j]){
        res =( 1 + count_allpal_seq(x,i+1,j) +  count_allpal_seq(x,i,j-1)) %mod;  
    }
    else{
        res =(((count_allpal_seq(x,i,j-1) + count_allpal_seq(x,i+1,j) )%mod - count_allpal_seq(x,i+1,j-1) ) %mod  + mod )%mod ;
    }
    dp[i][j] = res ; 
    return res ;
}

    long long int  countPS(string x)
    {
        dp.assign(x.size()+1 , vector<long long int>(x.size()+1,-1) ) ; 
       return count_allpal_seq(x,0,x.size() - 1) ; 
    }

    long long int countPSinDp(string x){
        dp.assign(x.size()+1 , vector<long long int>(x.size()+1,0) ) ; 
        int n = x.size() ; 
        for(int L = 2 ; L <= n ; ++L){
            for(int i = 0 ; i <= n - L ; ++i ){
                int j = L + i - 1  ;
                if(x[i] == x[j]){
                    dp[i][j] = (dp[i][j-1] + dp[i-1][j]  + 1) %Mod; 
                }
                else{
                    dp[i][j] =(((dp[i][j-1] + dp[i-1][j])%mod - dp[i-1][j-1] ) %mod + mod ) %mod ; 
                }
            }
        }
        return dp[0][n-1] ;
    }

int solve(){
    string x ; 
    cin>>x ;
    // dp.assign(x.size()+1 , vector<int>(x.size()+1,-1) ) ; 
    // return  count_allpal_seq(x,0,x.size() - 1 ) ; 
    return countPSinDp(x) ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
        cout<<solve()<<endl;
    //  solve();
}
