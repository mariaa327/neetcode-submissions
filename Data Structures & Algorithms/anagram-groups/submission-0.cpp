class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> groups;

        for(string word : strs) {
            string key = word;
            sort(key.begin(), key.end());
            groups[key].push_back(word);
        }

        vector<vector<string>> results;

        for(auto group : groups) {
            results.push_back(group.second); // group second adica valoarea deoarece avem un map
        }

        return results;
    }
};
