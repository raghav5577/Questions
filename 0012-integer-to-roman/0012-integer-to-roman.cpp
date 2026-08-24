class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string, int>> symList = {
            {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
            {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40},
            {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4},
            {"I", 1}
        };

        string result = "";
        int n = symList.size();

        for (int i = 0; i < n; i++) {
            if (num == 0) break;

            int times = num / symList[i].second;

            while (times--) {
                result += symList[i].first;
            }

            num = num % symList[i].second;
        }

        return result;
    }
};