#include <fstream>

using namespace std;

ifstream fin("numar-maxim.in");
ofstream fout("numar-maxim.out");

char c, st[1000005];

int main()
{
    int n, k, top = 0;
    fin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        fin >> c;
        while (top > 0 && k > 0 && st[top] < c)
        {
            top--;
            k--;
        }
        st[++top] = c;
    }

    for (int i = 1; i <= top; i++)
        fout << st[i];

    return 0;
}