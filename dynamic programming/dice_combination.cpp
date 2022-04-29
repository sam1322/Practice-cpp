#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define fr(i,a) for(int  i=0;i<a;i++)
#define forn(i,a,n) for(int i = a; i < n ;i++)
#define Sort(a) sort(a.begin(),a.end())
#define Rev(k)  reverse(k.begin(),k.end())
#define Sz(x) x.size()
#define Show(v) for(int i =0 ; i < v.size();i++) cout<<v[i] //only for sting and vector
#define Mod 1000000007
#define Fi first
#define Sc second
#define pb push_back
#define Ios ios::sync_with_stdio(false)
#define Tie cin.tie(0);    cout.setf(ios::fixed); cout.precision(0);
#define inf 0x3f3f3f3f
#define mk make_pair
template<typename T, typename V> inline void mn(T &x, V y) { if(y < x) x = y; }
template<typename T, typename V> inline void mx(T &x, V y) { if(x < y) x = y; }
//const int MAXN = 200100;
typedef long long  ll;
#define vi vector<int>
    // vector<vector<int>> dp ; 

int solve(int d,int f, int target,vector<vector<int>> &dp){
    // cout<<d<< " " <<f<<" "<<target<<endl;
    if(dp[d][target]!=-1)return dp[d][target] ;  
    
    if(d==1){
        if(target==0)
            return 0 ; 
        if(target<=f)
            return 1 ;
        return 0;

    }
        int total = 0 ; 
   
        for(int i =1 ;i<=f;i++){
            int l = solve(1 ,f , i ,dp) ;
            int r = (target>i)?solve(d-1,f,target-i,dp):0;
            total +=(l*r)%Mod ; 
            total%=Mod ; 
        }
        dp[d][target] = total ; 
        return total ;      
}

int main()
{
    Ios;
    Tie;
    int d,f ,target ; 
    cin>>d>>f>>target ; 
    vector<int> D(max(target,f)+1,-1) ;
    // dp.assign(d+1,D) ; 
    vector<vector<int>>dp(d+1 , D) ; 
    // for(int  i = 0 ;i<=d ;i++){
    //     for(int j = 0 ; j <=max(target,f) ; j++){
    //         cout<<dp[i][j]<<" " ;
    //     }
    //     cout<<endl;
    // }
    cout<<solve(d,f,target,dp) ; 

}
