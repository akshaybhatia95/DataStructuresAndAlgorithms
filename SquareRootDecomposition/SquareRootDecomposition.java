import java.util.*;
public class SquareRootDecomposition {
	static Scanner s=new Scanner(System.in);

	public static int query(int blocks[],int arr[],int l,int r,int rn) {
		int ans=0;
		while(l<r  && l%rn!=0) {
			ans+=arr[l++];
		}
		while(l+rn<=r) {
			ans+=blocks[l/rn];
			l+=rn;
		}
		while(l<=r) {
			ans+=arr[l++];
			
		}
		return ans;
	}
	public static void update(int blocks[],int arr[],int index,int value,int rn) {
		
		int block_id=index/rn;
		blocks[block_id]+=(value-arr[index]);
		arr[index]=value;
		return;
	}
	public static void main(String[] args) {
		int n=0;
		n=s.nextInt();

		int arr[]=new int[n];
		
		{
			int i=0;
			while(i<n) 
			{
				arr[i++]=s.nextInt();
			}
			
		}

		int rn=(int)Math.sqrt(n);
		int block_id = -1;
		int blocks[]=new int[rn+1];
		for(int i=0;i<n;i++) {
			if(i%rn==0) {
				block_id++;
			}
		
			blocks[block_id]+=arr[i];
			
		}
//		printArray(blocks);
		System.out.println(query(blocks,arr,2,8,rn));
		update(blocks,arr,2,15,rn);
		System.out.println(query(blocks,arr,2,8,rn));
		
	}


	private static void printArray(int[] arr) {
		for(int i=0;i<arr.length;i++) {
			System.out.print(arr[i]+" ");
		}
		
	}

}
