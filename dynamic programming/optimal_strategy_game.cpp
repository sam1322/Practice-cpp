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
int N ; 
vector<vector<int> > dp;
int f(vector<int> &a , int i , int j  ){
    
    if(dp[i][j]!=-1)return dp[i][j] ; 
     if(i==j)return a[i];

     if(i+ 1==j)return max(a[i],a[j] ) ;     

   return dp[i][j] =  max( a[i] +min(f(a,i+2 ,j) , f(a,i+1,j-1)) , a[j] +min(f(a,i+1 ,j - 1) , f(a,i,j-2)) )  ;
}

// iterative for the above 

int f(vector<int> &a, int n ){
   dp.assign(n,vector<int>(n)) ;  
   for(int gap = 0 ; gap < n ;++gap){
       for(int i = 0 , j = gap ; j < n ;++j,++i){
           int val ; 
           if(gap==0){
               val = a[i]; 
           }
           else if(gap==1){
               val = max(a[i],a[j]) ; 
           }
           else{
               val = max(a[i] + min(dp[i+1][j-1] , dp[i+2][j] ) ,  a[j] + min(dp[i+1][j-1] , dp[i][j-2])) ; 
           }
        dp[i][j] = val ; 
       }
   }
   return dp[0][n-1] ;
}

int solve(){
    int n ; 
    cin>>n;
    N = n ; 
    vi a(n) ; 
    dp.assign(n+1,vector<int>(n+1,-1)) ;
    fr(i,n)cin>>a[i] ; 
    return f(a,n);
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
4
5 3 7 10
*/