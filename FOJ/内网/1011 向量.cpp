#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		__int64 Ax,Ay,Bx,By,Cx,Cy,Dx,Dy;
		bool flag = false;
		scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&Ax,&Ay,&Bx,&By,&Cx,&Cy);
		if (Cx == 0 && Cy == 0)
		{
			if (Ax == Bx && Ay == By) //��� 
			{
				flag = true;
			}
			else if (Ax == -Bx && Ay == -By) //���� 
			{
				flag = true;
			} 
			else if (Ax*Bx+Ay*By==0&&(Ax*Ax+Bx*Bx)==(Bx*Bx+By*By)) //��ֱ����� 
			{
				flag = true;
			} 
		}
		else
		{
			int cnt = 4;
			while (cnt--) //A�����ĸ�������ת 
			{
				Dx = Bx - Ax;
				Dy = By - Ay;
				if ((Dx*Cx+Dy*Cy)%(Cx*Cx+Cy*Cy)==0)
				{
					flag = true;
					break;
				}
				int tmp = Ay;
				Ay = Ax;
				Ax = -tmp;
			}
		} 
		if (flag)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
} 
