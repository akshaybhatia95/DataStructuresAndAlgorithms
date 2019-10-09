#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int ll;

ll merge(ll arr[], int s,int mid,int e){
	ll ans=0;
	ll temp[e-s+1];
 int i=s,j=mid,k=0;
	while(i<mid && j<=e){
		if(arr[i]<arr[j]){
			ans= (ans+ ((e-j+1)*arr[i])%MOD)%MOD;
			temp[k++]=arr[i++];
		}
		else{
			temp[k++]=arr[j++];
		}
	}
	while(i<mid){
		temp[k++]=arr[i++];
	}
	while(j<=e){
		temp[k++]=arr[j++];
	}
	for(int z=s,k=0;z<=e;z++,k++){
		arr[z]=temp[k];
	}


	return ans;
}
ll mergeSort(ll arr[],int s,int e){
	if(s>=e){
		return 0;
	}
	int mid=(s+e)/2;
	ll ans1=mergeSort(arr,s,mid);
	ll ans2=mergeSort(arr,mid+1,e);
	ll ans3=merge(arr,s,mid+1,e);
	return (((ans1+ans2)%MOD)+ans3)%MOD;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	ll arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	ll ans=mergeSort(arr,0,n-1);
	cout<<ans<<endl;
	}
	return 0;
}
