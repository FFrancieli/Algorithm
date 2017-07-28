#include<iostream>
#include<algorithm>
using namespace std;
bool Check(int a[], int n, int m, int x);
int a[500002];
int main()
{
    a[0] = 0; //��ʼλ��
    int l, n, m, left, right, i, mid;
    while (cin >> l >> n >> m)
    {
        for (i = 1; i < n + 1; i++)
            scanf("%d",&a[i]);
        sort(a, a + n+1); //����ľ�������
        a[n+1] = l, //ĩλ��
                 left = a[1]; //��left�����������һ����ʼֵ
        right = l; //�ұ߽�
        n = n + 2; //���ϳ�ʼλ�ú�ĩλ�ã�a��һ����n+2��λ��
        while (left <right)
        {
            mid = (left + right)/2;
            if (!Check(a, n, m, mid)) //�����Ծm�β���ͨ��
                left = mid + 1;
            else
                right = mid; //����midͨ������ômid-1��ȷ���Ƿ�ͨ��
        }/*���ұ߽����ʱ����ѭ��*/
        cout << left << endl;
    }
    return 0;
}
bool Check(int a[], int n, int m, int x)
{
    int i = 0, step = 0, j = 1;
    bool flag;
    while (j<n)
    {
        flag = 1;
        while (j< n&&a[j] - a[i] <= x)
        {
            j++; //̰�ģ������ܶ��ͨ��ʯ��
            flag = 0;
        }
        i = j - 1;
        if (flag) //˵��x��ĳ����ʯ�ʼ���뻹ҪС
            return 0;
        step++;
        if (step>m) //��Ծ���Ĵ�������m��δ����԰�
            return 0;
    }
    return 1;
}
