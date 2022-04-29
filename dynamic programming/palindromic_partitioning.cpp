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
vector<vector<int>>dp;

bool pal(string &s , int i ,int j ){
    while(i <= j ){
        if(s[i]!=s[j]){
            return 0 ; 
        }
        ++i ;
        --j; 
    } 
    return 1 ; 
}

int pp(string &s,int i , int j ){
    if(dp[i][j]!=-1)return dp[i][j] ; 
    if((i>=j)||(pal(s,i,j))){
        dp[i][j] = 0 ; 
        return 0 ; 
    }
    int ans = INT_MAX ; 
    for(int k = i ; k <= j ;++k){
        if( pal(s,i,k) ){
            ans = min(ans , 1 + pp(s,k+1,j)) ; 
        }
        // cout<<ans<<endl;
    }
    return dp[i][j] = ans ;
}

int solve(){
    string s ;
    cin>>s ;
    int n = s.size() ; 
    dp.assign(n+1,vector<int>(n+1,-1));
    return pp(s,0,n-1) ; 
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
ababbbabbababa

*/