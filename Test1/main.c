#include <stdio.h>
#include <stdlib.h>
 
 void findMaxAndCount(int *max, int *count, const int *array, const int length)
 {
 	int i;
 	*max = array[0];
 	*count = 0;
	for(i = 0; i < length; i++)
	{
		if (array[i] > *max)
		{
			*max = array[i];
			*count = 1;
		}
		else if (array[i] == *max)
		{
			(*count)++;
		}
	}	 	
 }

 
/*******************************************/
int Time[] = {23, 59, 59};

int *GetTime(void)
{
//	int Time[] = {23, 59, 59};		// ��Ҫ���ؾֲ��������������˳��󽫱����٣��ٷ��ʾͻ��ɷǷ������� 
	return Time;
}
/*******************************************/



/*******************************************/
unsigned char AirData[4];

void SendData(const unsigned char *data, const char length)
{
	int i;
	for(i = 0; i < length; i++)
	{
		AirData[i] = data[i];
	}
}

void ReceiveData(unsigned char *data, const char length)
{
	int i;
	for(i = 0; i < length; i++)
	{
		data[i] = AirData[i];
	}	
}
/*******************************************/


int main(int argc, char** argv) {
	
	// 1���������ͺ�ָ����������͵�ָ��
	int a1;
	int *p1;
	printf("%d\n", sizeof(a1));			// 4
	printf("%d\n", sizeof(p1)); 		// 8��64λϵͳ���̶�Ϊ8�ֽڣ� 
	printf("\n");
	
	
	// 2��ָ�����
	int a2 = 0x55;
	int *p2 = &a2;						// ������a2���׵�ַ��ֵ��p2 
	printf("%x\n", a2);					// 55 
	printf("%x\n", p2);					// 62fe14
	printf("%x\n", *p2); 				// 55
	p2++;
	printf("%x\n", p2);					// 62fe18
	p2--;
	printf("%x\n", p2);					// 62fe14
	printf("\n");
	
	
	// 3��������ָ��
	char c[] = {0x33, 0x34, 0x45};
	printf("c[0]=%x\n", c[0]);
	printf("c[1]=%x\n", c[1]);
	printf("c[2]=%x\n", c[2]);
	printf("*c=%x\n", *c);
	printf("*(c+1)=%x\n", *(c+1));
	printf("*(c+2)=%x\n", *(c+2));	
	printf("\n");
	// ��Ч������� 
	// �ٶ���ָ�� 
	int *c2;
	// �ڷ����ڴ� 
	c2 = malloc(3 * 4);				// malloc��memory allocation, �ڴ���䣩
	// �۳�ʼ���������� 
	*c2 = 0x33;
	*(c2+1) = 0x34;
	*(c2+2) = 0x35; 
	printf("c2[0]=%x\n", c2[0]);
	printf("c2[1]=%x\n", c2[1]);
	printf("c2[2]=%x\n", c2[2]);	
	printf("\n");
	
	
	// 4�����ݲ���
	int array[] = {45, 56, 56, 67, 23, 23, 17, 67};
	int Max;
	int Count;
	findMaxAndCount(&Max, &Count, array, 8);
	printf("max=%d\n", Max);
	printf("count=%d\n", Count);
	printf("\n");
	
	char str1[20];
	char str2[] = "Hello World!\n";
	strcpy(str1, str2);
	printf(str1);
	printf(str2);
	printf("\n");
	
	
	// 5�� ���ݷ���ֵ
	int *pt;
	pt = GetTime();
	printf("pt[0]=%d\n", pt[0]);
	printf("pt[1]=%d\n", pt[1]);
	printf("pt[2]=%d\n", pt[2]);
	printf("\n");
	
	/***********************/
	FILE *f = fopen("D:\\test.txt", "w");
	fputc('A', f);
	fputs("HelloWrold!", f);
	fclose(f);
	
	char content1;
	char content2[10];
	FILE *f2 = fopen("D:\\test.txt", "r");
	content1 = fgetc(f2);
	fgets(content2, 15, f2);
	fclose(f2);
	printf("%c\n", content1);
	printf(content2);
	printf("\n");
	printf("\n");
	/***********************/


	// 6�����Ӹ�ʽ
	int i;
	float num = 123.456;
	unsigned char *pNum = (unsigned char *)&num;
	SendData(pNum, 4);
	for (i = 0; i < 4; i++)
	{
		printf("%x ", AirData[i]);	
	}
	printf("\n");
	
	unsigned char DataReceive[4];
	ReceiveData(DataReceive, 4);
	float *pf = (float *)DataReceive;
	printf("%f\n", *pf); 

	
	return 0;
}
