#include <bits/stdc++.h>
#define MOD 1000000007
#define loopex(a,b) for(int i=a;i<b;i++)
#define loopin(a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long int ll;

int fun(int n,int m){
  if(n<m) return 1;
  if(n==m) return 2;
 
  return (fun(n-1,m)+fun(n-m,m))%MOD;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;int m;
    cin>>n>>m;
    cout<<fun(n,m)<<endl;
  }
}
