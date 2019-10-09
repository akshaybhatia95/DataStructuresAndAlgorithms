#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct Job{
  ll start,finish;
};
bool cmp(Job j1,Job j2 ){
  if(j1.finish==j2.finish) return j1.start<j2.start;
  
  return j1.finish<j2.finish;
  
}
int activitySelection( Job jobs[],int n){
  sort(jobs,jobs+n,cmp);
  ll currFin=jobs[0].finish;
  int count=1;
  int chairCount=0;
  for(int i=1;i<n;i++){
    if(currFin<=jobs[i].start){
      count++;
      currFin=jobs[i].finish;
    }
    else{
    	chairCount++;
	}
  }
  return chairCount+1;
}
int main() {
	 ios_base::sync_with_stdio(false);
	  int n;
	  cin>>n;
	  struct Job jobs[n];
	  for(int i=0;i<n;i++){
	   cin>> jobs[i].start;
	   cin>> jobs[i].finish;
	  }
	  int ans=activitySelection(jobs,n);
	  cout<<ans<<endl;
	
}
