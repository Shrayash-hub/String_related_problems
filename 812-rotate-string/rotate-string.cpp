class Solution {
public:
    void LPS(vector<int> &lps, string s){
        int pre=0;
        int suf=1;
        while(suf<s.size()){
            if(s[suf]==s[pre]){
                lps[suf]=pre+1;
                suf++;pre++;
            }
            else{
                if(pre==0){
                    suf++;
                }
                else{
                    pre =lps[pre-1];
                }
            }
        }
    }
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        vector<int> lps(s.size(),0);
        goal = goal + goal; // if goal is same as s after few rotations then s is going to be a substring 
                            // of the goal + goal string
        LPS(lps,s); // we are going to use the lps algo to find that s is substring of goal+goal or not
        int first =0;
        int second =0;
        while(first<goal.size() && second<s.size()){
            if(goal[first]==s[second]){
                first++;second++;
            }
            else{
                if(second==0){
                    first++;
                }
                else{
                    second = lps[second-1];
                }
            }
        }
        if(second==s.size()){
            return true;
        }
        return false;
    }
};