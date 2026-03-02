#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, a, b;
    cin >> n >> a >> b;

    long long g = __gcd(a, b);
    long long lcm = (a * b) / g;


    long long left = min(a, b);
    long long right = n * min(a, b);

    while (left < right)
    {
        long long mid = left + (right - left) / 2;

        long long count = (mid / a) + (mid / b) - (mid / lcm);

        if (count < n)
            left = mid + 1;
        else
            right = mid;
    }

    cout << (left % 1000000007) << endl;

    return 0;
}
