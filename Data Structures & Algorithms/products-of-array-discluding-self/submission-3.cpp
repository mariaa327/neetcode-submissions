// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int length = (int)nums.size();

//         vector<int> output;

//         for(int i = 0; i < length; i++) {
//             int product = 1;

//             for(int j = 0; j < length; j++) {
//                 if(j != i) {
//                     product *= nums[j];
//                 }
//             }

//             output.push_back(product);
//         }

//         return output;
//     }
// };
// asta este solutia ineficienta dar nu trece toate testele

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int prod = 1, zeroCount = 0;

//         for(int num : nums) {
//             if(num != 0) {
//                 prod *= num;
//             } else {
//                 zeroCount++;
//             }
//         }

//         if(zeroCount > 1) return vector<int>(nums.size(), 0);

//         vector<int> res(nums.size());

//         for(int i = 0; i < nums.size(); i++) {
//             if(zeroCount > 0) {
//                 if(nums[i] == 0)
//                     res[i] = prod;
//                 else res[i] = 0;
//             } else {
//                 res[i] = prod/nums[i];
//             }
//         }
//         return res;
//     }
// };


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = (int)nums.size();

        vector<int> pref(n, 1);
        vector<int> suff(n, 1);
        vector<int> res(n, 1);

        pref[0] = 1;
        suff[n-1] = 1;

        for(int i = 1; i < n; i++) {
            pref[i] = pref[i-1] * nums[i-1];
        }

        for(int i = n-2; i >= 0; i--) {
            suff[i] = suff[i + 1] * nums[i + 1];
        }

        for(int i = 0; i<n; i++) {
            res[i] = pref[i] * suff[i];
        }

        return res;
    }
};
