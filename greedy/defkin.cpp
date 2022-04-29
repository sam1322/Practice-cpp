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
    int w , h ,n ;
    cin>>w>>h>>n;
    vector<int> x , y  ;
    fr(i,n){
        int a , b ; 
        cin>>a>>b;
        x.pb(a) ;
        y.pb(b) ;
    }
    
    
    Sort(x);
    Sort(y) ;
    int l = 1;
     int xmax = 0 ,ymax = 0 ; 
    fr(i,x.size()){
        mx(xmax ,x[i] - l);
        l = x[i] ;
    }
    mx(xmax,w-l) ;
    l = 1 ;
    fr(i,y.size()){
        mx(ymax,y[i]-l) ; 
        l = y[i] ;
    }
    mx(ymax,h-l) ;
    cout<<xmax<< " "<<ymax<<endl;
    return (xmax > 0 && ymax>0)?xmax*ymax : (xmax > 0 )?xmax:ymax;
}

int main()
{
     int tc;
    scanf("%d", &tc) ; 
    while(tc--){
        cout<<solve()<<endl;
    }
}
