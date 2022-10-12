class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long int a = LONG_MAX, b = LONG_MAX;
        if (nums.size() < 3) {
            return false;
        }
        for (auto x: nums) {
            if (x <= a) {
                a = x;
            } else if (x <= b) {
                b = x;
            } else {
                return true;
            }
        }
        return false;
    }
};