class Solution {
public:
    vector<vector<int>> ans ;
    void solve(vector<int>& subset, int idx, vector<int>& nums){
        if(idx >= nums.size()){
            ans.push_back(subset);
            return ;
        }
        subset.push_back(nums[idx]);
        solve(subset, idx+1, nums);
        subset.pop_back();
        solve(subset, idx+1, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset ;
        solve(subset, 0, nums);

        return ans ;
    }
};
