#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxIndexDifference(string &s) {
        int n = s.size();

        vector<int> bestReach(26, -1);
        vector<int> dp(n);

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            int c = s[i] - 'a';

            if (c == 25) { // If character is 'z'
                dp[i] = i;
            }
            else if (bestReach[c + 1] != -1) {
                dp[i] = bestReach[c + 1];
            }
            else {
                dp[i] = i;
            }

            // Update the farthest reachable index for this character
            bestReach[c] = max(bestReach[c], dp[i]);
        }

        int ans = -1;

        // Check only starting positions containing 'a'
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                ans = max(ans, dp[i] - i);
            }
        }

        return ans;
    }
};

int main() {
    string s;

    cout << "Enter the string: ";
    cin >> s;

    Solution obj;

    cout << "Maximum Reachable Index Difference = "
         << obj.maxIndexDifference(s) << endl;

    return 0;
}