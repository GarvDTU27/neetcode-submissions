class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0;
        int end = s.size() -1 ;

        while(st <= end){
            while(!isalnum(s[st])) st++ ;
            while(!isalnum(s[end])) end-- ;

            if(tolower(s[st]) != tolower(s[end])) return false ;
            st++ ;
            end-- ;
        }

        return true ;
    }
};
