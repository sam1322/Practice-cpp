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

Node* insertBst(int a ,Node* root ,Node*& succ ){
    if(!root)
    {
        Node* newNode = new Node(a);
        return newNode ; 
    }
    if(a < root->data){
        succ = root ; 
        root->left = insertBst(a,root->left,succ) ; 
    }
    else{
        root->right= insertBst(a,root->right,succ);
    }
    return root ;
}

 

void bstreplace(vector<int> &v){
    int n = v.size() ,val ;
    Node* root = NULL ,*succ;
    for(int i = n-1 ; i >= 0 ; --i){
        succ=NULL ;
        root=insertBst(v[i],root,succ);
        v[i] = (succ==NULL)?-1:succ->data ; 
        cout<<"( "<<i<<" ) " ;
        Print(root);
        cout<<endl;
    } 
}

void solve(){
    vector<int> v ;
    int a,n ; 
    cin>>n;
    fr(i,n){
        cin>>a;
        v.pb(a) ;
    }
    
    bstreplace(v);
    Show(v);
    cout<<endl;
}

int main()
{
    solve();
}
/*

8 58 71 18 31 32 63 92 43 3 91 93 25 80 28
*/