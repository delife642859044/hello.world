#include <stdio.h>

struct Hotel  //旅馆
{
		int number;		//房间号
		char name[128]; 	//姓名
		int ID_card;		//身份证
		struct Hotel *next;
};

/*		添加节点 	(头插法)	*/

void addList(struct Hotel **Hotel_list)
{
		struct Hotel *temp, *date;
		
		date = (struct Hotel *)malloc(sizeof(struct Hotel));

		if(date == NULL)
		{
						printf("内存分配失败！\n");
						exit(1);
		}

		getInput(date);

		if(*Hotel_list != NULL)
		{
						temp = *Hotel_list;
						*Hotel_list = date;
						date->next = temp;
		}
		else
		{
						*Hotel_list = date;
						date->next = NULL;
		}
	
}

/*	添加节点内容	*/
void getInput(struct Hotel *date)
{
		printf("请输入房间号：");
		scanf("%d", &date->number);
		printf("请输入住户名：");
		scanf("%s", &date->name);
		printf("请输入ID_card：");
		scanf("%d", &date->ID_card);
}

/*	打印链表	*/
void printList(struct Hotel *Hotel_list)
{
		struct Hotel *temp;
		int a = 1;

		temp = Hotel_list;
		while(temp != NULL)		
		{		
				printf("第 %d 位客人：\n", a);
				printf("房间号：%d\n", temp->number);
				printf("登记人：%s\n", temp->name);
				printf("身份证号：%d\n", temp->ID_card);

				temp = temp->next;
				a++;
		}
		
}

/*	释放内存	*/
void releaseList (struct Hotel **Hotel_list)
{
		struct Hotel *temp;

		while( *Hotel_list != NULL)
		{		
				temp = *Hotel_list;
				*Hotel_list = (*Hotel_list)->next;
				free(temp);
		}
}

void addList(struct Hotel **Hotel_list); //添加节点
void releaseList (struct Hotel **Hotel_list); //释放内存
void printList(struct Hotel *Hotel_list); //打印
void getInput(struct Hotel *date);	//录入数据


int main (void)
{
		struct Hotel *Hotel_list = NULL;
		int ch;

		while(1)
		{
				printf("是否要录入数据（Y/N）：");
				do
				{
						ch = getchar();
				}while(ch != 'y' && ch != 'n');

				if(ch == 'y')
				{
						addList(&Hotel_list);
				}
				else
				{
						break;
				}
		}

		printf("是否需要打印（Y/N）：");
		do
		{
				ch = getchar();
		}while(ch != 'y' && ch != 'n');

		if(ch == 'y')
		{
				printList(Hotel_list);
		}

		releaseList(&Hotel_list);

	return 0;
}
