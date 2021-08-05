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
#define vl vector<ll>
#define vp vector<pair<int,int>> 
typedef pair<int,int> pii; 
// sieve , binomial coeff , pascal 

int binarysearch(vi &a,int start ,int end ,int target){
	if(start>=end)
		return -1 ;

	int mid = start + (end - start)/2 ; 
	if(a[mid]==target)
		return mid  ; 
	else if(a[mid] < target) {
		return binarysearch(a,mid+1,end,target) ;
	}
	else return binarysearch(a,start,mid,target) ; 
}

int Binarysearch(vi &a,int start ,int end ,int target){
	int mid ; 
	while(start < end){
		mid = start + (end - start )/2 ;
		if(a[mid]==target)
		return mid  ; 
		else if(a[mid] < target) {
			start = mid + 1; 
		}
		else end = mid ; 
	}
	return -1; 
}

//int solve(){
void solve(){
	int n , target ; 
	cin>>n >>target;
	vi a(n); 
	fr(i,n)cin>>a[i] ; 

	printf("position of %d is %d \n",target,Binarysearch(a,0,a.size(),target)) ;
}

int main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
 
    
   #ifndef ONLINE_JUDGE
   freopen("/home/sriram/Coding-files/codeforces/input.txt", "r", stdin);
   // freopen("input.txt", "r", stdin);
   freopen("/home/sriram/Coding-files/codeforces/error.txt", "w", stderr);
   // freopen("output.txt", "w", stdout);
   freopen("/home/sriram/Coding-files/codeforces/output.txt", "w", stdout);
   #endif

    int tc;
    //scanf("%d", &tc) ; 
    cin>>tc; 

    while(tc--){
    	//cout<<solve()<<endl;
      solve();
      //cout<<endl;
    }
}