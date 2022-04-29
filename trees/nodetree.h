 #include<bits/stdc++.h>
#include<algorithm>
 
using namespace std;
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