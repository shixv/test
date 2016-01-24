#include "config.h"


//º¯ÊýÊµÏÖ
int write_config(IN char *file_name, IN char *key, IN char *value, IN int value_len)
{
	printf("write_config: %s=%s\n", key, value);
	return 0;
}

int read_config(IN char *file_name, IN char *key, OUT char *value, OUT int *value_len)
{
	printf("read config : key:%s\n", key);
	return 0;
}
