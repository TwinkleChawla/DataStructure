#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	sturct node *next;
};

struct node *insertStart(struct node* start, int r);
struct node *insertEnd(struct node* start, int r);
void insertGiven(struct node* start, int r, int sr);
struct node* deleteStart(struct node* start);
struct node* deleteEnd(struct node *start);
struct node* deleteGiven(struct node* start, int r);
struct node* searchList(struct node* start, int r);
void display(struct node* start);
void reverseLinkList(struct node* start);

int main(void) {
	int r, sr, ch;
	struct node *ptr, *start;
	start = NULL;
	do{
	printf("Enter your choice: ");
	printf("\n1. Enter a data in start of list");
	printf("\n2. Enter a data in end of list");
	printf("\n3. Enter a data in given node  of list");
	printf("\n4. Enter a data to delete data at start of list");
	printf("\n5. Enter a data to delete data at end of list");
	printf("\n6. Enter a data to delete data at given node in list");
	printf("\n7. Enter element want to search");
	printf("\n8. Display the list");
	printf("\n9. Display the reverse link list");
	printf("\n10. Exit");
	scanf("%d",&ch);

	switch(ch){
	case 1:
		printf("enter the data want to insert at start: ");
		scanf("%d",&r);
		start = insertStart(start, r);
		break;
	case 2:
		printf("enter the data want to insert at end: ");
		scanf("%d",&r);
		start = insertEnd(start, r);
		break;
	case 3:
		printf("enter the data want to insert after the given node:");
		scanf("%d",&r);
		printf("Enter the data to insert after: ");
		scanf("%d",&sr);
		insertGiven(start, r, sr);
		break;
	case 4:
		printf("enter the data want to delete at start ");
		scanf("%d",&r);
		start = deleteStart(start);
		break;
	case 5:
		printf("enter the data want to delete at end ");
		scanf("%d",&r);
		start = deleteEnd(start);
		break;
	case 6:
		printf("Enter a data to delete: ");
		scanf("%d",&r);
		start = deleteGiven(start, r);
		break;
	case 7:
		printf("enter the data want to search");
		scanf("%d",&r);
		ptr = searchList(start, r);
		if(ptr == NULL){
			printf("Found the data : %d",r);
		}
		else{
			printf("Not found");
		}
		break;
	case 8:
		display(start);
		break;
	case 9:
		reverseLinkList(start);
		break;
	case 10:
		break;
	default:
		printf("Invalid choice!!!");
	}
}while(ch != 10);
	return 0;
}
//insert at starting
struct node* insertStart(struct node* start, int r){
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data=r;
	temp->next=start;
	start = temp;
	return start;
}
//insert at end of the link list
struct node* insertEnd(struct node* start, int r){
	struct node *temp, *ptr;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = r;
	temp->next = NULL;
	if(start == NULL){
		start = temp;}
	else{
		ptr = start;
		while(ptr->next!= NULL){
			ptr=ptr->next;
		}
		ptr->next = start;
	}
	return start;
}
//insert after the given node in the link list
void insertGiven(struct node* start, int r, int sr){
	struct node *temp, *ptr;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data=r;
	temp->next=NULL;
	if(start == NULL)
		printf("List not exit!!!");
	else{
		ptr = start;
		while(ptr!=NULL && ptr->data != sr){
			ptr = ptr->next;
		}
		if(ptr == NULL){
			printf("Element not exist!!!!");
		}
		else{
			temp->next = ptr->next;
			ptr->next = temp;

		}
	}
}

//display the complete link list
void display(struct node *start){
	struct node *ptr;
	ptr = start;
	printf("List is: ");
	while(ptr!=NULL){
		printf("%d->",ptr->data);
		ptr=ptr->next;
	}
}

//delete the node from starting of the list
struct node *deleteStart(struct node *start){
	struct node *ptr;
	if(start == NULL){
		printf("List not exist!!!");
	}
	else{
		ptr =start;
		start = start->next;
		free(ptr);
	}
	return start;
}

//delete the node from the end of the link list
struct node *deleteEnd(struct node *start){
	struct node *ptr, *pptr;
	if(start == NULL)
		printf("List is not exist!!!");
	else if(start->next == NULL){
		ptr =start;
		start = start->next;
		free(ptr);
	}
	else{
		ptr = start;
		while(ptr->next != NULL ){
			pptr = ptr;
			ptr = ptr->next;
		}
		ptr->next = NULL;
		free(ptr);

	}
	return start;
}

//delete the node after the given node in the link list
struct node *deleteGiven(struct node *start, int r){
	struct node *ptr, *pptr;
	if(start == NULL)
		printf("List not exist!!!!");
	else if(start->data == r){
		ptr = start;
		start = start->next;
		free(ptr);
	}
	else{
		ptr = start;
		while(ptr!= NULL && ptr ->data != r){
			pptr = ptr;
			ptr= ptr->next;
		}
		if(ptr == NULL)
			printf("item not exist!!!");
		else{
			pptr->next = ptr->next;
			free(ptr);
		}
	}
	return start;
}

//search the particular node in the link list
struct node *searchList(struct node *start, int r){
	struct node *ptr = NULL;
	ptr = start;
	while(ptr!= NULL && ptr->data != r){
		ptr = ptr->next;
	}
	return start;
}

//display the reverse link list
void reverseLinkList(struct node* start){
	if(start ==  NULL){
		//for reaching to the end of the link list
		return;
	}
	//now recursively call the next node of the link list
	ReverseLinkList(start->next);

	//now print the node of the link list
	printf("%d->",start->roll);	
}
/*
void insertNode(struct node **head, int data, int position){
	struct Node *newNode;
	newNode = (struct Node *)malloc(sizeof(struct Node));
}
*/
