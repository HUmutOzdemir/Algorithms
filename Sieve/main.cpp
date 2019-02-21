#include <bits/stdc++.h>
using namespace std;
bool prime[10000001];
void Sieve(int n)
{
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p])
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
    for (int p=2; p<=n; p++)
        if (prime[p])
            cout << p << " ";
}
int main()
{
    int n = 30;
    cout << "Following are the prime numbers smaller "
         << " than or equal to " << n << endl;
    Sieve(n);
    return 0;
} 