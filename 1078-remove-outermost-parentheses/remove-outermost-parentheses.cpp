class Solution {
public:
    string removeOuterParentheses(string s) {
        int count =0;
        string ans = "";
        // we are going to increase the pointer for '(' this paranthesis and decrease for ')'
        for(int i=0;i<s.size();i++){
            if(s[i]==')') count--; // for closing we have to check the count becomes zero after updating the counter 
            if(count!=0) ans.push_back(s[i]); // for closing we have to check the count becomes zero before updating the counter
            if(s[i]=='(') count++;
        }
        return ans;
    }
};