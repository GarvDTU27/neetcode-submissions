class Solution {
public:
    int timeTaken(vector<int> &nums, int speed){
        int time = 0;
        for(int i = 0   ; i < nums.size(); i++){
            time += (nums[i]+speed -1 )/speed ;
        }

        return time ;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = INT_MIN ;
        for(auto it : piles){
            high = max(high, it);
        }

        while(low <= high){
            int mid = low + (high - low)/2 ;
            int hours = timeTaken(piles, mid);
            if(hours <= h){
                high = mid-1 ;
            }
            else{
                low = mid +1;
            }
        }

        return low ;
    }
};
