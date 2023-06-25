class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans=0,m,n,temp;
        for (int i=0;i<nums.size();i++) {
            temp=nums[i];m=0;
            while (temp) {
                m = temp%10;
                temp=temp/10;
            }
            for (int j=i+1;j<nums.size();j++) {
                n = nums[j]%10;
                
                if (__gcd(m,n) == 1) {
                    ans++;
                    // cout<<m<<" "<<n<<endl;
                }
            }
        }
        
        return ans;
    }
};