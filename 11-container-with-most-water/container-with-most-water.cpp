class Solution {
public:
    int maxArea(vector<int>& height) {
        int left_idx = 0, right_idx = height.size() - 1;
        int max_area = min(height[left_idx], height[right_idx]) * (right_idx - left_idx);
        int _max_area = 0;
        while (left_idx < right_idx) {  
            if (height[left_idx] < height[right_idx]) left_idx++;
            else right_idx--;

            _max_area = min(height[left_idx], height[right_idx]) * (right_idx - left_idx);                          
            if (_max_area > max_area) max_area = _max_area;            
        }
        return max_area;
    }
};