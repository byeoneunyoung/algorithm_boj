#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, s;
    int arr[100001];
    cin>>n>>s;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    int l = 0, h= 0;
    int sum = arr[0];
    int len = n+1;

    while(l <= h && h < n){
        if(sum < s) sum += arr[++h];
        else {
            len = min(len, h-l+1);
            sum -= arr[l++];
        }
    }
    if(len == n+1) len = 0;
    cout<<len<<endl;
}