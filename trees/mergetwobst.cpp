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
 
 
void inorder(Node *root , vector<Node*> &v){
    if(!root)return ;

    inorder(root->left,v);
    v.push_back(root);
    inorder(root->right,v) ; 
}
Node* dfs(vector<Node*> &v, int st , int end);
Node* convertBSTtobalancedBST(Node* root);

vector<Node*> merge(vector<Node*> &v1,vector<Node*>&v2){
    int i = 0 ,j = 0  , n1 = v1.size() ,n2 =v2.size() ; 
    vector<Node*> v ;
    while(i<n1 && j<n2){
        if(v1[i] < v2[j]){
            v.push_back(v1[i++]) ;
        }
        else{
            v.push_back(v2[j++]);
        }
    }
    while(i<n1){
            v.push_back(v1[i++]) ;
    }
    while(j<n2){
            v.push_back(v2[j++]);
    }
    return v ; 
}



void solve(){
    cout<<"first bst tree" <<endl;
    Node* root1 = takeInput() ; 
    cout<<"second bst tree" <<endl;
    Node* root2 = takeInput() ; 
   
    vector<Node*> v1 ,v2 ; 
    inorder(root1,v1);
    inorder(root2,v2);

    vector<Node*> v = merge(v1,v2);

    Node* newroot =  dfs(v,0,v.size()) ;
    cout<<"Balanced bst "<<endl;
    Print(newroot);
}

Node* dfs(vector<Node*> &v, int st , int end){
    if(st>=end)return NULL ;

    int mid = st + (end-st)/2 ; 

    v[mid]->left = dfs(v,st,mid);
    v[mid]->right = dfs(v,mid+1,end) ; 
    return v[mid] ; 
}

Node* convertBSTtobalancedBST(Node* root){
    if(!root)return NULL; 

    vector<Node*> v;
    inorder(root,v);
    Show(v);
    cout<<endl;
    Node* res = dfs(v,0,v.size()) ; 
    return res ; 
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
1 2 3 4 5 -1 -1 -1 -1 -1 7 -1 -1  binary tree

bst
6 4 7 -1 5 -1 40 -1 -1 -1 50 -1 -1  

54 92 9 4 41 26 63 -1 -1 -1 -1 -1 -1 -1 -1

bst 
54 26 92 9 41 63 -1 4 -1  -1 -1 -1 -1 -1 -1
*/
