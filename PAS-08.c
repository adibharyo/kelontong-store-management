#include <stdio.h>
#include <stdlib.h>//standard library
#include <string.h>//untuk strcmp dan strcopy
#include <conio.h>//library buat getch

//Raden Muhammad Adib Haryo Sulistyo - 2006483012
//Hendrich Herdanto Mulia - 2006579775

typedef struct {
	char id[10];
	char nama[20];
	int  jumlah;
	int harga;
}infoProd;

void printProd (infoProd prod[]);//Function untuk print daftar stok
void tambahProd (infoProd prod[]);//Function untuk input produk
void editProd (infoProd prod[]);//Function untuk mengubah data produk
void delProd (infoProd prod[]);//Function untuk menghapus produk
void jual(infoProd prod[], long *penjualan);//Function untuk penjualan produk
void penghasilan(long penjualan);//Function untuk melihat hasil penjualan
void input (int *p);//Funtion untuk error handling input integer
void keluar(); //Funtion untuk keluar program

int main()//Menu Utama
{
	int pilihmenu;
	int i, x;
	long penjualan = 0;
	infoProd prod[30];
	
	for (i = 0; i < 30; i++){
		strcpy(prod[i].id,"");
		strcpy(prod[i].nama,"");
		prod[i].harga = 0;
		prod[i].jumlah = 0;
	}
	system("cls");
	do {
		printf("=======================================\n");
		printf("      STOCK MANAGEMENT PROGRAM\n");
		printf("=======================================\n");
		printf("\nTekan:");
		printf("\n 1.) Input Stock");
		printf("\n 2.) Edit Stock");
		printf("\n 3.) Delete Stock");
		printf("\n 4.) Print Stock");
		printf("\n 5.) Pembelian");
   		printf("\n 6.) Total keuntungan");
		printf("\n 7.) Exit the program\n");
		printf("\nPilihanmu --> ");
		scanf("%d", &pilihmenu);
		if (pilihmenu < 1 || pilihmenu > 6) {
            puts("Masukkan angka sesuai menu");
          }
		switch(pilihmenu) {
			case 1:
				tambahProd(prod);
				break;
			case 2:
        		editProd(prod);
				break;
			case 3:
				delProd(prod);
				break;
			case 4:
				printProd(prod);
				break;
			case 5:
				jual(prod,&penjualan);
				break;
			case 6:
        		penghasilan(penjualan);
				break;
		}
	}
	while (pilihmenu != 7);
		system("cls");
      	printf("Thankyou for using this program");
	return 0;
}

void input(int * p) {
  do {
    scanf("%d", p);
    if ( * p < 0)
      printf("Input tidak boleh negatif\n");
  } while ( * p < 0);
}

void tambahProd(infoProd prod[]){
	int sentinel;
	int i, x;
	system("cls");
	
	printf("\nBerapa produk yang ingin anda tambahkan? ");
	scanf("%d", &sentinel);
	printf("=======================================\n");
	for (x = 0; x < 30; x++){
		if (!strcmp(prod[x].id,"")){
			for (i = x; i < x + sentinel; i++){
				printf("Produk ke-%d\n", i+1);
				printf("Kode Produk: ");
				scanf(" %255[^\n]s", prod[i].id);
				fflush(stdin);
				printf("Nama Produk: ");
				scanf(" %255[^\n]s", prod[i].nama);
				fflush(stdin);
				printf("Jumlah Produk : ");
				input(&prod[i].jumlah);
				printf("Harga Produk: ");
				input(&prod[i].harga);
				printf("=======================================\n");
			}
			break;
		}
	}
	printf("\nPenambahan Produk Berhasil!\n");
	keluar();
}

