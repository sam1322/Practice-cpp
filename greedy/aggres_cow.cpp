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
#define Ios ios::sync_with_stdio(false);cin.tie(0);
#define inf 0x3f3f3f3f
#define mk make_pair
template<typename T, typename V> inline void mn(T &x, V y) { if(y < x) x = y; }
template<typename T, typename V> inline void mx(T &x, V y) { if(x < y) x = y; }
//const int MAXN = 200100;
typedef long long  ll;
#define vi vector<int>
#define vp vector<pair<int,int>> 
typedef pair<int,int> pii; 

bool check(int c,vi a , int x){
	int ctr = 1 , prev = a[0] ; 
	for(int i = 1 ; i < a.size() ; ++i){
		if(a[i] - prev>=x){
			if(++ctr==c){
				return 1 ;
			}
			prev = a[i] ; 
		}
	}
	return 0 ; 
}

int solve(){
	int n , c  ; 
	cin>>n>>c ;
	vi a(n) ;
	fr(i,n)cin>>a[i] ; 

	Sort(a) ; 

	int low = 0  , high = 1000000000 ;
	int ans = 0 ; 
	while(low<=high){
		int mid = low + (high - low)/2  ;
		if(check(c,a,mid)){
			ans = max(ans , mid) ; 
			low = mid+1; 
		}
		else{
			high = mid - 1 ; 
		}

	}
	return ans ;

}

int main()
{
     int tc;
    scanf("%d", &tc) ; 
    while(tc--){
    	cout<<solve()<<endl;
    }
}