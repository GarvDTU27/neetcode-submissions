class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st ;

        for(auto it : nums){
            st.insert(it);
        }
        int ans = 1;
        for(auto it : st){
            int num = it ;
            if(st.find(num-1) == st.end()){
                int len = 1 ;
                while(st.find(num+1) != st.end()){
                    len++ ;
                    num++ ;
                }
                ans = max(len,ans);
            }
        }

        return ans ;
    }
};
