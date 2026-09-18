class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';

            if (first[c] == -1)
                first[c] = i;

            last[c] = i;
        }
        vector<pair<int, int>> intervals;
        for (int i = 0; i < s.size(); i++) {
            if (first[s[i] - 'a'] != i)
                continue;
            int l = i;
            int r = last[s[i] - 'a'];
            bool valid = true;
            for (int j = l; j <= r; j++) {
                int c = s[j] - 'a';
                if (first[c] < l) {
                    valid = false;
                    break;
                }
                r = max(r, last[c]);
            }

            if (valid)
                intervals.push_back({l, r});
        }
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        vector<string> ans;
        int previousEnd = -1;
        for (auto [l, r] : intervals) {
            if (l > previousEnd) {
                ans.push_back(s.substr(l, r - l + 1));
                previousEnd = r;
            }
        }

        return ans;
    }
};