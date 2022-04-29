#include<bits/stdc++.h>
#include<algorithm>
#include"./nodetree.h"
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
#define nl cout<<endl;
#define vp vector<pair<int,int>> 
typedef pair<int,int> pii; 
// sieve , binomial coeff , pascal 
void Printlevel(Node* root){
  
    queue<Node*> q; 
    q.push(root) ;
int ind = 0;
    while(!q.empty()){
      cout<<ind<<" : ";
        ind++;
      int n = q.size() ; 
      for(int i = 0 ; i < n ; ++i) 
      { Node* cur = q.front() ;
        q.pop() ; 
       cout<<cur->data<<" ";
        if(cur->left){ 
            q.push(cur->left) ; 
        }

        if(cur->right){ 
            q.push(cur->right) ; 
        }
     }
cout<<endl;
    }
}
void PrintDfs(Node* root){
    if(!root)return  ;

    cout<<root->data<<" : ";

    if(root->left){
        cout<<root->left->data<<" , ";
    } 
    if(root->right){
        cout<<root->right->data<< " ;" ; 
    }
    cout<<endl;
    PrintDfs(root->left);
    PrintDfs(root->right);
}
Node* insertBst(int data , Node* root){
    if(!root){
        return root=new Node(data) ; 
    }
    if(root->data < data) {
        root->right = insertBst(data,root->right);
    }
    else{
        root->left = insertBst(data,root->left);
    }
    return root ; 

}
bool isBinaryTreeBst(Node *root, int Min = INT_MIN , int Max = INT_MAX)
{
    if(!root){
        return true ;

    }
    
    if(root->data < Min || root->data > Max )
        return false ;


    return (isBinaryTreeBst(root->left,Min,root->data - 1) && isBinaryTreeBst(root->right,root->data,Max)) ; 
}

Node * findMin(Node *root){
    if(!root)return NULL ; 

    while(root->left){
        root=root->left ; 
    }

    return root ; 
}

Node* Delete(Node* root,int data){
        if(root==NULL)return NULL ;
        if(root->data < data) 
            root->right = Delete(root->right , data ) ;
        else if(root->data > data)
            root->left = Delete(root->left,data ) ;
        else {
            if(root->left==NULL&&root->right==NULL){
                delete root ;
                root =  NULL ;
            }
            else if(root->left==NULL){
                Node* temp = root->right ; 
                delete root ; 
                root = temp ;
            }
            else if(root->right == NULL){
                   Node* temp = root->left ; 
                delete root ; 
                root =  temp ;
            }
            else{
                Node* temp = findMin(root->right);
                root->data = temp->data ;
                root->right = Delete(root->right,temp->data ) ;
                               
            }
        }
        
        return root ;
    }

bool f(Node *root, int Min = 1 , int Max = INT_MAX)
{
    if(!root){
        return false   ;

    }
    
    if(!root->left&& !root->right){
        cout<<"found a leaf node "<<root->data<<" ";
        bool check =  ((Min>root->data-1)&&(Max<root->data+1)) ;
        cout<<check<<endl;
        return check ; 
    }
    return (f(root->left,Min,root->data-1)||f(root->right,root->data+1,Max)) ; 
}

Node* Find(Node* root , int data ){
    if(!root)return NULL ; 

    // cout<<root<<" "<<root->data<<endl;

    if(root->data < data){
        return Find(root->right,data); 
    }
    else if(root->data > data ) {
        return Find(root->left,data) ; 
    }
    else return root ; 
}
Node* GetSuccessor(Node *root ,int data) {
    Node *current = Find(root,data); 


    // cout<<root<<" "<< current;nl;

    if(!current)return NULL ; 
    else if(current->right){ // if there is some right subtree 
        return findMin(current->right) ; //where the inorder successor can exist  
    }
    else{ // if there is no right subtree 
        Node* ancestor = root , *successor = NULL ; 
        // cout<<current<<"No right tree";nl;
        while(ancestor!=current){
            if(current->data < ancestor->data){
                successor = ancestor ; //so far this is the deepest node 
                ancestor = ancestor->left ; 
            }
            else{
                ancestor = ancestor->right ; 
            }
        }
        return successor ; 
    }
}

void printSuccessor(Node* root, int ele ){
    Node* successor = GetSuccessor(root, ele) ;
    if(successor){
        cout<<"successor of element "<<ele<<" is "<<successor->data<<endl;
    }
    else {
        cout<<"No successor of element "<<ele;nl;
    }
}

void deleteTree(Node* root){
    if(root==NULL)return ; 
    deleteTree(root->left);
    deleteTree(root->right);
    cout<<"Deleting node "<<root->data<<endl;
    delete root ; 
}

void solve(){
    int n;
    // cout<<"enter ";
    cin>>n;
    vi a(n) ;
    fr(i,n)cin>>a[i];
    Node* root = NULL ; 
    fr(i,n){
        root= insertBst(a[i],root);
    }
    inorder_iter2(root);nl;
    // cout<<endl;
    Printlevel(root);
    int deletedElement = 3 ; 

    cout<<"Deleted element "<<deletedElement<<endl;
    
    root = Delete(root,deletedElement);
    
    PrintDfs(root);
    
    int ele = 1 ; 
    printSuccessor(root,ele);
    // Printlevel(root);
       // cout<<endl;
    cout<<isBinaryTreeBst(root)<<endl;

    Node* root2 = takeInput() ; 
    PrintDfs(root2) ; 
    cout<<isBinaryTreeBst(root2);nl;
    ele = 63;
    deleteTree(root2) ; 
    printSuccessor(root2,ele);

}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
 
    
   #ifndef ONLINE_JUDGE
   freopen("/home/sriram/Coding-files/codeforces/input.txt", "r", stdin);
   freopen("/home/sriram/Coding-files/codeforces/error.txt", "w", stderr);
   freopen("/home/sriram/Coding-files/codeforces/output.txt", "w", stdout);
   #endif
    solve();
}

/*
for this program 
eg
6
3 1 5 2 7 4
*/

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