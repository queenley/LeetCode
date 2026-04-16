class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxL = 0, maxR = 0;
        int total = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                maxL = max(maxL, height[left]);
                total += maxL - height[left];
                left++;
            }
            else {
                maxR = max(maxR, height[right]);
                total += maxR - height[right];
                right--;
            }
        }
        return total;
    }
};