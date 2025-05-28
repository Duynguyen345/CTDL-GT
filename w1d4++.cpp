#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char ten[50];
	int tuoi;
	float diem;
}Sinhvien;


void nhap(Sinhvien *sv){
	printf("vui long nhap ten:\n");
	fflush(stdin);
	fgets(sv->ten,sizeof(sv->ten),stdin);
	sv->ten[strcspn(sv->ten,"\n")] = '\0';
	printf("vui long nhap tuoi: \n");
	scanf("%d",&sv->tuoi);
	printf("vui long nhap diem\n");
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
		printf("diem:%.2f\n",sv[i].diem);
		
	}
}
void svgioi(Sinhvien *sv,int n){
    for(int i=0;i<n;i++){
        if(sv[i].diem>= 8.0){
            printf("sinh vien co diem tren 8 la:sv[%d] co diem %.2f\n",i+1,sv[i].diem);
        }
    }

}

float maxsv(Sinhvien *sv,int n){
    float max = sv[0].diem;
    for(int i=1;i<n;i++){
        if(sv[i].diem >max){
            max = sv[i].diem;
        }
    }
    return max;
}

void sapxepdiemsv(Sinhvien *sv,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(sv[i].diem<sv[j].diem){
                float tmp = sv[i].diem;
                sv[i].diem = sv[j].diem;
                sv[j].diem = tmp;
            }
        }
    }
}


int main(){
	Sinhvien sv[100];
	int n;
	printf("vui long nhap so luong sv:\n");
	scanf("%d",&n);
	nhapds(sv,n);
	in(sv,n);
    svgioi(sv,n);
    float maxp = maxsv(sv,n);
    printf("sinh vien co diem lon nhat la:%.2f\n",maxp);
      printf("\n=== Danh sach sinh vien sau khi sap xep giam dan theo diem ===\n");
    sapxepdiemsv(sv,n);
    in(sv,n);
    
	
}
