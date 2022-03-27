#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
void kayitEkleme();
void kayitSilme();
void kayitListeleme();
void kayitGuncelleme();


FILE *fp, *fg;

struct kitap {
	char kategori[20];
	int kitap_kodu;
	char kitap_adi[25];
	int sayfa_sayisi;	
	int basim_yili;
	int uygun_kitap_sayisi;
} x, gec;
struct yazar{
	int yazar_kodu;
	char yazar_adi[15];
	char yazar_soyadi[15];
	int dogum_yili;
	char ozgecmisi[50];
};
struct kitaplarin_yazarlari{
	int yazar_kodu;
	int kitap_kodu;
	int sira_no;
};


void kayitEkleme(){
	fp=fopen("KitapKayit.txt", "r");
	printf("kitabin kodunu giriniz: \n\n ");
	scanf("%d" , &x.kitap_kodu);
	
	
		while(fscanf(fp,"%d %s %d", &gec.kitap_kodu, gec.kitap_adi, &gec.uygun_kitap_sayisi)!=EOF);
	{
		
		if (x.kitap_kodu==gec.kitap_kodu && gec.uygun_kitap_sayisi==1)
		{
			printf("Bu kitap zaten kayitlidir! \n\n ");
			fclose(fp);
			return;
	
		}
	}
	fclose(fp);
	fp=fopen("KitapKayit.txt", "r+");
	fg=fopen("gecici.txt", "w+");
	
	printf("kitabin adini giriniz: ");
	scanf("%s", &x.kitap_adi);
	fprintf (fp, "%d %s\n" , x.kitap_kodu , x.kitap_adi );
	
	
		int durum=0;
	
	while (fscanf (fp, "%d %s %d", &gec.kitap_kodu ,gec.kitap_adi , &gec.uygun_kitap_sayisi) !=EOF)
	
           if(strcmp (x.kitap_adi , gec.kitap_adi) <0 && durum==0)
           {
               fprintf (fp, "%d %s var\n", x.kitap_kodu, x.kitap_adi);
               durum=1;
           }
           fprintf (fp, "%d %s %d\n",gec.kitap_kodu ,gec.kitap_adi , gec.uygun_kitap_sayisi);
           
           
	if (durum==0)
	{
   	fprintf(fg, "%d %s 1\n",x.kitap_kodu ,x.kitap_adi);
	}
	printf("\n\n");
	printf("Kayit islemi basarili :) \n\n");
	fclose(fp);
	fclose(fg);
	remove ("KitapKayit.txt");
	rename ("gecici.txt", "KitapKayit.txt");	
}












int main(){
	char secim, tus;
do{

	//menu
	printf("Kutuphane ototmasyonuna Hosgeldiniz!\n");
	printf("Yapmak istediginiz islemi seciniz..\n ");
	printf("****************************** \n");

	printf("1-Kayit ekleme islemleri\n");
	printf("2-Kayit silme islemleri\n");
	printf("3-Kayit guncelleme islemleri \n");
	printf("4-Kayit listeleme islemleri\n");
	
	printf("****************************** \n");
    //
    
    secim=getch();
    
    switch(secim)
    {
    	case '1': kayitEkleme(); break;
    	//case '2' : kayitSilme(); break;
    	//case '3' : kayitGuncelleme (); break;
     	//case '4' : kayitListeleme(); break;
    	
    	default : printf("Lutfen 1 ile 4 arasinda secim yapiniz!!\n"); break;
	}
	
    printf("Menuye donemk icin herhangi bir tusa basiniz! \n\n\n");
    tus=getch();
    
    }while(tus!=4);
    
    
    
  	return 0;
	}
