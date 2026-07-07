class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       deque<int> maxNumber;
       vector<int> maxes(nums.size() - k + 1);
    
       int l = 0; int r = 0;
       while (r < nums.size()) {
            while (!maxNumber.empty() && nums[maxNumber.back()] < nums[r]) {
                maxNumber.pop_back();
            }
            maxNumber.push_back(r);

            if (l > maxNumber.front()) {
                maxNumber.pop_front();
            }

            if ((r + 1) >= k) {
                maxes[l] = nums[maxNumber.front()];
                l++;
            }
            r++;
       }
       return maxes;
       
    }
};
