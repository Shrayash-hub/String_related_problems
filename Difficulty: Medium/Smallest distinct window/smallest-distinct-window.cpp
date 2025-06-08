class Solution {
  public:
    int findSubString(string& s) {
        // code here
        vector<int> count(256, 0);
        int first = 0, second = 0, len = INT_MAX;
        int diff = 0;

        // counting the unique characters
        while (first < s.size()) {
            if (count[s[first]] == 0) {
                diff++;
            }
            count[s[first]]++;
            first++;
        }

        // reset count array
        for (int i = 0; i < 256; i++) {
            count[i] = 0;
        }

        first = 0;

        while (second < s.size()) {
            // decrease diff until all unique chars are included
            while (diff > 0 && second < s.size()) {
                if (count[s[second]] == 0) {
                    diff--;
                }
                count[s[second]]++;
                second++;
            }

            // update minimum length
            if (diff == 0) {
                len = min(len, second - first);
            }
    
            // shrink the window
            while (diff == 0) {
                count[s[first]]--;
                if (count[s[first]] == 0) {
                    diff++;
                }
                first++;
                if (diff == 0) {
                    len = min(len, second - first);
                }
            }
        }

        return len;
        }
};