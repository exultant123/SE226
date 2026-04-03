#include <iostream>
#include <cmath>
using namespace std;

/*
    Recursively computes the equation:
    G_n = 1 + r + r^2 + ... + r^n
     Recursion stops when i > n
    - Each recursion adds r^i to the global variable sum
*/

double geometricSeries(int n, double r) {
    if (n == 0)
        return 1;
    
    return pow(r, n) + geometricSeries(n - 1, r);
}

int main() {
    int n;
    double r;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter common ratio r: ";
    cin >> r;

    double result = geometricSeries(n, r);

    cout << "G_n = " << result << endl;

    return 0;
}