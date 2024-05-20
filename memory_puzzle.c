#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
const int c=48;
void yaz(int p[c],int r[c]){
	int i;
	for(i=1;i<=48;i++){
	if(p[r[i]]<10){
		printf("| %d|",p[r[i]]);
	}
	else  {
	
	printf("|%d|",p[r[i]]);
	}if(i%6==0){
		printf("\n");
	}
	}
}
void byaz(int b[c]){
	int i;
	for(i=1;i<=48;i++){
		if(b[i]<10){
		printf("| %d|",b[i]);
	}
	else  {
	printf("|%d|",b[i]);
	}
	if(i%6==0){printf("\n");
	}	
	}
}
void hata(){
	printf("PLEASE TRY ANOTHER NUMBER\n");
}
int yer(int row,int column){
	int t;
	t=column+(row-1)*6;
}
int bit(int b[c]){
	int i,ctrl;
	for(i=1;i<=48;i++){
		if(b[i]!=0){
			ctrl++;
		}
	}
	if(ctrl==48){
		return 1;
	}
	else {
		return 0;
	}
}
int main(void){
	int i,j,k,column,row,ctrl,t,r2,c2,t2;
	ctrl=0;
	int p[48],b[48],r[48];
	srand(time(NULL));
	for(i=1;i<=48;i++){
		if(i<=24){
		p[i]=i;}
		else{p[i]=i-24;
		}
		b[i]=0;
	}
	for(j=1;j<=48;j++){
		r[j]=1+rand()%48;
		for(k=j-1;k>=1;k--){
			if(r[k]==r[j]){
				j-=1;
			}
		}
	}
	while(ctrl==0){
   byaz(b);
   scanf("%d",&row);
   if(row<1 || row>8){
   	system("cls");
   	hata();
   }
   else {
   	scanf("%d",&column);
   	if(column<1 || column>6){
   		system("cls");
   		hata();
	   }
	   else {
	   	t=yer(row,column);
	   	if(b[t]!=0){
	   		system("cls");
	   		hata();
		   }
		   else {
		   
	   	b[t]=p[r[t]];
	   	system("cls");
	   	byaz(b);
	   	scanf("%d",&r2);
	   	if(r2<1 ||r2>8){
	   		b[t]=0;
	   		system("cls");
	   		hata();
		   }
		   else{ 
		   scanf("%d",&c2);
		   if(c2<1 || c2>6){
		   	b[t]=0;
		   	system("cls");
		   	hata();
		   }
		   else {
		   	t2=yer(r2,c2);
		   	if(b[t2]!=0){
		   		b[t]=0;
		   		system("cls");
		   		hata();
			   }
			   else{
		   	b[t2]=p[r[t2]];
		    system("cls");
		    byaz(b);
		    sleep(2);
		    system("cls");
		    if(b[t2]!=b[t]){
		    	b[t2]=0;
		    	b[t]=0;}
		    	ctrl=bit(b);
			}}
		   }
		   }
	   }
   }
   
}}
