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
#define vl vector<ll>
#define vp vector<pair<int,int>> 
#define nl cout<<endl;
typedef pair<int,int> pii; 
// sieve , binomial coeff , pascal 

//int solve(){
void solve(){
	int N, Q ; 
	cin>>N>>Q; 
	vi a(N) ; 
	for(auto &x:a)cin>>x ;

	vi lg(N+1) ; //lg[i] = log2[i]
	lg[1] = 0 ; 
	for(int i = 2 ;i <=N ; ++i ){ 
		lg[i]= lg[i/2]+1; 
	}

	vector<vector<int>> sparse(lg[N] +1,vi(N,INT_MAX)) ; 

	for(int i = 0 ; i < N;++i)
		sparse[0][i]= a[i] ; 

	// for(int i = 1 ; i <= lg[N] ; ++i ){
	// 	for(int j= 0 ; j + (1<<i) - 1 < N ;++j){
	// 		sparse[i][j] = min(sparse[i-1][j] , sparse[i-1][ j + ( 1 << ( i - 1 ) )] ) ; 
	// 	}
	// }
	// while(Q--){
	// 	int l , r ; cin>> l >> r ; 
	// 	l--; 
	// 	r-- ;
	// 	int i = lg[r - l + 1] ; 
	// 	cout<<min(sparse[i][l] , sparse[i][r - ( 1 << i) + 1]);nl;
	// }


    for (int i = 1; i <= lg[N]; i++)
        for (int j = 0; j + (1 << i) - 1 < N; j++) // (1 << x) = 2^x
            sparse[i][j] = min(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
 
    while (Q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
 
        int i = lg[r - l + 1];
        cout << min(sparse[i][l], sparse[i][r - (1 << i) + 1]) << "\n";
    }
}


void solve1(){
int N, Q;
    cin >> N >> Q;
 
    vector<int> A(N);
    for (auto &x : A)
        cin >> x;
 
    vector<int> lg(N + 1); // lg[i] = log2(i)
    lg[1] = 0;
    for (int i = 2; i <= N; i++)
        lg[i] = lg[i / 2] + 1;
 
    // sparse[i][j] : Minimum value in the interval [j, j + 2^i - 1]
    vector<vector<int>> sparse(lg[N] + 1, vector<int>(N,INT_MAX));
 
    for (int j = 0; j < N; j++)
        sparse[0][j] = A[j];
 
    for (int i = 1; i <= lg[N]; i++)
        for (int j = 0; j + (1 << i) - 1 < N; j++) // (1 << x) = 2^x
            sparse[i][j] = min(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
 
    while (Q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
 
        int i = lg[r - l + 1];
        cout << min(sparse[i][l], sparse[i][r - (1 << i) + 1]) << "\n";
    }
}


int main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
 
        
  #ifndef ONLINE_JUDGE
   freopen("/home/sriram/Coding-files/codeforces/in", "r", stdin);
   freopen("/home/sriram/Coding-files/codeforces/err", "w", stderr);
   freopen("/home/sriram/Coding-files/codeforces/out", "w", stdout);
   #endif

      solve();
}