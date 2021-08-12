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


struct edge{
	int src , dest ; 
};

class Graph{
	public:
	int N ;
	vector<vector<int>> adj ;
	Graph(vector<vector<int>> edges , int N ){
		vector<int> V ; 
		adj.assign(N,V) ;
		this->N = N ; 
		for(auto &p : edges){
			adj[p[0]].push_back(p[1]) ; 
			// adj[p[1]].push_back(p[0]) ; 
		}
	}
};
bool Kahn_algo(vector<vector<int>> &adj,int N , vector<int> &v){
	vector<int> indegree(N) ;
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < adj[i].size() ;++j){
			indegree[adj[i][j]]++;
		}
	}
	vector<int>q ;
	for(int i = 0 ; i < N ; ++i){
		if(!indegree[i] ){
			q.push_back(i) ; 		
		}
		// cout<<i <<" : "<<indegree[i]<<endl;
	}
	int count = 0 ;

	while(!q.empty()){
		count++ ;
		v.push_back(q[0]) ; 
		int fr = q.front() ; 
		q.erase(q.begin()) ;  
		for(int j = 0 ; j < adj[fr].size() ; ++j ){
			// cout<<indegree[adj[fr][j]]<<" " ;
			indegree[adj[fr][j]]-- ;
			if(indegree[adj[fr][j]]==0)
				q.push_back(adj[fr][j]) ; 
		}
		// cout<<endl;
	}
	return count == N ; 
}

int main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
 
        
  #ifndef ONLINE_JUDGE
   freopen("/home/sriram/Coding-files/codeforces/in", "r", stdin);
   freopen("/home/sriram/Coding-files/codeforces/err", "w", stderr);
   freopen("/home/sriram/Coding-files/codeforces/out", "w", stdout);
   #endif
    vector<vector<int>> edges={
    	{ 5 , 0 } , { 5 , 2 } , { 4, 0 } , { 4 , 1 } , { 2 , 3 } , { 3 , 1 } 
    };

    int  N = 6 ; 

    // vector<vector<int>> edges = {
    // 	{0 , 1} , { 1 , 2 } , { 2 , 1 }
    // };
    // int N = 3 ;
    Graph g(edges , N) ; 

    vector<int> v ;
    if(Kahn_algo(g.adj,N, v)){
    	cout<<"It is DAG and the topological sorting is : "<<endl;
    	fr(i,v.size()){
    		cout<<v[i]<<" " ; 
    	}
    } 
    else{
    	cout<<" It is a cyclic graph" ; 
    }
    	cout<<endl;


}