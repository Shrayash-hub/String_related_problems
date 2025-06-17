class Solution {
public:
    // firstly we are going to find the LPS table of the needle string
    void LPS(vector<int> &lps, string s){
        int pre =0, suf=1;
        while(suf<s.size()){
            if(s[pre]==s[suf]){
                lps[suf]=pre+1;
                suf++;pre++;
            }
            else{
                if(pre==0){
                    lps[suf]=0;
                    suf++;
                }
                else{
                    pre=lps[pre-1];
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
        vector<int> lps(needle.size(),0);
        LPS(lps,needle);
        int first =0,second =0;
        // now we will be comparing both the strings 
        while(first<haystack.size() && second<needle.size()){
            // if they are equal, we will increase the pointe by one
            if(haystack[first]==needle[second]){
                first++;second++;
            }
            // if not then there will be two more cases 
            else{
                // if second will be at zero index , then we need to increase the first pointer 
                if(second==0){
                    first++;
                }
                else{
                    second=lps[second-1];
                }
            }
        }
        // incase second will be out of the index, that means we found the first occurrence 
        if(second==needle.size()){
            return first-second;
        }
        // and if not then there is no occurrence of needle string in the haystack string
        return -1;
    }
};