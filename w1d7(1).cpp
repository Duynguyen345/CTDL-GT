#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char mssv[20];
    char ten[50];
    float diem;
}sinhvien;


void nhap(sinhvien *sv){
    printf("vui long nhap ma so sinh vien:\n");
    fflush(stdin);
    fgets(sv->mssv,sizeof(sv->mssv),stdin);
    sv->mssv[strcspn(sv->mssv,"\n")] = '\0';
    printf("vui long nhap ho va ten:\n");
    fflush(stdin);
    fgets(sv->ten,sizeof(sv->ten),stdin);
    sv->ten[strcspn(sv->ten,"\n")] = '\0';
    printf("vui long nhap diem:\n");
    scanf("%f",&sv->diem);


}

void nhapds(sinhvien *sv,int n){
    
    for(int i=0;i<n;i++){
        printf("nhap thong tin sinh vien thu%d:\n",i+1);
        nhap(&sv[i]);
    }
}

void inds(sinhvien *sv,int n){
    for(int i=0;i<n;i++){
        printf("ma so sinh vien:%s\n",sv[i].mssv);
        printf("ho va ten:%s\n",sv[i].ten);
        printf("diem gpa:%.2f\n",sv[i].diem);
        printf("\n-------------------\n");
    }
}

void timkiem(sinhvien *sv,int n,char *masv){
	int f=0;
    for(int i=0;i<n;i++){
        if(strcmp(sv[i].mssv,masv) == 0){
        	f = 1;
            printf("ten:%s - mssv:%s - diem:%.2f",sv[i].ten,sv[i].mssv,sv[i].diem);

        }
    }
    if(f==0)
    printf("khong tim thay!!!");
}

void sapxep(sinhvien *sv,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++)
        if(sv[i].diem > sv[j].diem){
            sinhvien tmp = sv[i];
            sv[i] = sv[j];
            sv[j] = tmp;
        }
    }
}

void xoa(sinhvien *sv,int *n,char *masv){
    int found = 0;
    for(int i=0;i<*n;i++){
            if(strcmp(sv[i].mssv,masv) == 0){
                for(int j=i;j<*n-1;j++){
                sv[j] = sv[j+1];
                found =1;
                }
            
            printf("da xoa!\n");
            (*n)--;
            }


    }
    if(found ==0)
    printf("khong tim thay\n");

}

int main(){
    sinhvien sv[100];
    int n,chon;
    char masv[100];
    printf("vui long nhap so luong sinh vien:\n");
    scanf("%d",&n);
    getchar();
    nhapds(sv,n);

    do{
        printf("\n-------Menu--------\n");
        printf("1 .Them sinh vien\n");
        printf("2 .In sinh vien\n");
        printf("3 .Tim sinh vien\n");
        printf("4 .Sap xep sinh vien\n");
        printf("5 .Xoa sinh vien\n");
        printf("0. Thoat\n");
        printf("vui long chon chuc nang:\n");
        scanf("%d",&chon);
        getchar();

        switch(chon){
            case 1:
            	int them;
            	printf("nhap so luong muon them\n");
            	scanf("%d",&them);
            	
                nhapds(&sv[n],them);
                n += them;
                break;
            case 2:
                inds(sv,n);
                break;
            case 3:
            printf("nhap ma sv can tim:\n");
            fflush(stdin);
            fgets(masv,sizeof(masv),stdin);
            masv[strcspn(masv,"\n")] = '\0';
               timkiem(sv,n,masv);
               break;
            case 4:
           printf("da sap xep!");
           sapxep(sv,n);
           break;
            case 5:
            printf("nhap ma sv can xoa:\n");
            fflush(stdin);
            fgets(masv,sizeof(masv),stdin);
            masv[strcspn(masv,"\n")] = '\0';
            xoa(sv,&n,masv);
			break;
            case 0:
            break;
            
            default: printf("khong hop le!");
        }

    }
    while(chon != 0);
}
