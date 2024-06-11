#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct gudang
{
	char nama_barang[50];
	int harga;
	struct gudang *next;
	struct gudang *prev;
};

void cetak(struct gudang *head)
{
	struct gudang *temp = head;
	printf("List elements are - \n");
	while (temp != NULL)
	{
		printf("%s = %d --->", temp->nama_barang, temp->harga);
		temp = temp->next;
	}
}

int main()
{
	struct gudang *head;
	struct gudang *one = NULL;
	struct gudang *two = NULL;
	struct gudang *three = NULL;

	// Alokasikan memori
	one = (struct gudang *)malloc(sizeof(struct gudang));
	two = (struct gudang *)malloc(sizeof(struct gudang));
	three = (struct gudang *)malloc(sizeof(struct gudang));

	// masukkan value
	one->harga = 1000;
	strcpy(one->nama_barang, "obat nyamuk");
	two->harga = 5000;
	strcpy(two->nama_barang, "Gula 1 kilo");
	three->harga = 50000;
	strcpy(three->nama_barang, "Minyak Goreng");

	// hubungkan nodes
	one->next = two;
	one->prev = NULL;
	two->next = three;
	two->prev = one;
	three->next = NULL;
	three->prev = two;

	// simpan alamat dari node pertama ke head
	head = one;
	cetak(head);
}
