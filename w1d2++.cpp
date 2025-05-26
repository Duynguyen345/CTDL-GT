#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


typedef struct{
	char ten[50];
	int tuoi;;
	float diem;
}SinhVien;


void nhapSinhVien(SinhVien *sv){
	printf("vui long nhap ten sv:");
	fflush(stdin);
	fgets(sv->ten, sizeof(sv->ten), stdin);
sv->ten[strcspn(sv->ten, "\n")] = 0; // Xóa d?u \n th?a
	printf("vui long nhap tuoi sv:");
	scanf("%d",&sv->tuoi);
	printf("vui long nhap gpa:");
	scanf("%f",&sv->diem);
	
}

// In thông tin 1 sinh viên
void inSinhVien(SinhVien sv) {
    printf("Ten: %s | Tuoi: %d | Diem: %.2f\n", sv.ten, sv.tuoi, sv.diem);
}

//nhap list sinh viên
void nhapDanhSach(SinhVien a[],int *n){
	printf("nhap so luong sinh vien: ");
	scanf("%d",n);
	for(int i= 0;i<*n;i++){
		printf("vui long nhap thong tin sv thu %d:\n",i+1);
		nhapSinhVien(&a[i]);
		
	}
}

//tim kiem sinh vien

void timKiem(SinhVien a[],int n,char tentim[]){
	int f = 0;
	for(int i = 0;i<n;i++){
	if(strcmp(a[i].ten,tentim) == 0){
		printf("da tim thay sinh vien %s-%d-%f",a[i].ten,a[i].tuoi,a[i].diem);
		f = 1;
		
		}
		
		
	}
	if(!f){
		printf("khong tim thay!\n");
	}
	
}
//them sinh vien
void themSinhVien(SinhVien a[], int *n) {
    if (*n >= MAX) {
        printf("Danh sach day, khong the them!\n");
        return;
    }
    printf("Nhap thong tin sinh vien moi:\n");
    nhapSinhVien(&a[*n]);
    (*n)++;
}
// S?a sinh viên theo tên
void suaSinhVien(SinhVien a[], int n, char tenCanSua[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].ten, tenCanSua) == 0) {
            printf("Nhap thong tin moi cho sinh vien:\n");
            nhapSinhVien(&a[i]);
            return;
        }
    }
    printf("Khong tim thay sinh vien!\n");
}
//xoa sinh vien
void xoaSinhVien(SinhVien a[],int *n,char tencanxoa[]){
	for(int i=0;i<*n;i++){
		if(strcmp(a[i].ten,tencanxoa) == 0){
			for(int j=i;i<*n;i++){
				a[j] = a[j+1];
			}
			(*n)--;
			printf("da xoa ten sinh vien %s",tencanxoa);
			return;
		}
	}
	printf("khong tim thay!");
}
void sapXepTheoDiem(SinhVien a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].diem < a[j].diem) {
                SinhVien temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("Da sap xep danh sach theo diem giam dan!\n");
}
void inDanhSach(SinhVien a[], int n) {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < n; i++) {
        inSinhVien(a[i]);
    }
}

// Menu chuong trình
void menu() {
    printf("\n========== MENU ==========\n");
    printf("1. Nhap danh sach sinh vien\n");
    printf("2. Them sinh vien\n");
    printf("3. Sua sinh vien theo ten\n");
    printf("4. Xoa sinh vien theo ten\n");
    printf("5. Tim sinh vien theo ten\n");
    printf("6. Sap xep theo diem\n");
    printf("7. In danh sach\n");
    printf("0. Thoat\n");
    printf("==========================\n");
}

int main() {
    SinhVien a[MAX];
    int n = 0;
    int luaChon;
    char ten[50];

    do {
        menu();
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);
        fflush(stdin); // Xóa b? d?m tru?c khi nh?p chu?i

        switch (luaChon) {
            case 1:
                nhapDanhSach(a, &n);
                break;
            case 2:
                themSinhVien(a, &n);
                break;
            case 3:
                printf("Nhap ten sinh vien can sua: ");
                gets(ten);
                suaSinhVien(a, n, ten);
                break;
            case 4:
                printf("Nhap ten sinh vien can xoa: ");
                gets(ten);
                xoaSinhVien(a, &n, ten);
                break;
            case 5:
                printf("Nhap ten sinh vien can tim: ");
                gets(ten);
                timKiem(a, n, ten);
                break;
            case 6:
                sapXepTheoDiem(a, n);
                break;
            case 7:
                inDanhSach(a, n);
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (luaChon != 0);

    return 0;
}
