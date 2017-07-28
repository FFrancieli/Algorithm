#include<iostream>
#include<algorithm>
#include<cstdio>

__int64 gcd(__int64 a,__int64 b)
{
	return b?gcd(b,a%b):a;
}

void extgcd(__int64 a,__int64 b,__int64 &x,__int64 &y)
{
	if (!b)
	{
		x = 1;
		y = 0;
	}
	else
	{
		extgcd(b,a%b,y,x);
		y -= x*(a/b);
	}
}


int main()
{
	__int64 x,y,m,n,L;
	while (~scanf("%I64d%I64d%I64d%I64d%I64d",&x,&y,&m,&n,&L))
	{
		__int64 a,b,c,g,k1,k2,t;
		a = n-m;
		b = L;
		c = x - y;
		g = gcd(a,b);
		if (c % g)
		{
			printf("Impossible\n");
		}
		else
		{
			a /= g;
			b /= g;
			c /= g;
			extgcd(a,b,k1,k2);
			t = -c*k1/b;
			k1 = c*k1+t*b; //ע�� 
			if (k1 < 0)
			{
				k1 += b;
			}
			printf("%I64d\n",k1);
		}
	}
	return 0;
}


/*ע 1����ʱ���̵����н�Ϊ��x=c*k1:+b*t,x����С�Ŀ���ֵ��0��
��x=0�������x��Сʱ��t��ȡֵ��������x=0�ǿ��ܵ���Сȡֵ��
ʵ���Ͽ���x����ȡ����0����ô�ɼ������ȡ��������֪��
�� t=-c*k1/b�����t������x=c*k1+b*t�У������x���ܻ�С��0��
��ʱ��t=t+1�������x�ش���0��������غ�x���Ǵ��ڵ���0�ģ�
��ô����Ҫ����������*/
