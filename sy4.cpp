#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef int InfoType;

#define n 10					//������ļ����ȣ���������ļ�¼��Ŀ
typedef int KeyType;			//����Ĺؼ�������
typedef struct {				//��¼����
	KeyType key;				//�ؼ�����
	InfoType otherinfo;			//�������������InfoType�����ھ���Ӧ�ö�����
} RecType;
typedef RecType SeqList[n+1];	//SeqListΪ˳������ͣ����е�0����Ԫһ�������ڱ�


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
		printf("\t\t               ���Ա������  \n");
		printf("\t\t======================================");
		printf("\n\n");
		printf("\t\t             1���������Ա�            \n");
		printf("\t\t             2����ʾ���Ա�            \n");
		printf("\t\t             3����������              \n");
		printf("\t\t             4��ð������              \n");
		printf("\t\t             5��ֱ��ѡ������          \n");
		printf("\n");
		printf("\t\t             0���˳�        \n");
		printf("\n");
		printf("\t\t��ѡ��");

		choice = getch();
		system("cls");
		
		switch(choice)
		{
			case '1':				
				printf("���������������(10��)��\n");
	            for (i=1;i<=n;i++)
	             	scanf("%d",&R[i].key);
				printf("���Ա����ɹ���\n");
				getch();
				break;
			case '2':
				printf("���Ա��е�����Ϊ��\n");
				for (i=1;i<=n;i++)
		            printf("%d\n",R[i].key);
				getch();
				break;
			case '3':				
            	InsertSort(R);
				printf("��������ɹ���\n");
				getch();
				break;
			case '4':				
				BubbleSort(R);
				printf("ð������ɹ���\n");
				getch();
				break;
			case '5':				
				SelectSort(R);
				printf("ֱ��ѡ������ɹ���\n");
				getch();
				break;						
			case '0':
				exit(0);
		}
	}
}


//��˳���R�еļ�¼R[1..n]����������в�������
void InsertSort(SeqList R)
{
	int i,j;
      for(i=2;i<=n;i++)
      {
          //����������ǰһ����С����Ҫ����
          if(R[i].key<R[i-1].key)
          {
              //��С���������a[0]λ�ã���Ϊ�ڱ�
              R[0].key=R[i].key;
              //��ǰ�����������������
              for(j=i-1;R[0].key<R[j].key;j--)
              {
                  R[j+1].key=R[j].key;
              }
              R[j+1].key=R[0].key;
          }
      }
	//�˴�д�����
}

//R[1..n]�Ǵ�������ļ����������¶���ɨ���R��ð������
void BubbleSort(SeqList R)
{
	 for (int i = 1; i <= n; i++) {
        //�Դ��������н���ð������
        for (int j = 1; j  <= n - i; j++) {
            //����Ԫ�ؽ��бȽϣ���˳����ȷʱ������λ��
            if (R[j].key > R[j + 1].key) {
                Swap(&R[j].key , &R[j + 1].key);
            }
        }
	//�˴�д�����
}
}

//��R[1..n]����ֱ��ѡ��������R[0]���ݴ浥Ԫ
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
	//�˴�д�����
}
void Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}







