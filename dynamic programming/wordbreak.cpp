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

int f(string a , set<string> &dict ,map<string,int> &mp){
    
    if(a.empty())
        return 1 ; 

    if(mp.count(a))return mp[a] ; 
    
    for(int i = 1 ; i <= a.size() ; ++i){
        if(dict.find(a.substr(0,i)) !=dict.end() && f(a.substr(i),dict,mp) ){
            mp[a]= 1  ;
            return 1 ; 
        }
    }
    mp[a] = 0 ; 
    return 0 ; 
}

int wordBreak(string A, vector<string> &B) {
    //code here
    set<string> dict(B.begin(),B.end()) ; 
    
    map<string,int> mp ; 
    return f(A,dict,mp) ;
}

int solve(){
    int n = 12 ; 
    // cin>>n;

    vector<string> a = { "i", "like", "sam", "sung", "samsung", "mobile",
"ice","cream", "icecream", "man", "go", "mango" } ; 
    

    // fr(i,n){
    //     string s ;
    //     cin>>s;
    //     a.pb(s) ; 

    // }
    string s = "ilike" ; 
    // cin>>s ; 

    return wordBreak( s , a  ) ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int tc;
    // cin>>tc;
    // while(tc--){
        cout<<solve()<<endl;
    //  solve();
    // }
}
/*
{ "i", "like", "sam", "sung", "samsung", "mobile",
"ice","cream", "icecream", "man", "go", "mango" }

 "ilike"
*/