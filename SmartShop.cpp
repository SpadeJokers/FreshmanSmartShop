#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define N 100
#pragma warning(disable:4996);

/*滨江学院20级、物联网工程学院，计算机科学与技术2班，程方方，20202308049*/

/*本系统中，后缀挂有数字   1、2、3    的变量分别代表   新商品的链表、特价商品的链表、顾客购物车的链表
如：（*p_1：这是一个关于主函数中goods_1的在函数中的临时指针变量，通常用作查询，交换三部曲中的“容器”等）
剩下的以此类推，函数中的c变量一般用作存储一个int型的临时变量来使用*/

int number_1 = 0;//这两个全局变量用来记录顾客购买商品的数量。
int number_2 = 0;


typedef struct GoodsNode     //关于商品的结构体类型
{
	char goods_name[N];
	int goods_key;
	int goods_price;
	int goods_number = 0;
	struct GoodsNode *next;
}Goods;

/*以下是在本程序中要用到的函数*/
void Bargain(Goods *&head);   //特价商品函数
void CheckOut(Goods *L);      //结账函数
void Choose_Goods(int key, Goods *&L_1, Goods *&L_2, Goods *&L_3);//顾客选择商品的函数
void Customer_Choose(Goods *&L_1, Goods *&L_2, Goods *&L_3);    //顾客选择要进行的活动页面函数
void Destroy(Goods *&L);       //销毁链表函数
void Inithead(Goods *&head);    //初始化一个关于商品的头结点函数
void Initpage();       //初始身份选择页面函数
void MyCart(Goods *&L);   //展示顾客购物车中所要购买的东西
void Putshelves(Goods *&head);       //上架新货物的商品函数
void Queryinventory(Goods *L);//查询库存函数
void Salesperson_Choose(Goods *&L_1, Goods *&L_2);//售货员上架商品，查询库存的函数


