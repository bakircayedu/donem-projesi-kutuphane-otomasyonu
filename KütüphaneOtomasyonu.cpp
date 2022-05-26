#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<stdbool.h>

void kayitEkleme();
void kayitSilme();
void kayitListeleme();
void kayitGuncelleme();
void kayitArama();
void yazarBilgileri();

FILE *fp, *fg;

struct kitap {
	int kitap_kodu;
	char *kitap_adi;
	int sayfa_sayisi;	
	int basim_yili;
	int uygun_kitap_durum;
} mainKitap, tempKitap;

struct yazar{
	int yazar_kodu;
	char *yazar_adi;
	char *yazar_soyadi;
} mainYazar, tempYazar;

struct kitaplarin_yazarlari{
	int yazar_kodu;
	int kitap_kodu;
}x,y;

void yazarBilgileri(){
	fp=fopen("KitapKayit.txt","r");
	
	while (fscanf (fp, "%d %s %s %s %d %d %d %d", &mainKitap.kitap_kodu ,mainKitap.kitap_adi , mainYazar.yazar_adi, mainYazar.yazar_soyadi, &mainYazar.yazar_kodu, &mainKitap.sayfa_sayisi, &mainKitap.basim_yili, &mainKitap.uygun_kitap_durum) !=EOF){

		if(mainKitap.uygun_kitap_durum==1){
			printf("Yazar adi soyadi:%s %s\n yazarin kodu:%d kitabinin kodu:%d\n",mainYazar.yazar_adi, mainYazar.yazar_soyadi, mainYazar.yazar_kodu, mainKitap.kitap_kodu);
			}
		}
		fclose(fp);
}
void kayitEkleme(){
	
	
	fp=fopen("KitapKayit.txt", "r");
	
	printf("kitabin kodunu giriniz: \n\n ");
	scanf("%d" , &mainKitap.kitap_kodu);
	
	
		while (fscanf (fp, "%d %s %s %s %d %d %d %d", &tempKitap.kitap_kodu ,tempKitap.kitap_adi , tempYazar.yazar_adi, tempYazar.yazar_soyadi, &tempYazar.yazar_kodu, &tempKitap.sayfa_sayisi, &tempKitap.basim_yili, &tempKitap.uygun_kitap_durum) != EOF)
	{
		
		if (mainKitap.kitap_kodu==tempKitap.kitap_kodu && tempKitap.uygun_kitap_durum==1)
		{
			printf("Bu kitap zaten kayitlidir! \n\n ");
			fclose(fp);
			return;
		}
	}
	fclose(fp);
	
	fp=fopen("KitapKayit.txt", "r");
	
	if((fg=fopen("gecici.txt", "w+"))==NULL){
			printf("dosya acilamadi!\n");
			exit(1);
	}
	
	printf("Kitabin adini giriniz: Sayfa sayisini ve basim yilini giriniz:\n ");
	scanf("%s %d %d", mainKitap.kitap_adi, &mainKitap.sayfa_sayisi, &mainKitap.basim_yili);
	
	printf("Kitabin yazarinin adini soyadini ve yazar kodunu giriniz: ");
	scanf("%s %s %d", mainYazar.yazar_adi, mainYazar.yazar_soyadi, &mainYazar.yazar_kodu);
	
	fprintf(fg, "%d %s %s %s %d %d %d 1\n" , mainKitap.kitap_kodu , mainKitap.kitap_adi, mainYazar.yazar_adi, mainYazar.yazar_soyadi, mainYazar.yazar_kodu, mainKitap.sayfa_sayisi, mainKitap.basim_yili);
	
	while (fscanf (fp, "%d %s %s %s %d %d %d %d", &tempKitap.kitap_kodu ,tempKitap.kitap_adi , tempYazar.yazar_adi, tempYazar.yazar_soyadi, &tempYazar.yazar_kodu, &tempKitap.sayfa_sayisi, &tempKitap.basim_yili, &tempKitap.uygun_kitap_durum) != EOF)
	{
		fprintf(fg, "%d %s %s %s %d %d %d %d\n", tempKitap.kitap_kodu ,tempKitap.kitap_adi , tempYazar.yazar_adi, tempYazar.yazar_soyadi, tempYazar.yazar_kodu, tempKitap.sayfa_sayisi, tempKitap.basim_yili, tempKitap.uygun_kitap_durum);
	}
		
	printf("\n\n");
	printf("Kayit islemi basarili :) \n\n");
	fclose(fp);
	fclose(fg);
	remove ("KitapKayit.txt");
	rename ("gecici.txt", "KitapKayit.txt");	
}

