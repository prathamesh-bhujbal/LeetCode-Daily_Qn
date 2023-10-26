class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> mp;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = 1;
        }
        long long cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < i; j++) {
                int it = arr[i] % arr[j];
                int kt = arr[i] / arr[j];
                int mt = arr[j];
                if (arr[i] % arr[j] == 0) {
                    if (mp.find(kt) != mp.end()) {
                        mp[arr[i]] += (mp[kt] * mp[mt]) % 1000000007;
                    }
                }
            }
        }
        for (auto i : mp) {
            cnt = (cnt + i.second) % 1000000007;
        }
        return cnt;
    }
};
