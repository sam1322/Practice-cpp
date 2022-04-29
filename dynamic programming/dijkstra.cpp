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
#define vp vector<pair<int,int>> 
typedef pair<int,int> pii; 

struct edge{
	int src , dest ,wt; 
};

class Graph{
	public:
	int N ;
	vector<vector<pii>> adj ;
	Graph(vector<edge> edges , int N ){
		vector<pii> V ; 
		adj.assign(N,V) ;
		this->N = N ; 
		for(auto &p : edges){
			adj[p.src].push_back(mk(p.dest ,p.wt) )  ; 
		    adj[p.dest].push_back(mk(p.src ,p.wt)) ; 
		}
	}

};

int calMinIndex(vector<int> &wt ,vector<bool> &vis){
	int m = -1 ;
	for(int i = 0 ; i < wt.size() ;++i){
		if( !vis[i] && ( m==-1 || wt[m] > wt[i] ) ){
			m = i ;
		}
	}
	return m ;
}

void dijsktra(Graph &g ,int src ){
	   vector<int> wt(g.N,INT_MAX) ; 
	   vector<bool> vis(g.N) ; 
	   vector<pii> v ;
	   wt[src] = 0 ; 
	   for(int i = 0 ; i < g.N ; i++){
	   		int minIndex = calMinIndex(wt,vis) ;
	   		if(minIndex ==-1)break ; 
	   			vis[minIndex] = 1 ;
	   		int minwt = INT_MAX , mini = -1 ;
	   		for(auto &x : g.adj[minIndex]){
	   			if(wt[minIndex] + x.second < wt[x.first] ){
	   				wt[x.first ] = wt[minIndex] + x.second ; 
	   			}
	   			// if(!vis[x.first] && minwt > wt[x.first] ){
	   			// 	minwt = wt[x.first] ;
	   			// 	mini = x.first ; 
	   			// }

	   		}
	   		// if(mini!=-1)
	   		// v.push_back(mk(minIndex , mini) ) ; 


	   }
	   // cout<<"index1 index2\n" ;
	   // for(auto &x:v){
	   // 	cout<<x.first<<"\t"<<x.second <<endl;

	   // }
	   cout<<"index weight\n";
	   for(int i = 0 ;i < wt.size() ; ++i){
	   	cout<<i<< "\t" <<wt[i]<<endl;
	   }
}


int main()
{
    vector<edge> edges = { {0,1,4} , {0,7,8} , {1,7,11} , {1,2,8} , {2,8,2} , { 2 , 5 , 4 } , 
    { 2 , 3 , 7 }, { 3 , 4 , 9 }, {3, 5 ,14 } , { 4 ,5 ,10 },{5,6 , 2} , { 6,8,6 } , { 6 , 7 , 1} ,
     { 7 , 8 , 7}
    } ; 
    int N = 9 ; 

    Graph g(edges , N);
    dijsktra(g,0) ;

}