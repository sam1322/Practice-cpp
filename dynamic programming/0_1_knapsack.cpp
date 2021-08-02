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
int M  = 0 ; 

void knapsack(vi &wt , vi &val ,int W, int n , int cur){
	if(M<cur)M = cur ;
	cout<<wt[n-1]<<" "<<val[n-1]<<" "<<W<< " "<<n<<" "<<cur<<endl; 
	if(n<=0)return  ;

	if(W<=0)return ;

	if(wt[n-1] <= W){
		knapsack(wt,val, W - wt[n-1], n-1,cur+val[n-1])  ;
	}
		knapsack(wt,val, W, n-1,cur)  ;



}

int knapsack(vi &wt,vi &val ,int W,int n,vector<vector<int>> &dp ){
	if(n<=0||W<=0) return 0 ; 

	if(dp[W][n] !=-1)return dp[W][n]  ;

	if(wt[n - 1 ] > W){

		dp[W][n] = knapsack(wt,val,W,n-1,dp) ;

	}
	else{
		dp[W][n] = max(val[n-1] + knapsack(wt,val ,W - wt[n-1],n-1,dp) , knapsack(wt,val,W,n-1,dp)) ; 
	}

	return dp[W][n] ;
}

int knapsack(vi &wt ,vi &val ,int W ,int n){
	vector<int> V(n+1,0 );
	vector<vector<int>> dp(W+1,V) ;

	for(int i = 1; i <=W ; ++i){
		for(int j = 1 ; j <=n ;++j ){
			if(wt[j-1]>i){
				dp[i][j] = dp[i][j-1];
			}
			else dp[i][j] = max(dp[i - wt[j-1]][j - 1] + val[j-1] , dp[i][j-1]) ; 
		}
	}
	return dp[W][n] ; 
}

int main()
{
    Ios;
    Tie;
    
    M = 0 ;
    int n , W; 
    cin>>n >> W ;  
    vi wt(n) , val(n);
    fr(i,n)cin>>wt[i] ;
    fr(i,n)cin>>val[i]  ; 
    // vi V()
    // vector<int> V(n+1,-1);
    // vector<vector<int>> dp(W+1,V) ; 
// cout<<	knapsack(wt , val , W, n ,dp) <<endl; 
cout<<	knapsack(wt , val , W, n ) <<endl; 

    // cout<<M<<endl;
}