#include<bits/stdc++.h>
using namespace std;
const int INF = (1<<30);
const int maxn = 105;
int dp[maxn][maxn];

int main()
{
	//freopen("input.txt","r",stdin);
	int n,T;
	while (~scanf("%d%d",&n,&T))
	{
		int m,s,c,v;
		memset(dp,0,sizeof(dp));
		for (int i = 1;i <= n;i++)
		{
			scanf("%d%d",&m,&s);
			if (s == 0)
			{
				for (int j = 0;j <= T;j++)	dp[i][j] = -INF;
				while (m--)
				{
					scanf("%d%d",&c,&v);
					for (int j = T;j >= c;j--)
					{
						dp[i][j] = max(dp[i][j],max(dp[i-1][j-c] + v,dp[i][j-c] + v));
					}
				}
			}
			else if (s == 1)
			{
				for (int j = 0;j <= T;j++)	dp[i][j] = dp[i-1][j];
				while (m--)
				{
					scanf("%d%d",&c,&v);
					for (int j = T;j >= c;j--)
					{
						dp[i][j] = max(dp[i][j],dp[i-1][j-c] + v);
						//ע������˳���Ǵ���ģ���Ϊ��c = 0ʱ��dp[i][j]�������v 
						//dp[i][j] = max(dp[i][j],dp[i-1][j-c] + v);
                        //dp[i][j] = max(dp[i][j],dp[i][j-c] + v);
					}
				}
			}
			else if (s == 2)
			{
				for (int j = 0;j <= T;j++)	dp[i][j] = dp[i-1][j];
				while (m--)
				{
					scanf("%d%d",&c,&v);
					for (int j = T;j >=c;j--)
					{
						dp[i][j] = max(dp[i][j],dp[i][j-c] + v);
						dp[i][j] = max(dp[i][j],dp[i-1][j-c] + v);
					}
				}
			}
		}
		printf("%d\n",max(dp[n][T],-1));
	}
	return 0;
} 
