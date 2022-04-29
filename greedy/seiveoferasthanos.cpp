#include<bits/stdc++.h>
using namespace std ;

bool prime[1000000000] ;

void SieveofErathanos(int n){
for(int i = 0;i<=n;i++){
    prime[i]=1;
}

prime[0] = 0;
prime[1] = 0 ;
prime[2] = 1;
for(int i = 2 ; i<=n;i++){
    if(prime[i]){
        for(int j = 2;i*j<=n ;j++){
            prime[i*j] = 0 ;
        }
    }
}
}

void PrintPrime(int n){
SieveofErathanos(n);
for(int i = 2 ;i<=n;i++){
    if(prime[i]){
        cout<<i<<"\n";
    }
}
}

int main(){
int n ;
cin>>n ;
PrintPrime(n) ;
}
