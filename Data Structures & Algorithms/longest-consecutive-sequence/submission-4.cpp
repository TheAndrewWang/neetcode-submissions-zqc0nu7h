class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> tmp;
        for (size_t i = 0; i < nums.size(); i++) {
            tmp.insert(nums[i]);
        }
        set<int>::iterator itr = tmp.begin();
        int previous = *itr;
        int longestStreak = 0;
        int counter = 1;
        if (itr == tmp.end()) {
            counter = 0;
        }
        while (itr != tmp.end()) {
            cout << *itr << endl;
            if (*itr == previous + 1) {
                previous++;
                counter++;
                if (counter > longestStreak) {
                    longestStreak = counter;
                }
            } else {
                if (counter > longestStreak) {
                    longestStreak = counter;
                }
                counter = 1;
                previous = *itr;
            }
            itr++;
        }
        return longestStreak;
    }
};
