//返回一个整数数组中最大子数组的和
#include<iostream>
using namespace std;

int main()
{
	int sum = 0;//暂存的累加和
	int MaxSum=0;//最大子数组和
	//int a[8] = { 1,-2, 3, 10, -4, 7,2,-5 };maxsum=18
	int i,m=1;
	int *a=new int[m];//动态数组
	
	cout << "请输入数组个数\n";
	cin >> m;
	cout << "输入一个整数数组，包含正负数\n";
	for (i = 0; i < m; i++)
	{
		cin >> a[i];
	}
	////////////////////////////////////////////
	for (i = 0; i < m; i++)
	{
		sum += a[i];//累加
		
		if (sum < 0)
		{
			sum =0;//和小于0，就不要了
		}
		
		if (sum > MaxSum)//如果当前累加和大于最大和
		{
			MaxSum = sum;//最大和为当前和
		}
	}

	if (MaxSum == 0)//当所有元素都为负值，找最大那个
	{
		MaxSum = a[0];
		for ( i = 1; i < m; i++)
		{
			if (a[i]>MaxSum)
			{
				MaxSum = a[i];
			}

		}
	}
	cout << "最大和=" << MaxSum;


}
