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
map<string,int> mp;
int maxProfit(vector<vector<int>> &a , int n , int i , int start , int end ){

    string cur = to_string(i) + "$" + to_string(start) + "$" + to_string(end);
    if(mp.count(cur))return mp[cur] ; 
    if( i >= n )return 0 ;
    // cout<<i<< ": " ;Show(a[i]) ;cout<<"Start " <<start<<" End "<<end <<endl; 
    int res = 0 ; 
    if(a[i][0] >=end || a[i][1] <= start ){
        res =  max (a[i][2] + maxProfit(a,n, i + 1, min(start,a[i][0]) , max(end,a[i][1])) , maxProfit(a,n,i+1,start,end) ) ;  
    }
    else res =  maxProfit(a,n,i+1,start,end) ; 
    // cout<<"REs "<<res <<endl;
      return mp[cur] =  res ;      
}

int latestNonConflict(vector<vector<int>> &a,int n ){
    
    for(int i = n - 1 ; i >=0 ; --i){
        if(a[i][1] <= a[n][0] ){
            return i ; 
        }
    }
    return -1 ; 
}

int binarySearch(vector<vector<int>> &a, int n ){
    int low = 0 , high = n -1  ; 
    while(low<= high){
        // int mid = low + (high - low)/2 ;
        int mid = (high + low)/2 ;
                // cout<<low<<" "<<mid<<" "<<high<<endl ; 
        if(a[mid][1] <= a[n][0]){
            if(a[mid+1][1] <= a[n][0]){
                low = mid + 1 ; 
            }
            else{
                return mid ; 
            }
        }
        else{
            high = mid -1 ;
        }
        
    }
    return -1  ;
}

int maxProfit2(vector<vector<int>>&a,int n){
    // sort(a.begin(), a.end() , [](vector<int> const &v1 ,vector<int> const &v2){
    //     if(v1[1] == v2[1]){
    //         return v1[0] < v2[0] ; 
    //     }
    //     return v1[1] < v2[1] ; 
    // });
    vector<int> dp(n+1) ; 

    dp[0] = a[0][2]  ; 
    for(int i = 1 ; i < n ; ++i)
    {
       int prof = a[i][2] ;
    //    int l =  latestNonConflict(a,i); 
        int l = binarySearch(a,i) ;
       if(l!=-1){
           prof +=dp[l] ; 
       }
       dp[i] = max(prof,dp[i-1]) ; 
    }

    // Show(dp); cout<<endl;
    return dp[n-1] ; 
}

int solve(){
    vector<vector<int>> job = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = 4 ;
    sort(job.begin(), job.end() , [](vector<int> const &v1 ,vector<int> const &v2){
        if(v1[1] == v2[1]){
            return v1[0] < v2[0] ; 
        }
        return v1[1] < v2[1] ; 
    });
    // for(auto x : job){
    //     Show(x);
    //     cout<<endl;
    // }
    // return maxProfit(job,n,0,0,0) ; 
    return maxProfit2(job,n)  ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int tc;
    // cin>>tc;
    // // while(tc--){
        cout<<solve()<<endl;
    //  solve();
    // }
}
