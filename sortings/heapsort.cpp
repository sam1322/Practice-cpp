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

class Heap{
public:
	vector<int> heap;
	int Size ; 
	Heap(vector<int> a){
		heap.assign(a.size() , 0) ;
		for(int i = 0; i < a.size() ;++i ){
			heap[i] = a[i] ;
			heapcheck(i) ; 
		}
		Size = a.size() ; 
	}

	void heapify(){
		int  i = 0 ;
		int maxchild = 0 , leftchild = 2*i+1 , rightchild = 2*i+2, n = Size; 
		while(i< n &&leftchild < n){
			if(rightchild < n){
					if(heap[leftchild] < heap[rightchild]){
						maxchild = rightchild;
					}
					else{
						maxchild = leftchild ; 
					}
			}
			else if( leftchild < n){
				maxchild = leftchild ; 
			}	
			else {
				break ;
			}
			if(heap[i] < heap[maxchild])
			{
				swap(heap[i] , heap[maxchild]) ; 
				i = maxchild ;
				leftchild = 2*i+1 ; 
				rightchild = 2*i + 2 ;
			}
			else{
				break; 
			}
		}

	}

	void heapcheck(int i ){
		int pi= (i-1)/2 ;
		while(pi>=0){
			if(heap[pi]<heap[i]){
				swap(heap[pi] , heap[i]) ;
				i =pi;
				pi = (i-1)/2 ; 
			}
			else{break;}
		}
	}

	vector<int> heapsort(){
		 
		vector<int> v(Size) ;

		while(Size >0){
			v[Size-1]= heap[0] ;
			swap(heap[0],heap[Size-1]) ; 
			Size-- ;
			heapify() ;
		}

		return v ;
	}
}; 

int main()
{
	int n ; 
	cout<<"Enter the no of elements"<<endl;
	cin>>n;
	vector<int> v ;
	for(int i = 0 ; i < n ; i++){
		int a; 
		cin>>a; 
		v.push_back(a) ;

	}
	Heap h(v) ;
	v = h.heapsort() ;
	cout<<"Sorted string : "<<endl;
	for(int i = 0 ; i < n ;i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}