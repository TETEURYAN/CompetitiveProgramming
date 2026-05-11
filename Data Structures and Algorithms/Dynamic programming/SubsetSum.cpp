#include <bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int>& nums, int target) {
    int n = nums.size();
    // dp[i][j] = true se existe subconjunto dos primeiros i elementos que soma j
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    // Soma 0 é sempre possível (subconjunto vazio)
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            // Não pega o elemento i
            dp[i][j] = dp[i-1][j];

            // Pega o elemento i (se couber)
            if (j >= nums[i-1])
                dp[i][j] = dp[i][j] || dp[i-1][j - nums[i-1]];
        }
    }

    return dp[n][target];
}

int main() {
    vector<int> nums = {3, 1, 4, 2, 5};
    int target = 9;
    cout << (subsetSum(nums, target) ? "SIM" : "NAO") << "\n"; // SIM (4+5 ou 3+1+5 ...)
}