void kayitListeleme(){
	fp=fopen("KitapKayit.txt", "r");
	
	while (fscanf (fp, "%d %s %s %s %d %d %d %d", &mainKitap.kitap_kodu ,mainKitap.kitap_adi , mainYazar.yazar_adi, mainYazar.yazar_soyadi,&mainYazar.yazar_kodu, &mainKitap.sayfa_sayisi, &mainKitap.basim_yili, &mainKitap.uygun_kitap_durum) !=EOF){
		
		if(mainKitap.uygun_kitap_durum==0)continue;
		printf(" kitabin kodu:   %d\n kitabin adi:   %s\n yazar adi soyadi:   %s %s\n yazar kodu:   %d\n sayfa sayisi:   %d basim yili:   %d\n uygunluk durumu(1/0)=   %d\n\n", mainKitap.kitap_kodu, mainKitap.kitap_adi, mainYazar.yazar_adi, mainYazar.yazar_soyadi, mainYazar.yazar_kodu, mainKitap.sayfa_sayisi, mainKitap.basim_yili, mainKitap.uygun_kitap_durum);
		
		/*else
			printf("liste bos kayit etklemek icin 1e basiniz\n");*/
		
	}
	fclose(fp);
		
}

void kayitSilme(){
 	bool kayitVarmi = false;
 	int sayi;
 
	if((fp=fopen("KitapKayit.txt", "r"))==NULL){
			printf("dosya acilamadi!\n");
			exit(1);
	}
	if((fg=fopen("gecici.txt", "w+"))==NULL){
			printf("dosya acilamadi!\n");
			exit(1);
	}
	
 	printf ("Silmek istediginiz kitabin kodunu girin: \n");
 	scanf("%d", &sayi);
 	
	while (fscanf (fp, "%d %s %s %s %d %d %d %d", &mainKitap.kitap_kodu ,mainKitap.kitap_adi , mainYazar.yazar_adi, mainYazar.yazar_soyadi, &mainYazar.yazar_kodu, &mainKitap.sayfa_sayisi, &mainKitap.basim_yili, &mainKitap.uygun_kitap_durum) != EOF)
	{
		if(sayi == mainKitap.kitap_kodu && mainKitap.uygun_kitap_durum == 1)
		{
			kayitVarmi = true;
			fprintf(fg, "%d %s %s %s %d %d %d 0\n" , mainKitap.kitap_kodu , mainKitap.kitap_adi, mainYazar.yazar_adi, mainYazar.yazar_soyadi, mainYazar.yazar_kodu, mainKitap.sayfa_sayisi, mainKitap.basim_yili);
		}
		else{
   			fprintf(fg, "%d %s %s %s %d %d %d %d\n" , mainKitap.kitap_kodu , mainKitap.kitap_adi, mainYazar.yazar_adi, mainYazar.yazar_soyadi, mainYazar.yazar_kodu, mainKitap.sayfa_sayisi, mainKitap.basim_yili, mainKitap.uygun_kitap_durum);
   		}
   }
   
	if (kayitVarmi==false){
		printf("Aradiginiz kayit bulunamadi.");
	}
	printf("kayit silindi\n");
		
fclose(fp);
fclose(fg);
remove("KitapKayit.txt");
rename("gecici.txt","KitapKayit.txt");
}

void kayitArama(){
	
  	int aranansayi;
 	bool bulundumu=false;
  	fp=fopen("KitapKayit.txt","r");
  	
  	printf("Aranan kitabin kodunu giriniz:\n");
  	scanf("%d", &aranansayi);
  	
	while (fscanf (fp, "%d %s %s %s %d %d %d %d", &mainKitap.kitap_kodu ,mainKitap.kitap_adi , mainYazar.yazar_adi, mainYazar.yazar_soyadi, &mainYazar.yazar_kodu, &mainKitap.sayfa_sayisi, &mainKitap.basim_yili, &mainKitap.uygun_kitap_durum) != EOF)
  	{
    if(aranansayi == mainKitap.kitap_kodu && mainKitap.uygun_kitap_durum ==1){
    	bulundumu=true;
    	printf(" kitabin kodu:   %d\n kitabin adi:   %s\n yazar adi soyadi:   %s %s\n yazar kodu:   %d\n sayfa sayisi:   %d basim yili:   %d\n uygunluk durumu(1/0)=   %d\n\n", mainKitap.kitap_kodu, mainKitap.kitap_adi, mainYazar.yazar_adi, mainYazar.yazar_soyadi, mainYazar.yazar_kodu, mainKitap.sayfa_sayisi, mainKitap.basim_yili, mainKitap.uygun_kitap_durum);
    	return;
		}
	}
  	
  	bulundumu=false;
    printf("Aradiginiz Kayit Yok .. !!\n");
    	
  fclose(fp);
}

