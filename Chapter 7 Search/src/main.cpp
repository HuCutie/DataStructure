#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <process.h>

struct MyStruct
{
    int *pfindstart;//Ҫ���ҵ��׵�ַ
    int length;//�޶����ȣ����׵�ַ��ʼ
    int num;//Ҫ���ҵ�Ԫ��
    int bh;//�Ǹ��߳��ҵ���
    int *pfind;
};

void find(void *p)
{
    struct MyStruct *pstruct = (struct MyStruct *)p;
    //�ڴ�������ӵ�ַ��ʼ�ۼ�100��Ԫ�صĴ�С����������Ԫ��
    for (int *px = pstruct->pfindstart; px < pstruct->pfindstart + 100;px++)
    {
        if (*px==pstruct->num)
        {
            printf("�߳�%d�ҵ���%d,λ�ã�%p\n",pstruct->bh, *px, px);
            return;
        }
    }
    printf("%d�߳�û���ҵ�\n",pstruct->bh);

}

int main()
{
    int a[1000];//��783
    for (int i = 0; i < 1000;i++)
    {
        a[i] = i;//�����ʼ��
    }

    for (int i = 0; i < 10;i++)//����10���̲߳��в���
    {
        struct MyStruct threaddata;
        threaddata.pfindstart = a + i * 100;
        threaddata.length = 100;
        threaddata.bh = i;
        threaddata.num =345;
        threaddata.pfind = NULL;
        _beginthread(find, 0, &threaddata);
        Sleep(30);//�̴߳���Ҫʱ�䣬Ҫ��һ������ʱ��
    }
    return 0;
}