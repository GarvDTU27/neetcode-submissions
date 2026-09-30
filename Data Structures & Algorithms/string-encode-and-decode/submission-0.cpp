class Solution {
public:

    string encode(vector<string>& strs) {
        string s ;
        for(int i = 0; i< strs.size(); i++){
            int n = strs[i].size();
            s.append(to_string(n));
            s.push_back('!');
            s.append(strs[i]);
        }

        return s ;
    }

    vector<string> decode(string s) {
        vector<string> strs ;
        int idx = 0;
        while(idx < s.size()){
            // find size
            int n = 0 ;
            while(s[idx] != '!'){
                int dig = s[idx]-'0' ;
                n *= 10 ;
                n += dig ;
                idx++ ;
            }

            string small = s.substr(idx+1, n);
            strs.push_back(small) ;
            idx = idx + n + 1 ;
        }

        return strs ;
    }
};
