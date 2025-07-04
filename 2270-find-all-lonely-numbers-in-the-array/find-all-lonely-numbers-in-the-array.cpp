class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ans;
        map<int,int> freq;
        // count frequencies
        for(int num : nums) {
            freq[num]++;
        }

        for(int num : nums) {
            if(freq[num] == 1 &&
            freq[num - 1] == 0 &&
            freq[num + 1] == 0) {
            ans.push_back(num);
        }
        }
        return ans;
    }
};