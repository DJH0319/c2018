#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#define n 10

char variety[100];
int num[100];

void menu(void);

typedef struct information {
	char type;             //�ͺ�
	int number;            //���
	int amount;            //����
	struct information *next;
} information,*INFORM;

INFORM p;

INFORM list(INFORM p) {
	INFORM q;
	INFORM head;
	head=p=(INFORM)malloc(sizeof(information));      //Ϊͷ��������ڴ�
	for(int i=0; i<n; i++) {
		q=(INFORM)malloc(sizeof(information));
		p->next=q;
		p->number=i+1;
		p->amount=num[i];
		p->type=variety[i];
		p=p->next;
	}
	p->next=NULL;
	return head;
}

void input(INFORM p) {                        //�������
	char a=' ';
	FILE *fp=fopen("information.txt","r");     //���ⲿ�ļ�
	int b,c;
	b=1;
	INFORM element=list(p);
	while(b!=0) {
		printf("��������������ı�ż�����������0 0ֹͣ���룩");
		scanf("%d %d",&b,&c);
		if(b==0&&c==0) {
			system("cls");
			fp=fopen("information.txt","w");
			for(int i=0; i<n; i++) {
				fprintf(fp,"%d%c%c",num[i],variety[i],a);
			}
			fclose(fp);
			menu();

		}
		if(element->number==b) {
			element->amount=element->amount+c;      //��amount��c��λ�ò������
			num[b-1]=num[b-1]+c;
			printf("���ɹ���ʣ����%d\n",element->number);
			printf("�����������\n");
			getch();
			system("cls");
			continue;
		} else if(element->number!=b) {
			element=element->next;
			while(element!=NULL) {
				if(element->number==b) {
					element->amount=element->amount+c;
					num[b-1]=num[b-1]+c;    //��amount��c��λ�ò������
					printf("���ɹ���ʣ����%d\n",element->number);
					printf("�����������\n");
					getch();
					system("cls");
					break;
				}
			}
		}
		fp=fopen("information.txt","w");
		for(int i=0; i<n; i++) {
			fprintf(fp,"%d%c%c",num[i],variety[i],a);
		}
		fclose(fp);
	}

}

void output(INFORM P) {
	char a=' ';
	FILE *fp=fopen("information.txt","r");     //���ⲿ�ļ�
	int b,c;
	b=1;
	INFORM element=list(p);
	while(b!=0) {
		printf("��������������ı�ż�����������0 0ֹͣ���룩");
		scanf("%d %d",&b,&c);
		if(b==0&&c==0) {
			system("cls");
			fp=fopen("information.txt","w");
			for(int i=0; i<n; i++) {
				fprintf(fp,"%d%c%c",num[i],variety[i],a);
			}
			fclose(fp);
			menu();

		}
		if(element->number==b) {
			if(element->amount-c>=0) {
				element->amount=element->amount+c;      //��amount��c��λ��ȡ������
				num[b-1]=num[b-1]+c;
				printf("���ɹ���ʣ����%d\n",element->number);
				printf("�����������\n");
				getch();
				system("cls");
				continue;
			} else {
				printf("��治�㣡����ʧ�ܣ�\n");
				printf("�����������\n");
				getch();
				system("cls");
				continue;

			}
		} else 
		 {
			while(element!=NULL)
			 {
			   element=element->next;
			   if(element->number==b)
			   {
			   	if(element-c>=0)
			   	{
			   			
					element->amount=element->amount-c;
					num[b-1]=num[b-1]-c;    //��amount��c��λ�ò������
					printf("����ɹ���ʣ����%d\n",element->number);
					printf("�����������\n");
					getch();
					system("cls");
					break;
				   
			    }
			        else
			      {
			   	    printf("��治�㣡����ʧ�ܣ�\n");
			   	    printf("�����������\n");
			   	    getch();
			   	    system("cls");
			   	    break;
			      } 
				}
			}
		}
		fp=fopen("information.txt","w");
		for(int i=0; i<n; i++) {
			fprintf(fp,"%d%c%c",num[i],variety[i],a);
		}
		fclose(fp);
	}

}

void menu()
{
	printf("                                   \n");
	printf("           �ֿ����ϵͳ            \n");
	printf("                                   \n");
	printf("           ��ʾ�����б��밴 2      \n");
	printf("           ����밴 3              \n");
	printf("           �����밴 4              \n");
	printf("           ���沢�˳������밴 5    \n");
	char ch;
	char gh;
	char d[100];
	char a=' ';
	int c=0;
	FILE *fp=fopen("information.txt","r");
	FILE *fpRead=fopen("information.txt","r");
	if(fpRead!=NULL)
	{
		for(int i=0;i<1000;i++)
		{
			fscanf(fpRead,"%d%c",&num[i],&variety[i]);
			
		}
	}
	ch=getch();
	switch(ch)
	{
		case '2':
		system("cls");
		while(fscanf(fp,"%c",&d[c])!=EOF)
		{
			printf("%c",d[c]);
			c++;
		}
	
	printf("\n");
	printf("��5����������\n");
	gh=getch();
	if(gh==5)
	{
		system("cls");
		menu();
	}
	break;
	
	case '3':
		input(p);
		printf("\n");
		printf("��5����������\n");
		gh=getch();
		if(gh==5)
		{
			system("cls");
			menu();
		 } 
		 break;
		 
	case '4':
    	output(p);
		printf("\n");
		printf("��5����������\n");
	    gh=getch();
	    if(gh==5)
	   	{
			system("cls");
			menu();
		    } 
		  break;
		  
		  case '5':
		  	fp=fopen("information.txt","w");
		  	for(int i=0;i<n;i++)
		  	{
		  		fprintf(fp,"%d%c%c",num[i],variety[i],a);
		  		
			  }
			  fclose(fp);
			  break;
			  default:
			  	printf("������Ч��������ָ������\n");
			  	
		 	
	}
}
int main()
{
	menu();
	return 0;
}
	


