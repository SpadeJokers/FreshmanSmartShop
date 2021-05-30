#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define N 100
#pragma warning(disable:4996);

/*����ѧԺ20��������������ѧԺ���������ѧ�뼼��2�࣬�̷�����20202308049*/

/*��ϵͳ�У���׺��������   1��2��3    �ı����ֱ����   ����Ʒ�������ؼ���Ʒ�������˿͹��ﳵ������
�磺��*p_1������һ��������������goods_1���ں����е���ʱָ�������ͨ��������ѯ�������������еġ��������ȣ�
ʣ�µ��Դ����ƣ������е�c����һ�������洢һ��int�͵���ʱ������ʹ��*/

int number_1 = 0;//������ȫ�ֱ���������¼�˿͹�����Ʒ��������
int number_2 = 0;


typedef struct GoodsNode     //������Ʒ�Ľṹ������
{
	char goods_name[N];
	int goods_key;
	int goods_price;
	int goods_number = 0;
	struct GoodsNode *next;
}Goods;

/*�������ڱ�������Ҫ�õ��ĺ���*/
void Bargain(Goods *&head);   //�ؼ���Ʒ����
void CheckOut(Goods *L);      //���˺���
void Choose_Goods(int key, Goods *&L_1, Goods *&L_2, Goods *&L_3);//�˿�ѡ����Ʒ�ĺ���
void Customer_Choose(Goods *&L_1, Goods *&L_2, Goods *&L_3);    //�˿�ѡ��Ҫ���еĻҳ�溯��
void Destroy(Goods *&L);       //����������
void Inithead(Goods *&head);    //��ʼ��һ��������Ʒ��ͷ��㺯��
void Initpage();       //��ʼ���ѡ��ҳ�溯��
void MyCart(Goods *&L);   //չʾ�˿͹��ﳵ����Ҫ����Ķ���
void Putshelves(Goods *&head);       //�ϼ��»������Ʒ����
void Queryinventory(Goods *L);//��ѯ��溯��
void Salesperson_Choose(Goods *&L_1, Goods *&L_2);//�ۻ�Ա�ϼ���Ʒ����ѯ���ĺ���


