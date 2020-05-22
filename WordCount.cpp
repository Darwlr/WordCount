#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

FILE* fp;
// 统计字符数 
int CountChars(char* name) {	
	int chac_num = 0;
	char c;
	if ((fp = fopen(name, "r")) == NULL) {
		printf("文件打开失败\n");
		return -1;
	}
	//是否读取到文件末尾 
	while ((c = getc(fp)) != EOF) {
		if(c == '\n')  chac_num++;
		chac_num++;
	}
	fclose(fp);
	return chac_num;
}

//统计单词数 
int CountWords(char* name) { 
	int words = 0;		//单词个数 
	char c;
	bool flag = false;

	//是否读取到文件末尾
	if ((fp = fopen(name, "r")) == NULL) {
		printf("文件打开失败\n");
		return -1;
	}
	while ((c = getc(fp)) != EOF) {
		if (c == ',' || c == ' ' || c == '\n') {
			if(flag){
				words++;
				flag = false;
			}
	
		}else{
			flag = true;
		}
	}
	if(flag) words++;
	fclose(fp);
	return words;
}


int main(int argc,char *argv[]) {
	if(strcmp(argv[1], "-c") == 0) {
		printf("字符数为: %d\n", CountChars(argv[2]));
	}
	if(strcmp(argv[1], "-w") == 0) {
		printf("单词数为： %d\n", CountWords(argv[2]));
	}
	return 0;
}
