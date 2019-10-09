// you can also use imports, for example:
// import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

#include <bits/stdc++.h>
#define MOD 1000000007
#define loopex(a,b) for(int i=a;i<b;i++)
#define loopin(a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long int ll;
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
	cin>>arr[i];
	}
	
	   int odd[n]={0};
       int even[n]={0};
       odd[n-1]=1;
       even[n-1]=1;
       if(arr[n-2]>arr[n-1]){
       	even[n-2]=1;
	   }
	   if(arr[n-2]<arr[n-1]){
	   	odd[n-2]=1;
	   }
       for(int i=n-3;i>=0;i--){
           int min=INT_MAX;
           int index=-1;
           int min2=INT_MAX;
           int index2=-1;
           for(int j=i+1;j<n;j++){
               
               if(arr[j]-arr[i]>0){
                   if(arr[j]-arr[i]<min){
                    min=arr[j]-arr[i];
                    index=j;
                   }
                      
               }
               
               if(arr[i]-arr[j]>0){
                   if(arr[i]-arr[j]<min2){
                       min2=arr[i]-arr[j];
                       index2=j;
                   }
                 
               }
               
           }
           	 if(index!=-1){	
			 				
          //  cout<<"HERE"<<index<<" ";
            	odd[i]=even[index];
                   
             }
             if(index2!=-1){
			 
              
                even[i]=odd[index2];
                         
       		}
       }
       int sum=0;
       cout<<odd[2]<<" "<<even[2]<<" ";
       
     //  cout<<sum;
    }


//class Solution {
//    public int solution(int []arr) {
//       int n=arr.length;
//       int odd[]=new int[n];
//       int even[]=new int[n];
//       odd[n-1]=1;
//       even[n-1]=1;
//       for(int i=n-2;i>=0;i--){
//           int min=Integer.MAX_VALUE;
//           int index=-1;
//           int min2=Integer.MAX_VALUE;
//           int index2=-1;
//           for(int j=i+1;j<n;j++){
//               
//               if(arr[j]-arr[i]>0){
//                   if(arr[j]-arr[i]<min){
//                    min=arr[j]-arr[i];
//                    index=j;
//                   }
//                   if(even[index]>0){
//                       odd[i]=1;
//                   }     
//               }
//               
//               if(arr[i]-arr[j]>0){
//                   if(arr[i]-arr[j]<min2){
//                       min=arr[i]-arr[j];
//                       index2=j;
//                   }
//                   if(odd[index2]>0){
//                       even[i]=1;
//                   }
//               }
//        
//               
//              
//               
//           }
//       }
//       int sum=0;
//       for(int i=0;i<n;i++){
//           sum+=odd[i];
//       }
//       
//       return sum;
//    }
//}
