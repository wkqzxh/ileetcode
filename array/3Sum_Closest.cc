class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        for (int first = 0; first < nums.size()-2; first++) {
            if (first > 0 && nums[first] == nums[first-1]) continue;
            int second = first + 1;
            int third = nums.size() - 1;
            while (second < third) {
                int cur_sum = nums[first] + nums[second] + nums[third];
                if (cur_sum == target) return cur_sum;
                if (abs(target - closest) > abs(target - cur_sum)) {
                    closest = cur_sum;
                }
                if (cur_sum > target) {
                    third--;
                } else {
                    second++;
                }
            }
        }
        return closest;
    }
};
