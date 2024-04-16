#include<stdio.h>
#define ukuran 5
int deque[ukuran];
int f = -1, r = -1;

// Fungsi untuk menambahkan nilai pada bagian depan
void insert_front(int x){
	if((f==0 && r==ukuran-1) || (f==r+1)){
		printf("Overflow");
	}else if((f==-1) && (r==-1)){
		f=r=0;
		deque[f] = x;
	}else if(f==0){
		f=ukuran-1;
		deque[f] = x;
	}else{
		f = f-1;
		deque[f] = x;
	}
}

// Fungsi untuk menambahkan nilai pada bagian belakang
void insert_rear(int x){
	if((f==0 && r+1==ukuran) || (f==r+1)){
		printf("Overflow");
	}else if((f==-1) && (r==-1)){
		r=0;
		deque[r] = x;
	}else if(r==ukuran-1){
		r=0;
		deque[r] = x;
	}else{
		r++;
		deque[r] = x;
	}
}

// Menampilkan semua nilai yang di deque
void display(){
	int i=f;
	printf("\nElemen pada deque adalah: ");
	
	while(i != r){
		printf("%d ", deque[i]);
		i=(i+1)%ukuran;
	}
	printf("%d", deque[r]);
}

// getfront function retrieves the first value of the deque	
void getfront(){
	if((f==-1) && (r==-1)){
		printf("Deque kosong");
	}
	else{
		printf("\nNilai pada elemen bagian depan adalah %d ", deque[f]);
	}
}

// fungsi getrear digunakan untuk mendapatkan nilai paling belakang pada deque 
void getrear(){
	if((f==-1) && (r==-1)){
		printf("Deque kosong");
	}else{
		printf("\nNilai pada elemen belakang adalah %d", deque[r]);
	}
}

// fungsi delete_front() untuk menghapus elemen dari depan
void delete_front(){
	if((f==-1) && (r==-1)){
		printf("Deque kosong");
	}else if(f==r){
		printf("\nElemen yang dihapus adalah %d", deque[f]);
		f = -1;
		r = -1;
	}else if(f==ukuran-1){
		printf("\nElemen yang dihapus adalah %d ", deque[f]);
	}else{
		printf("\nElemen yang dihapus adalah %d ", deque[f]);
		f = f+1;
	}
}

// fungsi delete_rear() untuk menghapus elemen dari belakang
void delete_rear(){
	if((f==-1) && (r==-1)){
		printf("Deque kosong");
	}
	else if(f==r){
		printf("\nElemen yang dihapus adalah %d", deque[r]);
		f = -1;
		r = -1;
	}else if(r==0){
		printf("\nElemen yang dihapus adalah %d", deque[r]);
		r=ukuran-1;
	}else{
		printf("\nElemen yang dihapus adalah %d", deque[r]);
		r--;
	}
}

int main(){
	
	insert_front(20);
	insert_front(10);
	insert_rear(30);
	insert_rear(50);
	insert_rear(80);
	
	display(); // memanggil fungsi display untuk mendapatkan nilai yang di deque
	getfront(); // mendapatkan nilai pada bagian front-end
	getrear(); // mendapatkan nlai pada bagian rear-end

	delete_front();
	delete_rear();

	display(); // memanggil fungsi display untuk mendapatkan nilai yang ada di deque setelah penghapusan
	
	return 0;
}
