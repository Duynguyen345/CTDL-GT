#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
	char mssv[50];
	char name[50];
	float diem;
}SinhVien;



void nhap(SinhVien *sv){
	printf("vui long nhap mssv:\n");
	fflush(stdin);
	fgets(sv->mssv,sizeof(sv->mssv),stdin);
	sv->mssv[strcspn(sv->mssv,"\n")] = '\0';
	printf("vui long nhap ho va ten:\n");
	fflush(stdin);
	fgets(sv->name,sizeof(sv->name),stdin);
	sv->name[strcspn(sv->name,"\n")] = '\0';
	printf("vui long nhap diem:\n");
	
	scanf("%f",&sv->diem);
	
}

void nhapds(SinhVien *sv,int n){
	for(int i=0;i<n;i++){
		printf("vui long nhap thong tin sinh vien thu %d:\n",i+1);
		nhap(&sv[i]);
	}
}

void inds(SinhVien *sv,int n){
	for(int  i=0;i<n;i++){
		printf("thong tin sinh vien thu %d\n",i+1);
		printf("mssv:%s\n",sv[i].mssv);
		printf("ho&ten:%s\n",sv[i].name);
		printf("diem:%.2f\n",sv[i].diem);
		printf("\n---------------------\n");
	}
}

void xoa(SinhVien *sv,int *n,char *masv){
	int found =0;
	for(int i=0;i<*n;i++){
		if(strcmp(sv[i].mssv,masv) == 0){
			for(int j=i;j<*n-1;j++){
				sv[j] = sv[j+1];
			}
			(*n)--;
			found =1;
			return;
		}
	}
	if(!found)
	printf("khong tim thay!!!");
}

void sua(SinhVien *sv,int n,char *masv){
	int found = 0;
	for(int i=0;i<n;i++){
		if(strcmp(sv[i].mssv,masv) == 0){
			found =1;
			printf("nhap thong tin moi cho sinh vien co mssv:%s\n",sv[i].mssv);
			nhap(&sv[i]);
			
		}
	}
	if(!found) printf("khong tim thay sinh vien!!!");
}

void sapxep(SinhVien *sv,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(sv[i].diem>sv[j].diem){
				SinhVien tmp = sv[i];
				sv[i] = sv[j];
				sv[j] = tmp;
			}
		}
	}
}

void tiemkiem(SinhVien *sv,int n,char *masv){
	int found = 0;
	for(int i=0;i<n;i++){
		if(strcmp(sv[i].mssv,masv) == 0){
			found= 1;
			printf("da tim thay sinh vien!");
			printf("mssv:%s\n",sv[i].mssv);
			printf("ho&ten:%s\n",sv[i].name);
			printf("diem:%.2f\n",sv[i].diem);
			printf("\n---------------------\n");
			
		}
	}
	if(found==0)
	printf("khong tim thay!!!");
}


int main(){
	SinhVien sv[100];
	int n,chon;
	printf("vui long nhap so luong sinh vien:\n");
	scanf("%d",&n);
	char masv[50];
	
	do{
		printf("\n---------Menu----------\n");
		printf("1. Them sinh vien\n");
		printf("2. Hien thi danh sach\n");
		printf("3. Tim sinh vien theo ma sinh vien\n");
		printf("4. Sua sinh vien\n");
		printf("5. Xoa sinh vien\n");
		printf("6. Sap xep theo diem\n");
		printf("0. Thoat\n");
		printf("vui long nhap lua chon: \n");
		scanf("%d",&chon);
		getchar();
		
		switch(chon){
			case 1:
				printf("nhap so luong sinh vien muon them:\n");
				int them;
				scanf("%d",&them);
				getchar();
				nhapds(&sv[n],them);
				n += them;
				break;
			
			case 2:
				inds(sv,n);
			break;
			case 3:
				printf("vui long nhap mssv can tim:\n");
				fflush(stdin);
				fgets(masv,sizeof(masv),stdin);
				masv[strcspn(masv,"\n")] = '\0';
				tiemkiem(sv,n,masv);
			break;
			case 4:
				printf("vui long nhap mssv can sua:\n");
				fflush(stdin);
				fgets(masv,sizeof(masv),stdin);
				masv[strcspn(masv,"\n")] = '\0';
				sua(sv,n,masv);
			break;
			case 5:
				printf("vui long nhap mssv can xoa:\n");
				fflush(stdin);
				fgets(masv,sizeof(masv),stdin);
				masv[strcspn(masv,"\n")] = '\0';
				xoa(sv,&n,masv);
			break;
			case 6:
				sapxep(sv,n);
			printf("da sap xep theo tang dan!\n");
			break;
			case 0:
				break;
			
			default:
			printf("invalid!!!\n");
			
				
		}
}
		while(chon != 0);
	
}
