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

string solve(){
int n ; 
cin>> n; 
string a ; 
cin>>a ;
	vector<char> ch = {'t' ,'r','y','g','u','b'} ;
	int j = 0  , pos = 0 ; 
	fr(i,a.size()){
		if( j < ch.size() && a[i] == ch[j]){
			j++;

		}
		if(j == ch.size()){
			while(a[pos]==ch.back()){
				pos++;
			}
			swap(a[pos] , a[i]) ;
			pos++ ;  
			j--;
		}
	}
	return a ; 
	
}

int main()
{
    Ios;
    Tie;
    int tc;
    cin>>tc;
    while(tc--){
    	cout<<solve()<<endl;
    }
}