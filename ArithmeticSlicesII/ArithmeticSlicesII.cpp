#define ll long long

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0;
        
        vector<unordered_map<ll, int>> dp(n);
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                ll differ = (ll)nums[i] - nums[j];
                
                if (dp[j].find(differ) != dp[j].end()) {
                    ans += dp[j][differ];
                    dp[i][differ] += dp[j][differ] + 1;
                } else {
                    dp[i][differ] += 1;
                }
            }
        }
        
        return (int)ans;
    }
};
