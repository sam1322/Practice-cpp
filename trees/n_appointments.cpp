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
 
// inorder recursive
void inorder(Node *root , vector<Node*> &v){
    if(!root)return ;

    inorder(root->left,v);
    v.push_back(root);
    inorder(root->right,v) ; 
}
//inorder iterative using stack
void inorder_iter(Node* root ){
    stack<Node*> st;
    unordered_map<Node*,int>cnt;

    st.push(root) ;
    while(!st.empty()){
        Node* cur = st.top() ; 
     
        if(cur==NULL){st.pop();continue ; }
       if(!cnt[cur])
            st.push(cur->left) ; 
        else if(cnt[cur]==1){
            cout<<cur->data<<" "; 
        }
        else if(cnt[cur]==2){
            st.push(cur->right);
        }
        else{
            st.pop() ; 
        }
        
        cnt[cur]++;
    }
}
//without map
void inorder_iter2(Node* root ){
    stack<pair<Node*,int>> st;
     st.push({root,0}) ;
    while(!st.empty()){
        Node* cur = st.top().first ; 
        int state = st.top().second ; 
   
        if(cur==NULL||state==3){st.pop();continue ; }

        st.top().second++;
            

       if(!state)
            st.push({cur->left,0}) ; 
        else if(state==1){
            cout<<cur->data<<" "; 
        }
        else if(state==2){
            st.push({cur->right,0});
        }
        else{
            st.pop() ; 
        }
        
    }
}

void morris_inorder_traversal(Node* root){
    Node* cur = root ; 
    while(cur){
        if(cur->left){
            Node* pred = cur->left ; //predecessor
            while(pred->right && pred->right!=cur){
                pred = pred->right ; 
            }
            if(pred->right==cur){
                pred->right = NULL ; 
                cout<<cur->data<<" " ;
                cur = cur->right;
            }
            else{
                pred->right = cur ; 
                cur = cur ->left  ; 
            }
        }
        else{
            cout<<cur->data<<" ";
            cur = cur->right ; 
        }
    }
}




void solve(){

    Node* root = takeInput() ; 

    Print(root);
    cout<<endl;
    inorder_iter2(root);
    cout<<endl;
    
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

/*
 binary tree
1 2 3 4 5 -1 -1 -1 -1 -1 7 -1 -1 

bst
6 4 7 -1 5 -1 40 -1 -1 -1 50 -1 -1  

54 92 9 4 41 26 63 -1 -1 -1 -1 -1 -1 -1 -1

bst 
54 26 92 9 41 63 -1 4 -1  -1 -1 -1 -1 -1 -1

8 58 71 18 31 32 63 92 43 3 91 93 25 80 28

*/