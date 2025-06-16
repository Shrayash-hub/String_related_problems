
// User function template for C++

class Solution {
  public:
    int longestPrefixSuffix(string &s) {
        // Your code goes here
        vector<int> LPS(s.size(),0);
        int pre =0, suf =1;
        while(suf<s.size()){
            // there can be 2 cases , either its going to match
            if(s[pre]==s[suf]){
                LPS[suf]=pre+1; // so we will update the LPS table like this
                pre++;suf++; // and increase the pointers by one
            }
            // or there will be no match
            else{
                if(pre==0){   // firstly we will be checking that pre is at zero or not
                    LPS[suf]=0; // if yes then we will update LPS table
                    suf++;
                }
                else{
                    pre=LPS[pre-1]; // and if not then we will update the pre pointer to find the match
                }
            }
        }
        return LPS[s.size()-1];
    }
};