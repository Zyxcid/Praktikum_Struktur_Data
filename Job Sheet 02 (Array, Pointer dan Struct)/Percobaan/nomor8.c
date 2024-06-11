// NAMA : Syahid Nurhidayatullah
// NIM  : 23343056

// ADT(Abstarct Data Type)
typedef int angka;
typedef char huruf;

int main()
{
    angka umur;
    huruf h;
    huruf nama[10];

    printf("Masukkan umur anda : ");
    scanf("%d", &umur);
    printf("Umur anda adalah %d", umur);
    printf("\nMasukkan huruf : ");
    h = getche();
    printf("\nHuruf anda %c", h);
    printf("\nMasukkan nama : ");
    scanf("%s", nama);
    printf("Nama anda %s", nama);
    getch();
}
