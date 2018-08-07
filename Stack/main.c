#include <stdio.h>
#include <stdlib.h>
#define initSize 20
//ռ�ռ��ʼ��С

//#define maxsize 100
//typedef int SElemType;
//typedef struct
//{
//    SElemType elem[maxsize];
//    int top;
//}SeqStack;
typedef int SElemType;
typedef struct
{
    SElemType *elem;
    int maxSize;
    int top;
}SeqStack;
void InitStack(SeqStack S)
//����һ�����ߴ�ΪinitSize�Ŀ�ջ�������䲻�ɹ�����д�����
{
    S.elem=(SElemType*)malloc(initSize*sizeof(SElemType));
//    ����ջ�ռ�
    if(S.elem==NULL)
    {
        printf("�洢����ʧ�ܣ�\n");
        exit(1);
    }
    S.maxSize=initSize;
    S.top=-1;
}
int Push(SeqStack S,SElemType x)
//��ջ��������ջ��������Ԫ��x����ջ������������1������ջ�������������0��
{
    if(S.top==S.maxSize-1)
    {
        return 0;
    }
    S.elem[++S.top]=x;
    return 1;
}
int Pop(SeqStack S,SElemType x)
//��ջ����ջ��������ͨ�����ò���x����ջ��Ԫ��ֵ��ջ��ָ����1����������1������������0����x��ֵ�������á�
{
    if(S.top==-1)
    {
        return 0;
    }
    x=S.elem[S.top--];
    return 1;
}
int Gettop(SeqStack S,SElemType x)
//��ȡջ��Ԫ�ص�ֵ����ջ������������ջ��Ԫ�ص�ֵ�Һ�������1������������0
{
    if(S.top==-1)
    {
        return 0;
    }
    x=S.elem[S.top];
    return 1;
}
int StackEmpty(SeqStack S)
//��������ջS�Ƿ�Ϊ�ա���ջ������������1������������0
{
    return S.top==-1;
}
int StackFull(SeqStack S)
//��������ջS�Ƿ�Ϊ������ջ������������1������������0
{
    return S.top==S.maxSize;
}
int StackSize(SeqStack S)
//��������ջS�ĳ��ȣ���ջS��Ԫ�ظ���
{
    return S.top+1;
}
void Reverse(int a[],int n)
//������a������Ԫ������
{
    SeqStack S;
    InitStack(S);
    int i;
    for(i=1;i<=n;i++)
    {
        Push(S,a[i-1]);
    }
    i=0;
    while(!StackEmpty(S))
    {
        Pop(S,a[i++]);
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
