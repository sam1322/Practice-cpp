#include<bits/stdc++.h>
using namespace std ; 
int n ;
int partition(vector<int> &a, int l , int r ){

	int  c = 0 ; 
	for(int i = l+1 ; i <=r ; i++ ){
		if(a[l]>a[i]){
			c++;
		}
	}
	int pi = l+c ; 
// cout<<" l : "<<l<<" r : "<<r<<endl;
	swap(a[l],a[l+c]) ;
	while(l<pi&&pi<r){
		if(a[l]>=a[pi]&&(a[r]<a[pi])){
			swap(a[l],a[r] );
			l++;
			r-- ;
		}
		if(a[l]<a[pi]){
			l++;
		}
		if(a[r]>=a[pi]){
			r--;
		}

	}
// cout<<" l : "<<l<<" r : "<<r<<endl;

// for(int i = 0 ; i < n ; i++){
// 		cout<<a[i]<<" " ;

// 	}
// 	cout<<endl;

	return pi ;
}

void quicksort(vector<int> &v , int l ,int r){

if(l>=r)return ;
int pi = partition(v,l,r) ;

	quicksort(v, l,pi-1) ;
	quicksort(v, pi+1 , r) ;


}

int main(){
 cout<<"Enter no of elements\n" ;
	cin>>n ; 
	cout<<"Enter the elements\n" ;
	vector<int> v; 
	for(int i = 0 ; i < n ; i++){
		int a ;
		cin>>a ; 
		v.push_back(a) ;

	}

	quicksort(v ,0 ,n-1);

	for(int i = 0 ; i < n ; i++){
		cout<<v[i]<<" " ;

	}
	cout<<endl;
}
