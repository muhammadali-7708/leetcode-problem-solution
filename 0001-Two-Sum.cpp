class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int , int>mapp;
        for(int i = 0 ; i < nums.size() ; i++){
            if(mapp.find(target - nums[i]) != mapp.end())
                return {mapp[target - nums[i]] , i};
            else
                mapp[nums[i]] = i;
        }
        return {0 , 0};
    }
};