class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0;
        int end = s.size() -1 ;

        while(st <= end){
            // eliminating all non alnum characters from start
            while(st < s.size() && !isalnum(s[st])) st++ ;
            // eliminating all non alnum characters from end
            while(end >= 0 && !isalnum(s[end])) end-- ;
            // if range already crossed then break
            if(st > end) break ;
            // if unmatched then not a palindrome
            if(tolower(s[st]) != tolower(s[end])) return false ;
            st++ ;
            end-- ;
        }

        return true ;
    }
};
