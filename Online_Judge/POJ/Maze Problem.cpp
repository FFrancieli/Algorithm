#include<iostream>
#include<utility>
#include<queue>
#include<cstdio>
#define MAX_N 105
#define MAX_M 105
using namespace std;
const int INF = 100000000;
typedef pair<int, int>P;
char maze[MAX_N][MAX_M+1]; //��ʾ�Թ����ַ������� 
int N,M;

 
int bfs(int sx,int sy,int gx,int gy)
{
	int d[MAX_N][MAX_M]; //������λ����̾�������� 
	int dx[4] = {1,0,-1,0}, dy[4] = { 0,1,0,-1}; //4�������ƶ����� 
	queue<P>que;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			d[i][j] = INF; //����λ�ó�ʼ��ΪINF 
		}
	}
	
	que.push(P(sx,sy));
	d[sx][sy] = 0;  //���ѹ����У���������������Ϊ0 
	
	while (que.size())
	{
		P p = que.front();
		que.pop();
		
		if (p.first == gx && p.second == gy)
		{
			break; //ȡ����״̬Ϊ�յ㣬�������� 
		}
		
		for (int i = 0; i < 4;i++) //�ĸ�����ѭ�� 
		{
			int nx = p.first + dx[i],ny = p.second + dy[i];
			
			if (0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' && d[nx][ny] == INF)
			{
				que.push(P(nx,ny));  //�����ƶ��������У������¸�λ�þ��� 
				d[nx][ny] = d[p.first][p.second] + 1;
			}
		}
	}
	return d[gx][gy];
}


int main()
{
	int i,j,res;
	int sx,sy;  //�������
    int gx,gy;  //�յ�����
	scanf("%d%d",&N,&M);
	for (i=0;i<N;i++)
	{
		scanf("%s",maze[i]); 
	}
	for (i=0;i<N;i++)
	{
		for (j=0;j < M;j++)
		{
			if (maze[i][j] == 'S') 
			{
				sx = i;
				sy = j;
			}
			if (maze[i][j] == 'G')
			{
				gx = i;
				gy = j;
			}
		} 
	}
	res = bfs(sx,sy,gx,gy);
	printf("%d\n",res);
	return 0;
} 
