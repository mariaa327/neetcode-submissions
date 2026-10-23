class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) return "";

        vector<pair<string, int>> &values = mp[key];

        int left = 0;
        int right = values.size() - 1;
        string ans = "";

        while(left <= right) {
            int mid = (left + right) / 2;

            if(values[mid].second <= timestamp) {
                ans = values[mid].first;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
