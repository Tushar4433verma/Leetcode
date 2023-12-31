class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0,fast=0;
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        fast=0;
        while(1){
            if(slow==fast) return slow;
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};