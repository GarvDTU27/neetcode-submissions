class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // val, ind
        unordered_map<int,int> ind ;

        for(int i = 0 ; i< nums.size(); i++){
            int req = target - nums[i];

            if(ind.find(req) != ind.end()){
                return { ind[req], i} ;
            }
            ind[nums[i]] = i ;
        }

        return {} ;
    }
};
