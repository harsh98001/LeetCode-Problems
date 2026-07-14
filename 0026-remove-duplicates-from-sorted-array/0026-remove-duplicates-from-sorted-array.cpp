class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int write = 1;  // Position to write the next unique element
        
        for (int read = 1; read < nums.size(); read++) {
            // If current element is different from the last unique element
            if (nums[read] != nums[write - 1]) {
                nums[write] = nums[read];
                write++;
            }
        }
        
        return write;
    }
};