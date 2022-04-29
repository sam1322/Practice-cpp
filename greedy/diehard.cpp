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

int solve(){
    int h ,a ; 
    cin>>h>> a ;
    int i = 0 ,ctr = 0 ; 
    while(h>0 && a>0){
        if(i==0)//air
        {
            h+=3 ;
            a+=2 ;
            if(h>5 && a>10  ){
                i++;
            }
            else i=2;
        }
        else if(i==1){
            h-=5 ; 
            a-=10 ;
            i=0;
        }
        else if(i==2){
            h-=20 ; 
            a+=5 ; 
            i=0;
        }
        if(h>0 && a>0) 
            ctr++;
            // cout<<i<<" "<<h<<" "<<a<<" ctr : " <<ctr<<endl;
        
    }
    return ctr ; 
}

int main()
{
     int tc;
    scanf("%d", &tc) ; 
    while(tc--){
        cout<<solve()<<endl;
    }
}
