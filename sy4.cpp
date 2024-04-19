#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef int InfoType;

#define n 10					//假设的文件长度，即待排序的记录数目
typedef int KeyType;			//假设的关键字类型
typedef struct {				//记录类型
	KeyType key;				//关键字项
	InfoType otherinfo;			//其它数据项，类型InfoType依赖于具体应用而定义
} RecType;
typedef RecType SeqList[n+1];	//SeqList为顺序表类型，表中第0个单元一般用作哨兵


void InsertSort(SeqList R);  
void BubbleSort(SeqList R);
void SelectSort(SeqList R);
int Partition(SeqList R,int i,int j);
void QuickSort(SeqList R,int low,int high);
void Swap(int* a, int* b);

int main()
{
	void InsertSort(SeqList R);
	int i;
	SeqList R;

	char choice;
	while (1)
	{
		system("cls");
		printf("\n\n\n\n");
		printf("\t\t               线性表的排序  \n");
		printf("\t\t======================================");
		printf("\n\n");
		printf("\t\t             1：建立线性表            \n");
		printf("\t\t             2：显示线性表            \n");
		printf("\t\t             3：插入排序              \n");
		printf("\t\t             4：冒泡排序              \n");
		printf("\t\t             5：直接选择排序          \n");
		printf("\n");
		printf("\t\t             0：退出        \n");
		printf("\n");
		printf("\t\t请选择：");

		choice = getch();
		system("cls");
		
		switch(choice)
		{
			case '1':				
				printf("请输入欲排序的数(10个)：\n");
	            for (i=1;i<=n;i++)
	             	scanf("%d",&R[i].key);
				printf("线性表创建成功！\n");
				getch();
				break;
			case '2':
				printf("线性表中的数据为：\n");
				for (i=1;i<=n;i++)
		            printf("%d\n",R[i].key);
				getch();
				break;
			case '3':				
            	InsertSort(R);
				printf("插入排序成功！\n");
				getch();
				break;
			case '4':				
				BubbleSort(R);
				printf("冒泡排序成功！\n");
				getch();
				break;
			case '5':				
				SelectSort(R);
				printf("直接选择排序成功！\n");
				getch();
				break;						
			case '0':
				exit(0);
		}
	}
}


//对顺序表R中的记录R[1..n]按递增序进行插入排序
void InsertSort(SeqList R)
{
	int i,j;
      for(i=2;i<=n;i++)
      {
          //如果这个数比前一个数小，就要交换
          if(R[i].key<R[i-1].key)
          {
              //把小的数存放再a[0]位置，作为哨兵
              R[0].key=R[i].key;
              //将前面比这个数大的数后移
              for(j=i-1;R[0].key<R[j].key;j--)
              {
                  R[j+1].key=R[j].key;
              }
              R[j+1].key=R[0].key;
          }
      }
	//此处写入代码
}

//R[1..n]是待排序的文件，采用自下而上扫描对R做冒泡排序
void BubbleSort(SeqList R)
{
	 for (int i = 1; i <= n; i++) {
        //对待排序序列进行冒泡排序
        for (int j = 1; j  <= n - i; j++) {
            //相邻元素进行比较，当顺序不正确时，交换位置
            if (R[j].key > R[j + 1].key) {
                Swap(&R[j].key , &R[j + 1].key);
            }
        }
	//此处写入代码
}
}

//对R[1..n]进行直接选择排序，用R[0]做暂存单元
void SelectSort(SeqList R)
{
	int i = 1;
    for (i = 1; i < n; i++)
    {
        int min = i;
        int j = 1;
        for (j = i+1; j <= n; j++)
        {
            if (R[j].key< R[min].key)
            {
                min = j;
            }
        }
        Swap(&R[i].key, &R[min].key);
    }
	//此处写入代码
}
void Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}







