#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


bool isWhiteSpace(char c) {
	return c == ' ' || c == '\t' || c == '\n';
}

bool specialCharacter(char c) {
	return c == ',' || c == '.' || c == '(' || c == ')' 
	|| c == '?' || c == ':' || c == ';' || c == '!';
}




void xoadaucach(char *ptr){
	int i=0,j=0;
	int len = strlen(ptr);
	 while (isWhiteSpace(ptr[i])) i++;
	for(i=0;i<len;i++){
		if(isWhiteSpace(ptr[i]) && isWhiteSpace(ptr[i+1])){
			for( j=i+1;j<len;j++){
				ptr[j] = ptr [j+1];
				
			}
			i--;
			len--;
		}
			else if(isWhiteSpace(ptr[i]) && specialCharacter(ptr[i+1])){
			for( j=i;j<len;j++){
				ptr[j] = ptr [j+1];
				
			}
			i--;
			len--;
		}
		 else if(ptr[i] == '\t') {
			ptr[i] = ' ';
		}
	}
		
}

void daonguoc(char *ptr){
	char *i=ptr;
	char *j= ptr + strlen(ptr) -1;
	char tmp;
	while(i<j){
		tmp = *i;
		*i = *j;
		*j = tmp;
		i++;
		j--;
	}
}

int demtu(char *ptr){
	int len = strlen(ptr);
	int inword = 0;
	int count=0;
	while(*ptr){
		if(*ptr != ' ' && inword == 0){
			inword =1;
			count++;
		}
		else if(*ptr == ' ') inword = 0;
		ptr++;
	}
	return count;
}


int main() {
	char s[100];
	printf("Nhap chuoi: ");
	fgets(s, sizeof(s), stdin);
	s[strcspn(s, "\n")] = '\0';

	xoadaucach(s);
	printf("Sau khi xoa dau cach: '%s'\n", s);

	int soTu = demtu(s);
	printf("So tu trong chuoi: %d\n", soTu);

	daonguoc(s);
	printf("Chuoi dao nguoc: '%s'\n", s);

	return 0;
}
