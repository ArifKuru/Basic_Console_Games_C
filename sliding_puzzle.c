#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//yazdýrma fonksiyonu
void yaz(int p[],int size){
	int i,y;
	y=2;
	printf("    <1>   <2>   <3>   <4>   <5>\n");
	printf("--------------------------------\n");
	printf("<1>");
	for(i=1;i<=24;i++){
		if(p[i]<10){
			printf(" | %d| ",p[i]);
		}
		else {
		printf(" |%d| ",p[i]);}
			if(i%5==0){
			printf("\n<%d>",y);
			y+=1;
		}
	}
	if(p[25]<10){
		printf(" | %d| ",p[25]);
	}
	else {
	printf(" |%d| ",p[25]);}
	printf("\n--------------------------------\n");
}
//Alýnan sayýlarý index düzenine göre doðru kutuya eþleþtirme
int yenix(int y,int x){
	int yeni;
	if (y==1){
		yeni=x;
	}
	else if (y==2){
		yeni=x+5;
	}
	else if (y==3){
		yeni=x+10;
	}
	else if (y==4){
		yeni=x+15;
	}
	else {
		yeni=x+20;
	}
	return yeni;
}
//bosu belirleme fonksiyonu
int bosubul(int p[],int size){
	int i;
	for(i=1;i<=25;i++){
		if(p[i]==99){
			return i;
		}
	}
}
//bitirme fonskiyonu
int bitirme(int p[],int size){
	int i,ctrl;
	ctrl=0;
	for(i=1;i<=24;i++){
		if(p[i]==i){
			ctrl++;
		}
		}
	if(ctrl==24){
		return 1;
	}
	else { return 0;
	}
	}
int main(void){
	int i,j,k,y,x,ctrl,eskideger,yeni,bos;
    int p[25];
    //deðerlerý rasgele atama 1-24 arasý
	srand(time(NULL));
	for(i=1;i<=24;i++){
		p[i]=1+rand()%24;
		for(j=i-1;j>=1;j--){
			if(p[i]==p[j]){
				i-=1;
				break;
			}
		}
	}
	//bos
	p[25]=99;
	printf("WELCOME TO SLIDING PUZZLE GAME YOU SHOULD INPUT ROW NUMBER FIRST THEN COLUMN NUMBER THAT YOU WANT TO MOVE\n");
	yaz(p,25);
	//Oyunun ana döngüsü
	while(ctrl!=1){
		//bitip bitmedýðýne karar verme
		if(bitirme(p,25)==1){
			ctrl=1;
		}
		else {
		printf("Please enter row number:");
		scanf("%d",&y);
		if (y<1 || y>5){
			printf("Please try another number");
		}
		else {
		printf("Please enter column number:");
		scanf("%d",&x);
		if (x<1 || x>5){
			printf("Please try another number");
		}
		else {  
		yeni=yenix(y,x);
		bos=bosubul(p,25);
		//eðer hamle boþ olan kutunun çevresindeyse index düzenine göre
		if(yeni==bos+1 || yeni==bos-1 || yeni==bos+5 || yeni==bos-5){
			eskideger=p[yeni];
			p[yeni]=p[bos];
			p[bos]=eskideger;
			system("cls");
			yaz(p,25);
		}
		else {printf("please try another number");
		}
		
		
		}
		}
}}
}

