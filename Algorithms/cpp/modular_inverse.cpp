///Calculating modular inverse using Euclid's extended algorithm
#include <iostream>
using namespace std;

//Calculating gcd(a,b)
int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    if(a == 0)
    {
        return b;
    }
    return gcd(b, a % b);
}

///Extended Euclidean algorithm helps in computing x and y for equation of the type: Ax + By = GCD(A, B)
int x, y, g;
pair <int, int> extendedEuclidean(int a, int b)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        g = a;
        return make_pair(x, y);
    }
    extendedEuclidean(b, a % b);
    int cx = y;
    int cy = x - (a / b)*y;
    x = cx;
    y = cy;
    return make_pair(x, y);
}

///Function to compute modular inverse of 'a' w.r.t 'm'
int modularInverse(int a, int m)
{
    if(gcd(a, m) != 1)
    {
        cout << "does not exist." << endl;
    }
    return (extendedEuclidean(a, m).first + m) % m;
}

int main()
{
    int a, m;
    cin >> a >> m;
    cout << modularInverse(a, m) << endl;
}
