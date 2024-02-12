#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> athletes; // (strength, endurance)

        for (int i = 0; i < n; i++) {
            int s, e;
            cin >> s >> e;
            athletes.push_back({s, e});
        }

        sort(athletes.begin(), athletes.end());

        long long total_strength = 0;
        long long max_lifts = 0;
        long long min_weight = 1;

        for (int i = 0; i < n; i++) {
            total_strength += athletes[i].first;
            max_lifts = max(max_lifts, total_strength * 1LL * athletes[i].second);
            while (min_weight <= athletes[i].first) {
                max_lifts = max(max_lifts, min_weight * 1LL * (total_strength - min_weight));
                min_weight++;
            }
        }

        cout << max_lifts << endl;
    }

    return 0;
}
