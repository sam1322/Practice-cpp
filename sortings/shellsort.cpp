#include<bits/stdc++.h>
using namespace std ;

void shellsort(vector<int> &v, int n) 
{ 
     int gap = n / 2 ;
     while(gap)
    {  
        for (int i = gap; i < n; ++i ) 
        {  
            int t  = v[i] , j = i ;              
            for (j = i; j >= gap && v[j - gap] > t ; j -= gap) 
                v[j] = v[j - gap]; 
 
              v[j] = t; 
        }

        gap/=2 ; 
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
   shellsort(v,n) ;
    cout<<"Sorted string : "<<endl;
    for(int i = 0 ; i < n ;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}