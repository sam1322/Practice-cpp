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
vector<int> x = {-1, 1 ,0, 0} ; 
vector<int> y = { 0 , 0, -1 ,1 } ;

bool isvalid(vector<vector<int>> &a,vector<vector<int>> &vis,int i ,int j ){
	int n = a.size() ;
	int m = a[0].size() ; 

	return ( i >= 0 && i< n && j >=0 && j < m && a[i][j]!=0 && vis[i][j] == 0 ) ;

}

void bfs(vector<vector<int>> &a,vector<vector<int>> &b ,int i ,int j ){
	int n = a.size() ;
	int m = a[0].size() ; 
	vector<vector<int>> vis(n,vector<int>(m)) ; 
	vector<pair<int,int>> q ; 
	q.emplace_back(i,j) ;
	int t = 0 ;
	while(!q.empty()){
		int N= q.size() ;
		for(int c = 0 ; c < N ; ++c){
			pair<int,int>p = q.front() ;
			 i= p.first ;
			 j = p.second ;
			 b[i][j] = min(b[i][j] , t ) ; 
			 q.erase(q.begin()) ; 
			 for(int k = 0 ; k < 4 ;++k){
			 	int X = i + x[k] , Y = j + y[k] ; 
			 	if(isvalid(a,vis,X,Y)){
			 		vis[X][Y] = 1; 
			 		q.emplace_back(X,Y) ; 
			 	}
			 }
		}
		t++ ; 
	}
}

//int solve(){
void solve(){
	int n , m;
	cin>>n>>m;
	vector<vector<int>> a(n,vector<int>(m)) ; 
	vector<vector<int>> b(n,vector<int>(m,INT_MAX)) ; 
	for(int i= 0 ; i < n ; ++i){
		for(int j = 0 ; j < m ;++j){
			cin>>a[i][j] ; 
		}
	}

	for(int i = 0 ; i  < n ; ++i){
		for(int j = 0 ; j < m ; ++j ){
			if(a[i][j]==2){
				bfs(a,b,i,j) ; 
			}
		}
	}
	int mn = 0; 
	for(int i = 0 ; i < n ;++i){
		for(int j =0 ;  j < m ;++j){
			if(b[i][j]==INT_MAX)continue ; 
			mn = max(mn ,b[i][j] ) ;
		}
	}

	fr(i,n){
		fr(j,m){
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<mn<<endl;

}

int main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
 
    
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("error.txt", "w", stderr);
   freopen("output.txt", "w", stdout);
   #endif

    int tc;
    //scanf("%d", &tc) ; 
    cin>>tc; 

    while(tc--){
    	//cout<<solve()<<endl;
      solve();
      cout<<endl;
    }
}

/*
1
3 5 
2 1 0 2 1
1 0 0 2 1 
1 0 0 2 1
*/