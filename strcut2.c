#include <stdio.h>

int main()
{

		struct a{
		char *name;	//姓名
		int age;	 	//年龄
		char *class; 	//班级
		int result;		//成绩
		};

		struct a lining, liuxiang;

		lining.name = "linning";
		lining.age = 18;
		lining.class = "1 班";
		lining.result = 89;

		liuxiang.name = "liuxiang";
		liuxiang.age = 19;
		liuxiang.class = "2 班";
		liuxiang.result = 99;

		printf("姓名： %s\n", lining.name);
		printf("年龄： %d\n", lining.age);
		printf("班级： %s\n", lining.class);
		printf("成绩： %d\n", lining.result);
		printf("\n");	
		printf("姓名： %s\n", liuxiang.name);
		printf("年龄： %d\n", liuxiang.age);
		printf("班级： %s\n", liuxiang.class);
		printf("成绩： %d\n", liuxiang.result);
		return 0;
}
