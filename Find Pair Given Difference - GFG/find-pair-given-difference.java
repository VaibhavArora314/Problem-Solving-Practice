//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*;
class GfG
{
    public static void main (String[] args)
    {
        
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int l = sc.nextInt();
            int n = sc.nextInt();
            
            int arr[] =  new int[l];
            
            for(int i = 0;i<l;i++)
                arr[i] = sc.nextInt();
            
            Solution ob = new Solution();
                
            if(ob.findPair(arr, l, n)==true)
                System.out.println(1);
                
            else
                System.out.println(-1);    
                
        }
        
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    public boolean binarySearch(int arr[],int low,int high,int target,int x) {
        int mid;
        while (low<=high) {
            mid = (low+high)/2;
            
            if (arr[mid] - x == target) return true;
            if (arr[mid] - x < target) low = mid+1;
            else high = mid-1;
        }
        
        return false;
    }
    public boolean findPair(int arr[], int size, int n)
    {
        Arrays.sort(arr);
        
        boolean ans = false;
        for (int i=0;i<size-1;i++) {
            ans = binarySearch(arr,i+1,size-1,n,arr[i]);
            if (ans == true) return true;
        }
        return false;
    }
}