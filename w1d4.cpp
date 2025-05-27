#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char ten[50];
	int tuoi;
	float diem;
}Sinhvien;


void nhap(Sinhvien *sv){
	printf("vui long nhap ten:");
	fflush(stdin);
	fgets(sv->ten,sizeof(sv->ten),stdin);
	sv->ten[strcspn(sv->ten,"\n")] = '\0';
	printf("vui long nhap tuoi: ");
	scanf("%d",&sv->tuoi);
	printf("vui long nhap diem");
	scanf("%f",&sv->diem);
	
}

void nhapds(Sinhvien *sv,int n){
	
	for(int i=0;i<n;i++){
		printf("vui long nhap thong tin cua sv thi [%d]:\n",i+1);
		nhap(&sv[i]);
	}
}

void in(Sinhvien *sv,int n){
	for(int i=0;i<n;i++){
		printf("thong tin sinh vien thu %d\n",i+1);
		printf("ten:%s\n",sv[i].ten);
		printf("tuoi:%d\n",sv[i].tuoi);
		printf("diem:%2.f\n",sv[i].diem);
		
	}
}

int main(){
	Sinhvien sv[100];
	int n;
	printf("vui long nhap so luong sv:");
	scanf("%d",&n);
	
	nhapds(sv,n);
	in(sv,n);
	
}
