class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = (int)numbers.size() - 1;

        while(left < right) {
            int num = numbers[left] + numbers[right];
            if(target == num)
                return {left + 1, right + 1};

            if(num < target) left++;
            else right--;

        }
        return {};

    }
};
