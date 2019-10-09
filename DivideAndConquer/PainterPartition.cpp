#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int ll;
bool isPossible(ll *boardLen,int noOfPainters,int noOfBoards,int mid){
	if(noOfPainters==0){
		return false;
	}
	int paintersUsed=1;
	ll time=0;
	for(int i=0;i<noOfBoards;i++){
		if(boardLen[i]>mid){
			return false;
		}
		if(time+boardLen[i]<=mid){
			time+=boardLen[i];
			
		}
		else{
			paintersUsed++;
			time=boardLen[i];
		}
		if(paintersUsed>noOfPainters){
			return false;
		}
	}
		
	return true;
	
}
ll minTime(ll *boardLen,int noOfPainters,int noOfBoards){
ll s=boardLen[0];
ll e=0,best;
for(int i=0;i<noOfBoards;i++){
	e+=boardLen[i];
	
}

while(s<=e){
	int mid=(s+e)/2;
	if(isPossible(boardLen,noOfPainters,noOfBoards,mid)){
		best=mid;
		e=mid-1;
	}
	else{
		s=mid+1;
	}
}
return best ;
}
int main(){
	int noOfPainters,noOfBoards;
	cin>>noOfPainters>>noOfBoards;
	ll boardLen[noOfBoards];
	for(int i=0;i<noOfBoards;i++){
		cin>>boardLen[i];
	}
//	sort(boardLen,boardLen+noOfBoards);
	ll ans=minTime(boardLen,noOfPainters,noOfBoards);
	cout<<ans<<endl;
}
