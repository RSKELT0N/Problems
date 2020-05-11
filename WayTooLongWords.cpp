#include <iostream>
using namespace std;

void solve(string s) {
    string res = "";
    if (s.length() <= 10) {
        cout << s << endl;
        return;
    }

    res += s[0];
    int i;
    res += to_string(s.length() - 2);
    res += s[s.length() - 1];
    cout << res << endl;
}

int main() {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        solve(s);
    }
    return 0;
}
