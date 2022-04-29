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

 
 
vector<long long> printFirstNegativeInteger(long long int A[],  long long int N, long long int K) {
           
    vector<pair<ll,ll>> v ;
    for(int i = N-1 ;i >=0 ;++i){
        if(A[i]<0){
            v.push_back({i,A[i]}) ; 
        }
        
    }
    vector<ll> ans(N-K); 
    ll i = 0 , r ; 
    for( ; i <= N - K ;++i){
        r = i + K - 1 ;
        while(!v.empty() && v.back().first < i){
            v.pop_back() ; 
        }
        if(!v.empty() && v.back().first <=r &&v.back().first>=i){
            ans[v.back().second]  ;
        } 
    }
    return ans ;
                                                 
 }

int solve(){
  long long int n ,k;
    cin>>n;
    long long int a[n];
    fr(i,n)cin>>a[i];
    cin>>k;
    // vector<ll> v = printFirstNegativeInteger(a,n,k);
    // Show(v);;
    cout<<endl;
    return 0;
}

int main()
{
     int tc;
    scanf("%d", &tc) ; 
    while(tc--){
        cout<<solve()<<endl;
    }
}

/*
5
-8 2 3 -6 10
2
*/