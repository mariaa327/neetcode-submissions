class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charIndex(128, -1);
        int left = 0; 
        int maxLength = 0;

        for(int i = 0; i < (int)s.size(); i++) {
            int currentChar = s[i];

            if(charIndex[currentChar] >= left) 
                left = charIndex[currentChar] + 1;

            charIndex[currentChar] = i;

            maxLength = max(maxLength, i - left + 1);
        }

        return maxLength;
    }
};