void printProd(infoProd prod[]){
	int i;
	system("cls");

	printf("---------------------------------------------------------------------------------\n");
	printf("                                    STOK BARANG\n");
    printf("---------------------------------------------------------------------------------\n");
    printf("No.   |   Kode   |   Nama Barang  |    Jumlah Barang    |      Harga Barang     |\n");
    printf("---------------------------------------------------------------------------------\n");
	for (i = 0; i < 30; i++){
		if(strcmp(prod[i].id,"")){
			printf("%d\t  ", i+1);
			printf("%s\t  ", prod[i].id);
			printf("\t%s\t", prod[i].nama);
			printf("\t%d\t", prod[i].jumlah);
			printf("\t\t%d\n", prod[i].harga);
		}
	}
	keluar();
}

void editProd(infoProd prod[]){
	int i, j, pilih;
	char temp[10];
	system("cls");
	
	printf("Masukkan kode produk yang ingin anda ubah: ");
	scanf(" %9[^\n]s", temp);
	fflush(stdin);
	for (i = 0; i < 30; i++){
		if (!strcmp(temp,prod[i].id)){
			printf("Produk ditemukan!\n");
			printf("\nPilih yang ingin anda ubah");
			printf("\n1. Kode Produk ");
          	printf("\n2. Nama Produk ");
          	printf("\n3. Jumlah Produk");
          	printf("\n4. Harga Produk");
          	printf("\n->");
          	input(&pilih);
          	switch(pilih){
          		case 1:
          			printf("Masukkan kode produk baru: ");
					scanf(" %255[^\n]s", prod[i].id);
					fflush(stdin);
          			break;
          		case 2:
          			printf("Masukkan nama produk baru: ");
					scanf(" %255[^\n]s", prod[i].nama);
					fflush(stdin);	
          			break;
          		case 3:
          			printf("Masukkan jumlah produk baru : ");
					input(&prod[i].jumlah);
          			break;
          		case 4:
          			printf("Masukkan harga produk baru: ");
					input(&prod[i].harga);
          			break;
          		default:
          			printf("Pilih angka sesuai menu\n");
          			break;
			  }
			printf("Produk berhasil diubah!\n");
			break;
		}
	}
	if (i == 30)
		printf("ID tidak ditemukan!\n");
	keluar();
}

void delProd(infoProd prod[]){
int i, j;
  char kode[50];
  system("cls");

  printf("Masukkan kode produk yang ingin anda hapus: ");
  scanf(" %49[^\n]s", kode);
  
  for (i = 0; i < 30; i++){
    if(!strcmp(prod[i].id, kode)){
		for (j = i; j < 29; j++){
	  		prod[j]= prod[j+1];
  			}
		strcpy(prod[29].id,"");
		strcpy(prod[29].nama,"");
	  	prod[29].harga = 0;
	  	prod[29].jumlah = 0;
	  	
      		printf("Produk berhasil dihapus!\n\n");
	  		break;
    		}
	}
	keluar();
}

void jual(infoProd prod[], long *penjualan){
	int i;
	char temp[10];
	unsigned int beli;
	system("cls");
	
	printf("Masukkan kode produk yang ingin anda jual: ");
	scanf(" %9[^\n]s", temp);
	fflush(stdin);
	for (i = 0; i < 30; i++){
		if (!strcmp(temp,prod[i].id)){
			printf("Produk ditemukan!\n");
			printf("ID: %s\n", prod[i].id);
			printf("Nama: %s\n", prod[i].nama);
			printf("Jumlah: %d\n", prod[i].jumlah);
			printf("Harga: %d\n", prod[i].harga);
			do{
				printf("Masukkan jumlah barang yang ingin terjual: ");
				scanf("%d",&beli);
				if (beli > prod[i].jumlah){
					printf("Jumlah penjualan lebih banyak daripada jumlah barang. Tidak boleh!\n");
				}
			}while(beli > prod[i].jumlah);

			*penjualan = beli * prod[i].harga;
			prod[i].jumlah -= beli;
			printf("Penjualan berhasil!\n");
			break;
		}
		
	}
	if (i == 30)
		printf("produk tidak ditemukan!\n");
	keluar();
}

void penghasilan(long penjualan){
	
	printf("Hasil penjualan yang didapatkan adalah: %ld\n", penjualan);
	keluar();
}

void keluar(){
	printf("\t\t\tPress any key to continue.....");
	getch();
  	system("cls");
}
