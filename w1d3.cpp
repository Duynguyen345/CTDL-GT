#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strlen_ptr(char *s){
	int leng = 0;
	while(*s){
		leng++;
		
		s++;
	}
	return leng;
}

void strcpy_ptr(char *copy,const char *s){
	while(*s){
		*copy = *s;
		copy++;
		s++;
	}
	
}

int demTu(char *s){
	int count = 0;
	int inword = 0;
	while(*s){
		if(*s != ' ' && inword ==0 ){
			inword = 1;
			count++;
		}
		else if(*s == ' '){
			inword = 0;
		}
		s++;
	}
	return count;
}


int main() {
    char s[100], copy[100];
    printf("Nhap chuoi: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0'; // Xoa \n

    printf("Do dai chuoi: %d\n", strlen_ptr(s));
    strcpy_ptr(copy, s);
    printf("Chuoi sau khi sao chep: %s\n", copy);
    printf("So tu trong chuoi: %d\n", demTu(s));
    return 0;
}
