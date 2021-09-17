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
const int  alphabet_size = 256 ; 
//int solve(){

class trie{
	public:
	vector<trie*> child ; 
	bool isEndofWord ; 
	trie(){
		child.assign(256,NULL) ;
		isEndofWord = false ; 
	}
	~trie(){
		child.clear(); 

	}
};
 
void insert(trie*root ,string data){
	trie* temp = root ;
	int n = data.size() ;  
	for(int i = 0 ; i < n ;++i){
		int index = data[i] ;
		// int index = data[i] - 'A' ; 
		if(temp->child[index]==NULL){
			temp->child[index] = new trie;
		}

		temp = temp->child[index] ; 

	}
	temp->isEndofWord = true ; 
} 

bool search(trie* root, string word){
	int n = word.size() ;
	for(int i = 0 ; i < n ;++i){
		if(root->child[word[i]]==NULL){
			return false ;
		}
		root = root->child[word[i]] ; 
	}
	return root->isEndofWord ; 
}

void print(trie* root ,string s=""){


	for(int i = 0 ; i < 256 ; ++i ){
		if(root->child[i]){
			// char ch = i;
			print(root->child[i],s+(char)i);
		}
	}
	if(root->isEndofWord)
	cout<<s<<endl;
}

void printAll(trie* root,vector<string> &res,string cur ){

	if(root->isEndofWord){
		res.push_back(cur) ; 
	}

	for(int i = 0 ; i < 256 ; ++i){
		if(root->child[i]){
			printAll(root->child[i],res,cur+ char(i)) ; 
		}
	}

}

void find(trie* root , string word){
	int n = word.size() ;
	trie* it = root ;
	for(int i = 0 ; i < n ;++i){
		if(it->child[word[i]]==NULL){
			cout<<"No suggestions"<<endl;
			insert(root ,word );
			return ; 
		}
		it = it->child[word[i]] ;
	}

	vector<string> res; 
	printAll(it,res,"");
	for(string c:res){
		cout<<word<<c<<endl;
	}

}

void solve(){
	trie* T = new trie ;
	// insert(T,"hello");
	// insert(T,"hallo");
	vector<string> words = {"abracadabara", "alladin", "hello","allisweLL","allisGood","allmightyEvan"} ;
	for(string &w:words){
		insert(T,w) ;
	}
	print(T);
	find(T,"all");
	cout<<search(T,"hello")<<endl;
	cout<<search(T,"helloe")<<endl;

}

int main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
 
        
  #ifndef ONLINE_JUDGE
   freopen("/home/sriram/Coding-files/codeforces/in", "r", stdin);
   freopen("/home/sriram/Coding-files/codeforces/err", "w", stderr);
   freopen("/home/sriram/Coding-files/codeforces/out", "w", stdout);
   #endif

    // int tc;
    // //scanf("%d", &tc) ; 
    // cin>>tc; 
      solve();
      //cout<<endl;
}