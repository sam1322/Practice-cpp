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
typedef pair<int,int> pii ;
typedef pair<int,pair<int,int>> piii ;

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
			adj[p.src].push_back(mk(p.dest ,p.wt) ) ; 
		    adj[p.dest].push_back(mk(p.src ,p.wt) ) ; 
		}
	}

};

int find(vector<int>&parents , int v){
	if(parents[v]==-1)
		return v ;

	parents[v] = find(parents,parents[v])  ;
	return parents[v] ; 
}

bool Unionfind(vector<int> &rank , vector<int> &parents , int a,int b){
	int x = find(parents , a) ;
	int y = find(parents , b) ;

	if(x==y)
		return true; 

	if(rank[x] > rank[y]){
		parents[y] = x ;
	}
	else if(rank[x] < rank[y] ){
		parents[x] = y ; 
	}
	else{
		parents[x] = y  ;
		rank[y]++ ; 

	}
	return false ; 

}

void Kruskal(Graph &g ){
	priority_queue< piii ,vector<piii> , greater<piii>> q ;
	vector<int>parents(g.N , -1 ) ; 
	vector<int> rank(g.N , 0) ; 
	vp mst ; 
	// int count = 1 ;
	int minimumcount =  0;
	for(int i = 0 ; i < g.N ; ++i){
		for(auto &x: g.adj[i]){
			q.push({ x.second , {i , x.first }}) ; 
		}
	}

	while(!q.empty()){
		piii p = q.top() ;
		q.pop() ; 
		int wt = p.first , a = p.second.first , b =p.second.second ;
		if(!Unionfind(rank,parents,a,b)){
			// count++ ; 
			minimumcount+=wt ; 
			mst.push_back(p.second) ; 
		} 

	}

	cout<<"Minimum sum " <<minimumcount<<endl;
	cout<<"MST \nindex parent\n" ;
	for(auto &x: mst){
		cout<<x.first<<"\t"<<x.second<<endl;
	}
}


void Kruskal(vector<vector<pii>> &adj , int N ){
	priority_queue< piii ,vector<piii> , greater<piii>> q ;
	vector<int>parents(N , -1 ) ; 
	vector<int> rank(N , 0) ; 
	vp mst ; 
	// int count = 1 ;
	int minimumcount =  0;
	for(int i = 0 ; i < N ; ++i){
		for(auto &x: adj[i]){
			q.push({ x.second , {i , x.first }}) ; 
		}
	}

	while(!q.empty()){
		piii p = q.top() ;
		q.pop() ; 
		int wt = p.first , a = p.second.first , b =p.second.second ;
		
		if(!Unionfind(rank,parents,a,b)){
			minimumcount+=wt ; 
			mst.push_back(p.second) ; 
		} 

	}

	cout<<"Minimum sum " <<minimumcount<<endl;
	cout<<"MST \nindex parent\n" ;
	for(auto &x: mst){
		cout<<x.first<<"\t"<<x.second<<endl;
	}
}
		// cout<<"A - "<<a<<" B - "<<b<<" wt : "<<wt;
			// cout<<"MinSum = "<<minimumcount ;



int main()
{
    
   ios_base::sync_with_stdio(false);cin.tie(NULL);
 
        
  #ifndef ONLINE_JUDGE
   freopen("/home/sriram/Coding-files/codeforces/in", "r", stdin);
   freopen("/home/sriram/Coding-files/codeforces/err", "w", stderr);
   freopen("/home/sriram/Coding-files/codeforces/out", "w", stdout);
   #endif
    vector<edge> edges = { 
        { 0 , 1 , 4 } , 
        { 0 , 7 , 8 } , 
        { 1 , 7 , 11} , 
        { 1 , 2 , 8 } , 
        { 2 , 8 , 2 } , 
        { 2 , 5 , 4 } , 
        { 2 , 3 , 7 } ,  
        { 3 , 4 , 9 } , 
        { 3 , 5 , 14} , 
        { 4 , 5 , 10} , 
        { 5 , 6 , 2 } , 
        { 6 , 8 , 6 } , 
        { 6 , 7 , 1 } , 
        { 7 , 8 , 7 }
    } ; 
    int N = 9 ;

    Graph g(edges , N);

    // Kruskal(g) ;
    Kruskal(g.adj,g.N) ;


}