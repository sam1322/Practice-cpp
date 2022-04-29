#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define fr(i,a) for(int  i=0;i<a;i++)
#define forn(i,a,n) for(int i = a; i < n ;i++)
#define Sort(a) sort(a.begin(),a.end())
#define Rev(k)  reverse(k.begin(),k.end())
#define Sz(x) x.size()
#define Show(v) for(int i =0 ; i < v.size();i++) cout<<v[i] //only for sting and vector
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


bool check(vector<vector<int>> &edges , vector<int> &vis, int v , int c ,int n ){

	for(int i = 0 ; i < n ; i++ ){
		if(edges[v][i] && vis[i]==c)
			return false ;
	}

	return true ; 
}

bool mcoloring(vector<vector<int>> &edges ,  vector<int> &vis,int v ,int n , int m  ){
	if(v>=n){
		return true; 
	}

	for(int i = 1 ; i <= m ;i++){

		if(check(edges,vis,v ,i , n ) ){
			vis[v] = i ;

			if(mcoloring(edges,vis,v+1,n,m)){
				return true ; 
			}

			vis[v] = 0 ;
		}

	}
	return false; 
}

void Print(vector<int> &vis){
	cout<<"vertex : color"<<endl;
	for(int i = 0 ; i < vis.size() ;i++){
		cout<<i<< "\t   "<< vis[i]<<endl;
	}
}
void PrintGraph(vector<vector<int>> &edge , int n){
	for(int i = 0 ; i < n ; i++ ){
		for(int j = 0 ; j < n ; j++){
			cout<<edge[i][j]<<" " ; 
		}
	cout<<endl;
	}

}

int main()
{
    int n , e;
    cout<<"Enter the no of  vertices and no of edges "<<endl; 
   	cin>>n >>e; 
   	cout<<"Enter the edges "<<endl;
   	vector<int> vis(n,0) ;
   	vector<vector<int>> edges(n,vis) ;

   	for(int i = 0 ; i < e ;i++){
   		int f , s ;
   		cin>>f>>s ;
   		edges[f][s] = 1 ;
   		edges[s][f] = 1 ;
   	}
   	int m ; 
   	cout<<"Enter the no of colors"<<endl;
   	cin>>m ;

   	if(!mcoloring(edges , vis , 0 , n , m ))
   	{
   		cout<<"Error occurred" <<endl;
   	}
   	else{
   		// PrintGraph(edges , n) ;
   		Print(vis) ;
   	}
}
/*
4 5
0 1 
0 2 
0 3
1 2
2 3 
3
*/