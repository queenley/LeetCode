class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {            
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    output.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                }
                else if (sum < 0) left++;
                else right--;
            }            
        }
        sort(output.begin(), output.end());
        output.erase(unique(output.begin(), output.end()), output.end());
        return output;
    }
};