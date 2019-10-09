class Solution {
    boolean calculateCondition(int[] A,int start,int end){
        int diff=A[start]-A[start+1];
        for(int i=start+1;i<end;i++){
            if(A[i]-A[i+1]!=diff){
                return false;
            }
        }
        return true;
    }
    public int numberOfArithmeticSlices(int[] A) {
        if(A.length < 3){
            return 0;
        }
        int i=0,j=2;
        int count=0;
        while(i<=A.length-3){
            if(j<A.length){
             if(calculateCondition(A,i,j)){
                  count++;
                  j++;
              }
              else{
                  i++;
                  j=i+2;
              }
            }
            else{
                i++;
                j=i+2;
            }
        }
        return count;
    }
}
