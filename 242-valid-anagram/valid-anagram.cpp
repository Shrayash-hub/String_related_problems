class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> freq(26, 0);
        // find the frequency of each character from the s string
        for (char c : s) freq[c - 'a']++;
        // decrease the frequency of each character from the string t , if overall frequency is zero then strings are anagaram
        for (char c : t) freq[c - 'a']--;
        for (int count : freq) if (count != 0) return false;
        return true;

        // second method with nlogn time complexity
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // if(s==t){
        //     return true;
        // }
        // return false;

    }
};