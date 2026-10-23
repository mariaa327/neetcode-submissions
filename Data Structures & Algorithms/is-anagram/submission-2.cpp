// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if(s.size() != t.size())
//             return false;

//         unordered_map<char, int> countS;
//         unordered_map<char, int> countT;

//         for(char c : s) 
//             countS[c]++;
//         for(char c : t)
//             countT[c]++;

//         if(countS == countT) return true;
//         else return false;
//     }
// };

// sau

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        vector<int> count(26, 0);

        for(int i = 0; s[i]!='\0'; i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for(int i = 0; i<26; i++) {
            if(count[i] != 0)
                return false;
        }

        return true;
    }
};