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

class job {
    public:
    int at,bt ,ct,wt,tt ;
    bool comp;
    job(){
        at=bt=wt=ct=tt= 0;
        comp = false;
    }
};

class Compare{
    public:
    bool operator() (job j1,job j2){
        return j1.at < j2.at ; 
    }
};
int solve(){
    int n;
    cout<<"Enter the no of process ";
    cin>>n;
    vector<job> j(n);
    fr(i,n){
        cin>>j[i].at>>j[i].bt ;
    }
    sort(j.begin(),j.end(),[](job j1,job j2){
        return j1.at < j2.at ; 
    }) ;
    int time = j[0].at + j[0].bt ;
    j[0].ct= time;
    j[0].tt = j[0].bt; 
    j[0].comp = 1 ;
    cout<<j[0].at<< "\t"<<j[0].bt<<"\t"<<j[0].ct<<"\t"<<j[0].wt<<"\t"<<j[0].tt<<endl; 
    int ind = 1 , Min ,mind ; 
    while(ind < n){
        mind = -1 ;
        Min = inf ; 
        for(int i = 0 ; i < n ;++i){
            if(j[i].at <= time ){
                if(!j[i].comp &&  j[i].bt < Min){
                    Min = j[i].bt ;
                    mind = i ;
                }
            }
            else if(mind==-1){
                mind = i ;break ;
            }
            else{
                break;
            }
        }
        ind++;
        time+=j[mind].bt ; 
        j[mind].comp = 1;  
        j[mind].ct = time ; 
        j[mind].tt = j[mind].ct  - j[mind].at ;     
        j[mind].wt = j[mind].tt  - j[mind].bt ;    
        cout<<j[mind].at<< "\t"<<j[mind].bt<<"\t"<<j[mind].ct<<"\t"<<j[mind].wt<<"\t"<<j[mind].tt<<endl;  
    }

    // for(int i = 0 ; i < n ; ++i){
    //     cout<<j[i].at<< "\t"<<j[i].bt<<"\t"<<j[i].ct<<"\t"<<j[i].wt<<" "<<j[i].tt<<endl; 
    // }
    return 0 ;

}

int main()
{
    solve() ;
}

/*
   2               3 
   0               4 
   4               2
   5               4
*/