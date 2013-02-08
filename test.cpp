/*************************************************************
*  文件名：Producer_Consumer.cpp
*  创建日期：2011.11.11
*  作   者：陳德深
*  使用者：软件工程级，操作系统实验用
*  功   能：用P－V操作解决生产者－消费者问题（windows版本）
*  描   述：) 1个生产者，个消费者
*            2) 缓冲区大小：
*            3) 互斥对象：csArray
*                  信号量：hFull
*                  信号量：hEmpty
*
*
**************************************************************/
#include "stdafx.h"
#include "stdio.h"
#include <windows.h>
#define FILE_LOG
#ifdef FILE_LOG
FILE * cfileLog;
#endif

//缓冲区，大小为
int array[5];
//记录生成数据的个数
int pointer;
//记录取得的数据的位置
int pointerget;
//用来保存数据和
int sum;
//临界区对象
CRITICAL_SECTION csArray;
//句柄，保存Full信号量
HANDLE hFull;
//句柄，保存Empty信号量
HANDLE hEmpty;

//生产者函数
DWORD WINAPI Producer(LPVOID lpParam)
{
    int i = 0;
    pointer = 0;
    while( i < 100 )
    {
        WaitForSingleObject(hEmpty,INFINITE);
        EnterCriticalSection( &csArray);
        array[(pointer++)%5] = i + 1;
        printf("new data: %5d\n",i + 1);
#ifdef FILE_LOG
        char DebugString[100];
        int StringLong;
        sprintf(DebugString,"new data: %5d\n",i + 1);
        StringLong = strlen(DebugString);
        fwrite(DebugString,1,StringLong,cfileLog);
#endif
        LeaveCriticalSection( &csArray);
        ReleaseSemaphore(hFull,1,NULL);
        i++;
    }
    return 0;
}

//消费者函数A
DWORD WINAPI ConsumerA(LPVOID lpParam)
{
    while(1)
    {
        WaitForSingleObject(hFull,INFINITE);
        EnterCriticalSection( &csArray);
        sum += array[(pointerget ++ )%5];
        printf("        Consumer A get %5d\n",array[(pointerget -1)%5]);
        if(pointerget == 100)
        {
            printf("The sum is %d",sum);
        }
#ifdef FILE_LOG
        char DebugString[100];
        int StringLong;
        sprintf(DebugString,"Consumer A get %5d\n",array[(pointerget -1)%5]);
        StringLong = strlen(DebugString);
        fwrite(DebugString,1,StringLong,cfileLog);
#endif
        LeaveCriticalSection( &csArray);
        ReleaseSemaphore(hEmpty,1,NULL);
    }
    return 0;
}

//消费者函数B
DWORD WINAPI ConsumerB(LPVOID lpParam)
{
    while(1)
    {
        WaitForSingleObject(hFull,INFINITE);
        EnterCriticalSection( &csArray);
        sum += array[(pointerget ++ )%5];
        printf("Consumer B get %5d \n",array[(pointerget -1 )%5]);
        if(pointerget == 100)
        {
            printf("The sum is %d",sum);
        }
#ifdef FILE_LOG
        char DebugString[100];
        int StringLong;
        sprintf(DebugString,"Consumer B get %5d \n",array[(pointerget -1 )%5]);
        StringLong = strlen(DebugString);
        fwrite(DebugString,1,StringLong,cfileLog);
#endif
        LeaveCriticalSection( &csArray);
        ReleaseSemaphore(hEmpty,1,NULL);
    }
    return 0;
}



int main(int argc, char* argv[])
{
    HANDLE hThreadProducer,hThreadConsumerA,hThreadComsumerB;
    sum = 0;
    pointerget = 0;
#ifdef FILE_LOG
    cfileLog = fopen("生产者_消费者日志.txt","w");
#endif
    InitializeCriticalSection( &csArray);
    hFull  = CreateSemaphore(NULL, 0, 5, NULL);
    hEmpty = CreateSemaphore(NULL, 5, 5, NULL);
    hThreadProducer  = CreateThread(NULL, 0, Producer,  NULL, 0, NULL);
    hThreadConsumerA = CreateThread(NULL, 0, ConsumerA, NULL, 0, NULL);
    hThreadComsumerB = CreateThread(NULL, 0, ConsumerB, NULL, 0, NULL);
    getchar();
    fclose(cfileLog);
    return 0;
}
