#include <stdio.h>
int main(int argc,char *argv[])
{	char ch;
	FILE *fptr1,*fptr2;
	fptr1=fopen(argv[1],"r");
	if(fptr1==NULL) {
		printf("File doesnt exist");
		exit(1);
	}
	fptr2=fopen(argv[2],"w");
	if(fptr1==NULL) {
		printf("File doesnt exist");
		exit(1);
	}
	while((ch=fgetc(fptr1))!=EOF) fputc(ch,fptr2);
	printf("File copied");
	fclose(fptr1);
	fclose(fptr2);
	return 0;
}