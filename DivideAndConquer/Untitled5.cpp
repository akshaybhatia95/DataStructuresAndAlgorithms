#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int ll;

ll maxGoodCoupons(ll noOfStudents,ll noOfDiscountCoupons,ll goodCoupons,ll badCoupons){

	ll s=0;
	ll e=noOfStudents;
	ll best=0;
	while(s<=e){
		ll mid=(s+e)/2;
	
		if((mid*goodCoupons)+(noOfStudents-mid)*badCoupons<=noOfDiscountCoupons){
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
	ll noOfStudents,noOfDiscountCoupons,goodCoupons,badCoupons;
	cin>>noOfStudents>>noOfDiscountCoupons>>goodCoupons>>badCoupons;
	cout<<maxGoodCoupons(noOfStudents,noOfDiscountCoupons,goodCoupons,badCoupons)<<endl;
	return 0;
}
