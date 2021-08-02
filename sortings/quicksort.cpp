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

int  partition(vi &a , int start ,int end ){
	//using starting position as  pivot point 
	int pivotpos = start ;
	int pivot = a[pivotpos]  ,count = 0 ; 
	for (int i = start ; i < end; ++i)
	{
		if(i==pivotpos)continue ;

		if(a[i] < pivot )
			count++ ;
	}

	swap(a[pivotpos] , a[start+count ]) ; 

	pivotpos = start + count ; 

	int leftIndex = start , rightIndex = end - 1 ; 
	while(leftIndex < pivotpos && pivotpos < rightIndex ){
		if(a[rightIndex] < pivot && a[leftIndex ]>=pivot ){
			swap(a[rightIndex],a[leftIndex]) ; 
			rightIndex--; 
			leftIndex++ ; 
		}	
		if(a[rightIndex] >= pivot)rightIndex--; 
		if(a[leftIndex] < pivot )leftIndex++; 
	}
	return pivotpos ; 
}

void quicksort(vi &arr , int start ,int end ){
	if( start + 1>=end)return ; 

	int pos = partition(arr , start,end) ; 

	quicksort(arr,start , pos );
	quicksort(arr, pos + 1 ,end );

}

//int solve(){
void solve(){
	int n ;
	cin>>n ;
	vi a(n) ; 
	fr(i,n)cin>>a[i]; 
	quicksort(a,0,a.size()) ; 
	Show(a);cout<<endl;
}

int main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
 
    
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("error.txt", "w", stderr);
   freopen("output.txt", "w", stdout);
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