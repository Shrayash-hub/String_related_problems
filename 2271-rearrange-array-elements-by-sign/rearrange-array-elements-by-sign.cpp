class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
      vector<int> arr(nums.size(),0);
      int positiveindex =0;
      int negativeindex =1;
      for(int i=0;i<nums.size();i++){
        if(nums[i]<0){
            arr[negativeindex]=nums[i];
            negativeindex+=2;
        }
        else{
            arr[positiveindex]=nums[i];
            positiveindex+=2;
        }
      }
      return arr;
    }
};