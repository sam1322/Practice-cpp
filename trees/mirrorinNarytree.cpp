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


bool dfs(vector<vector<int>>&adj1 , vector<vector<int>>&adj2,int i , int j){
          int  res = 1 ;
  if(i==j && adj1[i].size()==adj2[j].size()){

    for(int l = 0 ; l < adj1[i].size() ; ++l){
        res*=dfs(adj1,adj2,adj1[i][l], adj2[j][adj1[i].size() - l- 1  ] ) ; 
        if(!res){
            return 0 ; 
        }
    }
  }
  else return 0 ;
    return res; 
}

int solve(){
    int n , e ; 
    // cout<<"enter " ;
    cin>>n>>e; 
    vector<vector<int>>adj1(n+1),adj2(n+1);
    fr(i,e){
        int u,v;
        // cout<<"Enter 1 ";
        cin>>u>>v ;
        adj1[u].pb(v) ;
        
    }

       fr(i,e){
        int u,v;
        // cout<<"Enter 1 ";
        cin>>u>>v ;
        adj2[u].pb(v) ;
        
    }
    
    bool ans = dfs(adj1,adj2,1,1);
    return ans ;
}

int main()
{
     int tc;
    scanf("%d", &tc) ; 
    while(tc--){
        // cout<<"Soln ";
        cout<<solve()<<endl;
    }
}
