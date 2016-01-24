#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "config.h"

#define FILE_NAME "c:/test/config.ini"

void menu()
{
	printf("=====\n");
	printf("1. Ğ´ÅäÖÃ\n");
	printf("2.¶ÁÅäÖÃ\n");
	printf("0. ÍË³ö\n");
	printf("=====\n");

}


//²âÊÔĞ´ÅäÖÃÎÄ¼şµÄ ²âÊÔÓÃÀı 
int test_write_config()
{
	char key[KEY_LEN] = { 0 };
	char value[VALUE_LEN] = { 0 };
	int ret = 0;
	printf("===== Ğ´ ÅäÖÃÎÄ¼ş ==== \n");

	printf("ÇëÊäÈëkey:");
	scanf("%s", key);
	printf("ÇëÊäÈëvalue:");
	scanf("%s", value);

	ret =  write_config(FILE_NAME, key, value, strlen(value)); 
	if (ret < 0) {
		printf("write_config  error\n");
		return -1;
	}
	else {
		printf("write config succ!\n");
	}

	return 0;
}

int test_read_config()
{
	char key[KEY_LEN] = { 0 };
	char value[VALUE_LEN] = { 0 };
	int value_len = 0;
	int ret = 0;
	printf("===== ¶Á ÅäÖÃÎÄ¼ş ==== \n");

	printf("ÇëÊäÈëkey:");
	scanf("%s", key);

	ret = read_config(FILE_NAME, key, value, &value_len);
	if (ret < 0) {
		printf("read _config error\n");
		return -1;
	}
	else {
		printf("read  succ!\n");
		printf("%s=%s\n", key, value);
	}


	return 0;
}

int main(void)
{
	int choice = 0;


	while (1) {
		menu();
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			//Ğ´ÅäÖÃ
			test_write_config();
			break;
		case 2:
			//¶ÁÅäÖÃ
			test_read_config();
			break;
		case 0:
			//ÍË³ö
			return 0;
		default:
			break;
		}
	}

	return 0;
}
