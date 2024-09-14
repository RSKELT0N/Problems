#include <iostream>
#include <cmath>

using namespace std;

bool checkValidSquare(int num) {
    if (num == 1) return true;
    int l = 0;
    int r = num / 2;
    while (l <= r) {
        double mid = l + (r - l) / 2;
        if (mid == num / mid)
            return true;
        if (mid > num / mid)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return false;

//    for (long i = 0; i < LONG_MAX; i++) {
//        long long res = i * i;
//        if (res == num)
//            return true;
//        if (res > num)
//            return false;
//    }
//    return false;
}

int main() {
    cout << checkValidSquare(100);
    return 0;
}
