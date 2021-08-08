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
#include <chrono>
// sieve , binomial coeff , pascal 

//int solve(){

class Node {
	public:
	int val ;
	Node* next ; 
	Node(){
		next= NULL; 
	}
	Node(int data){
		val = data ;
		next = NULL ;
	}
};

Node* partition(Node* head){
	if(head==NULL || head->next==NULL){
        return head ; 
    }
	Node* slow = head , *fast = head ; int i = 0 ; 
	while(fast->next && fast->next->next){
		
            slow = slow->next ;
            fast = fast->next ->next ;
        
    }

    // cout<<"Slow "<<slow->val;nl;
	return slow ; 
}

Node *merge(Node *a,Node* b){
	if(a==NULL )return b ;
	if(b==NULL)return a ; 
	Node* res ; 
	if(a->val < b->val ){
		res = a ; 
		a->next = merge(a->next,b);
	}
	else{
		res = b ; 
		b->next = merge(a,b->next) ; 
	}
	return res ;
}

Node* mergesortll(Node* head){
	if(head==NULL || head->next == NULL)return head ; 
	cout<<head->val;nl;

	Node *slow = partition(head) ;
	Node* mid = slow->next ;
	slow->next = NULL ;
	// cout<<" Slow "<<slow->val<<endl; 
	// cout<<head <<" "<<mid<<endl;

	Node* head1 = mergesortll(head) ;
	Node* head2 = mergesortll(mid) ; 

	return merge(head1,head2) ; 

}


Node* push( Node* head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = head_ref;
   head_ref = new_node;
   return head_ref ; 
}

void printll(Node *head){
if(!head)return ; 

	for(;head!=NULL ; head= head->next ){
		cout<<head->val<<" ";
	}

}

void solve(){
	int a,n ; 
	cin>> n; 
	Node *head = NULL ;
	for(int i = 0 ; i < n ; ++i){
		cin>>a; 
		head = push(head,a) ; 
	}
	printll(head); nl;

	head = mergesortll(head) ; 
	printll(head); nl;

}

int main()
{

    ios_base::sync_with_stdio(false);cin.tie(NULL);
 
    
   #ifndef ONLINE_JUDGE
   freopen("/home/sriram/Coding-files/codeforces/input.txt", "r", stdin);
   freopen("/home/sriram/Coding-files/codeforces/error.txt", "w", stderr);
   freopen("/home/sriram/Coding-files/codeforces/output.txt", "w", stdout);
   #endif
    int tc;
    //scanf("%d", &tc) ; 
    cin>>tc; 

    while(tc--){
    	//cout<<solve()<<endl;
    	    auto started = std::chrono::high_resolution_clock::now();

      solve();

	 auto done = std::chrono::high_resolution_clock::now();
    std::cout <<"Time took "<< std::chrono::duration_cast<std::chrono::nanoseconds>(done-started).count();nl;

    
      //cout<<endl;
    }
}