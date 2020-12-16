#include <stdio.h>

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

	// 포인터 => 배열 전체를 함수에 넘겨준다. 
	add_five(&data);


	for(i = 0; i<5; i++)
	{
		printf("%-5d",data[i].id);
		printf("%-5s\n",data[i].name);
	}

	return 0;
}

void add_five(struct st *idnum)
{
	int i;
	for(i = 0; i<5; i++)
	{
		(idnum+i)->id = (idnum+i)->id + 5;
	} 				
}