void kayitGuncelleme(){
	int sayi;
	if((fp=fopen("KitapKayit.txt", "r"))==NULL){
			printf("dosya acilamadi!\n");
			exit(1);
	}
	if((fg=fopen("gecici.txt", "w+"))==NULL){
			printf("dosya acilamadi!\n");
			exit(1);
	}
	
	printf("Guncellemek istediginiz kitabin kayit numarasini yaziniz:\n");
	scanf("%d", &sayi);
	
	printf("kitabin yeni adini giriniz\n");
	scanf("%s", tempKitap.kitap_adi);
	
	printf("kitabin yazarin adi ve soyadini yeniden giriniz\n");
	scanf("%s %s", tempYazar.yazar_adi, tempYazar.yazar_soyadi);
	
	printf("kitabin sayfa sayisini ve basim yilini yeniden giriniz.\n");
	scanf("%d %d", &tempKitap.sayfa_sayisi, &tempKitap.basim_yili);
	
	int durum=1;
	
	while (fscanf (fp, "%d %s %s %s %d %d %d %d", &mainKitap.kitap_kodu ,mainKitap.kitap_adi , mainYazar.yazar_adi, mainYazar.yazar_soyadi, &mainYazar.yazar_kodu, &mainKitap.sayfa_sayisi, &mainKitap.basim_yili, &mainKitap.uygun_kitap_durum) != EOF)
	{
		if(mainKitap.kitap_kodu == sayi && mainKitap.uygun_kitap_durum == 1)
		continue;
		
		if(strcmp(tempKitap.kitap_adi,mainKitap.kitap_adi)<0 && durum ==1){
			fprintf(fg,"%d %s %s %s %d %d %d 1\n", sayi, tempKitap.kitap_adi, tempYazar.yazar_adi, tempYazar.yazar_soyadi, mainYazar.yazar_kodu, tempKitap.sayfa_sayisi, tempKitap.basim_yili);
			durum=0;
		}
		fprintf(fg,"%d %s %s %s %d %d %d %d\n",mainKitap.kitap_kodu, mainKitap.kitap_adi, mainYazar.yazar_adi, mainYazar.yazar_soyadi, mainYazar.yazar_kodu, mainKitap.sayfa_sayisi, mainKitap.basim_yili, mainKitap.uygun_kitap_durum);
	}
	if(durum==1)
	{
		fprintf(fg,"%d %s %s %s %d %d %d 1\n", sayi, tempKitap.kitap_adi, tempYazar.yazar_adi, tempYazar.yazar_soyadi, mainYazar.yazar_kodu, tempKitap.sayfa_sayisi, tempKitap.basim_yili);
		durum=0;
	}
	printf("\n\n");
	printf("Kayit Guncellendi\n\n");
	fclose(fp);
	fclose(fg);
	remove("KitapKayit.txt");
	rename("gecici.txt","KitapKayit.txt");
}

int main(){
	mainKitap.kitap_adi=(char*)malloc(sizeof(mainKitap.kitap_adi));
	tempKitap.kitap_adi=(char*)malloc(sizeof(tempKitap.kitap_adi));
	
	mainYazar.yazar_adi=(char*)malloc(sizeof(mainYazar.yazar_adi));
	tempYazar.yazar_adi=(char*)malloc(sizeof(tempYazar.yazar_adi));

	mainYazar.yazar_soyadi=(char*)malloc(sizeof(mainYazar.yazar_soyadi));
	tempYazar.yazar_soyadi=(char*)malloc(sizeof(tempYazar.yazar_soyadi));
	
	char secim, tus;
do{

	printf("Kutuphane otomasyonuna Hosgeldiniz!\n");
	printf("Yapmak istediginiz islemi seciniz..\n ");
	printf("****************************** \n");

	printf("1-Kayit ekleme islemleri\n");
	printf("2-Kayit silme islemleri\n");
	printf("3-Kayit guncelleme islemleri \n");
	printf("4-Kayit listeleme islemleri\n");
	printf("5-Kayit arama islemleri\n");
	printf("6-Yazar bilgileri arama\n");
	printf("7-Cikis\n");
	printf("****************************** \n\n");
    
    secim=getch();
    
    switch(secim)
    {
    	case '1': kayitEkleme(); break;
    	case '2': kayitSilme(); break;
    	case '3': kayitGuncelleme (); break;
     	case '4': kayitListeleme(); break;
     	case '5': kayitArama(); break;
     	case '6': yazarBilgileri(); break;
    	case '7': exit(1);
    	default : printf("Lutfen 1 ile 7 arasinda secim yapiniz!!\n"); break;
	}
	
    printf("Menuye donmek icin herhangi bir tusa basiniz! \n\n\n");
    tus=getch();
    
    }while(tus);
    
  	return 0;
	}
