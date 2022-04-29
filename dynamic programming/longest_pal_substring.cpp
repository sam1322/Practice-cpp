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


// wrong
map<string,string> mp ; 

string f(string &x ,int i , int j ,string &ans){
    string cur = to_string(i) + "$" + to_string(j) ; 
    if(mp.count(cur))return mp[cur] ; 
    string res ;
    if( i > j )res = "" ; 
else if(i==j)res += x[i] ; 

else if(x[i] == x[j]){
    string r = f(x,i+1,j-1,ans) ;
    if(r !="$" ){
        res +=x[i] ; 
        res+=r ;
        res+=x[j] ; 
        if(res.size() > ans.size()){
            ans =res; 
        } 
    }
    else{
        res =r ; 
    }
}

else {
    string res1 = f(x,i+1,j,ans) ;
    string res2 = f(x,i,j-1,ans) ;
    if(res1 !="$" && res2.size() > ans.size())
    ans = res1 ; 
    if(res2 !="$" && res2.size() > ans.size())
    ans = res2 ; 
    res = "$" ; 
}
return mp[cur] = res ;
}

string longestPalindrome(string x){
   mp.clear() ; 
   string ans ="" ;
   string cur =  f(x,0,x.size() -1 ,ans)  ; 
   return ans ; 
}

string solve(){
 string x; 
 cin>>x;

return longestPalindrome(x) ; 

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
