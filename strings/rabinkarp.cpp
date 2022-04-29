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
#define d 256 
int rabinkarp(string text , string pat ,int q ){
	// using rolling hash
	if(text.size() < pat.size())return -1 ; 
	int m = pat.size() ;  
	int n = text.size() ; 
	int h = 1 ; // h = d ^ (m -1 )

	int t = 0 , p = 0 ; //t  for text , p for pat ; 
	for(int i = 1 ; i < m ; ++i){
		h=(h*d)%q ;
	}

	//for the first window 

	for(int i = 0 ; i < m ; ++i){
		p = (p*d + pat[i])%q; 
		t = (t*d + text[i])%q;
	} 

	for(int i = 0 ; i <= n-m ; ++i){
		cout<<p<<" "<<t<<endl;
		if(p == t ){
			int j = 0 ; 
			for(j = 0 ; j < m ;++j ){
				cout<<text[i+j]<<" "<<pat[j]<<endl;
				if(text[i+j]!=pat[j]){
					break ;
				}

			}
			// if text[i,i+1,...,i+m]==pat[j,j+1...,m] return i which is the position at which the pattern is found 
			if(j==m)return i ; 
		}

		if ( i < n - m)
		{
			t = (d*(t - h*text[i]) + text[i+m])%q ; 
			if(t < 0 )
				t = t+q ; 
		}

	}

	return - 1 ;

}

string solve(){
	string s , t ,ans ;
	getline(cin>>ws ,t) ;
	getline(cin>>ws ,s) ;
	// cout<<t<<" "<<s<<endl;
	int q = 101 ;
	 q= 5381 ; 
	int pos = rabinkarp(t,s,q);
	if(pos == -1){
		ans = "No match found" ; 
	}
	else{
		ans = "Match found at "+ (to_string(pos)) +" position " ; 

	}
	// cout<<endl;
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