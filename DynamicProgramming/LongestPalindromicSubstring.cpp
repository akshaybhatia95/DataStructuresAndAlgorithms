class Solution {
    // public boolean isPalindrome(String s){
    //     int i=0,j=s.length()-1;
    //     while(i<j){
    //         if(s.charAt(i)==s.charAt(j)){
    //             i++;
    //             j--;
    //         }
    //         else{
    //             return false;
    //         }
    //     }
    //     return true;
  //  }
   /* public String longestPalindrome(String s) {
        if(s.length()==0){
            return "";
        }
        if(s.length()==1){
            return ""+s.charAt(0);
        }
        
        
        
        String ans=""; int max=0;
        for(int i=0;i<s.length();i++){
            for(int j=i;j<=s.length();j++){
                String temp=s.substring(i,j);
                    if(isPalindrome(temp)){
                        if(temp.length()>=max){
                            max=s.substring(i,j).length();
                            ans=temp;
                        }
                    }
                }
            }
           return ans;
        }*/
     public String longestPalindrome(String s) {
             if(s.length()==0){
                return "";
             }
             if(s.length()==1){
                return ""+s.charAt(0);
             }
            int maxLen=1,start=-1;
            int table[][]=new int[s.length()][s.length()];
            for(int i=0,j=0;i<s.length();i++,j++){
                table[i][j]=1;
                start=i;
                
            }
            for(int i=0;i<s.length()-1;i++){
                if(s.charAt(i)==s.charAt(i+1)){
                    table[i][i+1]=2;
                    start=i;
                    maxLen=2;
                    
                }
            }
         
             int k=3;
             while(k<=s.length()){
             for(int i=0;i<=s.length()-k;i++){
                    int j=i+k-1;
                    if(s.charAt(i)==s.charAt(j) && table[i+1][j-1]>0){
                        table[i][j]= table[i+1][j-1]+2;
                        if(k>=maxLen){
                            maxLen=k;
                            start=i;
                        }
                    }
                 
             }
                 k++;
             }
         return s.substring(start,start+maxLen);
         
     
     }
}
     
        
        
    

