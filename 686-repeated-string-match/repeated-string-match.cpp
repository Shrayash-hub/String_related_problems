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
    int KMP(string haystack, string needle) {
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
            return 1;
        }
        // and if not then there is no occurrence of needle string in the haystack string
        return -1;
    }
    int repeatedStringMatch(string a, string b) {
        int rep = 1;
        string goal =a;
        vector<int> lps(b.size(),0);
        // firstly we will make that string equal to the size of b by repeating a multiple times
        while(goal.size()<b.size()){
            goal=goal+a;
            rep++; 
        }
        // then we will check that b is substring of that string or not
        if(KMP(goal,b)==1){
            return rep;
        }
        // then we will check one more time for that string by adding a to it
        if(KMP(goal+a,b)==1){
            return rep+1;
        }
        // at the end if b is not found in both the cases , that means its not going to be found in other also
        return -1;
    }
};