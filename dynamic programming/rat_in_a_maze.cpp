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
#define Ios ios::sync_with_stdio(false)
#define Tie cin.tie(0);    cout.setf(ios::fixed); cout.precision(0);
#define inf 0x3f3f3f3f
#define mk make_pair
template<typename T, typename V> inline void mn(T &x, V y) { if(y < x) x = y; }
template<typename T, typename V> inline void mx(T &x, V y) { if(x < y) x = y; }
//const int MAXN = 200100;
typedef long long  ll;
#define vi vector<int>
#define vp vector<pair<int,int> 
typedef pair<int,int> pii; 

bool valid(int i , int j ,int n ){
    return i >=0 && i <n && j>=0 && j< n ; 
}
vector<string> v ;
unordered_map<string,int>V ;
#define MAX 1024  
void helper(string cur , int m[MAX][MAX] , int i ,int j ,int n ){
    
    if(i==n-1 && j==n-1){
        V[cur]++ ; 
    }
        
    if(valid(i+1,j,n) && m[i+1][j]){
        helper(cur+'D', m , i+1,j,n) ;
    }
    if(valid(i,j+1,n) && m[i][j+1]){
        helper(cur+'R' , m , i,j+1,n) ;
    }
}

vector<string> printPath(int m[MAX][MAX], int n) {
    // Your code goes here
    helper("" , m , 0 , 0 , n ); 
    for(auto x : V){
        v.push_back(x.first) ; 
    }
    
    return v ; 
    
}


int main()
{
    int m[MAX][MAX] = {{1 , 0 ,0 , 0},
	{1,1,0,1},
	{1,1,0,0},
	{0,1,1,1} 	
	};

	printPath(m,4);

	for(int i =0 ; i < v.size() ;++i){
		cout<<v[i]<<endl;
	}
}

/*



*/