class Solution {
public:
    string largestOddNumber(string num) {
        // check the last character number which is odd in the string, from first to that char number will be the largest odd number in the string
        int n = num.size();
        string ans = "";
        int index;
        for(int i=n-1;i>=0;i--){
            if((num[i]-'0')%2!=0){
                ans+= num[i];
                index =i;
                break;
            }
        }
        return num.substr(0,index+1);
    }
};