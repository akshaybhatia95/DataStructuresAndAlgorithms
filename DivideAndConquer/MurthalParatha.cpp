#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int ll;
bool isPossible(int mid,int rank[],int noOfParathas,int noOfCooks){
	int time=1;
	int counter[noOfCooks];
	int realTime[noOfCooks];
	for (int i=0; i<noOfCooks; ++i)
	{
		realTime[i]=rank[i];
   		counter[i] = 1;   
	}
	while(time<=mid){
		for(int i=0;i<noOfCooks;i++){
			if(noOfParathas==0){break;}
			
			if(time%realTime[i]==0){
				noOfParathas--;
				counter[i]++;
				realTime[i]=time+counter[i]*rank[i];
				
			}
		}
		if(noOfParathas==0){break;}
		time++;
	}
	if(noOfParathas<=0){
		return true;
	}
	else{
		return false;
	}
	
}

ll minTime(int ranks[], int noOfParathas,int noOfCooks){
	int *index1=max_element(ranks,ranks+noOfCooks);
	int *index2=min_element(ranks,ranks+noOfCooks);
	int max;
	int original=*index1;
	int min=*index2;
	int temp=noOfParathas;
	int counter=1;

	while(temp--){
		
		max+= original+counter*original;
		counter++;
	}
	int s=0,e=max,best=INT_MAX;
	while(s<=
	
	e){
		int mid= (s+e)/2;
		if(isPossible(mid,ranks,noOfParathas,noOfCooks)){
			best=mid;
			e=mid-1;
		}
		else{
			s=mid+1;
		}
	}
	return best;
	
	
	
}
int main(){
int noOfParathas;
cin>>noOfParathas;
int noOfCooks;
cin>>noOfCooks;
int ranks[noOfCooks];
for(int i=0;i<noOfCooks;i++){
	cin>>ranks[i];
}

int ans=minTime(ranks,noOfParathas,noOfCooks);
cout<<ans<<endl;


return 0;
}

