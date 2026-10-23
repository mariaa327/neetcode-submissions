class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());

        int left = 1;
        int right = piles.back();
        int ans = right;

        while(left <= right) {
            int mid = (left + right) / 2;

            long long hours = 0;

            for(int pile : piles) {
                hours += (pile + mid - 1) / mid;
            }

            if(hours <= h) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
