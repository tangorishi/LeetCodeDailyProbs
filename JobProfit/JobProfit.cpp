 #include <vector>
#include <algorithm>

class Solution {
public:
    int n;
    std::vector<int> memo;

    int getNextIndex(const std::vector<std::vector<int>>& array, int l, int currentJobEnd) {
        int r = n - 1;
        int result = n + 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (array[mid][0] >= currentJobEnd) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return result;
    }

    int solve(const std::vector<std::vector<int>>& array, int i) {
        if (i >= n)
            return 0;

        if (memo[i] != -1)
            return memo[i];

        int next = getNextIndex(array, i + 1, array[i][1]);
        int taken = array[i][2] + solve(array, next);
        int notTaken = solve(array, i + 1);

        return memo[i] = std::max(taken, notTaken);
    }

    int jobScheduling(const std::vector<int>& startTime, const std::vector<int>& endTime, const std::vector<int>& profit) {
        n = startTime.size();
        memo.resize(n, -1);

        std::vector<std::vector<int>> array(n, std::vector<int>(3, 0));

        for (int i = 0; i < n; ++i) {
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }

        std::sort(begin(array), end(array), [](const auto& vec1, const auto& vec2) {
            return vec1[0] <= vec2[0];
        });

        return solve(array, 0);
    }
};
