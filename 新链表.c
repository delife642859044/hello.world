#include <stdio.h>
#include <stdlib.h>

struct Family
{
		char name[64];		//姓名
		int Family_number;	//家庭人数
		char Home_add[64]; 	//家庭住址
		int Phone;			//联系电话
		struct Family *next;
};

/*		添加链表节点		*/
void addFamily (struct Family **family)
{
		struct Family *tenement, *temp;

		tenement = (struct Family *)malloc(sizeof(struct Family));

		if (tenement == NULL)
		{
				printf("内存分配失败！！");
				exit(1);
		}

		getInput(tenement);		//录入数据

		if ( *family != NULL)
		{	
				temp = *family;
				*family = tenement;
				tenement->next = temp;
		}
		else
		{
				*family = tenement;
				tenement->next = NULL;
		}


}

/*		录入数据	*/
void getInput (struct Family *tenement)
{
		printf("请输入您的姓名：");
		scanf("%s",&tenement->name);
		printf("请输入您的家庭人数：");
		scanf("%d",&tenement->Family_number);
		printf("请输入您的家庭住址：");
		scanf("%s",&tenement->Home_add);
		printf("请输入您的联系方式：");
		scanf("%d",&tenement->Phone);
}

/*		打印链表		*/
void printFamily(struct Family *family)
{
		int count = 1;

		while(family != NULL)
		{
				printf("第 %d 位：", count);
				printf("姓名：%s\n", family->name);
				printf("家庭人数：%d\n", family->Family_number);
				printf("家庭住址：%s\n", family->Home_add);
				printf("家庭联系方式：%d\n", family->Phone);
				family = family->next;
				count++;
		}
}

/*		释放地址		*/

void delFamily (struct Family **family)
{
		struct Family *temp;
		while ( *family != NULL)
		{
				temp = *family;
				*family = (*family)->next;
				free(temp);

		}
}

void delFamily (struct Family **family);
void printFamily(struct Family *family);
void getInput (struct Family *tenement);
void addFamily (struct Family **family);

int main(void)
{
		struct Family *family = NULL;
		int ch;

		while(1)
		{
			printf("是否需要录入数据（Y/N）：");
			do
			{
					ch = getchar();
			}while(ch != 'y' && ch != 'n');
			if(ch == 'y')
			{
					addFamily(&family);
			}
			else
			{
					break;
			}
			
		}
			printf("是否需要录入数据（Y/N）：");
			do
			{
					ch = getchar();
			}while(ch != 'y' && ch != 'n');
			if(ch == 'y')
			{
					printFamily(family);
			}

			delFamily(&family);
		return 0;
}
