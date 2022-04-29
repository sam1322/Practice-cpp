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
#define Ios ios::sync_with_stdio(false)
#define Tie cin.tie(0);    cout.setf(ios::fixed); cout.precision(0);
#define inf 0x3f3f3f3f
#define mk make_pair
template<typename T, typename V> inline void mn(T &x, V y) { if(y < x) x = y; }
template<typename T, typename V> inline void mx(T &x, V y) { if(x < y) x = y; }
//const int MAXN = 200100;
typedef long long  ll;
#define vi vector<int>
#define vp vector<pair<int,int>> 
typedef pair<int,int> pii; 

void helper(vector<ll> &A){
	for(auto a : A){
	vector<char>c ;
		do{
				
			 int f = a&1 ;
			c.pb('0' +f) ;
			a>>=1 ;
			
		}while(a) ;
	Show(c)
	cout<<endl ; 
	}
}

void solve(){
	int n , x ; 
	cin>>n>>x; 
	vector<int> V ;
	vector<vi> v(33 ,V) ; 
	vector<vector<char>> ch ; 

	// vi a(n) ; 
	fr(i,n){
		ll a;
		cin>>a;
		int j = 0 ; 
		vector<char>c ;
		while(a){
			if(a&1) {
				v[j].pb(i);
			 }	
			 int f = a&1 ;
			c.pb('0' +f) ;
			a>>=1 ;
			j++ ;
		}
		ch.pb(c) ;

	}	

	for(auto X : ch ){
		Show(X);
		cout<<endl;
	}

	for(int i = 0 ; x > 0 && i < n - 1 ; ++i){
		for(int j = 32 ; x > 0 && j >= 0 ; --j){
			if(v[j].size() > 1 && v[j][0] == i){
				x-- ; 
				v[j].erase(v[j].begin() , v[j].begin() + 2 );

			}
			else if(v[j].size()==1  && v[j][0] == i ){
				x-- ; 	
				v[j][0] = n-1 ; 
			}
		}
	}

	vector<ll> l(n) ; 
	ll power = 1 ;
	for(int i = 0 ; i <	33; ++i ){
		for(int j= 0 ; j < v[i].size() ; ++j){
			l[v[i][j]] += power ; 
		}
		power*=2 ; 
	}	

	if(x>0 && x%2 ){
		l[n-2]^=1 ;
		l[n-1]^=1 ;
	}

	Show(l) ; 
	cout<<endl;
	helper(l);



}

int main()
{
    Ios;
    Tie;
    int tc;
    cin>>tc;
    while(tc--){
    	solve(); 

    }
}

/*
1
10 21
21 4 65 8497 22543 11 323 33 6 101

*/