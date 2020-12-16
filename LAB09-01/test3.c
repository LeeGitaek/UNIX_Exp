#include <stdio.h>
#include <stdlib.h>

struct st {
	int id;
	char name[30];
};

//add five function 
void add_five(struct st *idnum);

int main(void)
{
	
	int i; 
	struct st data[5];

	for(i = 0; i<5; i++)
	{
		scanf("%d",&data[i].id);
		scanf("%s",&data[i].name);
	}

	for(i = 0; i<5; i++)
	{
		// add_five 함수로 포인터를 넘겨준다.
		// 배열 전체가 아닌 원소 하나씩 포인터로 전달하며, 함수는 리턴하지 않는다.

		add_five(&data[i]);
	}

	for(i = 0; i<5; i++)
	{
		printf("%-5d",data[i].id);
		printf("%-5s\n",data[i].name);
	}

	return 0;
}

void add_five(struct st *idnum)
{
	idnum->id = idnum->id + 5;		
}
