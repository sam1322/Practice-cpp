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
 
// Time complexity of towerOfHanoi is O(2^N)

void towerOfHanoi(int n,char from ,char to ,char temp){
	if(n<=1)
	{	cout<<n<<" disk is going from "<<from<<" to "<<to;nl;
		return ; 
	}
	towerOfHanoi(n-1,from,temp,to) ;
	cout<<n<<" disk is going from "<<from<<" to "<<to;nl;
	towerOfHanoi(n-1,temp,to,from) ;
}

 //int solve(){
 void solve(){
 	int n ; 
	cin>>n ; 
	towerOfHanoi(n,'A','C','B') ;nl; 

 }
 
 int main()
 {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
  
         
   #ifndef ONLINE_JUDGE
    freopen("/home/sriram/Coding-files/codeforces/in", "r", stdin);
    freopen("/home/sriram/Coding-files/codeforces/err", "w", stderr);
    freopen("/home/sriram/Coding-files/codeforces/out", "w", stdout);
    #endif
 
     int tc;
     //scanf("%d", &tc) ; 
     cin>>tc; 
 
     while(tc--){
     	//cout<<solve()<<endl;
       solve();
       //cout<<endl;
     }
 }