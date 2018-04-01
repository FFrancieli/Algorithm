#include<iostream>
#include<string>
#include<cstdio>
#include<map>
using namespace std;

int main()
{
	string NameOfCadite,NameOfParty,ballot,winner;
	int N,M;

	while(scanf("%d",&N) != EOF)
	{
		map<string,string>cadite1;
		map<string,int>cadite2;
		map<string,string>::iterator it;
		int max = 0,flag = 0;

		cin.get();

		while (N--)
		{
			getline(cin,NameOfCadite);
			getline(cin,NameOfParty);

			cadite1[NameOfCadite] = NameOfParty;   //������ѡ�˼������ڵ��ɵĹ�������
		}

		cin >> M;
		cin.get();   //������� 

		while (M--)
		{
			getline(cin,ballot);
			it = cadite1.find(ballot);     //�����Ƿ��м�ֵΪ'ballot'��Ԫ�� 
			if (it == cadite1.end())       //û�ҵ������� 
			{
				continue;
			}
			else
			{
				cadite2[ballot]++;
				int tmp = cadite2[ballot];
				if (tmp > max)            //ѡ��Ʊ�����ľ�ѡ�� 
				{
					flag = 1;            //�����Ʊ������� 
					winner = ballot;     //��¼Ʊ�����ľ�ѡ�����֣�ͨ�������֡��ؼ����ҳ����ڵ���
					max = tmp;          //�������ֵ
				}
				else if (tmp == max)
				{
					flag = 0;         //����Ʊ������������ͬ�����
				}
			}
		}

		if (flag)
		{
			if (cadite1[winner] == "independent")
			{
				cout << "independent" << endl;
			}
			else
			{
				cout << cadite1[winner] << endl;
			}
		}
		else
		{
			cout << "tie" << endl;
		}
	}
	return 0;
}
