vector<int> reconstruct(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    for (int i = 0; i <= n; i++) dp[i][0] = true;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= target; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= nums[i-1])
                dp[i][j] = dp[i][j] || dp[i-1][j - nums[i-1]];
        }

    if (!dp[n][target]) return {}; // Impossível

    // Rastreia de volta
    vector<int> chosen;
    int j = target;
    for (int i = n; i >= 1; i--) {
        if (!dp[i-1][j]) { // Veio de pegar o elemento i
            chosen.push_back(nums[i-1]);
            j -= nums[i-1];
        }
    }
    return chosen;
}
