// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> freq;
//         for(int num: nums)
//             freq[num]++;

//         vector<pair<int, int>> v;

//         for(auto x : freq)
//             v.push_back({x.second, x.first});

//         sort(v.begin(), v.end());

//         vector<int> result;

//         for(int i = (int)v.size() - 1; i>=(int)v.size() - k; i--)
//             result.push_back(v[i].second);

//         return result;
//     }
// };

// sau cu vector<pair<int, int>>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>> freq;

        for(int num: nums) {
            int ok = 0;

            for(int i = 0; i < (int)freq.size(); i++) {
                if(freq[i].second == num) {
                    freq[i].first++;
                    ok = 1;
                    break;
                }
            }

            if(ok == 0)
                freq.push_back({1, num});    
        }

        sort(freq.begin(), freq.end());

        vector<int> result;

        for(int i = (int)freq.size() - 1; i >= (int)freq.size() - k; i--) 
            result.push_back(freq[i].second);

        return result;
    }
};


