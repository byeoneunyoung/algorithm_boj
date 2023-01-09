#include<iostream>
#include<cmath>
//에라토스테네스의 채
#define MAX 1000001
using namespace std;
void main(){
    int m, n;
    cin>>m>>n;
    int pN[MAX];
    for(int i = 2; i<=n; i++){
        pN[i] = i;
    }
    for(int i = 2; i<sqrt(n); i++){
        if(pN[i] == 0) continue;
        for(int j = i*i; j<=n; j+=i)
            pN[j] = 0;
    }
    for(int i = m; i<=n; i++){
        if(pN[i] != 0) cout<<pN[i]<<"\n";
    }
}
