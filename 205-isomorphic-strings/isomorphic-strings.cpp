class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        // we are going to take to maps and we will be saving the key value form of each char pair in the map
        map<char, char> m1;
        map<char, char> m2;

        for (int i = 0; i < s.size(); ++i) {
            char c1 = s[i], c2 = t[i];
            // now if the key already exist and diffrent value is mapped at that position then it is not a          isometric string 
            if (m1.count(c1) && m1[c1] != c2) return false;
            if (m2.count(c2) && m2[c2] != c1) return false;

            m1[c1] = c2;
            m2[c2] = c1;
        }
        return true;
    }
};