#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
#define N 100

typedef struct
{
	int dian[N];
	int xian[N][N];
	int dianx, xianx;
}A;

void set(A &shu, int x, int y, ifstream &infile)
{
	shu.dianx = x*y;
	srand((unsigned)time(NULL));
	for (int i = 1; i <= shu.dianx; i++)
	{
			infile >> shu.dian[i];
	}
	infile.close();
	for (int i = 1; i <= shu.dianx; i += y)
	{
		for (int j = i; j <= i + y - 2; j++)
		{
			shu.xian[j][j + 1] = 1;
			shu.xian[j + 1][j] = 1;
		}
	}
	for (int i = 1 + y; i<shu.dianx; i += y)
	{
		for (int j = i; j <= i + x - 1; j++)
		{
			shu.xian[j][j - y] = 1;
			shu.xian[j - y][j] = 1;
		}
	}
}
void numdian(A &Shu,int &hangshu,int &lieshu)
{
	ifstream infile("input.txt", ios::in);
	if (infile.is_open() == false)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	infile >> hangshu >> lieshu;
	set(Shu, hangshu, lieshu, infile);
}
void output(A shu)
{
	for (int i = 1; i <= shu.dianx; i++)
	{
		cout << shu.dian[i];
		if (shu.xian[i][i + 1] == 1)
			cout << "  ";
		else
			cout << endl;
	}
}
void bianli(A &shu, int v, int visit[], int &b, int &max, int x)
{
	visit[v] = 1;

	max += shu.dian[v];
	if (max >= b)
		b = max;

	int a = 0, bo = 0;
	for (int w = 1; w <= shu.dianx; w++)
	{
		for (int c = 1; c <= shu.dianx; c++)
		{
			if ((visit[w] == 0) && (shu.xian[c][w] == 1) && (visit[c] == 1))
			{
				a = w; bo = 1; break;
			}
		}
		if (bo == 1)
			break;
	}
	for (int w = 1; w <= shu.dianx; w++)
	{
		for (int c = 1; c <= shu.dianx; c++)
		{
			if ((visit[w] == 0) && (shu.xian[c][w] == 1) && (visit[c] == 1))
			{
				if (shu.dian[a]<shu.dian[w])
					a = w;
			}
		}
	}
	if (b + shu.dian[a]<0)
	{
		shu.xian[v][a] = 0;
	}
	else
		bianli(shu, a, visit, b, max, x);
}

int NoVisit(int visit[], A shu)
{
	int k = 0, i;
	for (i = 1; i <= shu.dianx; i++)
	{
		if (visit[i] == 0)
		{
			k = i;
			break;
		}
	}
	return k;
}

int main()
{

	int hangshu, lieshu;
	A shu;
	numdian(shu, hangshu, lieshu);

	output(shu);

	int v = 1, b[N] = { 0 }, h = 0;
	for (int i = 1; i <= shu.dianx; i++)
	{
		if (shu.dian[i]<0)
		{
			b[i] = shu.dian[i];
		}
		else
		{
			int visit[N] = { 0 };
			int max = 0;
			bianli(shu, i, visit, b[i], max, hangshu);
		}
	}

	int max = b[1];
	for (int i = 2; i <= shu.dianx; i++)
	{
		if (b[i]>max)
			max = b[i];
	}
	cout << "最大联通子数组的和为：" << max << endl;
}
