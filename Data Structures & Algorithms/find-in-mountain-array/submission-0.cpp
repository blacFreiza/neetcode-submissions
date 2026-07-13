/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        // Find peak
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                l = mid + 1;
            else
                r = mid;
        }
        int peak = l;

        // Search increasing part
        int ans = binarySearch(mountainArr, 0, peak, target, true);
        if (ans != -1) return ans;

        // Search decreasing part
        return binarySearch(mountainArr, peak + 1, n - 1, target, false);
    }

private:
    int binarySearch(MountainArray &arr, int l, int r, int target, bool asc) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = arr.get(mid);

            if (val == target) return mid;

            if (asc) {
                if (val < target)
                    l = mid + 1;
                else
                    r = mid - 1;
            } else {
                if (val < target)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return -1;
    }
};