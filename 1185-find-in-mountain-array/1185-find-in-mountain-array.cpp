/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    int getValue(int index,MountainArray &mountainArr,unordered_map<int,int> &store) {
        // if (store.find(index) != store.end()) return store[index];

        int val = mountainArr.get(index);
        // store[index] = val;
        return val;
    }
    int binMountainLeft(int low,int high,int target,MountainArray &mountainArr,unordered_map<int,int> &store) {
        int mid,val;
        while (low <= high) {
            mid = (low + high)/2;
            val = getValue(mid,mountainArr,store);

            if (val == target) return mid;
            if (val > target) high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
    int binMountainRight(int low,int high,int target,MountainArray &mountainArr,unordered_map<int,int> &store) {
        int mid,val;
        while (low <= high) {
            mid = (low + high)/2;
            val = getValue(mid,mountainArr,store);

            if (val == target) return mid;
            if (val < target) high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        unordered_map<int,int> store;
        int length = mountainArr.length();

        int low = 0,high=length-1,mid;
        while (low < high) {
            mid = (low+high)/2;
            
            int m1 = getValue(mid,mountainArr,store),
                m2 = getValue(mid+1,mountainArr,store);
            
            if (m1 < m2) low = mid+1;
            else high = mid;
        }

        int mountainIndex = (low+high)/2;

        int index = binMountainLeft(0,mountainIndex,target,mountainArr,store);
        if (index != -1) return index;
        
        index = binMountainRight(mountainIndex+1,length-1,target,mountainArr,store);
        return index;
    }
};