#include<bits/stdc++.h>
using namespace std ;

void bucketsort(vector<float> &v , int n) 
{ 
    
    vector<float> buckets[n]; 
  
     for (int i = 0; i < n; i++) { 
        int bi = n * v[i];   
        buckets[bi].push_back(v[i]); 
    } 
  
  
    for (int i = 0; i < n; i++) 
        sort(buckets[i].begin(), buckets[i].end()); 
  
   
    int index = 0; 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < buckets[i].size(); j++) 
            v[index++] = buckets[i][j]; 
} 

int main()
{
    int n ; 
    cout<<"Enter the no of elements"<<endl;
    cin>>n;
    vector<float> v ;
    for(int i = 0 ; i < n ; i++){
        float a; 
        cin>>a; 
        v.push_back(a) ;

    }
   bucketsort(v,n) ;
    cout<<"Sorted string : "<<endl;
    for(int i = 0 ; i < n ;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

/*
0.897 0.565 0.656 0.1234 0.665 0.3434
*/