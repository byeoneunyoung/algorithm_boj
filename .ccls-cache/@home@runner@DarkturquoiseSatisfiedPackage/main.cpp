#include <iostream>
using namespace std;
long gcd(long a, long b){
  long t;
  while(b!=0){
    t = a%b;
    a = b;
    b = t;
  }
  return a;
}
long lcm(long a, long b){
  return a*b/gcd(a, b);
}
int main(){
  int n;
  cin>>n;
  long a, b;
  for(int i = 0; i<n; i++){
    cin>>a>>b;
    cout<<lcm(a,b)<<endl;
  }
}