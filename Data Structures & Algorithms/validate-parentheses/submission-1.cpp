class Solution {
public:
    bool isValid(string s) {
        stack<char> stk ;

        for(int i = 0; i< s.size();i++){
            if(s[i] == '(' || s[i] == '{'|| s[i] =='['){
                stk.push(s[i]);
            }
            else{
                if(stk.size() == 0 
                 || (s[i] == ')' && stk.top() != '(')
                 || (s[i] == '}' && stk.top() != '{')
                 || (s[i] == ']' && stk.top() != '[')
                 ) return false ;
                else{
                    stk.pop();
                }
            }
        }

        return stk.size() == 0 ;

    }
};
