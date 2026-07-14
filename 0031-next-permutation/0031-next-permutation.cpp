class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // Find pivot
        int pivot = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }
        
        if (pivot == -1) {
            // Reverse manually
            int left = 0, right = n - 1;
            while (left < right) {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
            return;
        }
        
        // Find successor
        int successor = -1;
        for (int i = n - 1; i > pivot; i--) {
            if (nums[i] > nums[pivot]) {
                successor = i;
                break;
            }
        }
        
        // Swap
        swap(nums[pivot], nums[successor]);
        
        // Reverse suffix manually
        int left = pivot + 1, right = n - 1;
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};