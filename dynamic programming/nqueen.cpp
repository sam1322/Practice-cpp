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

int ctr = 1 ;
void Print(vector<vector<int>>v , int n ){
	for(int i = 0 ; i < n ;i++){
    		for(int j = 0 ; j < n ; j++){
    			cout<<v[i][j] <<" " ;
    		}
    		cout<<endl;
    	}
}

bool nqueen(vector<vector<int>> &v ,int row,int n ,vector<int> &l , vector<int> &r , vector<int> &cur)
{
	if(row>=n){
		cout<<"Solution "<<ctr++<<endl;
		Print(v,n);
		cout<<endl;
		return true ;
	}

	bool res = false ;
	for(int i = 0 ; i < n ; i++){
		if(!l[row - i + n -1 ] && !r[row + i] && !cur[i]){
			v[row][i] = l[row - i + n -1 ]  = r[row + i ]  = cur[i] = 1 ;
			cout<<row<<" "<<i<<endl;			
			res = (nqueen(v,row+1,n,l,r,cur) )|| res ;  
			
			v[row][i] = l[row - i + n -1 ]  = r[row + i]  = cur[i] = 0 ;

		}
	}
	return res ; 
}

int main()
{
     
   ios_base::sync_with_stdio(false);cin.tie(NULL);
 
        
  #ifndef ONLINE_JUDGE
   freopen("/home/sriram/Coding-files/codeforces/in", "r", stdin);
   freopen("/home/sriram/Coding-files/codeforces/err", "w", stderr);
   freopen("/home/sriram/Coding-files/codeforces/out", "w", stdout);
   #endif

   
    int n ;
    cout<<"Enter the no of queens ";
    cin>>n ; 
    vector<int> V(n);
    vector<int> leftdiagonal(2*n+1) ; 
    vector<int> rightdiagonal(2*n+1) ;
    vector<int> currentcolumn(n+1) ; 
    vector<vector<int>> v(n,V) ; 

    if(!nqueen(v,0,n,leftdiagonal ,rightdiagonal , currentcolumn)){
    	cout<<"Error occured "<<endl ; 
    }
    // else{
    // 	Print(v, n);
    // }

}