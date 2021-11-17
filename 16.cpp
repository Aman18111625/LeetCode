//Question : Kth Smallest Number in Multiplication Table(https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/)
//Difficulty : Hard
//Pre-requisite:- Binary Search

//Method-1
store whole multiplication table in a vector than sort that vector ,now kth smallest element v[k-1]
TC : - O(M*N)(store multiplication table in a vector)+O(MNlog(MN))(sort vector)
SC:- O(M*N) (store in a vector)

//Method-2
using heap
store multiplication table in a max heap of size k .. if size is greater than k than pop element from heap .At the end top element is kth smallest element
TC:- O(M*Nlogk)
SC:-O(logk) using heap of size K

//Method-3 
Using Binary Search
TC:- O(M*log(MN))
SC:-O(1)

/*
In the function kSmaller we start counting.
We loop through the rows of the table.
Each row looks like this: [1 * i, 2 * i, 3 * i, ..., n * i].
If the last number in the row is larger than num, then the number of smaller numbers is num/i. Otherwise, the whole row is smaller = n.
So we add to c the minimum between the two.
*/

  bool kSmaller(int n, int m, int num, int k) {
        int c = 0;
        for (int i = 1; i <= m; i++)
            c += min(n, num/i);
        
       return c >= k;
 }
    
 int findKthNumber(int m, int n, int k) {
         int low=1,high=m*n,mid,res;
        while(low<high)
        {
            mid=low+(high-low)/2;
            if(kSmaller(n,m,mid,k)) high=mid;
            else low=mid+1;
        }
        return low;
    }