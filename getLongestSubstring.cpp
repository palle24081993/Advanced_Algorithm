#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
string getLongestSubstring(const string& s1, const string& s2, int& bestLen) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> grid(n + 1, vector<int>(m + 1, 0));
    bestLen = 0;
    int lastPos = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                grid[i][j] = grid[i - 1][j - 1] + 1;
                if (grid[i][j] > bestLen) {
                    bestLen = grid[i][j];
                    lastPos = i - 1;
                }
            }
        }
    }
    cout << "\nDP Grid:\n    ";
    for (char c : s2) cout << setw(3) << c;
    cout << "\n";
    for (int i = 0; i <= n; i++) {
        if (i > 0) cout << setw(3) << s1[i - 1] << " ";
        else cout << "    ";
        for (int j = 0; j <= m; j++) cout << setw(3) << grid[i][j];
        cout << "\n";
    }

    return s1.substr(lastPos - bestLen + 1, bestLen);
}

int main() {
    string a, b;
    cout << "Enter first string: ";
    cin >> a;
    cout << "Enter second string: ";
    cin >> b;

    if (a.size() != b.size()) {
        cout << "Strings must be same length.\n";
        return 0;
    }

    int len;
    string ans = getLongestSubstring(a, b, len);

    cout << "\nResult:\n";
    cout << "Longest Common Substring: \"" << ans << "\"\n";
    cout << "Length: " << len << "\n";
}
