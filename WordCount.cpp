#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

FILE* fp;
// ͳ���ַ��� 
int CountChars(char* name) {	
	int chac_num = 0;
	char c;
	if ((fp = fopen(name, "r")) == NULL) {
		printf("�ļ���ʧ��\n");
		return -1;
	}
	//�Ƿ��ȡ���ļ�ĩβ 
	while ((c = getc(fp)) != EOF) {
		if(c == '\n')  chac_num++;
		chac_num++;
	}
	fclose(fp);
	return chac_num;
}

//ͳ�Ƶ����� 
int CountWords(char* name) {
	int character = 0;	//�ַ����� 
	int words = 0;		//���ʸ��� 
	int t_words = 0;//��ĸ���� 
	char c;

	//�Ƿ��ȡ���ļ�ĩβ
	if ((fp = fopen(name, "r")) == NULL) {
		printf("�ļ���ʧ��\n");
		return -1;
	}
	while ((c = getc(fp)) != EOF) {
		character++;
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == ',')) {
			t_words++;
			if (t_words < character) {
				t_words = character;
				words++;
			}
		}
	}
	fclose(fp);
	return words;
}


int main(int argc,char *argv[]) {
	if(strcmp(argv[1], "-c") == 0) {
		printf("�ַ���Ϊ: %d\n", CountChars(argv[2]));
	}
	if(strcmp(argv[1], "-w") == 0) {
		printf("������Ϊ�� %d\n", CountWords(argv[2]));
	}
	return 0;
}
