class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0;
        int end = s.size() -1 ;

        while(st <= end){
            while(st < s.size() && !isalnum(s[st])) st++ ;
            while(end >= 0 && !isalnum(s[end])) end-- ;
            if(st > end) break ;
            if(tolower(s[st]) != tolower(s[end])) return false ;
            st++ ;
            end-- ;
        }

        return true ;
    }
};
