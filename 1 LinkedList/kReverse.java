
/*

Implement kReverse( int k ) in a linked list i.e. you need to reverse first K elements then reverse next k elements and join the linked list and so on.
Indexing starts from 0. If less than k elements left in the last, you need to reverse them as well. If k is greater than length of LL, reverse the complete LL.
You don't need to print the elements, just return the head of updated LL.

Input format :

Line 1 : Linked list elements (separated by space and terminated by -1)

Line 2 : k




class LinkedListNode<T> {
	public T data;
	public LinkedListNode<T> next;

	public LinkedListNode(T data) {
		this.setData(data);
		this.next = null;
	}

	public T getData() {
		return data;
	}

	public void setData(T data) {
		this.data = data;
	}

}
* */
public class Solution {
    static int countLL(LinkedListNode<Integer> head){
        LinkedListNode<Integer> temp=head;
        int count=0;
        while(temp!=null){
            temp=temp.next;
            count++;
        }
        return count;
    }
    public static Pair revLL(LinkedListNode<Integer> head){
        
        if(head==null){
            Pair p=new Pair();
            p.head=null;
            p.tail=null;
            return p;
        }
        
        if(head.next==null){
            Pair p=new Pair();
            p.head=head;
            p.tail=head;
            return p;
        }
        
        
        Pair p=revLL(head.next);
        p.tail.next=head;
        head.next=null;
        p.tail=p.tail.next;;
        return p;
        
    }
    
	public static LinkedListNode<Integer> kReverse(LinkedListNode<Integer> head, int k) { //O(n)
        if(head==null){
            return head;
        }
        if(k==0){
            return head;
        }
        int count=countLL(head);
        if(k>count){
            return revLL(head).head;
        }
        int tempK=k-1;
        LinkedListNode<Integer> temp=head;
        while(tempK!=0){
            temp=temp.next;
            tempK--;
        }
        LinkedListNode<Integer> beginFromHere=temp.next;
        temp.next=null;
        Pair p=revLL(head);
        p.tail.next=kReverse(beginFromHere,k);
        return p.head;
        
    }
}

class Pair{
    public LinkedListNode<Integer> head;
    public LinkedListNode<Integer> tail;
    
    
    
}
