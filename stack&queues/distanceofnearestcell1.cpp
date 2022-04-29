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

class Solution {

public:
    bool isvalid(int i ,int j ,vector<vector<int>> &grid ,vector<vector<int>>&vis){
        int n =grid.size() , m = grid[0].size() ;
        return i >=0 && i < n && j >=0 && j < m && grid[i][j]==0 && !vis[i][j];
    }

    
	vector<vector<int>>nearest(vector<vector<int>>grid){
	    // Code here
	    int n =grid.size() , m = grid[0].size() ;
        // vector<vector<int>> a(n,vector<int>(m,INT_MAX)) ;
        vector<vector<int>> a(n,vector<int>(m)) ;
        vector<vector<int>> vis(n,vector<int>(m)) ; 
        queue<pair<int,int>> q;
        vector<int> x = {-1,1, 0,0} ;
        vector<int> y = { 0,0,-1,1} ;
        for(int i = 0 ;i < n ;++i ){
            for(int j = 0 ; j < m ;++j ){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        int level = 0; 
        while(!q.empty()){
            int N = q.size() ; 
            if(N==0)break;
            // level++;
            for(int  i= 0 ; i < N ; ++i){
                pair<int,int> cur = q.front() ;              
                q.pop() ; 
                a[cur.first][cur.second]= level;
                for(int j =0 ; j < 4 ;++j){
                    int l = cur.first + x[j] ; 
                    int k = cur.second + y[j];
                    
                    if(isvalid(l,k ,grid,vis) ){
                        vis[l][k] = 1 ;
                        // grid[l][k] = 1 ;
                        // cout<<"l = "<<l <<" k = "<<k<<" : "<<level<<endl;
                        // a[l][k] = level ;  
                        // a[l][k] = min(a[l][k] ,a[cur.first][cur.second] + 1 ); 
                        q.push({l,k}) ;
                    }
                }
     
            }
            level++ ;
        }
        
        return a ; 
	}
};

int  solve(){
    Solution obj ;
    vector<vector<int>> v = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}; 
    vector<vector<int>> ans = obj.nearest(v) ; 
    fr(i,ans.size()){
        fr(j,ans[i].size()){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

int main()
{
    //  int tc;
    // scanf("%d", &tc) ; 
    // while(tc--){
    //     cout<<solve()<<endl;
    // }
    solve();
}

