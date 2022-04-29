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
// class Compare{
//     public:
//     bool operator() (foo,foo){
//         return expression
//     }
// };

class dll{
    public:
    int data ;
    dll *prev , *next ;
    dll(){
        data = 0 ;
        prev = next = NULL ;
    }
    dll(int data){
        this->data = data ; 
        prev = next = NULL ;     
    }
};

class mystack{
    public:
    dll *head ;
    dll *mid ; 
    int size ; 
    mystack(){
        head = mid = NULL ; 
        size = 0 ; 
    }
    mystack(dll *head){
        this->head = this->mid = head ; 
        size = 1; 
    }
};

 void push(mystack *ms , int data){
        dll *node = new dll(data) ; 
        // if(ms==NULL){
        //     ms = new mystack(node) ; 
        //     return ; 
        // }
        ms->size++ ;

        if(ms->head==NULL){
            ms->head = ms->mid = node ;
            return ;
        }
        node->next = ms->head ; 
        ms->head->prev = node ;
        ms->head = node ; 

        if(ms->size % 2 ){
            ms->mid  = ms->mid->prev ; 
        }
        cout<<ms->head->data<<endl;

    }

    int pop(mystack* ms){
        if(ms==nullptr||ms->head==NULL){
            return -1; 
        }

        ms->size-- ;
        dll* temp = ms->head ; 
        if(ms->size<=0){
            ms->head = ms->mid = NULL ; 
            return -1; 
        }
        else{
            if(ms->size%2==0){
                ms->mid =ms->mid->next ;
            }
            ms->head=ms->head->next ; 
        }
        int val = temp->data;
        delete temp ; 
        return val ;
    }

    int findMiddle(mystack* ms){
        if( ms==NULL || ms->head == nullptr)return -1 ;
        
        return ms->mid->data ; 
    }

    int deleteMiddle(mystack *ms){
        if(ms==nullptr||ms->head==NULL){
            return -1; 
        }
        else if(ms->size<=0){
            ms->head = ms->mid = NULL ; 
            return -1; 
        }
        dll *temp = ms->mid ; 
        temp->prev->next = temp->next ; 
        temp->next->prev = temp->prev ;
        if(ms->size % 2 ){
            ms->mid = temp->next ; 
        }
        else{
            ms->mid = temp->prev ; 
        }
        ms->size--;
        int val = temp->data ; 
        delete temp ;
        return val ; 
    }

void solve(){
     mystack* ms = new mystack();
    push(ms, 1);
    push(ms, 2);
    push(ms, 3);
    push(ms, 4);
    push(ms, 5);
    push(ms, 6);
    push(ms, 7);
    cout<<"middle element "<<findMiddle(ms)<<endl;
    cout<<"Poped the head "<<pop(ms)<<endl;
    cout<<"middle element "<<findMiddle(ms)<<endl;
    cout<<"Poped the head "<<pop(ms)<<endl;
    cout<<"middle element "<<findMiddle(ms)<<endl;
    cout<<"Deleting the middle element  "<<deleteMiddle(ms)<<endl;
    cout<<"middle element "<<findMiddle(ms)<<endl;
    cout<<"Deleting the middle element  "<<deleteMiddle(ms)<<endl;
    cout<<"middle element "<<findMiddle(ms)<<endl;
}

int main()
{
 
       solve() ;
 
}
