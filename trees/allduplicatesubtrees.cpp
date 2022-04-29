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

class Node{
    public:
    int data ;
    Node* left ,*right ; 

    Node(){
        left=right = NULL ; 

    }
    Node(int data){
        this->data = data;
        left=right = NULL ; 
        
    }
};

Node* takeInput(){
    int data ; 
    cin>>data;
    if(data==-1)return nullptr ;
    
    Node* root = new Node(data) ; 
// cout<<"Root "<<root->data<<endl;
    queue<Node*> q; 
    q.push(root) ;

    while(!q.empty()){
        Node* cur = q.front() ;
        // cout<<"cur root "<<cur->data<<endl;
        q.pop() ; 
        int leftdata,rightdata;
        cin>>leftdata>>rightdata;
        if(leftdata!=-1){
            Node* newNode= new Node(leftdata) ; 
            cur->left = newNode ; 
            q.push(cur->left) ; 
        }
        if(rightdata!=-1){
            Node* newNode= new Node(rightdata) ; 
            cur->right = newNode  ; 
            q.push(cur->right) ; 
        }

    }

    return root ; 

}

void Print(Node* root){
  
    queue<Node*> q; 
    q.push(root) ;

    while(!q.empty()){
        Node* cur = q.front() ;
        q.pop() ; 
       cout<<cur->data<<" ";
        if(cur->left){ 
            q.push(cur->left) ; 
        }

        if(cur->right){ 
            q.push(cur->right) ; 
        }

    }
 

}
 
string DuplicateSubtreeinBT(Node* root,unordered_set<string> &st  ){
    
    string s = "" ; 
    if(root==NULL)
        return s+"$" ;


    string Left = DuplicateSubtreeinBT(root->left,st  ) ;
        if(Left.empty()){
            return ""; 
        }
    string Right = DuplicateSubtreeinBT(root->right,st  ) ;
  
    if(Right.empty())return "" ;
      string str ="" ;
    str+=root->data ; 
    s += Left  + str + Right ; 
    
    if(s.size() > 3 && st.find(s)!=st.end()){
        return "" ; 
       
    }
    st.insert(s) ; 
    return s ; 
}

vector<int> f(Node* root , unordered_set<string> &st ,vector<string> &v){

    if(!root){
        return {};
    }

    vector<int> l = f(root->left,st,v) ;
    vector<int> r = f(root->right,st,v) ;
    
    l.push_back(root->data) ; 

    l.insert(l.end(), r.begin(),r.end());

    if(l.size()>1){
        string s ="" ; 
        for(auto i : l ){
            s+=i + " ";
        }
        if(st.find(s)!=st.end()){
            v.push_back(s);
        }
        else{
            st.insert(s) ;
        }
    }
    return l ; 

}

void solve(){

    Node* root = takeInput() ; 

    Print(root);
    unordered_set<string> st; 
    vector<string> v ; 
    vector<int> x = f(root,st,v) ;
    if(!v.empty()){
        for(auto &i:v){
            cout<<i<<endl;
        }
    }
    else{
        cout<<"-1"<<endl;
    }
}

int main()
{
    //  int tc;
    // scanf("%d", &tc) ; 
    // while(tc--){
        // cout<<solve()<<endl;
    // }
    solve() ;
}