void Initpage()        //初始身份选择页面
{
	printf("\t\t你好，欢迎光临程方方的智能超市\n");
	printf("\t\t\t 请选择你的身份！\n\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t1.售货员\n");
	printf("\t\t2.顾客\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	return;
}

void Queryinventory(Goods *L)        //查询库存函数
{
	Goods *p;
	p = L->next;
	printf("\t\t今日商品剩余库存\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t序列号\t名 称\t价 格\t数 量\n");
	while (p != NULL)
	{
		printf("\t%d\t%s\t%d\t%d\n", p->goods_key, p->goods_name, p->goods_price, p->goods_number);
		p = p->next;
	}
	printf("* * * * * * * * * * * * * * * * * * * * * * * * *\n");
	return;
}

void Inithead(Goods *&head)    //初始化一个关于商品的头结点
{
	head = (Goods*)malloc(sizeof(Goods));
	head->next = NULL;
	return;
}

void Putshelves(Goods *&head)       //上架商品函数
{
	int n,i;
	Goods *p_1,*q_1;
	Inithead(head);           
	q_1 = head;

	printf("请输入今日要上架商品的数量：");
	scanf("%d", &n);
	printf("\n");
	system("cls");
	printf("录入信息中...............\n");

	for (i = 0 ; i < n ; i++)
	{
		p_1 = (Goods*)malloc(sizeof(Goods));
		p_1->next = q_1->next;                 //运用尾插法进行插入
		q_1->next = p_1;
		q_1 = p_1;
		printf("* * * * * * * * * * * * * * * * * * * * * * * * *\n");
		printf("第%d件商品名称：",i+1);
		scanf("%s", p_1->goods_name);
		printf("\n");
		printf("商品序列号：");
		scanf("%d", &p_1->goods_key);
		printf("\n");
		printf("商品价格：");
		scanf("%d", &p_1->goods_price);
		printf("\n");
		printf("上架数量：");
		scanf("%d", &p_1->goods_number);
		printf("\n");
	}
	printf("* * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("已录入信息库！\n");
	return;
}

void Bargain(Goods *&head)                       //上架特价商品
{
	int n, i;
	Goods *p_2, *q_2;
	Inithead(head);           
	q_2 = head;

	printf("请输入今日要上架特价商品的数量：");
	scanf("%d", &n);
	printf("\n");
	system("cls");
	printf("录入信息中...............\n");

	for (i = 0; i < n; i++)
	{
		p_2 = (Goods*)malloc(sizeof(Goods));
		p_2->next = q_2->next;                 //运用尾插法进行插入
		q_2->next = p_2;
		q_2 = p_2;
		printf("* * * * * * * * * * * * * * * * * * * * * * * * *\n");
		printf("第%d件商品名称：", i + 1);
		scanf("%s", p_2->goods_name);
		printf("\n");
		printf("商品序列号：");
		scanf("%d", &p_2->goods_key);
		printf("\n");
		printf("商品价格：");
		scanf("%d", &p_2->goods_price);
		printf("\n");
		printf("上架数量：");
		scanf("%d", &p_2->goods_number);
		printf("\n");
	}
	printf("* * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("已录入信息库！\n");
	return;
}

void Destroy(Goods *&L)       //销毁链表
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
	p_3 = pre_3->next;								//顾客购物车的单链
	if (L_1 != NULL)
	{
		pre_1 = L_1->next;								 //新商品的单链
	}
	if (L_2 != NULL)
	{
		pre_2 = L_2->next;								//特价商品的单链
	}
	while (p_3 != NULL)								//先在自身检索，如果链表中存在则在其数量上加一
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

void MyCart(Goods *&L)   //展示顾客购物车中所要购买的东西
{
	Goods *p;
	p = L->next;
	printf("\n我的购物车：\t序列号\t名称\t价格\t数量\n");
	while (p != NULL) 
	{
		printf("\t\t%d\t%s\t%d\t%d\n", p->goods_key, p->goods_name, p->goods_price, p->goods_number);
		p = p->next;
	}
	return;
}

void CheckOut(Goods *L)//结账函数
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
	printf("总金额为：%.2d\n", price);
	printf("是否确认缴费：1：是\t2：否\n");
	scanf("%d",&c);
	switch (c)
	{
	case 1:
		system("cls");
		printf("感谢您的光临！祝您生活愉快！\n");
		getch();
		break;
	case 2:
		system("cls");
		printf("缴费失败！请重新选择！\n");
		getch();
		break;
	}
	return;
}

void Customer_Choose(Goods *&L_1,Goods *&L_2,Goods *&L_3)    //顾客选择页面
{
	int c_1, c_2, c_3 = 1;
	float price = 0;
	Goods  *p_1 = L_1, *p_2 = L_2, *p_3 = L_3;
	printf("----------------------------------------------------------------\n");
	printf("1：智能购物\n");
	printf("----------------------------------------------------------------\n");
	printf("0：退出\n");
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
					printf("今日无商品可售！\n");
					getch();
					system("cls");
					return;
				}
				if (L_1 == NULL)
				{
					printf("今日无商品可售！\n");
				}
				else {
					Queryinventory(L_1);            //新商品的展示页面
					printf("\n");                        
				}
				if (L_2 == NULL)
				{
					printf("今日无特价商品可售！\n");
				}
				else {
					Queryinventory(L_2);                 //特价商品的展示页面
					printf("\n");
				}
				printf("请输入要购买的商品序列号：\n");
				printf("\t（输入0则为结账）\n");
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
				while (p_1 != NULL)    //在新商品中查找是否存在这个商品的序列号，没有则错误，重新选
				{
					if (c_3 == p_1->goods_key)
					{
						break;
					}
					p_1 = p_1->next;
				}
				while (p_2 != NULL)   //在特价商品中查找是否存在这个商品的序列号，没有则错误，重新选
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
					printf("没有该商品，请重新输入！");
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

void Salesperson_Choose(Goods *&L_1,Goods *&L_2)           //销售人员选择页面
{
	int c_1,c_2=1;
	while (1)
	{
		system("cls");
		printf("----------------------------------------------------------------\n");
		printf("1：上架新商品\n");
		printf("----------------------------------------------------------------\n");
		printf("2：上架今日特价商品\n");
		printf("----------------------------------------------------------------\n");
		printf("3：查看货物库存\n");
		printf("----------------------------------------------------------------\n");
		printf("0：返回上一级\n");
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
				printf("1：新商品库存\n");
				printf("----------------------------------------------------------------\n");
				printf("2：特价商品库存\n");
				printf("----------------------------------------------------------------\n");
				printf("0：返回上一级\n");
				printf("----------------------------------------------------------------\n");
				scanf("%d", &c_2);
				switch (c_2)
				{
				case 1:
					if (L_1 == NULL)
					{
						system("cls");
						printf("暂无数据！");
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
						printf("暂无数据！");
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
		Initpage();//初始话页面菜单，选择身份的地方
		scanf("%d", &c);
		system("cls");
		switch (c)
		{
		case 1:
			Salesperson_Choose(goods_1, goods_2);//销售人员上架商品，查询库存的函数
			break;
		case 2:
			Inithead(shopcart);//建立一个购物车的头结点链表
			system("cls");
			Customer_Choose(goods_1, goods_2, shopcart);//顾客选择的项目栏
			number_1 = number_2 = 0;  //将上一个顾客选择的商品数量归零
			Destroy(shopcart);  //将上一个顾客选购的购物车销毁，以便于下一个顾客选择
			break;
		}
	}
	return 0;
}