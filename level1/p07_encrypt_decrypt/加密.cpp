#include<stdio.h>
#define SIZE 6
int main(void)
{
	int index;
	char num[6];
	
	printf("������������ĸ��Ϊ�������ʼ������Դ\n");

	scanf("%s",num);
	for(index=0;index<SIZE;index++)
	num[index]=num[index]+3;	

	printf("�������Ϊ");
    for(index=0;index<SIZE;index++)

	printf("%d",num[index]);
	return 0;
}
