#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // value -> index
        
        for (int i = 0; i < (int)nums.size(); i++) {
            int complement = target - nums[i];
            
            auto it = seen.find(complement);
            if (it != seen.end()) {
                return {it->second, i};
            }
            
            seen[nums[i]] = i;
        }
        
        return {}; // no solution found (won't happen per problem constraints)
    }
};