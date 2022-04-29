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

//this time using last pivot 

int Partition(vector<int>&a, int low ,int high){
    int c= low- 1 ; 
    for(int i = low ; i<high;i++){
        if(a[high]>a[i])
        {
            c++;
            swap(a[c],a[i]) ; 
        }
    }

    swap(a[high],a[c+1]) ; 
    return c+1;

}

void QuickSort_tail_call(vector<int> &a,int l , int r ){
    while(l < r){
    if(l<r){
        int pi = Partition(a,l,r) ; 

        if(pi - l<r  - pi ){
            QuickSort_tail_call(a, l,pi-1) ; 
            l = pi + 1 ;
        }
        else{
            QuickSort_tail_call(a,pi+1, r) ; 
            r= pi -1; 
        }
    }
}
    
}


int main()
{
    Ios;
    Tie;
    int n ;
    cin>>n ;
    vector<int> a; 

    for(int i = 0 ; i < n ; i++){
        int k ;
        cin>> k ; 
        a.push_back(k) ; 
    }

    QuickSort_tail_call(a,0,n-1) ; 

    for(int i = 0 ; i < n;i++){
        cout<<a[i]<<" " ;
    }
    cout<<endl;
}

