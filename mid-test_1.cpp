/*
Nama Program : UTS
Nama         : Hana Meilina Fauziyyah
NPM          : 140810180012
Tanggal buat : 24 April 2019
Deskripsi    : Program memesan makanan
******************************************/

#include <iostream>
#include <conio.h>
using namespace std;

struct restoran{
    char pemesan[20];
    char pesanan;
    int jumlah;
    restoran* next;
};

typedef restoran* pointer;
typedef pointer List;

void createList(List& First);
void createElmt(pointer& pBaru);
void pesan(List& First, pointer pBaru);
void insertFirst(List& First, pointer pBaru);
void deleteFirst(List& First, pointer& pHapus);
void traversal(List First);

main(){
    pointer p;
	List Pesanan;
	int pil,n;
	char loop='Y';
    do{
        cout<<"1. Tampilkan Menu "<<endl;
        cout<<"2. Pesan "<<endl;
        cout<<"3. Hapus pesanan di awal "<<endl;
        cout<<"4. Tampilkan pesanan "<<endl;
        do{
            cin>>pil;
        }
        while(pil<1 || pil>5);
        switch(pil){
        case 1:
            cout<<"Menu : "<<endl;
            cout<<"1. Omlet Rendang   Rp8000"<<endl;
            cout<<"2. Nasi Gila       Rp10000"<<endl;
            cout<<"3. Chicken Katsu   Rp12000"<<endl;
            cout<<"4. Ayam Geprek     Rp10000"<<endl;
            cout<<"5. Nasi Goreng     Rp8000"<<endl;
            getch();
            break;
        case 2:
            createElmt(p);
            pesan(Pesanan,p);
            insertFirst(Pesanan,p);
            cout<<"Pesanan berhasil dibuat";
            getch();
            break;
        case 3:
            deleteFirst(Pesanan,p);
            cout<<"Pesanan berhasil dihapus";
            getch();
            break;
        case 4:
            traversal(Pesanan);
            cout<<"Kembali ke menu? (Y/N) ";
            do{
                cin>>loop;
                }while(loop!='Y' && loop!='y' && loop!='N' && loop!='n');
            break;
        case 5:
			loop='s';
            break;
        }
		}while(loop=='Y' || loop=='y');
	while(loop=='s');
}

void createList(List& First){
	First=NULL;
}

void createElmt(pointer& pBaru){
	pBaru=new restoran;
	cout<<"Nama Pemesan : ";
	cin>>pBaru->pemesan;
	pBaru->next=NULL;
}

void pesan(List& First, pointer pBaru){
    pBaru=new restoran;
    cout<<"Masukkan jumlah pesanan setiap menu : "<<endl;
	cout<<"1. Omlet Rendang   Rp8000"<<endl;
	cin>>pBaru->jumlah;
    cout<<"2. Nasi Gila       Rp10000"<<endl;
    cin>>pBaru->jumlah;
    cout<<"3. Chicken Katsu   Rp12000"<<endl;
    cin>>pBaru->jumlah;
    cout<<"4. Ayam Geprek     Rp10000"<<endl;
    cin>>pBaru->jumlah;
    cout<<"5. Nasi Goreng     Rp8000"<<endl;
    cin>>pBaru->jumlah;
    pBaru->next=NULL;
}

void insertFirst(List& First, pointer pBaru){
	if(First==NULL){
		First=pBaru;
	}else{
		pBaru->next=First;
		First=pBaru;
	}
}

void deleteFirst(List& First, pointer& pHapus){
	if(First==NULL){
		pHapus=NULL;
		cout<<"List kosong, tidak ada yang dihapus"<<endl;
	}else if(First->next==NULL){
		pHapus=First;
		First=NULL;
	}else{
		pHapus=First;
		First=First->next;
		pHapus->next=NULL;
	}
}

void traversal(List First){
    List restoran;
	pointer pBantu, pBaru;
	int i=1;
	if(First==NULL){
		cout<<"List Kosong"<<endl;
	}else{
		pBantu=First;
		do{
			cout<<"Pesanan ke-"<<i<<endl;
			cout<<"Nama Pemesan : "<<pBantu->pemesan<<endl;
			cout<<"Pesanan : "<<pesan(restoran, pBaru);
			pBantu=pBantu->next;
			i++;
		}while(pBantu!=NULL);
	}
	cout<<endl;
}
