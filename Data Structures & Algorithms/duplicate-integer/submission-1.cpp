class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n= nums.size();
        int count =0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    count++;
                }
            }

           
        }
        if(count>0){
                return true;
            }
            else{
                return false;
            }
    }
};