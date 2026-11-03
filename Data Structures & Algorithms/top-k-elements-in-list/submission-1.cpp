class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq ;

        for(auto it: nums){
            freq[it]++ ;
        }

        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > minHeap;

        for(auto it: freq){
            if(minHeap.size() < k){
                minHeap.push({it.second, it.first});
            }
            else{
                if(minHeap.top().first < it.second){
                    minHeap.pop();
                    minHeap.push({it.second, it.first});
                }
            }
        }

        vector<int> ans ;

        while(minHeap.size()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans ;
    }
};
