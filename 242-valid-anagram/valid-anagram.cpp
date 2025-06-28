class Solution {
public:
    bool isAnagram(string s, string t) {
        // vector<int> s_count(256,0);
        // vector<int> t_count(256,0);
        // for(int i=0;i<s.size();i++){
        //     s_count[s[i]-'0']++;
        // }
        // for(int i=0;i<s.size();i++){
        //     t_count[t[i]-'0']++;
        // }
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t){
            return true;
        }
        return false;

    }
};