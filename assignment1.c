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
            strcpy(p[h]->name,name);
            strcpy(p[h]->class_type,class_type);
            p[h]->next = NULL;
            prev = p[h];
    }
    else{
            temp = (node*)malloc(sizeof(node));
            strcpy(temp->name,name);
            strcpy(temp->class_type,class_type);
            temp->next = p[h];
            p[h] = temp;
    }
}

int search(char name[],char class_type[]){
    int j=hash(name);
    node *temp;
    temp = p[j];
    while(temp!=NULL){
        if(strcmp(temp->name,name)==0 && strcmp(temp->class_type,class_type)==0)
            return 1;
        else
            temp = temp->next;
        }
        return 0;
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

void updatef(char name[],char class_type[],char updated_type[]){
    int index = hash(name);
    node *temp;
    temp = p[index];
    while(temp!=NULL && strcmp(temp->name,name)!=0 && strcmp(temp->class_type,class_type)!=0 )
        temp = temp->next;
    strcpy(temp->class_type,updated_type);
}

void del(char name[],char class_type[]){
    node *temp,*temp1;
    int location = hash(name);///using hash() to find the desired node
    if(p[location]==NULL)
        printf("NOT FOUND\n");
    else if(strcmp(p[location]->name,name)==0 && strcmp(p[location]->class_type,class_type)==0){
        temp = p[location];
        p[location] = p[location]->next;
        free(temp);
    }
    else{
        temp = p[location];
        while(temp->next!=NULL && strcmp(temp->next->name,name)!=0 && strcmp(temp->next->class_type,class_type)!=0)
            temp = temp->next;
        if(temp->next==NULL)
            printf("NOT FOUND\n");
        else{
            temp1 = temp->next;
            temp->next = temp1->next;
            free(temp1);
        }
    }

}
int main(){
	int choice;
	char name[100];
	char class_type[100];
	char update[100];
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
                insert(name,class_type);
			break;

			case 2:
                printf("Enter tuples:\n");
                scanf("%s",name);
                scanf("%s",class_type);
                if(search(name,class_type)==1)
                    printf("FOUND\n");
                else
                    printf("NOT FOUND\n");
			break;

			case 3:
                printf("Enter tuples:\n");
                scanf("%s",name);
                scanf("%s",class_type);
                del(name,class_type);
			break;

			case 4:
			    show();
			break;

			case 5:
                printf("Enter tuples to update:\n");
                scanf("%s",name);
                scanf("%s",class_type);
                printf("Enter new type:");
                scanf("%s",update);
                updatef(name,class_type,update);
			break;

			case 6:
            exit(0);
            default:
                exit(0);

		}
	}

	return 0;
}

