#include <bits/stdc++.h>
#define MOD 1000000007
#define loopex(a,b) for(int i=a;i<b;i++)
#define loopin(a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long int ll;


ll pivot(ll arr[], int n,int s,int e){
	
	while(s<=e){
		int mid=(s+e)/2;
		if(arr[mid]<arr[mid-1]){
			return mid-1;
		}
		if(arr[mid]>arr[mid+1]){
			return mid;
		}
		if(arr[s]<=arr[mid]){
			s=mid+1;
		}
		else{
			e=mid-1;
		}
	}
	
	return -1;
}
int main(){
	int n;
	cin>>n;
	ll arr[n];
	loopex(0,n){
		cin>>arr[i];
	}
	ll ans=pivot(arr,n,0,n-1);
	cout<<ans<<endl;
}
