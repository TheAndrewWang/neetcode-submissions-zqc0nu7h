class Solution {
public:
    int hammingWeight(uint32_t n) {
        string binaryNumber = bitset<32>(n).to_string();

        int res = 0;
        for (char i : binaryNumber) {
            if (i == '1') {
                res++;
            }
        }
        return res;
    }
};
