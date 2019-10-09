#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int ll;
ll merge(ll arr[],int s,int mid,int e){
	ll *temp=new ll[e-s+1];
	int i=s,j=mid,k=0;
	ll count=0;
	while(i<mid && j<=e){
		if(arr[i]<=arr[j]){
			temp[k++]=arr[i++];
		}
		else{
			count+=(mid-i);
			temp[k++]=arr[j++];
		}
	}
	while(i<mid){
		temp[k++]=arr[i++];
	}
	while(j<=e){
		temp[k++]=arr[j++];
	}
	k=0;
	for(i=s;i<=e;i++,k++){
		arr[i]=temp[k];
	}
	delete []temp;
	return count;
}

ll inversionCount(ll arr[],int n,int s,int e){
	if(s>=e) return 0;
	
	int mid=(s+e)/2;
	ll left=inversionCount(arr,n,s,mid);
	ll right=inversionCount(arr,n,mid+1,e);
	ll curr=merge(arr,s,mid+1,e);
	return left+right+curr;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		ll ans=inversionCount(arr,n,0,n-1);
		cout<<ans<<endl;
	}
}
