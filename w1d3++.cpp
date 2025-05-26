#include <stdio.h>
#include <string.h>

void strrev_ptr(char *str){
	char *p1 = str;
	char *p2 = str+strlen(str)-1;
	char tmp;
	while(p1<p2){
		tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		
		p1++;
		p2--;
	}
}

int main(){
	char str[100];
	printf("nhap chuoi: ");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")] = '\0';
	strrev_ptr(str);
	printf("chuoi sao khi dao nguoc:%s\n",str);
}
