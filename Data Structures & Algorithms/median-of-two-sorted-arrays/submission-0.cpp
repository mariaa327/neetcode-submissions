class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();

        int left = (total + 1) / 2;
        int right = (total + 2) / 2;

        int a = getKth(nums1, nums1.size(), nums2, nums2.size(), left, 0, 0);
        int b = getKth(nums1, nums1.size(), nums2, nums2.size(), right, 0, 0);

        return ((double)a + b) / 2;
    }

    int getKth(vector<int>& a, int m, vector<int>& b, int n,
               int k, int aStart, int bStart) {

        // a trebuie sa fie vectorul mai scurt
        if(m > n)
            return getKth(b, n, a, m, k, bStart, aStart);

        // Daca a este gol, cautam direct in b
        if(m == 0)
            return b[bStart + k - 1];

        // Daca vrem cel mai mic element
        if(k == 1)
            return min(a[aStart], b[bStart]);

        // Alegem cate elemente analizam
        int i = min(m, k / 2);
        int j = min(n, k / 2);

        if(a[aStart + i - 1] > b[bStart + j - 1]) {
            // Eliminam j elemente din b
            return getKth(a, m, b, n - j, k - j,
                          aStart, bStart + j);
        }
        else {
            // Eliminam i elemente din a
            return getKth(a, m - i, b, n, k - i,
                          aStart + i, bStart);
        }
    }
};