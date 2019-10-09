#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int ll;
bool isPossible(ll pages[],int noOfBooks,int noOfStudents,ll mid){
	ll curr_pages=0;
	ll curr_student=1;
	for(int i=0;i<noOfBooks;++i){
		if(pages[i]>mid){
			return false;
		}
		if(curr_pages+pages[i]<=mid){
			curr_pages+=pages[i];
		}
		else{
			curr_student++;
			curr_pages=pages[i];
		}
		if(curr_student>noOfStudents){
			return false;
		}
	}
	return true;
}
ll minMaxPages(ll pages[],int noOfBooks,int noOfStudents){
	ll s=pages[noOfBooks-1];
	ll e,best;
	for(int i=0;i<noOfBooks;i++){
		e+=pages[i];
	}
	if(noOfStudents==1){
		return e;
	}
	while(s<=e){
		ll mid=(s+e)/2;
		if(isPossible(pages,noOfBooks,noOfStudents,mid)){
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
	int noOfBooks,noOfStudents;
	cin>>noOfBooks>>noOfStudents;
	ll pages[noOfBooks];
	for(int i=0;i<noOfBooks;i++){
		cin>>pages[i];
	}
	
	ll ans=minMaxPages(pages,noOfBooks,noOfStudents);
	cout<<ans<<endl;
	
	
}
