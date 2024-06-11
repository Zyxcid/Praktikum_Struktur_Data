#include<stdio.h>
#define ukuran 5

void enqueue(int);
void dequeue();
void tampilkan();

int items[ukuran], front = -1, rear = -1;
int main(){
	dequeue();
	enqueue(7);
	enqueue(8);
	enqueue(3);
	enqueue(4);
	enqueue(9);
	enqueue(6);
	tampilkan();
	dequeue();
	tampilkan();
	return 0;	
}

void enqueue(int value){
	if(rear == ukuran-1){
		printf("\nQueue sudah penuh!");
	}else{
		if(front == -1){
			front = 0;
		}
		rear++;
		items[rear] = value;
		printf("\nNilai ditambahkan -> %d ", value);
	}
}

void dequeue(){
	if(front == -1){
		printf("Queue kosong!!");
	}else{
		printf("\nNilai dihapus adalah : %d ", items[front]);
		front++;
		if(front > rear){
			front = rear = -1;
		}
	}
}

void tampilkan(){
	if(rear == -1){
		printf("\nQueue kosong!!!");
	}else{
		int i;
		printf("\nElemen pada queue adalah:\n");
		for(i=front; i <= rear; i++){
			printf("%d\t", items[i]);
		}
	}
}
