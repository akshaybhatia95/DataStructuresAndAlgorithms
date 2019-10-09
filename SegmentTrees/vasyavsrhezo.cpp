#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
struct node{
  ll A;
  ll B;
  int index;
};

void buildTree(ll *arr1,ll *arr2,node *tree,int s,int e,int i){
  if(e<s) return;
  if(s==e){
    
    tree[i].A=arr1[s];
    tree[i].B=arr2[s];
    tree[i].index=s;
    
    return;
  }
  int mid=(s+e)/2;
  buildTree(arr1,arr2,tree,s,mid,2*i);
  buildTree(arr1,arr2,tree,mid+1,e,2*i+1);
  
  if(tree[2*i].A>tree[2*i+1].A){
    tree[i].A=tree[2*i].A;
    tree[i].B=tree[2*i].B;
    tree[i].index=tree[2*i].index;
    
    return;
  }
  if(tree[2*i].A<tree[2*i+1].A){
    tree[i].A=tree[2*i+1].A;
    tree[i].B=tree[2*i+1].B;
     tree[i].index=tree[2*i+1].index;
    
    return;
  }
  if(tree[2*i].A==tree[2*i+1].A){
    
    	if(tree[2*i].B<tree[2*i+1].B){
    		tree[i].A=tree[2*i].A;
    		tree[i].B=tree[2*i].B;
            tree[i].index=tree[2*i].index;
          
    		return;
  		}
  		if(tree[2*i].B>tree[2*i+1].B){
    		tree[i].A=tree[2*i+1].A;
    		tree[i].B=tree[2*i+1].B;
          tree[i].index=tree[2*i+1].index;
          
    		return;
  		}
    	if(tree[2*i].B==tree[2*i+1].B){
    		tree[i].A=tree[2*i+1].A;
    		tree[i].B=tree[2*i+1].B;
            tree[i].index=tree[2*i+1].index;
          
    		return;
  		}
    
    	
    return;
  }
  
  
}
node query(node *tree,int l,int r,int s,int e,int i){
  if(s>r || e< l){
    node ans;
    ans.A=INT_MIN;
    ans.B=INT_MAX;
    ans.index=INT_MIN;
    return ans;
  }
  if(l<=s && e<=r){
    return tree[i];
  }
  int mid=(s+e)/2;
  node left=query(tree,l,r,s,mid,2*i);
  node right=query(tree,l,r,mid+1,e,2*i+1);
 
  node ans;
  
    if(left.A>right.A){
    ans.A=left.A;
    ans.B=left.B;
    ans.index=left.index;
    
    return ans;
  }
  if(left.A<right.A){
    ans.A=right.A;
    ans.B=right.B;
     ans.index=right.index;
    
    return ans;
  }
  if(left.A==right.A){
    
    	if(left.B<right.B){
    		ans.A=left.A;
    		ans.B=left.B;
            ans.index=left.index;
          
    		return ans;
  		}
  		if(left.B>right.B){
    		ans.A=right.A;
    		ans.B=right.B;
          ans.index=right.index;
          
    		return ans;
  		}
    	if(left.B==right.B){
    		ans.A=right.A;
    		ans.B=right.B;
            ans.index=right.index;
          
    		return ans;
  		}
    
    	
    return ans;
  }
  
  
  
}
int main() {

	int n;
  	cin>>n;
  	ll *arr1=new ll[n+1];
  	
  	for(int i=1;i<=n;i++){
      cin>>arr1[i];
    }
  
  	ll *arr2=new ll[n+1];
  	
  	for(int i=1;i<=n;i++){
      cin>>arr2[i];
    }
 
  
  	node *tree=new node[4*n+1];
  	buildTree(arr1,arr2,tree,1,n,1);
  
  	int q;
  	cin>>q;
  	while(q--){
      int l,r;
      cin>>l>>r;
     
      node ans=query(tree,l,r,1,n,1);
      cout<<ans.index<<endl;
    }
  	
  	
}