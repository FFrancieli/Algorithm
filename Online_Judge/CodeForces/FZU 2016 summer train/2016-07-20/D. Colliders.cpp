#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
#define maxn 100005
bool is_prime[maxn]; //�ж��������
bool visit[maxn];    //ɸѡ���ʱ��
int prime[maxn];     //��������
bool active[maxn];   //������
int tool[maxn][20];  //��¼һ����������������
int count[maxn];     //���������Ӧ�ļ���Ź���

void select_prime () //ɸѡ����
{
	is_prime[0] = 0;
    is_prime[1] = 0;
    int cnt = 0;
    /*int x = sqrt(maxn);
    for (int i = 2;i <= x;i++)
    {
    	if (is_prime[i])
    	{
    		prime[cnt++] = i;
    		for (int j = i*i;j<=maxn;j+=i)
    		{
    			is_prime[j] = 0;
    		}
    	}
    }*/
    
    for ( int i = 2 ; i < maxn ; i ++ )
        if ( !visit[i] )
        {
            visit[i] = 1;
            if ( is_prime[i] )
            {
                prime[cnt++] = i;
                for ( int j = 2 * i ; j < maxn ; j += i )
                {
                    visit[j] = 1;
                    is_prime[j] = 0;
                }
            }
        }
}

void div_prime ( int n )  //���������
{
    int ths = 1; //����0���±�������Ӹ���
    for ( int i = 0 ; prime[i] <= n / 2 ; i ++ )
    {
		if ( n % prime[i] == 0 ) //ÿ�ҵ�һ�������ʹ�����
            tool[n][ths++] = prime[i];
    }
    if ( is_prime[n] ) tool[n][ths++] = n;
    tool[n][0] = ths - 1;  //����0���±�������Ӹ���
}

void Active ( int num )  //�������
{
    if ( active[num] ) printf ( "Already on\n" );
    else
    {
        for ( int i = 1 ; i <= tool[num][0] ; i ++ ) //Ѱ�ҳ�ͻ���Լ��������ӳ������Ѿ������
        {                       		     //��������������
			if ( count[tool[num][i]] != 0 ) 
            {
                printf ( "Conflict with %d\n" , count[tool[num][i]] );
                return ;
            }
        }
        active[num] = 1;
        for ( int i = 1 ; i <= tool[num][0] ; i ++ )
        {
        	count[tool[num][i]] = num;
        	//cout << tool[num][i] << " " << count[tool[num][i]] << endl;
        }
            
        printf ( "Success\n" );
    }
}

void Deactive ( int num )  //�رռ������
{
    if ( !active[num] ) printf ( "Already off\n" );
    else
    {
        active[num] = 0;
        for ( int i = 1 ; i <= tool[num][0] ; i ++ )
        {
        	count[tool[num][i]] = 0;
			//cout << tool[num][i] << " " << count[tool[num][i]] << endl;
        }
        printf ( "Success\n" );
    }
}

int main()
{
    int n,m,pos;
    char tmp;
    memset ( active , 0 , sizeof ( active ) );
    memset ( is_prime , 1 , sizeof ( is_prime )) ;  
    memset ( visit , 0 , sizeof ( visit ) );
    memset ( prime , 0 , sizeof ( prime ) );
    memset ( count , 0 , sizeof ( count ) );
    select_prime();
    scanf ( "%d %d" , &n , &m );
        for ( int i = 1 ; i <= n ; i ++ )
            div_prime ( i );
        /*for ( int i = 1 ; i <= n ; i ++ )
        {
            cout << i <<"����������" << tool[i][0] << "��: ";
            for ( int j = 1 ; j <= tool[i][0] ; j ++ ) 
                cout << tool[i][j] <<  ' ';
            cout << endl;
        }*/
        while ( m-- )
        {
            getchar();
			scanf("%c %d",&tmp,&pos);
			if (tmp == '+')
			{
				Active(pos);
			}
			else if (tmp == '-')
			{
				Deactive(pos);
			}
        }
    return 0;
}
