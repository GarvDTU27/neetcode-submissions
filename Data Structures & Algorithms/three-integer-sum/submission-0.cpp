class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans ;
        set<vector<int>>st ;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] > 0) break ;

            int j = i+1;
            int k = nums.size()-1 ;
            while(j < k){
                int sumi = nums[i] + nums[j] + nums[k] ;

                if(sumi == 0){
                    st.insert( {nums[i], nums[j], nums[k]});
                    j++ ;
                    k-- ;
                }
                else if(sumi > 0) k-- ;
                else j++ ;
            }
        }

        for(auto it: st){
            ans.push_back(it);
        }

        return ans ;
    }
};
