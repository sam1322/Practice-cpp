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
  
/*
Satyajit • a year ago • edited
Tip : It is very important to understand LCA in various scenarios before attempting the question.

The solution is very easy if all scenarios understood clearly.

scenario 1: both n1 and n2 are in left and right subtree of the ancestor. (return the ancestor)
scenario 2 : either n1 or n2 is the ancestor or other. Then return the ancestor(node n1 or n2)
scenario 3 : only one of n1 or n2 found. the return that node
scenario 4 : none found. return null

I misunderstood and spent unnecessary time. Hence just writing the scenarios explicitly for others.
*/
  
Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       
       if(!root)return NULL  ; 
       if(root->data==n1||root->data==n2) return root ; 
       Node* l = lca(root->left,n1,n2);
       Node* r = lca(root->right,n1,n2);
       
       if(r&&l)return root; 
       
       
       if(l)return l ;
       return r ;
       
    }

void solve(){

    Node* root = takeInput() ; 

    Print(root);
    int n1 ,n2 ; 
    cout<<"Enter n1 n2 " ;
    cin>>n1>>n2;  
    Node* LCA = lca(root,n1,n2) ;
    if(LCA)
    cout<<LCA->data<<endl;
    else
    cout<<"None found "<<endl;
}

int main()
{ 
    solve() ;
}

/*
1 2 3 4 5 -1 -1 -1 -1 -1 7 -1 -1

*/