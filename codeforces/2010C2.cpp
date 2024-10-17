#include <iostream>
#include <vector>
using namespace std;

// Function to compute the prefix function
vector<int> compute_prefix_function(const string& t) {
    int n = t.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && t[i] != t[j]) {
            j = pi[j-1];
        }
        if (t[i] == t[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

// Function to solve the problem
void solve(const string& t) {
    int n = t.size();
    vector<int> pi = compute_prefix_function(t);

    int longest_border = pi[n-1];
    int s_length = n - longest_border;

    // Check if we have a valid overlap and the string `t` can be represented as `s` merged with itself.
    if (longest_border > 0 && s_length < n && n % s_length == 0) {
        string s = t.substr(0, s_length);
        // Verify that the entire string `t` can be built by repeating `s` with the overlap
        string expected = s + s.substr(0, longest_border);
        if (expected == t) {
            cout << "YES" << endl;
            cout << s << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    string t;
    cin >> t;
    solve(t);
    return 0;
}
