class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq ;
        for(auto it : nums){
            freq[it]++ ;
        }

        priority_queue<pair<int,int> , vector<pair<int, int>> , greater<pair<int , int>> > minHeap ;

        for(auto it : freq){
            pair<int,int> curr = {it.second, it.first};

            if(minHeap.size() < k){
                minHeap.push(curr);
            }
            else{
                if(curr.first > minHeap.top().first){
                    minHeap.pop();
                    minHeap.push(curr);
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
