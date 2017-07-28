#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char people[3][3]= {'.','O','.','/','|','\\','(','.',')'}; //�����˵�����
char mp[105][105];
bool vis[105][105];
int n,m;
int judge(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m||vis[x][y])return 0;
    return 1;
}
void search_p(int i,int j)
{
    vis[i][j]=1;
    if(mp[i][j]=='O') //������ʵ���һ��û�з��ʹ���ͷ���͸������λ�÷��ʸ��˵�����λ�á�
    {
        if(judge(i+1,j-1)&&mp[i+1][j-1]=='/')vis[i+1][j-1]=1;
        if(judge(i+1,j)&&mp[i+1][j]=='|')vis[i+1][j]=1;
        if(judge(i+1,j+1)&&mp[i+1][j+1]=='\\')vis[i+1][j+1]=1;
        if(judge(i+2,j-1)&&mp[i+2][j-1]=='(')vis[i+2][j-1]=1;
        if(judge(i+2,j+1)&&mp[i+2][j+1]==')')vis[i+2][j+1]=1;
    }
    if(mp[i][j]=='/')
    {
        if(judge(i,j+1)&&mp[i][j+1]=='|')vis[i][j+1]=1;
        if(judge(i,j+2)&&mp[i][j+2]=='\\')vis[i][j+2]=1;
        if(judge(i-1,j+1)&&mp[i-1][j+1]=='O')vis[i-1][j+1]=1;
        if(judge(i+1,j)&&mp[i+1][j]=='(')vis[i+1][j]=1;
        if(judge(i+1,j+2)&&mp[i+1][j+2]==')')vis[i+1][j+2]=1;
    }
    if(mp[i][j]=='|')
    {
        if(judge(i-1,j)&&mp[i-1][j]=='O')vis[i-1][j]=1;
        if(judge(i,j+1)&&mp[i][j+1]=='\\')vis[i][j+1]=1;
        if(judge(i,j-1)&&mp[i][j-1]=='/')vis[i][j-1]=1;
        if(judge(i+1,j-1)&&mp[i+1][j-1]=='(')vis[i+1][j-1]=1;
        if(judge(i+1,j+1)&&mp[i+1][j+1]==')')vis[i+1][j+1]=1;
    }
    if(mp[i][j]=='\\')
    {
        if(judge(i,j-1)&&mp[i][j-1]=='|')vis[i][j-1]=1;
        if(judge(i,j-2)&&mp[i][j-2]=='/')vis[i][j-2]=1;
        if(judge(i-1,j-1)&&mp[i-1][j-1]=='O')vis[i-1][j-1]=1;
        if(judge(i+1,j)&&mp[i+1][j]==')')vis[i+1][j]=1;
        if(judge(i+1,j-2)&&mp[i+1][j-2]=='(')vis[i+1][j-2] =1;
    }
    if(mp[i][j]=='(')
    {
        if(judge(i-1,j+1)&&mp[i-1][j+1]=='|')vis[i-1][j+1]=1;
        if(judge(i,j+2)&&mp[i][j+2]==')')vis[i][j+2]=1;
        if(judge(i-1,j)&&mp[i-1][j]=='/')vis[i-1][j]=1;
        if(judge(i-1,j+2)&&mp[i+1][j]=='\\')vis[i-1][j+2]=1;
        if(judge(i-2,j+1)&&mp[i-2][j+1]==')')vis[i-2][j+1]=1;
    }
    if(mp[i][j]==')')
    {
        if(judge(i-1,j-1)&&mp[i-1][j+1]=='|')vis[i-1][j-1]=1;
        if(judge(i,j-2)&&mp[i][j+2]=='(')vis[i][j-2]=1;
        if(judge(i-1,j)&&mp[i-1][j]=='\\')vis[i-1][j]=1;
        if(judge(i-1,j-2)&&mp[i+1][j]=='/')vis[i-1][j-2]=1;
        if(judge(i-2,j-1)&&mp[i-2][j-1]==')')vis[i-2][j-1]=1;
    }
}
int main()
{
    int cases,i,j,cnt;
    cin>>cases;
    while(cases--)
    {
        memset(vis,0,sizeof(vis));
        cnt=0;
        cin>>n>>m;
        for(i=0; i<n; i++)
            scanf("%s",mp[i]);
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(!vis[i][j]&&mp[i][j]!='.') //����ҵ�һ��û�з��ʹ����˵����岿λ����������1
                {
                    cnt++;
                    search_p(i,j);//Ѱ�Ҹ�������������λ���ұ�ǳ���
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}

