class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size()-1 ;
        int lMax = height[l];
        int rMax = height[r];

        int ans = 0;

        while(l < r){
            if(height[l] <= height[r]){
                // left process
                if(lMax < height[l]) lMax = height[l];

                ans += lMax - height[l];
                l++ ;
            }
            else{

                if(rMax < height[r]) rMax = height[r];

                ans += rMax - height[r];
                r-- ;
                //right process
            }


        }

        return ans ;
    }
};
