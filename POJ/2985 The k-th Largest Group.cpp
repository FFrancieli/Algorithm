#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 200005;
int N,root[maxn],a[maxn],c[maxn];

int find(int x)
{
	if (root[x] != x)	root[x] = find(root[x]);
	return root[x];
} 

int find_kth(int x) //���ҵ�kС��Ԫ�� 
{
	int ans = 0,cnt = 0;
	for (int i = 20;i >= 0;i--)   //�����20�ʵ���ȡֵ����MAX_VAL�йأ�һ��ȡlg(MAX_VAL)
	{
		ans += (1 << i);
		if (ans > N || cnt + c[ans] >= x)
			ans -= (1 << i);
		else
			cnt += c[ans]; 
	}
	return ans + 1;
}

void upd(int i,int v)
{
	while (i <= N)
	{
		c[i] += v;
		i += i & -i; 
	}
}

int main()
{
	int M;
	while (~scanf("%d%d",&N,&M))
	{
		int tot = N;
		memset(c,0,sizeof(c));
		for (int i = 1;i <= N;i++)	root[i] = i,a[i] = 1; //a[i]��ʾ���Ϊi��Group��С 
		upd(1,N);                //��ʼGroup��СΪ1����N�� 
		while (M--)
		{
			int opt,x,y;
			scanf("%d",&opt);
			if (opt == 0)
			{
				scanf("%d%d",&x,&y);
				x = find(x);
				y = find(y);
				if (x == y)	continue;
				upd(a[x],-1);
				upd(a[y],-1);       //x��y�ϲ�������Ϊx��Group����Ϊy��Group��С��1
				upd(a[x] + a[y],1); //��СΪa[x]+a[y]��Group�Ĵ�С��1 
				root[y] = x;        //y�����Ƚڵ�Ϊx��
				a[x] += a[y];       //���Ϊx��Group��С����a[y]
				tot--;              //���鼯�ϲ�������Ԫ�ؼ���1 
			}
			else
			{
				scanf("%d",&x);
				printf("%d\n",find_kth(x)); 
			}
		}
	}
	return 0;
}
