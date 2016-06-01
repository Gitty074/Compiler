#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 53

struct symbol_info
{
    char name[100];
    char class_type[100];
    struct symbol_info *next;
}* p[MAX] = {NULL};

typedef struct symbol_info node;
int i;
int hash(char name[]){
	int sum=0;
	int i;
	for(i=0;i<strlen(name);i++)
	sum+=name[i];
	int hash=sum%MAX;
	return hash;
}

void insert(char name[],char class_type[]){
    node *prev,*temp;
    int h = hash(name);
    printf("name is:%s and type is:%s\n",name,class_type);
    if(p[h]==NULL){
            p[h] = (node*)malloc(sizeof(node));
            /*for(i=0;name[i]!='\0';i++)
                p[h]->name[i] = name[i];
            for(i=0;class_type[i]!='\0';i++)
                p[h]->class_type[i] = class_type[i];*/
            strcpy(p[h]->name,name);
            strcpy(p[h]->class_type,class_type);
            p[h]->next = NULL;
            prev = p[h];
    }
    else{
            temp = (node*)malloc(sizeof(node));
            /*for(i=0;name[i]!='\0';i++)
                p[h]->name[i] = name[i];
            fflush(stdin);
            for(i=0;class_type[i]!='\0';i++)
                p[h]->class_type[i] = class_type[i];*/
            strcpy(p[h]->name,name);
            strcpy(p[h]->class_type,class_type);
            fflush(stdin);
            temp->next = NULL;
            prev->next = temp;
            prev = temp;
    }
}

void search(char name[],char class_type[]){
}

void show(){
    node *temp;
    for(i=0;i<MAX;i++){
            temp=p[i];
            if(temp==NULL){
                printf("%d null null\n",i);

            }
            else{
                while(temp!=NULL){
                printf("%d %s %s\n",i,temp->name,temp->class_type);
                temp = temp->next;
                }
            }
    }
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
			printf("Enter tuples:\n");
			scanf("%s",name);
			scanf("%s",class_type);
			//fgets(name,100,stdin);
            //fgets(class_type,100,stdin);
            insert(name,class_type);

			break;

			case 2:
			printf("Enter tuples");



			break;
			case 3:
			printf("Enter tuples");



			break;
			case 4:
			    show();
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

