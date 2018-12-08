class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() < 3) return ans;
        sort(nums.begin(), nums.end());
        for (int first = 0; first < nums.size()-2; first++) {
            if (first > 0 && nums[first] == nums[first-1]) continue;
            int second = first + 1;
            int third = nums.size() - 1;
            while (second < third) {
                int cur_sum = nums[first] + nums[second] + nums[third];
                if (cur_sum < 0) {
                    second++;
                } else if (cur_sum > 0) {
                    third--;
                } else {
                    ans.push_back({nums[first], nums[second], nums[third]});
                    while (nums[second] == nums[second+1]) second++;
                    while (nums[third] == nums[third-1]) third--;
                    second++;
                    third--;
                }
            }
        }
        return ans;
    }
};

