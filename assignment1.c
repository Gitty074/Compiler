#include<stdio.h>
#include<string.h>
#define MAX 53

struct symbol_info
{
    char name[100];
    char class_type[100];
    struct symbol_info *next;
}*p[53];

int hash(char name[]){
	int sum;
	int i;
	for(i=0;i<strlen(name);i++)
	sum+=name[i];
	int hash=sum%MAX;
	return hash;
}

void insert(char name[],char class_type[]){
}

void search(char name[],char class_type[]){
}

void show(){
}

void update(char name[],char class_type[],char update){
}

int main(){
	int choice;
	char name[100];
	char class_type[100];
	char update;
	int i,j;
	
	while(1){
			printf("1.Insert 2.Search 3.Delete 4.Show 5.Update 6.Quit\n");
			printf("Enter Choice:");
			scanf("%d",&choice);
			switch(choice){
			case 1:
			printf("Enter tuples:");
			scanf("%s",&name);
	        	scanf("%s",&class_type);
	        	//printf("name:%s\n",name);
	        	//printf("type:%s\n",class_type);
	        	insert(name,class_type);

			break;

			case 2:
			printf("Enter tuples");



			break;
			case 3:
			printf("Enter tuples");



			break;
			case 4:
			break;

			case 5:
			printf("Enter tuples");

			break;

			case 6:
			break;

		}
	}

	return 0;
}

