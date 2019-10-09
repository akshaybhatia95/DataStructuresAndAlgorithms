#include <bits/stdc++.h>
#include <algorithm>
#define MOD 1000000007
using namespace std;
typedef long long int ll;

ll max(ll a,ll b){
	if(a>b) return a;
	return b;
}

ll merge(ll arr[],int s,int mid,int e){
ll *leftPrefixSum=new ll[mid-s];
ll *rightSuffixSum=new ll[e-mid+1];
for(int i=0;i<mid-s;i++){
	leftPrefixSum[i]=0;
}

for(int i=0;i<e-mid+1;i++){
	rightSuffixSum[i]=0;
}

ll leftSum=0;
ll rightSum=0;
int index=mid-s-1;

for(int i=mid-1;i>=s;i--){
	leftSum+=arr[i];
	leftPrefixSum[index--]=leftSum;
}

index=0;
for(int i=mid;i<=e;i++){
	rightSum+=arr[i];
	rightSuffixSum[index++]=rightSum;
}
ll leftMax=0;
ll rightMax=0;

for(int i=0;i<mid-s;i++){
	if(leftPrefixSum[i]>leftMax){
		leftMax=leftPrefixSum[i];
	}
}
for(int i=0;i<e-mid+1;i++){
	if(rightSuffixSum[i]>rightMax){
		rightMax=rightSuffixSum[i];
	}
}
delete []rightSuffixSum;
delete []leftPrefixSum;

return leftMax+rightMax;
}

ll maxSubArraySum(ll arr[],int n,int s,int e){
	if(s>e){
		return 0;
	}
	if(s==e){
		if(arr[s]< 0){
		return 0;}
		else{
			return arr[s];
	}
		
	}
	
	
	int mid=(s+e)/2;
	ll left=maxSubArraySum(arr,n,s,mid);
	ll right=maxSubArraySum(arr,n,mid+1,e);
	ll curr=merge(arr,s,mid+1,e);
	return max(max(left,right),curr);
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
		ll ans=maxSubArraySum(arr,n,0,n-1);
		cout<<ans<<endl;
	}
}
