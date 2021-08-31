#include <stdio.h>
#include <stdlib.h>

struct Queue{
	int data;
	struct Queue*ptr;
};

int size = 0; // initialized globally to use in different functions

struct Queue*front = NULL;
struct Queue*back = NULL;

int isempty(){
	return ( size == 0 );
}
void peek(){
	if( isempty()){
		printf("\nThe queue is empty\n\n");
		return;
	}else {
		printf("\nThe first element is %d\n\n", front-> data) ;
	}
}
void Get_front(){
	if(isempty()){
		printf("\nThe queue is empty\n\n");
	}else{
		printf("\nThe first element is %d\n\n",front-> data);
	}
}

void Get_back(){
	if(isempty()){
		printf("\nThe queue is empty\n\n");
	}else{
		printf("\nThe last element is %d\n\n",back-> data);
	}
}

void enqueue(int num){
	struct Queue* element = (struct Queue*)malloc(sizeof(struct Queue));
	element -> data = num;
	element -> ptr = NULL;
	if (isempty()){
		front = element;
		back = element;
		size ++;
	}else{
		back -> ptr = element;
		back = element;
		size ++;
	}	
	printf("\nThe element was added to the queue\n\n");
	}

void dequeue(){
	if(isempty()){
		printf("\nThe queue is empty\n\n");
	}else if(size == 1){
		front = back = NULL;
		size--;
	}else{
		front = front-> ptr;
		size--;
	}
	printf("\nThe first element was dequeued\n\n");
}
int Menu_options(){
	int choice;
	printf("[1] to enqueue an element\n[2] to dequeue an element\n[3] to peek on the first element\n[4] to get the first element\n[5] to get the last element\n[6] to exit\n");
	scanf("%d", &choice);
	return choice;
}

int main() {
	int num, choice;
	choice = Menu_options();
	while (choice != 6){
		if (choice == 1){
			printf ("\nenter the number you want to enqueue: ");
			scanf("%d", &num);
			enqueue(num);
		}else if(choice == 2){
			dequeue();
		}else if(choice == 3){
			peek();
		}else if(choice == 4){
			Get_front();
		}else if(choice == 5){
			Get_back();
		}
		choice = Menu_options();
	}
	return 0;
}
