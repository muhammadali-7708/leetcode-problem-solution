class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int counter = nums.size();
        for(int i = 0; i < nums.size(); i = i + 1){
            if(nums[i] == val){
                nums.erase(nums.begin() + i);
                counter--;
                i = i - 1;
            }
        }
        return counter;
    }
};