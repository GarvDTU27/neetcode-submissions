class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp1 ;
        unordered_map<char,int> mp2 ;
        for(int i = 0; i< s1.size(); i++){
            mp1[s1[i]]++ ;
            mp2[s2[i]]++ ;
        }        

        int r = s1.size() ;
        int l = 0;

        while(r < s2.size()){
            
            if(mp2 == mp1) return true ;

            mp2[s2[l]]-- ;
            if(mp2[s2[l]] == 0) mp2.erase(s2[l]);
            mp2[s2[r]]++ ;
            l++ ;
            r++ ;
        }

        return mp1 == mp2 ;
    }
};
