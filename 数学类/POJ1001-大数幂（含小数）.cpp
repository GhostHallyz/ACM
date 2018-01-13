#include <iostream>
using namespace std;

// 计算 多 乘以 一 的情况，例如，1234 * 4
// many:    多位数
// one:        单位数
// offset:    乘10偏移
// return:    返回计算结果

char * MMO(char * many, char one, int offset)
{
    int mLength;    // 多位数的长度
    char * res;        // 计算结果
    int i;
    int n1, n2;        // 逐位相乘的两个乘数
    int sres;        // 逐位相乘的积
    int carry;        // 进位
    // 初始化各变量
    n2 = one - 48;
    carry = 0;
    // 获取多位数的位数
    mLength = -1;
    while(many[++mLength]);
    // 计算运算结果的位数并分配空间
    res = new char[mLength + 1 + offset + 1];
    // 初始化结果为0
    for(i=0; i < mLength + offset + 1; i++)
    {
        res[i] = '0';
    }
    res[mLength + offset + 1] = 0;    // 字符串结尾
    // 逐位相乘
    for(i = mLength - 1; i >= 0; i--)
    {
        n1 = many[i] - 48;    
        sres = n1 * n2; // 1. 将两个乘数相乘
        sres += carry; // 2. 将结果再加上进位
        res[i + 1] = sres % 10 + 48;    // 3. 将计算得到的结果分成10进位和个位，直接存在计算结果中
        carry = sres / 10;        // 十位，保存在进位中
    }   
    res[0] = carry + 48; // 将进位存入最高位
    return res; // 返回计算结果
}

// 计算两个多位数相加，将结果存入m1，并释放m2
// m1:        多位数1
// m2:        多位数2
// 需要注意的是，多位数1的位数一定要大于等于两数和的位数

void MPM(char * m1, char * m2)
{
    int l1, l2;        // 两个多位数的长度
    char * res;        // 计算结果
    int i;
    int lRes;        // 结算结果的长度
    int carry;        // 进位
    int n1, n2;        // 两个单位加数位
    carry = 0; // 初始化变量
    l1 = l2 = -1;
    while(m1[++l1]);// 获取两个加数的长度
    while(m2[++l2]);
    for (i=1; i <= l1; i++)// 实现两数相加
    {
        n1 = m1[l1 - i] - 48;
        if(l2 - i < 0)
            n2 = 0;
        else
            n2 = m2[l2 - i] - 48;
        m1[l1 - i] = (n1 + n2 + carry) % 10 + 48;// 计算两数和并存入m1中
        carry = (n1 + n2 + carry) / 10;
    }  
    if(l1 != l2)// 将进位存入首位
        m1[l1 - l2 - 1] = carry + 48;
    delete m2;// 释放被加数
}

// 计算两个多位数相乘
// m1:        乘数1
// m2:        乘数2
// return:    返回两数相乘结果

char * MMM(char * m1, char * m2)
{
    int l1, l2;        // 两个多位数的长度
    char * res;        // 计算结果
    int i;
    int lRes;        // 结算结果的长度
    int carry;        // 进位
    int n1, n2;        // 两个单位乘数位  
    carry = 0; // 初始化变量
    l1 = l2 = 0;
    while(m1[l1++]);// 获取两个加数的长度
    while(m2[l2++]);
    l1--;  l2--;
    if(l1 < l2)// 为了减少计算乘法次数，将位数较少的数作为乘数
    {
        char * tp = m2;
        m2 = m1;
        m1 = tp;
        int tpl = l2;
        l2 = l1;
        l1 = tpl;
    }
    // 为计算结果分配空间
    // 两数相乘的结果的位数 = 被乘数的位数 + 乘数的位数
    lRes = l2 + l1;
    res = new char[lRes + 1];
    for (i=0; i < lRes; i++)// 初始化结果为0
    {
        res[i] = '0';
    }
    res[lRes] = 0;
    for(i=1; i <= l2; i++)// 进行逐位相乘
    {
        char * sr = MMO(m1, m2[l2 - i], i-1);
        MPM(res, sr);
    }
    return res;
}

// 计算 R 的 N 次方，R和N均为整数
// return: 返回未修饰的计算结果

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

// 规范化输出计算结果，加上小数点，并去掉多余的0
void OutputRes(char * res, int pNum)
{
    int lRes;
    int i;
    bool flag;
    lRes = -1;
    while(res[++lRes]);// 获取输出字符串的长度
    // 计算输出区间
    flag = false;
    if(pNum > 0)
    {
        // 过滤首尾不用输出的0
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
        if(i > pNum)        // 小数部位不用输出
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
    // 输出结果
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
    char R[10], Rin[10];        // 读入的乘幂运算的底
    int N;            // 读入的乘幂运算的指数
    int pNum;        // 读入的小数位数
    // 读入并计算
    while(cin>>Rin>>N)
    {
        // 获得小数点的位数，并获取去掉小数点后的整数
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
        // 计算并输出结
        char * s = RN(R, N);
        OutputRes(s, pNum);
        if(s != R)
            delete s;
    }
    return 0;
}
