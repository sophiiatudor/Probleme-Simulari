#include <fstream>

using namespace std;

ifstream fin("sum-div.in");
ofstream fout("sum-div.out");

int s[10000005];

int main()
{
    long long a, b, S = 0;
    fin >> a >> b;

    for (int d = 1; d <= b / 2; d++)
    {
        for (int j = 2 * d; j <= b; j += d)
        {
            s[j] += d;
        }
    }

    for (int i = a; i <= b; i++)
    {
        if (i > s[i]) S += i - s[i];
        else S += s[i] - i;
    }

    fout << S;
    return 0;
}