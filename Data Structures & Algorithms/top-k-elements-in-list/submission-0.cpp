class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // sau unordered_map<int, int>
        for(int num: nums)
            freq[num]++;

        vector<pair<int, int>> v;

        for(auto x : freq)
            v.push_back({x.second, x.first});

        sort(v.begin(), v.end());

        vector<int> result;

        for(int i = (int)v.size() - 1; i>=(int)v.size() - k; i--)
            result.push_back(v[i].second);

        return result;
    }
};
