class Solution {
  public:
    // finding the lps table of the pattern
    void LPS(string s,vector<int> &lps){
        int prefix =0;
        int suffix =1;
        while(suffix<s.size()){
            if(s[prefix]==s[suffix]){
                lps[suffix]=prefix+1;
                suffix++,prefix++;
            }
            else{
                if(prefix==0){
                    lps[suffix]=0;
                    suffix++;
                }
                else{
                    prefix=lps[prefix-1];
                }
            }
        }
    }
    
    vector<int> search(string& pat, string& txt) {
        // code here
        vector<int> lps(pat.size(),0);
        vector<int> result;
        LPS(pat,lps);
        int first =0,second=0;
        while(first<txt.size()){
            // if characters of the string is going to match then we are going to increase the pointer by one
            if(txt[first]==pat[second]){
                first++;second++;
            }
            // when the whole second string is matched then we are going to save the index in the result vector
            if(second==pat.size()){
                result.push_back(first-second);
                second = lps[second-1]; // and then we are going to find other occurences
            }
            // but if the some part of the string is matched we are going to set the second pointer according to the lps table
            else if(first<txt.size() && txt[first]!=pat[second]){
                if(second==0){
                    first++;
                }
                else{
                    second=lps[second-1];
                }
            }
        }
        return result;
        
    }
};