class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // maintain deque of length k, and bottom element is always the 
        //max element for that range
        // i

        vector<int> ans ;
        deque<int> dq ;

        for(int i = 0; i< nums.size(); i++){
            while(dq.size() > 0 && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            int valid = i- k +1 ;
            while(dq.size() > 0 && dq.front() < valid){
                dq.pop_front();
            }
            dq.push_back(i);
            if(i >= k -1 )ans.push_back( nums[dq.front()]);
            
        }

        return ans ;
    }
};
