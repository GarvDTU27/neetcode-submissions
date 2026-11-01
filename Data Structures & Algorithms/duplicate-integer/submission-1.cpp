class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,bool> appear ;

        for(auto it: nums){
            if(appear.find(it) == appear.end()){
                appear[it] = true ;
            }
            else{
                return true ;
            }
        }

        return false ;
    }
};