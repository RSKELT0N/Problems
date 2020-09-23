#include <iostream>
#include <cmath>


using namespace std;

int i, t;
long a[32];

int findComplement(int n) {
    for (i = 0; n > 0; i++) {
        a[i] = n % 2;
        n = n / 2;

        if (a[i] == 1)
            a[i] = 0;
        else
            a[i] = 1;
    }

    int val = 0;
    for (int j = 0; j <= i; j++)
        if (a[j] == 1)
            val += pow(2, j);

    return val;
}
int main() {
    cout << findComplement(5);
    return 0;
}