void Initpage()        //��ʼ���ѡ��ҳ��
{
	printf("\t\t��ã���ӭ���ٳ̷��������ܳ���\n");
	printf("\t\t\t ��ѡ�������ݣ�\n\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t1.�ۻ�Ա\n");
	printf("\t\t2.�˿�\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	return;
}

void Queryinventory(Goods *L)        //��ѯ��溯��
{
	Goods *p;
	p = L->next;
	printf("\t\t������Ʒʣ����\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t���к�\t�� ��\t�� ��\t�� ��\n");
	while (p != NULL)
	{
		printf("\t%d\t%s\t%d\t%d\n", p->goods_key, p->goods_name, p->goods_price, p->goods_number);
		p = p->next;
	}
	printf("* * * * * * * * * * * * * * * * * * * * * * * * *\n");
	return;
}

void Inithead(Goods *&head)    //��ʼ��һ��������Ʒ��ͷ���
{
	head = (Goods*)malloc(sizeof(Goods));
	head->next = NULL;
	return;
}

void Putshelves(Goods *&head)       //�ϼ���Ʒ����
{
	int n,i;
	Goods *p_1,*q_1;
	Inithead(head);           
	q_1 = head;

	printf("���������Ҫ�ϼ���Ʒ��������");
	scanf("%d", &n);
	printf("\n");
	system("cls");
	printf("¼����Ϣ��...............\n");

	for (i = 0 ; i < n ; i++)
	{
		p_1 = (Goods*)malloc(sizeof(Goods));
		p_1->next = q_1->next;                 //����β�巨���в���
		q_1->next = p_1;
		q_1 = p_1;
		printf("* * * * * * * * * * * * * * * * * * * * * * * * *\n");
		printf("��%d����Ʒ���ƣ�",i+1);
		scanf("%s", p_1->goods_name);
		printf("\n");
		printf("��Ʒ���кţ�");
		scanf("%d", &p_1->goods_key);
		printf("\n");
		printf("��Ʒ�۸�");
		scanf("%d", &p_1->goods_price);
		printf("\n");
		printf("�ϼ�������");
		scanf("%d", &p_1->goods_number);
		printf("\n");
	}
	printf("* * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("��¼����Ϣ�⣡\n");
	return;
}

void Bargain(Goods *&head)                       //�ϼ��ؼ���Ʒ
{
	int n, i;
	Goods *p_2, *q_2;
	Inithead(head);           
	q_2 = head;

	printf("���������Ҫ�ϼ��ؼ���Ʒ��������");
	scanf("%d", &n);
	printf("\n");
	system("cls");
	printf("¼����Ϣ��...............\n");

	for (i = 0; i < n; i++)
	{
		p_2 = (Goods*)malloc(sizeof(Goods));
		p_2->next = q_2->next;                 //����β�巨���в���
		q_2->next = p_2;
		q_2 = p_2;
		printf("* * * * * * * * * * * * * * * * * * * * * * * * *\n");
		printf("��%d����Ʒ���ƣ�", i + 1);
		scanf("%s", p_2->goods_name);
		printf("\n");
		printf("��Ʒ���кţ�");
		scanf("%d", &p_2->goods_key);
		printf("\n");
		printf("��Ʒ�۸�");
		scanf("%d", &p_2->goods_price);
		printf("\n");
		printf("�ϼ�������");
		scanf("%d", &p_2->goods_number);
		printf("\n");
	}
	printf("* * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("��¼����Ϣ�⣡\n");
	return;
}

void Destroy(Goods *&L)       //��������
{
	int i;
	Goods *pre, *p;
	pre = L;
	p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
	return;
}

void Choose_Goods(int key,Goods *&L_1,Goods *&L_2,Goods *&L_3)
{
	Goods *pre_1=NULL, *pre_2=NULL, *pre_3=NULL, *p=NULL, *p_3=NULL;
	pre_3 = L_3;
	p_3 = pre_3->next;								//�˿͹��ﳵ�ĵ���
	if (L_1 != NULL)
	{
		pre_1 = L_1->next;								 //����Ʒ�ĵ���
	}
	if (L_2 != NULL)
	{
		pre_2 = L_2->next;								//�ؼ���Ʒ�ĵ���
	}
	while (p_3 != NULL)								//���������������������д��������������ϼ�һ
	{
		if (key == p_3->goods_key)
		{
			p_3->goods_price = p_3->goods_price + p_3->goods_price / p_3->goods_number;
			p_3->goods_number++;
			while (pre_1 != NULL)
			{
				if (key == pre_1->goods_key)
				{
					pre_1->goods_number--;
					return;
				}
				pre_1 = pre_1->next;
			}
			while (pre_2 != NULL)
			{
				if (key == pre_2->goods_key)
				{
					pre_2->goods_number--;
					return;
				}
				pre_2 = pre_2->next;
			}
		}
		else {
			p_3 = p_3->next;
		}
	}
	while (pre_1 != NULL)
	{
		if (key == pre_1->goods_key)
		{
			p = (Goods*)malloc(sizeof(Goods));
			p->next = pre_3->next;
			pre_3->next = p;
			number_1++;
			strcpy(p->goods_name, pre_1->goods_name);
			p->goods_key = pre_1->goods_key;
			p->goods_number = number_1;
			p->goods_price = pre_1->goods_price;
			pre_1->goods_number--;
			return;
		}
		pre_1 = pre_1->next;
	}
	while(pre_2 != NULL)
	{
		if (key == pre_2->goods_key)
		{
			p = (Goods*)malloc(sizeof(Goods));
			p->next = pre_3->next;
			pre_3->next = p;
			number_2++;
			strcpy(p->goods_name, pre_2->goods_name);
			p->goods_key = pre_2->goods_key;
			p->goods_number = number_2;
			p->goods_price = pre_2->goods_price;
			pre_2->goods_number--;
			return;
		}
		pre_2 = pre_2->next;
	}
	return;
}

void MyCart(Goods *&L)   //չʾ�˿͹��ﳵ����Ҫ����Ķ���
{
	Goods *p;
	p = L->next;
	printf("\n�ҵĹ��ﳵ��\t���к�\t����\t�۸�\t����\n");
	while (p != NULL) 
	{
		printf("\t\t%d\t%s\t%d\t%d\n", p->goods_key, p->goods_name, p->goods_price, p->goods_number);
		p = p->next;
	}
	return;
}

void CheckOut(Goods *L)//���˺���
{
	int c, price = 0;
	Goods *p;
	p = L->next;
	MyCart(L);
	while (p != NULL)
	{
		price = price + p->goods_price;
		p = p->next;
	}
	printf("�ܽ��Ϊ��%.2d\n", price);
	printf("�Ƿ�ȷ�Ͻɷѣ�1����\t2����\n");
	scanf("%d",&c);
	switch (c)
	{
	case 1:
		system("cls");
		printf("��л���Ĺ��٣�ף��������죡\n");
		getch();
		break;
	case 2:
		system("cls");
		printf("�ɷ�ʧ�ܣ�������ѡ��\n");
		getch();
		break;
	}
	return;
}

void Customer_Choose(Goods *&L_1,Goods *&L_2,Goods *&L_3)    //�˿�ѡ��ҳ��
{
	int c_1, c_2, c_3 = 1;
	float price = 0;
	Goods  *p_1 = L_1, *p_2 = L_2, *p_3 = L_3;
	printf("----------------------------------------------------------------\n");
	printf("1�����ܹ���\n");
	printf("----------------------------------------------------------------\n");
	printf("0���˳�\n");
	printf("----------------------------------------------------------------\n");
	scanf("%d", &c_1);
	while (1)
	{
		switch (c_1)
		{
		case 1:
			while(1)
			{
				system("cls");
				if (L_1 == NULL && L_2 == NULL)
				{
					printf("��������Ʒ���ۣ�\n");
					getch();
					system("cls");
					return;
				}
				if (L_1 == NULL)
				{
					printf("��������Ʒ���ۣ�\n");
				}
				else {
					Queryinventory(L_1);            //����Ʒ��չʾҳ��
					printf("\n");                        
				}
				if (L_2 == NULL)
				{
					printf("�������ؼ���Ʒ���ۣ�\n");
				}
				else {
					Queryinventory(L_2);                 //�ؼ���Ʒ��չʾҳ��
					printf("\n");
				}
				printf("������Ҫ�������Ʒ���кţ�\n");
				printf("\t������0��Ϊ���ˣ�\n");
				if (L_3->next != NULL)
				{
					MyCart(L_3);
				}
				scanf("%d", &c_3);
				if (c_3 == 0) 
				{
					system("cls");
					CheckOut(L_3);
					system("cls");
					return;
				}
				while (p_1 != NULL)    //������Ʒ�в����Ƿ���������Ʒ�����кţ�û�����������ѡ
				{
					if (c_3 == p_1->goods_key)
					{
						break;
					}
					p_1 = p_1->next;
				}
				while (p_2 != NULL)   //���ؼ���Ʒ�в����Ƿ���������Ʒ�����кţ�û�����������ѡ
				{
					if (c_3 == p_2->goods_key)
					{
						break;
					}
					p_2 = p_2->next;
				}
				if (p_1 == NULL && p_2 == NULL)
				{
					system("cls");
					printf("û�и���Ʒ�����������룡");
					getch();
					p_1 = L_1;
					p_2 = L_2;
					break;
				}
				p_1 = L_1;
				p_2 = L_2;
				if (c_3 != 0)
				{
					Choose_Goods(c_3, L_1, L_2, L_3);
					if (p_3 != NULL)
					{
						p_3 = p_3->next;
					}
				}
				break;
			}
			break;
		case 0:
			system("cls");
			return;
		}
	}
	return;
}

void Salesperson_Choose(Goods *&L_1,Goods *&L_2)           //������Աѡ��ҳ��
{
	int c_1,c_2=1;
	while (1)
	{
		system("cls");
		printf("----------------------------------------------------------------\n");
		printf("1���ϼ�����Ʒ\n");
		printf("----------------------------------------------------------------\n");
		printf("2���ϼܽ����ؼ���Ʒ\n");
		printf("----------------------------------------------------------------\n");
		printf("3���鿴������\n");
		printf("----------------------------------------------------------------\n");
		printf("0��������һ��\n");
		printf("----------------------------------------------------------------\n");
		scanf("%d", &c_1);
		switch (c_1)
		{
		case 1:
			system("cls");
			Putshelves(L_1);
			getch();
			break;
		case 2:
			system("cls");
			Bargain(L_2);
			getch();
			break;
		case 3:
			while (c_2)
			{
				system("cls");
				printf("----------------------------------------------------------------\n");
				printf("1������Ʒ���\n");
				printf("----------------------------------------------------------------\n");
				printf("2���ؼ���Ʒ���\n");
				printf("----------------------------------------------------------------\n");
				printf("0��������һ��\n");
				printf("----------------------------------------------------------------\n");
				scanf("%d", &c_2);
				switch (c_2)
				{
				case 1:
					if (L_1 == NULL)
					{
						system("cls");
						printf("�������ݣ�");
					}
					else {
						system("cls");
						Queryinventory(L_1);
					}
					getch();
					break;
				case 2:
					if (L_2 == NULL)
					{
						system("cls");
						printf("�������ݣ�");
					}
					else {
						system("cls");
						Queryinventory(L_2);
					}
					getch();
					break;
				case 0:
					c_2 = 0;
					system("cls");
					break;
				}
			}
			c_2 = 1;
			break;
		case 0:
			system("cls");
			return;
		}
	}
	return;
}

int main(void)
{
	Goods *goods_1, *goods_2, *shopcart;
	goods_1 = goods_2 = shopcart = NULL;   
	int c;
	while (1)
	{
		Initpage();//��ʼ��ҳ��˵���ѡ����ݵĵط�
		scanf("%d", &c);
		system("cls");
		switch (c)
		{
		case 1:
			Salesperson_Choose(goods_1, goods_2);//������Ա�ϼ���Ʒ����ѯ���ĺ���
			break;
		case 2:
			Inithead(shopcart);//����һ�����ﳵ��ͷ�������
			system("cls");
			Customer_Choose(goods_1, goods_2, shopcart);//�˿�ѡ�����Ŀ��
			number_1 = number_2 = 0;  //����һ���˿�ѡ�����Ʒ��������
			Destroy(shopcart);  //����һ���˿�ѡ���Ĺ��ﳵ���٣��Ա�����һ���˿�ѡ��
			break;
		}
	}
	return 0;
}