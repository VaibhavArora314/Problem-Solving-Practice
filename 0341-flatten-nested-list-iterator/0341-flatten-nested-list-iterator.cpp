/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<int> nums;
    int index;

    void helper(int i,vector<NestedInteger> &nestedList) {
        if (i == nestedList.size()) return;

        if (nestedList[i].isInteger())
            nums.push_back(nestedList[i].getInteger());
        else {
            vector<NestedInteger> temp = nestedList[i].getList();
            helper(0,temp);
        }
        helper(i+1,nestedList);
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        index = 0;

        helper(0,nestedList);
    }
    
    int next() {
        return nums[index++];
    }
    
    bool hasNext() {
        return index < nums.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */