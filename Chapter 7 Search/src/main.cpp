#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <process.h>

struct MyStruct
{
    int *pfindstart;//要查找的首地址
    int length;//限定长度，从首地址开始
    int num;//要查找的元素
    int bh;//那个线程找到的
    int *pfind;
};

void find(void *p)
{
    struct MyStruct *pstruct = (struct MyStruct *)p;
    //内存遍历，从地址开始累加100个元素的大小，遍历所有元素
    for (int *px = pstruct->pfindstart; px < pstruct->pfindstart + 100;px++)
    {
        if (*px==pstruct->num)
        {
            printf("线程%d找到：%d,位置：%p\n",pstruct->bh, *px, px);
            return;
        }
    }
    printf("%d线程没有找到\n",pstruct->bh);

}

int main()
{
    int a[1000];//找783
    for (int i = 0; i < 1000;i++)
    {
        a[i] = i;//数组初始化
    }

    for (int i = 0; i < 10;i++)//创建10个线程并行查找
    {
        struct MyStruct threaddata;
        threaddata.pfindstart = a + i * 100;
        threaddata.length = 100;
        threaddata.bh = i;
        threaddata.num =345;
        threaddata.pfind = NULL;
        _beginthread(find, 0, &threaddata);
        Sleep(30);//线程创建要时间，要给一个缓冲时间
    }
    return 0;
}