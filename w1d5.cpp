#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
	char ten[50];
	float diem;
}sinhvien;

void nhap(sinhvien *s){
	printf("vui long nhap ten:\n");
	fflush(stdin);
	fgets(s->ten,sizeof(s->ten),stdin);
	s->ten[strcspn(s->ten,"\n")] = '\0';
	printf("vui long nhap diem:\n");
	scanf("%f",&s->diem);
	
}

void nhapds(sinhvien *s,int n){
	for(int i=0;i<n;i++){
		printf("nhap thong tin sv thu %d:\n",i+1);
		fflush(stdin);
		nhap(&s[i]);
	}
}

void inds(sinhvien *s,int n){
	for(int i=0;i<n;i++){
		printf(" thong tin sv thu %d:\n",i+1);
		printf("ten: %s\n",s[i].ten);
		printf("diem: %.2f\n",s[i].diem);
	}
}

void sapxepten(sinhvien *s,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
		
		if(strcmp(s[i].ten,s[j].ten) > 0){
			sinhvien tmp = s[i];
			s[i] = s[j];
			s[j] = tmp;
		}	
	}
	}
}

void timkiemten(sinhvien *s,int n,char *name){
	int found = 0;
	for(int i=0;i<n;i++){
		if(strcmp(s[i].ten,name) == 0){
			printf("sinh vien can tim:\n");
			printf("ten:%s  |    diem:%.2f\n",s[i].ten,s[i].diem);
			found = 1;
		}
	}
	if(!found) printf("khong tim thay sinh vien!\n");
}


void timkiemdiem(sinhvien *s,int n,float min,float max){
	printf("sinh vien co diem can tiem:\n");
	int found = 0;
	for(int i=0;i<n;i++){
		if(s[i].diem >=min && s[i].diem <=max){
			printf("sinh vien can tim:\n");
			printf("ten:%s  |    diem:%.2f\n",s[i].ten,s[i].diem);
			found = 1;
		}
	}
	if(!found) printf("khong tim thay sinh vien!\n");
}


int main(){
	sinhvien s[100];
	int n,chon;
	printf("nhap so luong sinh vien:\n");
	scanf("%d",&n);
	nhapds(s,n);
	
	do{
	 printf("\n------ MENU ------\n");
        printf("1. In danh sach sinh vien\n");
        printf("2. Sap xep theo ten (A-Z)\n");
        printf("3. Tim kiem theo ten\n");
        printf("4. Tim sinh vien theo khoang diem\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &chon);
        getchar(); // x? lý Enter còn l?i
        
        switch(chon){
        	case 1:
        		inds(s,n);
        		break;
        	case 2:
        		
        		sapxepten(s,n);
        		printf("da sap xep.\n");
        		break;
        	case 3:
        		char name[100];
        		printf("vui long nhap ten can tim:\n");
        		fgets(name,sizeof(name),stdin);
        		name[strcspn(name,"\n")] = '\0';
        		timkiemten(s,n,name);
        		break;
        	case 4:
        		float min;
        		float max;
        		printf("vui long nhap max:\n");
        		scanf("%f",&max);
        		printf("vui long nhap min:\n");
        		scanf("%f",&min);
        		timkiemdiem(s,n,min,max);
        		break;
        	case 0:
        		printf("tam biet!");
        		break;
        	default:
        		printf("invalid!!!");
		}
	}
	while(chon!=0);
	

}
