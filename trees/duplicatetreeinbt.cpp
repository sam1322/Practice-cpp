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

template<typename T> 
class tree { 
    public:
    T data ; 
    tree<T> *left , *right ; 

    tree(int data){
        this->data = data ;
        this->left = NULL;
        this->right = NULL ;
    }



} ;
tree<int>* takeinput(){
    int data ;
    // cout<<"Enter data(except -1 else it terminates)\n" ;
    cin>>data ;
    tree<int>* root = NULL ;
    if(data == -1 ){
        return root ;    }
    root = new tree<int>(data)  ;
    tree<int>* leftchild = takeinput() ;
    root ->left = leftchild ;
    tree<int>* rightchild = takeinput() ;
    root ->right = rightchild ;
    return root ;
}

tree<int>* takeinputlevelwise(){
    int data ;
    cin>>data;
    if(data==-1)return 0 ;
    tree<int>* root  = new tree<int>(data) ;
    queue<tree<int>* > pending_queue ; 
    pending_queue.push(root) ; 
    while(!pending_queue.empty()){
        tree<int>* current = pending_queue.front() ;
        pending_queue.pop() ;
        int leftdata  , rightdata;
        cin>>leftdata>>rightdata ;
        if(leftdata!=-1){
            tree<int>* leftchild = new tree<int>(leftdata) ;
            current->left = leftchild ;
            pending_queue.push(leftchild) ;

        }
        if(rightdata!=-1){
            tree<int>* rightchild = new tree<int>(rightdata) ;
            current->right = rightchild ;
            pending_queue.push(rightchild) ;

        }
    }
    return root ;
}

void printtree(tree<int>* root){
    if(root==NULL)return;
    cout<<root->data<<" " ;
    printtree(root->left) ;
    printtree(root->right)  ;

}

void printlevelwise(tree<int>* root){
    if(root==NULL)return ; 
    queue<tree<int>*> pending_queue ; 
    pending_queue.push(root) ;
    while(!pending_queue.empty()){
        tree<int>* current = pending_queue.front() ;
        pending_queue.pop() ;
        cout<<current->data<<" :";
        if(current->left!=NULL){
            cout<<" L "<<current->left->data<<" , ";
            pending_queue.push(current->left) ;
        }
        else{
            cout<<" L -1 ," ;
        }
        if(current->right!=NULL){
            cout<<" R "<<current->right->data<<" , ";
            pending_queue.push(current->right) ;
        }
        else{
            cout<<" R -1 " ;
        }
        cout<<endl;
    }
}

//asked in google
string DuplicateSubtreeinBT(tree<int>* root,unordered_set<string> &st  ){
    
    string s = "" ; 
    if(root==NULL)
        return s+"$" ;


    string Left = DuplicateSubtreeinBT(root->left,st ) ;
 if(Left.empty()){
     return ""; 
 }
    string Right = DuplicateSubtreeinBT(root->right,st ) ;
  
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



int main()
{
    tree<int>* root  = takeinputlevelwise() ;
    printlevelwise(root) ;
}
 

/*
1 2 3 4 5 -1 -1 -1 -1 -1 7 -1 -1

1 2 4 -1 -1 5 -1 -1 3 -1 7 -1 -1

8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
*/

