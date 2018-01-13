#include <iostream>
using namespace std;

// ���� �� ���� һ ����������磬1234 * 4
// many:    ��λ��
// one:        ��λ��
// offset:    ��10ƫ��
// return:    ���ؼ�����

char * MMO(char * many, char one, int offset)
{
    int mLength;    // ��λ���ĳ���
    char * res;        // ������
    int i;
    int n1, n2;        // ��λ��˵���������
    int sres;        // ��λ��˵Ļ�
    int carry;        // ��λ
    // ��ʼ��������
    n2 = one - 48;
    carry = 0;
    // ��ȡ��λ����λ��
    mLength = -1;
    while(many[++mLength]);
    // ������������λ��������ռ�
    res = new char[mLength + 1 + offset + 1];
    // ��ʼ�����Ϊ0
    for(i=0; i < mLength + offset + 1; i++)
    {
        res[i] = '0';
    }
    res[mLength + offset + 1] = 0;    // �ַ�����β
    // ��λ���
    for(i = mLength - 1; i >= 0; i--)
    {
        n1 = many[i] - 48;    
        sres = n1 * n2; // 1. �������������
        sres += carry; // 2. ������ټ��Ͻ�λ
        res[i + 1] = sres % 10 + 48;    // 3. ������õ��Ľ���ֳ�10��λ�͸�λ��ֱ�Ӵ��ڼ�������
        carry = sres / 10;        // ʮλ�������ڽ�λ��
    }   
    res[0] = carry + 48; // ����λ�������λ
    return res; // ���ؼ�����
}

// ����������λ����ӣ����������m1�����ͷ�m2
// m1:        ��λ��1
// m2:        ��λ��2
// ��Ҫע����ǣ���λ��1��λ��һ��Ҫ���ڵ��������͵�λ��

void MPM(char * m1, char * m2)
{
    int l1, l2;        // ������λ���ĳ���
    char * res;        // ������
    int i;
    int lRes;        // �������ĳ���
    int carry;        // ��λ
    int n1, n2;        // ������λ����λ
    carry = 0; // ��ʼ������
    l1 = l2 = -1;
    while(m1[++l1]);// ��ȡ���������ĳ���
    while(m2[++l2]);
    for (i=1; i <= l1; i++)// ʵ���������
    {
        n1 = m1[l1 - i] - 48;
        if(l2 - i < 0)
            n2 = 0;
        else
            n2 = m2[l2 - i] - 48;
        m1[l1 - i] = (n1 + n2 + carry) % 10 + 48;// ���������Ͳ�����m1��
        carry = (n1 + n2 + carry) / 10;
    }  
    if(l1 != l2)// ����λ������λ
        m1[l1 - l2 - 1] = carry + 48;
    delete m2;// �ͷű�����
}

// ����������λ�����
// m1:        ����1
// m2:        ����2
// return:    ����������˽��

char * MMM(char * m1, char * m2)
{
    int l1, l2;        // ������λ���ĳ���
    char * res;        // ������
    int i;
    int lRes;        // �������ĳ���
    int carry;        // ��λ
    int n1, n2;        // ������λ����λ  
    carry = 0; // ��ʼ������
    l1 = l2 = 0;
    while(m1[l1++]);// ��ȡ���������ĳ���
    while(m2[l2++]);
    l1--;  l2--;
    if(l1 < l2)// Ϊ�˼��ټ���˷���������λ�����ٵ�����Ϊ����
    {
        char * tp = m2;
        m2 = m1;
        m1 = tp;
        int tpl = l2;
        l2 = l1;
        l1 = tpl;
    }
    // Ϊ����������ռ�
    // ������˵Ľ����λ�� = ��������λ�� + ������λ��
    lRes = l2 + l1;
    res = new char[lRes + 1];
    for (i=0; i < lRes; i++)// ��ʼ�����Ϊ0
    {
        res[i] = '0';
    }
    res[lRes] = 0;
    for(i=1; i <= l2; i++)// ������λ���
    {
        char * sr = MMO(m1, m2[l2 - i], i-1);
        MPM(res, sr);
    }
    return res;
}

// ���� R �� N �η���R��N��Ϊ����
// return: ����δ���εļ�����

char * RN(char * R, int N)
{
    if(N < 2)
        return R;
    char * res = MMM(R, R);
    for(int i=0; i < N-2; i++)
    {
        char * res2 = res;
        res = MMM(res, R);
        delete res2;
    }
    return res;
}

// �淶�����������������С���㣬��ȥ�������0
void OutputRes(char * res, int pNum)
{
    int lRes;
    int i;
    bool flag;
    lRes = -1;
    while(res[++lRes]);// ��ȡ����ַ����ĳ���
    // �����������
    flag = false;
    if(pNum > 0)
    {
        // ������β���������0
        for (i=0; i < lRes - pNum; i++)
        {
            if(res[i] != '0')
                break;
            else
                res[i] = '#';
        }
        for(i=1; i <= pNum; i++)
        {
            if(res[lRes - i] != '0')
                break;
            else
                res[lRes - i] = '#';
        }
        if(i > pNum)        // С����λ�������
            flag = true;
    }
	else
	{
        flag = true;
        for (i=0; i < lRes; i++)
        {
            if(res[i] != '0')
                break;
            else
                res[i] = '#';
        }
        for (i=1; i <= lRes; i++)
        {
            if(res[lRes - i] != '0')
                break;
            else
                res[lRes - i] = '#';
        }
    }
    // ������
    for(i=0; i < lRes; i++)
    {
        if((i == lRes - pNum) && (!flag))
            cout<<".";
        if(res[i] != '#')
        {
            cout<<res[i];
        }
    }
    cout<<endl;
}

int main()
{
    char R[10], Rin[10];        // ����ĳ�������ĵ�
    int N;            // ����ĳ��������ָ��
    int pNum;        // �����С��λ��
    // ���벢����
    while(cin>>Rin>>N)
    {
        // ���С�����λ��������ȡȥ��С����������
        int l;
        int ll;
        l = ll = 0;
        pNum = -1;
        while(Rin[l])
        {
            if(Rin[l] == '.')
            {
                pNum = l + 1;
            }
			else
			{
                R[ll++] = Rin[l];
            }
            l++;
        }
        R[ll] = 0;
        if(pNum != -1)
            pNum = l - pNum;
        else
            pNum = 0;
        pNum = pNum * N;
        // ���㲢�����
        char * s = RN(R, N);
        OutputRes(s, pNum);
        if(s != R)
            delete s;
    }
    return 0;
}
