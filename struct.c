#include <stdio.h>

int main()
{

		struct names{
		int a;
		int age;
		};

	struct names b;

	b.a = 18;
	b.age = 19;

	printf("%d %d \n", b.a, b.age);
	return 0;
}
