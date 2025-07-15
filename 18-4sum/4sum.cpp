class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // similar to 3 sum problem , but here we will use 4 pointers , 2 of them will be fixed and another two will be moving
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end()); // sorting the elements so that duplicates come together
        for(int i=0;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue; // if i is similar than moving it forward to skip the duplicates
            for(int j=i+1;j<n;j++){  // if j is similar than moving it forward to skip the duplicates
                if(j!=i+1 && nums[j]==nums[j-1]) continue;
                int k=j+1;
                int l=n-1;
                while(k<l){ // moving k and l pointers
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum==target){
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;l--;
                        while(k<l && nums[k]==nums[k-1]) k++; // moving k and l pointer until duplicates get skipped
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                    else if(sum>target) l--;
                    else k++;
                }
            }
        }
        return ans;
    }
};