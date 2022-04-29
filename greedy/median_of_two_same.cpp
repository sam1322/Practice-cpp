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
//for equal size 
int solve(vector<int>&a ,vector<int> &b){
	int n = a.size() , m = b.size() ; 
	int bcount = 0 , acount = 0 , x,y,l = 0 , r = n    , lefthalf = (n + m + 1)/2 ; 

//	n <= m 
	while( l <= r ){
		acount =  l + ((r - l )/2 )  ;
		bcount = lefthalf - acount ;
		// x = a[acount - 1] ; 
		// y = b[bcount - 1]
		// x1 = a[acount] ; 
		// y1 = b[bcount] ; 

		// median if y < x <= y1 || x < y <= x1 

		if(acount > 0 && a[acount - 1 ] > b[bcount] ){
			r = acount - 1 ; 
		}
		else if(acount < n && b[bcount - 1 ] > a[acount]){
			l = acount + 1 ;
		}
		else {
			// if everything is not satisfied then we are in endgame
			//for odd 
			// if acount doesn't contribute or  it is 0
			int leftHalfEnd  ;
			if(acount==0){
				leftHalfEnd = b[bcount - 1] ;
			} 
			else if(bcount == 0 ){
				leftHalfEnd = a[acount - 1];
			}
			else{
				leftHalfEnd = max(a[acount - 1] ,b[bcount - 1] ) ; 
			}

			if((n+m)%2){
				return leftHalfEnd ; 
			}

			// if n + m is even 

			int rightHalfEnd ; 

			if(acount>n){
				rightHalfEnd = b[bcount]; 
			}
			else if(bcount >m){
				rightHalfEnd = a[acount]; 
			}
			else {
				rightHalfEnd = min( a[acount], b[bcount]) ; 
			}

			return (leftHalfEnd + rightHalfEnd ) / 2.0 ; 

		}
	}
return -1 ; 

}

int main()
{
     int tc;
    scanf("%d", &tc) ; 
    while(tc--){
   		int n , m  ; 
		cin>>n >>m ; 
		vi a(n) , b(m) ; 
		
		fr(i,n)cin>>a[i] ; 
		fr(i,m)cin>>b[i]; 
		if(a.size() < b.size())
    		cout<<solve(a,b)<<endl;
    	else{
    		cout<<solve(b,a)<<endl;
    	}
    }
}