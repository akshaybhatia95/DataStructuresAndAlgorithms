#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int ll;
bool isPossible(int mid,ll *stalls,int n, int c){
	int lastPlaced=stalls[0];
	c--;
	for(int i=1;i<n;i++){
		if(c==0){
			return true;
		}
		if(stalls[i]-lastPlaced>=mid){
			c--;
			lastPlaced=stalls[i];
		}
	}
	

		return false;

	
}
ll maxMinDist(ll *stalls,int n,int c){
	int s=stalls[0],e=stalls[n-1],best=0;
	while(s<e){
		int mid=(s+e)/2;
		if(isPossible(mid,stalls,n,c)){
			best=mid;
			s=mid+1;
		}
		else{
			e=mid-1;
		}
	}
	return best;
}
int main(){
	int n,c;
	cin>>n>>c;
	
	ll stalls[n];
	for(int i=0;i<n;i++){
		cin>>stalls[i];
	}
	sort(stalls,stalls+n);
	ll ans=maxMinDist(stalls,n,c);
	cout<<ans<<endl;
	
	return 0;
}
