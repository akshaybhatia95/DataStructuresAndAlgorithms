#include <bits/stdc++.h>
#define MOD 1000000007
#define loopex(a,b) for(int i=a;i<b;i++)
#define loopin(a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long int ll;
ll dp[1001][1001];
ll funDP(ll n,ll m,vector<pair<ll ,ll > > v){

	

	if(dp[1][1]==-1){
		return 0;
	}
	if(dp[m][n]==-1){
		return 0;
	}
	dp[1][1]=1;
	for(ll i=2;i<=m;i++) 
	{
		if(dp[1][i]!=-1){
			dp[1][i]=1;
		}
		else{
			break;
		}
	}
	for(ll i=2;i<=n;i++) 
	{
		if(dp[i][1]!=-1){
			dp[i][1]=1;
		}
		else{
		
			break;
		}
	}
	
	for(ll i=2;i<=n;i++){
		for(ll j=2;j<=m;j++){
			if(dp[i][j]!=-1){
				if(dp[i-1][j]!=-1){
					
					dp[i][j]=(dp[i][j] + dp[i-1][j])%MOD;	
				}
				if(dp[i][j-1]!=-1){
					dp[i][j]=(dp[i][j] + dp[i][j-1])%MOD;	
				}
				
			}
			
		}
	}
	
	
	return dp[n][m];
	
	
}


int main(){
	ll n,m,p;
	cin>>n>>m>>p;
	vector<pair< ll , ll > > v;
	
	
	for(ll k=0;k<p;k++){
		ll i,j;
		cin>>i>>j;
		v.push_back(make_pair(i,j));
		//cout<<"HI"<<endl;
	}
	
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			dp[i][j]=0;
		}
	}
	for(ll i=0;i<v.size();i++){
		dp[v[i].first][v[i].second]=-1;
	}

	ll ans =funDP(n,m,v);
	cout<<ans<<endl;
}
