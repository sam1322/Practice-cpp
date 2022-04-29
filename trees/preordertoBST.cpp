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

Node* preordertoBST(vi &a, int &i,int Min = -inf,int Max = inf ){
    if(i>=a.size())
        return NULL ; 
    Node* root = NULL; 
    if(a[i]>=Min && a[i]<= Max )
       {    root = new Node(a[i++]);
            root->left = preordertoBST(a,i,Min,root->data) ; 
            root->right = preordertoBST(a,i,root->data,Max) ; 
       }
   
   return root ;
}

void solve(){
    int n ; 
    cout<<"Enter the no ";
    cin>>n;
    vi a(n);
    fr(i,n)cin>>a[i] ; 
    int  I = 0 ;
    Node* root = preordertoBST(a,I);
    inorder_iter2(root);
    cout<<endl;
    Print(root);
    cout<<endl;
 
}

int main()
{
solve();
}
