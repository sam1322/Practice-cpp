#include<bits/stdc++.h>
using namespace std ;

int linearsearch(int a[],int n ,int k){
    for(int i = 0 ; i< n ; i++){
        if(a[i]==k)return i ;
    }
    return -1;
}

int binary_search(int a[] ,int k,int l ,int r ){
    if(l>r)
    return -1 ; 

    int m = (l + r)/2 ; 
    if(a[m] == k ){
        return m  ; 
    }
    else if(a[m]<k){
        return binary_search(a,k,m+1,r) ;
    }
    else{
        return binary_search(a,k, l ,m -1 ) ;
    }
}

int  main(){

    int n ; 
    cout<<"No of elements " ;  
    cin>>n;

    int a[n];
    for(int i = 0;i<n;i++)cin>>a[i];

    int element ; 
    cout<<"Enter element which is to be searched " ; 
    cin>>element ; 

    int pos1 = linearsearch(a,n,element) ; 
    sort(a,a+n) ;
    if(pos1==-1)
    cout<<"The element was not found on the the array" ; 
    else{
        cout<<element <<" was found on position on "<<pos1 <<endl;
    }

    int pos2 = binary_search(a,element,0,n-1) ; 
     if(pos2==-1)
    cout<<"The element was not found on the the array " ; 
    else{
        cout<<element <<" was found on position on  "<<pos2 <<" in a sorted array "<<endl;
    }

}