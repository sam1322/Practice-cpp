#include<bits/stdc++.h>
using namespace std ;
int table[1020][1020] ; 

void lcslength(string &x,string &y){
    
    for(int i = 0;i <x.size();i++){
        for(int j= 0 ; j<y.size();j++){
            if(x[i]==y[j]){
                table[i+1][j+1] = table[i][j] + 1 ;
            }
            else{
                table[i+1][j+1] = max(table[i][j+1] ,table[i+1][j] ) ; 
            }
        }
   }

}


string lcs(string &x,string &y,int m ,int n ){

    if(m==0||n==0)return "";
 

    string k = "" ;

    if(x[m-1]==y[n-1]){
        return lcs(x,y,m-1,n-1) + x[m-1];
    }
    else if(table[m-1][n] >table[m][n-1]) {
        return lcs(x,y,m-1,n) ;

    }
    else return lcs(x,y,m,n-1) ;

}
string lcs(string &x,string &y){
    int m = x.size() , n  = y.size() ;
    lcslength(x,y) ; 
    return lcs(x,y,m,n) ;
}

int main(){
    string x,y ;
    cout<<"Enter two strings\n" ;
    cin>>x>>y ;
    cout<<"The longest common substring is\n" ;
    string r =lcs(x,y) ;
    cout<<r<<endl; 
}