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

class minheap{
	public:
	vector<int> v ; 
 
	minheap(){
 		; 
	}
	minheap(vector<int> arr){
		for(auto x:arr){
			insert(x) ;
		}
	}
	void Print(){
		Show(v) ;
		cout<<endl;
	}


	void sift_up(int i){
		int par = (i-1) /2 ;

		while( par>=0 ){
			if(v[par] > v[i]){
				swap(v[par] , v[i]) ; 
			}
			else break ;
			i = par ; 
			par = (i-1) /2 ;
		}
	}

	void insert(int data){
		v.push_back(data) ; 
		int i = v.size() -1 ; 
		
		sift_up(i);
		// Print();
	}

	int extractMin(){
		if (v.empty())return INT_MAX ; 
		int deletedElement = v[0];  
		v[0] = v.back() ; 
		v.pop_back() ; 
		// heapify2( 0 ) ;  
		heapify( 0 ) ;// also known as sift_down in wikipedia 
		return deletedElement ; 
	}
	int heap_size(){
		return v.size() ; 
	}

	int top(){
		if(v.empty())
			return -1 ; 
		return v[0] ; 
	}

	void heapify2(int i ){
		int left,right,min = i ;
		left = 2*i+1 ; 
		right= 2*i + 2 ; 
		while(left < heap_size()){
			if(left < heap_size() && v[left] < v[min] ){
			 min = left ;
			}

			if(right < heap_size() && v[right] < v[min]) {
				min = right ; 
			}

			if(min!=i){
				swap(v[i] , v[min]) ;
				i = min ; 
			}
			else{
				break ; 
			}
			left = 2*i+1 ; 
			right= 2*i + 2 ; 
		}
	}

	void heapify(  int i  ){
		int min = i ,left,right ;
		left = 2*i+1 ; 
		right= 2*i + 2 ; 
		if(left < heap_size() && v[left] < v[min] ){
			 min = left ;
		}
		if(right < heap_size() && v[right] < v[min]) {
			min = right ; 
		}

		if(min !=i){
			swap(v[i] , v[min]) ;
			heapify( min ) ; 
			 
		}
	}

	void changeValue(int i , int newVal){
		if(v.empty())return ; 
		v[i] = newVal ; 
		sift_up(i) ; 
		heapify(i) ;
	}

	void remove(int i){
		changeValue(i,INT_MIN) ; 
		int k = extractMin() ;
	}

};


 
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
 
    
   #ifndef ONLINE_JUDGE
   freopen("/home/sriram/Coding-files/codeforces/input.txt", "r", stdin);
   freopen("/home/sriram/Coding-files/codeforces/error.txt", "w", stderr);
   freopen("/home/sriram/Coding-files/codeforces/output.txt", "w", stdout);
   #endif
   // int tc ;
   // cin>>tc;
   // while(tc--){
   // 		int n , m ; 
   // 		cin>>n>>m;
   // 		vector<int>v ;
   // 		fr(i,n){
   // 			int a ;
   // 			cin>>a;
   // 			v.pb(a) ;
   // 		}

   // 		fr(i,m){
   // 			int a ;
   // 			cin>>a;
   // 			v.pb(a) ;
   // 		}
   // 		minheap h(v);
   // 		h.Print();

   // }
    vector<int> v = {10 , 5 ,3, 4 ,1 } ; 
    minheap h(v) ; 
    h.Print() ; 
    cout<<h.top() <<endl; 
    cout<<"Deleted Element is " <<h.extractMin()<<endl;
    cout<<h.top() <<endl; 
    int pos = 3 ; // in 0 index
	cout<<"Delete element at position "<<pos<<endl;
	h.remove(pos) ;

    h.Print();
}


/*class minheap{
	public:
	vector<int> v ;

	minheap(){ ; 	}

	minheap(vector<int> arr){
		for(auto x:arr){
			insert(x) ;
		}
	}

	void Print(){
		Show(v) ;
		cout<<endl;
	}

	void insert(int data) ;

	int top(){
		if(v.empty())
			return -1 ; 
		return v[0] ; 
	}

	void extractMin() ;

	void heapify(int i , int n ) ;

	void heapify2() ;
};*/