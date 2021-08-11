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

//int solve(){

void merge1(vi &a,int start ,int end ){
	if(start + 1 >=end ) return ; 
	
	int mid = start + (end - start) /2 ; 

	vi left,right ,final ;
	
	for(int index = start ; index < mid ;++index){
		left.push_back(a[index]); 
	}
	
	for(int index = mid ; index < end ; ++index ){
		right.push_back(a[index]) ; 
	}

	int leftIndex = 0 , rightIndex = 0 , leftSize = left.size() ,rightSize = right.size(); 	
	
	while(leftIndex < leftSize && rightIndex < rightSize ) 
	{
		if(left[leftIndex] < right[rightIndex]){
			final.push_back(left[leftIndex++])  ;
		}
		else {
			final.push_back(right[rightIndex++])  ;

		}
	}
	cout<<start<<" "<<mid<<" "<<end<<endl;
	// cout<<"left : ";Show(left);cout<<" ; ";
	// cout<<"right : ";Show(right);cout<<" ; ";
	// cout<<endl;	
	while(leftIndex < leftSize ){
			final.push_back(left[leftIndex++])  ;

	}	
	while(rightIndex < rightSize ){
			final.push_back(right[rightIndex++])  ;
		
	}
	for(int index = 0 ; index < final.size() ; index++){
		a[start + index ]= final[index] ; 
	}

	cout<<"left : ";Show(left);cout<<" ; ";
	cout<<"right : ";Show(right);cout<<" ; ";
	cout<<"final : ";Show(final);cout<<" ; "<<endl;

}


void merge(vi &a,int start ,int end ){
	if(start + 1 >=end ) return ;
	int mid = start + (end - start) /2 ;  
	vi left,right ,final ;
	int leftIndex = 0 , rightIndex = 0 , leftSize  ,rightSize ; 	
	
	for(int index = start ; index < mid ;++index){
		left.push_back(a[index]); 
	}
	
	for(int index = mid ; index < end ; ++index ){
		right.push_back(a[index]) ; 
	}
	
	leftSize = left.size() ; rightSize = right.size(); 	
	
	while(leftIndex < leftSize && rightIndex < rightSize ) 
	{
		if(left[leftIndex] < right[rightIndex]){
			final.push_back(left[leftIndex++])  ;
		}
		else {
			final.push_back(right[rightIndex++])  ;
		}
	}
	
	while(leftIndex < leftSize ){
			final.push_back(left[leftIndex++])  ;
	}	
	
	while(rightIndex < rightSize ){
			final.push_back(right[rightIndex++])  ;
	}

	for(int index = 0 ; index < final.size() ; index++){
		a[start + index ]= final[index] ; 
	}
}

void mergesort(vi &a,int start ,int end ){ // end not included 
	if(start + 1>= end )return  ;
	int mid = start + (end - start) /2 ; 
	mergesort(a,start,mid) ; 
	mergesort(a,mid ,end ) ; 
	merge(a,start ,end) ; 
}

void mergesort_iter(vi &a,int start ,int end ){
	for(int m = 1 ; m <=  end - start ; m *=2  ){
		for(int i = start;  i <= end   ; i +=2*m ){
			merge(a,i,min(i + 2*m  ,end )) ; 
		}
	}
}

void solve(){
	vi a;
	int n ; 
	cin>>n ;
	 srand(time(NULL));

	fr(i,n){
		int k = rand() %50 ; 
		// cin>>k ;
		a.pb(k) ; 
	}
	
cout<<"Original array : ";	Show(a);cout<<endl;

	mergesort_iter(a,0,a.size()); 
	cout<<"Sorted Array : ";Show(a);cout<<endl;
}

int main()
{
      ios_base::sync_with_stdio(false);cin.tie(NULL);
 
        
   #ifndef ONLINE_JUDGE
   freopen("/home/sriram/Coding-files/codeforces/in", "r", stdin);
   freopen("/home/sriram/Coding-files/codeforces/err", "w", stderr);
   freopen("/home/sriram/Coding-files/codeforces/out", "w", stdout);
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



/*
2
5
3 7 4 1 6 
3
1 3 2
5
47 10 28 12 6 
3
44 49 38 
3
47 10 28


*/








