#include<stdio.h>

int gcd(int m,int n)
{
	int tmp;
	if (m < n)
	{
		tmp = m;
		m = n;
		n = tmp;
	}
	
	if (m % n == 0)
	{
		return n;
	}
	else
	{
		return gcd(n,m%n);
	}
}

int main()
{
	int N,i;
	
	scanf("%d",&N);
	
	while (N--)
	{
		double num1,num2;
		int sum1,sum2 = 1,fac;
		
		scanf("%lf",&num1);
		
		for (i = 1;i <= 9;i++)
		{
			num1 *= 10;
			sum2 *= 10;
			num2 = num1 + 0.000001;    //����double���͵ľ������⣬�硰1����double�����ԡ�0.99999���������棬
			                           // ���Լ�һ����С��С��ʹ֮�ܵõ���Ҫ������ 
			if (num1 - (int)num2 <= 0.000001)   //��������double�ľ������⣬����printf�����num1ֵ��(int)num2��ֵ 
			{                                   //��ͬ �������ڲ�������������С��λ�������ǲ��ȵģ��ж���ȷ������ö��߲�ֵ�Ƿ�С 
				break;
			}
		}
		
		sum1 = (int)num2;
		
		fac = gcd(sum1,sum2);
		
		printf("%d/%d\n",sum1/fac,sum2/fac);
	}
	
	return 0;
}
