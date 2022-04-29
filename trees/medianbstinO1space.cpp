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
#define vp vector<pair<int,int>> 
typedef pair<int,int> pii; 
// sieve , binomial coeff , pascal 

void check(int &med,int size,int cur ,int data ){
    if(size==-1)return ; 

    if(size%2){
        if(cur ==(size+1)/2){
            med = data;
        }
    }
    else{
        if(cur==size/2){
            med+=data;
        }
        else if(cur == (size/2) + 1)
           { med+=data ;
            med/=2 ;
           }
    }

}

int morris_inorder_traversal_count(Node* root,int size = -1){
    Node* cur = root ; 
    int ans = 0 ; 
    int median = 0 ; 
    while(cur){
        if(size!=-1 && ans >size/2 )
            return median ; 
        if(cur->left){
            Node* pred = cur->left ; //predecessor
            while(pred->right && pred->right!=cur){
                pred = pred->right ; 
            }
            if(pred->right==cur){
                pred->right = NULL ; 
                ans++;
                check(median,size,ans,cur->data);
                cur = cur->right;
            }
            else{
                pred->right = cur ; 
                cur = cur ->left  ; 
            }
        }
        else{
            ans++;
            check(median,size,ans,cur->data);
            cur = cur->right ; 
        }
    }
    return ans ;
}
int getCount(Node *root, int l, int h)
{
  // your code goes here   
 if(!root)return 0 ; 
 int ans = 0 ; 
 if(root->data >=l && root->data<= h )
    {
        ans++;
        ans+=getCount(root->left,l,h);
        ans+=getCount(root->right,l,h);
        
    }
else if(root->data> h ){
    ans+=getCount(root->left,l,h);
}
else {
    ans+=getCount(root->right,l,h) ;
 }
    return ans; 
    
}
void solve(){

    Node* root = takeInput() ; 

    // Print(root);
    // cout<<endl;
    inorder_iter2(root);
    cout<<endl;
    int size =  morris_inorder_traversal_count(root) ; 
    
    int median =morris_inorder_traversal_count(root,size) ; 

    cout<<"Median = "<<median <<" size = "<<size<<endl;
   
   
    cout<<"enter l and h ";
    int l , h ; 
    cin>>l>>h;
    cout<<getCount(root,l,h)<<endl ;
    
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
bst1
4 3 5 2 -1 -1 7 -1 -1 -1 -1 
4 3 6 2 -1 5 7 -1 -1 -1 -1 -1 -1
bst2


bst
6 4 7 -1 5 -1 40 -1 -1 -1 50 -1 -1  

54 92 9 4 41 26 63 -1 -1 -1 -1 -1 -1 -1 -1

bst 
54 26 92 9 41 63 -1 4 -1  -1 -1 -1 -1 -1 -1

*/
 