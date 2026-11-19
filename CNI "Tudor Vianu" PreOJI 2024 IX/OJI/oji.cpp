#include <fstream>

using namespace std;

ifstream fin("oji.in");
ofstream fout("oji.out");

const int M = 651;
int a[500005], b[500005];
int sp[M + 1][M + 1];

int frecventa(int x, int y)
{
    return sp[x][y] - sp[x - 1][y] - sp[x][y - 1] + sp[x - 1][y - 1];
}

int main()
{
    int n;
    fin >> n;

    for (int i = 1; i <= n; i++)
    {
        fin >> a[i] >> b[i];
        sp[a[i] + 1][b[i] + 1]++;
    }

    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= M; j++)
            sp[i][j] = sp[i][j] + sp[i - 1][j] + sp[i][j - 1] - sp[i - 1][j - 1];

    for (int i = 1; i <= n; i++)
    {
        int x = a[i] + 1;
        int y = b[i] + 1;

        int maiMari = n - sp[x][M] - sp[M][y] + sp[x][y];
        int maiMici = sp[x - 1][y - 1];

        int mini = 1 + maiMari;
        int maxi = n - maiMici;

        if (a[i] == 650) maxi -= frecventa(1, y);
        if (b[i] == 650) maxi -= frecventa(x, 1);

        fout << mini << ' ' << maxi << '\n';
    }

    return 0;
}