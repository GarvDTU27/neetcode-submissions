class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int ans = 0;
        unordered_map<char,int> freq ;

        while(r < s.size()){
            while(freq[s[r]] == 1){
                freq[s[l]]-- ;
                l++ ;
            }

            ans = max(ans, r-l +1);
            freq[s[r]]++ ;
            r++ ;
        }

        return ans ;
    }
};
