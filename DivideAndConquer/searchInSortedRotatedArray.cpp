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
ll search(ll arr[], int n,int s,int e,ll x){
	while(s<=e){
		int mid=(s+e)/2;
		if(arr[mid]==x){
			return mid;
		}
		if(arr[s]<=arr[mid]){
		
			if(x>=arr[s] && x<arr[mid]){
				e=mid-1;
			}
			else{
				s=mid+1;
			}
		}
		else{
			 if(x>arr[mid] && x<=arr[e]){
				s=mid+1;
			}
			else{
				e=mid-1;
			}
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
	int x;
	cin>>x;
	ll ans=search(arr,n,0,n-1,x);
	cout<<ans<<endl;
}
