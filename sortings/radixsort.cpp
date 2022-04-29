#include<bits/stdc++.h>
using namespace std ;

int maxval(vector<int> &v ,int n){
    int m = v[0] ;
    for(int i = 0  ; i < n ;i++){
        m = max(m , v[i]) ;
    }
    return m ; 
}

void countsort(vector<int> &v , int n ,int d){
     vector<int> count[10] ; 
    for(int i = 0 ; i < n ;i++){
           int x =( v[i] / d ) % 10 ; 
           count[x].push_back(v[i]) ; 
        }
        int ctr  =  0 ; 
        for(int i = 0 ; i < 10 ;i++){

            for(int j = 0 ;j < count[i].size() ; j++){
                v[ctr++] = count[i][j] ; 
            }
          
        }
}
void radixsort(vector<int> &v , int n) 
{    
   
    int Max = maxval(v,n) ;
    int D = 0 ; 
    while(Max){
        D++ ;
        Max/=10 ;
    }
    int d = 0 , k =1 ,f =1;
    while(d<D){
        countsort(v,n,k) ;
        d++;
        k*=10;
    }

} 

int main()
{
    int n ; 
    cout<<"Enter the no of elements"<<endl;
    cin>>n;
    vector<int> v ;
    for(int i = 0 ; i < n ; i++){
        float a; 
        cin>>a; 
        v.push_back(a) ;

    }
   radixsort(v,n) ;
    cout<<"Sorted string : "<<endl;
    for(int i = 0 ; i < n ;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

 /*
8
170 45 75 90 802 24 2 66 
  */