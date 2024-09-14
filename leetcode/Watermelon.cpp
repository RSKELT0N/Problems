#include <iostream>
using namespace std;

void solve(int x) {
    if (x <= 2) {
        cout << "NO";
        return;
    }

    if (x & 1) {
        cout << "NO";
    } else cout << "YES";
}

int main() {
    int x;
    cin >> x;
    solve(x);
   return 0;
}
