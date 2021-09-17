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


	void heapify2(vi &v , int i , int n {
		int  left,right;
		left = 2*i+1 ; 
		right= 2*i + 2 ; 
		while(left < n){
			int max = left ;
			if(right < n && v[right] > v[left]) {
				max = right ; 
			}
			if(v[i] <= v[max]){
				swap(v[i] , v[max]) ;
				i = max ; 
			}
			else{
				break ; 
			}
			left = 2*i+1 ; 
			right= 2*i + 2 ; 
		}

	}

void heapify1(vi &v , int i , int n{
		int left,right;
		left = 2*i+1 ; 
		right= 2*i + 2 ; 
		if(left < n ){
			int max = left ;
			if(right < n && v[right] > v[left]) {
				max = right ; 
			}
			if(v[i] < v[max]){
				swap(v[i] , v[max]) ;
				i = max ; 
			}
			 
		heapify1(v, max , n  ) ; 

		}
	}

void heapify(vi &v,int i, int n  ){
		int left , right , max = i ; 
		left = 2*i +1;
		right = 2*i + 2 ;
		if(left < n && v[left] > v[max])
			max = left ;
		if(right < n && v[right] > v[max])
			max = right ;
		
		if(max!=i)
		{
			swap(v[max],v[i]) ; 
			heapify(v, max , n  ) ; 
		}
}

void heapsort(vi &a){
	int n = a.size() ; 
	for(int i = n/2 - 1 ; i >= 0 ; --i){
		// heapify(a,i,n) ;
		heapify(a,i,a.size()) ;
		// heapify2(a,i ,n) ;
		Show(a);
		cout<<endl;
	}

	for(int i = n-1 ; i >0 ;--i ){
		swap(a[0] , a[i]);
		// heapify2(a,0,i) ;
		heapify(a,0, i);	
		Show(a);cout<<endl;	
	}
}

int main()
{
  
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("error.txt", "w", stderr);
   freopen("output.txt", "w", stdout);
   #endif 
    vector<int> v = {10 , 1 , 0 , 2 , 3 , 45 ,3, 4 ,1 } ; 
   	heapsort(v) ;
   	Show(v) ; 
   	cout<<endl;
}