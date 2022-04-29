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
// sieve , binomial coeff , pascal 
// class Compare{
//     public:
//     bool operator() (foo,foo){
//         return expression
//     }
// };   

int pageFaults(int n,int c,int a[]){
    int res = min(c,n);
    set<int> v ;
    unordered_map<int,int> mp ; 
    for(int i = 0 ; i < res; ++i){
      v.insert(a[i]);
        mp[a[i]] = i ;

    }
    for(int i = res ; i < n ; ++i ){
        if(v.find(a[i])==v.end()){
            int Min = INT_MAX , ind = -1; 
            for(auto j : v){
                if(mp[j] < Min){
                    ind = j ;
                    Min = mp[j] ; 
                }
            }
            v.erase(ind);
            v.insert(a[i]);
            res++;
            // cout<<ind<<" "<<Min<<" "<<res<<endl; 
        }
        mp[a[i]] = i ;
    }
    return res; 
}

void solve(){   

    int n , c ; 
    cin>>n>>c;
    int pages[n]; 
    fr(i,n)cin>>pages[i] ; 
    cout<<pageFaults(n,c,pages) <<endl;
    
}

int main()
{
    solve() ;
}

/*
9 4
5 0 1 3 2 4 1  0 5
*/