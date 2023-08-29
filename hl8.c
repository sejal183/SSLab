#include<stdio.h>
int main(){
	const char* filename = "employee_records.csv";
	FILE* file = fopen(filename,"r");
	if(file==NULL){
		perror("Error opening file.");
		return 1;
	}
	char buf[20];
	while(fgets(buf,sizeof(buf),file) != NULL){
		printf("%s",buf);
	}
	fclose(file);
	return 0;
}
