#include <stdio.h>
#include <stdlib.h>

int* nhap(int* n){
	printf("vui long nhap n:");
	scanf("%d",n);
	
	int *matrix = (int*)malloc(*n * sizeof(int));
	
	if(matrix == NULL ){
	
	printf("khong du bo nho!");
	exit(1);
}
	printf("vui long nhap cac phan tu:");
	for(int i=0;i<*n;i++){
		scanf("%d",&matrix[i]);
	}
	return matrix;
}

int main(){
	int n;
	int* matrixx = nhap(&n);
	free(matrixx);
}
