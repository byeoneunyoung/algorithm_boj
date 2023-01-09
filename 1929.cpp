#include<iostream>
#include<cmath>
//에라토스테네스의 채
using namespace std;
 int m = 0, n = 0;
 int pN[1000001] = {0, };
int main() {
    cin>>m>>n;
    for(int i = 2; i<=n; i++){
        pN[i] = i;
    }
    for(int i = 2; i*i<=n; i++){
        if(pN[i] == 0) continue;
        for(int j = i*i; j<=n; j+=i)
            pN[j] = 0;
    }
    for(int i = m; i<=n; i++){
        if(pN[i] != 0) cout<<pN[i]<<"\n";
    }
    return 0;
}
