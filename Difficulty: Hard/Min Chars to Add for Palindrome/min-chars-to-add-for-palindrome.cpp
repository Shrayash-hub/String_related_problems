class Solution {
  public:
    int LPS(string s){
        vector<int> lps(s.size(),0);
        int pre=0;
        int suf=1;
        while(suf<s.size()){
            if(s[pre]==s[suf]){
                lps[suf] = pre+1;
                pre++;suf++;
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
        return lps[s.size()-1];
    }
    int minChar(string& s) {
        // Write your code here
        string new_string = s + "$" ;
        reverse(s.begin(),s.end());
        new_string = new_string + s; // --> firstly we are going to make the string of type s + "$" + reverse_of_s
        
        int lps = LPS(new_string); // then we will be finding the longest prefix suffix ..which is going to be length of longest palindrome in the string
        return s.size()-lps; // no. of char we have to add will be
    }
};
