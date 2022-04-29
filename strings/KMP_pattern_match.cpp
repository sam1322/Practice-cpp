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

void CalculateLPS(string &a,int lps[]){
    int m =a.size(), len = 0 ,i = 1 ;
    lps[0] = 0;
    while(i< m){
        if(a[len]==a[i]){
            lps[i] = len+ 1 ;
            len++ ;
            i++;
        }
        else{
            if(len!=0){
                len = lps[len - 1 ] ; 
             }
            else{
                lps[i] = 0 ; 
                i++;
            }
        }
    }

}

void KMPSearch(vector<int> &v ,string pat ,string txt){
    int n = txt.size(), m = pat.size() ; 
    
    int lps[m] ;
    CalculateLPS(pat,lps) ;

    int j=0,i = 0 ;
    while(i<n){
        if(txt[i] == pat[j]){
            i++ ;
            j++;
        }
        else{
                if(j != 0 ){
                    j = lps[j-1 ] ;
                }
                else{
                    i++;
                }
        
        }
        if(j==m){
            // cout<<i - j <<" "; 
            v.push_back(i-j);
            j = lps[j - 1] ;
        }
    }

}

int main()
{
    Ios;
    Tie;
    string s , p ;
    cout<<"Enter the string to be searched "<<endl ;
    cin>>s;
    cout<<"Enter the pattern to be matched"<<endl ;
    cin>>p; 

    vector<int> v ;
    KMPSearch(v,p,s) ;
    if(v.empty()){
        cout<<"No Match found" ;
    }
    else{
        cout<<v.size()<<" match found\n" ;
        cout<<"At index ";
        for(auto x:v){
            cout<<x<<" " ; 
        }
        cout<<endl;

    }
}
