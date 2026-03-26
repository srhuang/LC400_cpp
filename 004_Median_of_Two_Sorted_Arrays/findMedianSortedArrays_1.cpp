#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // make sure nums1 is less than nums2
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();
        int k = (n1 + n2 + 1) / 2;

        // binary search for m1
        int left = 0;
        int right = n1;
        while (left < right)
        {
            int m1 = left + (right - left) / 2;
            int m2 = k - m1;
            // check m1
            if (nums1[m1] < nums2[m2 - 1]) {
                left = m1 + 1;
            } else {
                right = m1;
            }
        }

        // calculate median
        int m1 = left;
        int m2 = k - m1;
        int c1 = max(m1 == 0 ? INT_MIN : nums1[m1 - 1], 
                     m2 == 0 ? INT_MIN : nums2[m2 - 1]);
        // odd
        if ((n1 + n2) % 2 == 1) {
            return c1;
        }

        // even
        int c2 = min(m1 == n1 ? INT_MAX : nums1[m1],
                     m2 == n2 ? INT_MAX : nums2[m2]);
        return (c1 + c2) * 0.5;
    }
};

int main(int argc, char* argv[])
{
    // input data
    int ary1[] = {1, 2};
    int ary2[] = {3, 4};
    int m = sizeof(ary1) / sizeof(ary1[0]);
    int n = sizeof(ary2) / sizeof(ary2[0]);
    vector<int> nums1(ary1, ary1 + m);
    vector<int> nums2(ary2, ary2 + n);

    // solution
    Solution s;
    double ans = s. findMedianSortedArrays(nums1, nums2);

    // print
    cout << "Answer: " << ans << endl;

}
