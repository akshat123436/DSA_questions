#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b;
    cout << "Enter a and b : ";
    cin >> a >> b;
    double t = 0;
    if (a < b && a < 10)
    {
        t = a * a + a * b + sqrt(a * b);
    }
    else if (a == b || b > 10)
    {
        t = a * b * b - 2 * a + 5 * b;
    }
    else
    {
        cout << "No conditions met" << endl;
        return 0;
    }
    cout << t << endl;
    return 0;
}