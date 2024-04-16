// Queue menggunakan prinsip Array
#include<stdio.h>
#include<stdlib.h>
#define ukuran 5
void tambah();
void hapus();
void display();
int front = -1, rear = -1;
int queue[ukuran];

int main(){
	int pilihan;
	while(pilihan != 4){
		printf("\n************************Main Menu**************************\n");
		printf("===============================================================");
		printf("\n1.Tambah semua elemen\n2.hapus sebuah elemen\n3.Tampilkan antrian\n4.Keluar\n");
		printf("Masukan pilihanmu ? ");
		scanf("%d", &pilihan);
		switch(pilihan){
			case 1:
				tambah();
				break;
			case 2:
				hapus();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("\nMasukan pilihan yang sesuai!\n");
		}
	}
}

void tambah(){
	int item;
	printf("\nSilahkan masukan elemen yang kamu inginkan :");
	scanf("%d", &item);
	if(rear == ukuran - 1){
		printf("\nOVERFLOW\n");
		return;
	}
	if(front == - 1 && rear == - 1){
		front = 0;
		rear = 0;
	}else{
		rear = rear + 1;
	}
	queue[rear] = item;
	printf("\nNilai berhasil ditambahkan ");
}

void hapus(){
	int item;
	if(front == -1 || front > rear){
		printf("\nUNDERFLOW\n");
		return;
	}else{
		item = queue[front];
		if(front == rear){
			front = -1;
			rear = -1;
		}else{
			front = front + 1;
		}
		printf("\nNilai berhasil dihapus");
	}
}

void display(){
	int i;
	if(rear == -1){
		printf("\nAntrian kosong\n");
	}else{
		printf("\nMenampilkan nilai ......\n");
		for(i=front; i<=rear; i++){
			printf("%d -- ", queue[i]);
		}
	}
}
