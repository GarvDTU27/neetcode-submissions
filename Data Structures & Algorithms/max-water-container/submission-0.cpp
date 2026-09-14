class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxi = 0;
        int low = 0;
        int high = heights.size()-1 ;

        while(low < high){
            int width = high - low ;
            int height = min(heights[high], heights[low]);
            maxi = max(maxi, height*width);

            if(heights[low] < heights[high]) low++ ;
            else high -- ;
        }

        return maxi ;
    }
};
