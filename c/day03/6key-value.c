#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//p = strstr(母串， key);
//p = strstr(母串, =);

/*
2、键值对（“key = value”）字符串，在开发中经常使用.
要求1：请自己定义一个接口，实现根据key获取.
要求2：编写测试用例。
要求3：键值对中间可能有n多空格，请去除空格
注意：键值对字符串格式可能如下：
"key1	=	value1"
"     key2	=							value2       "
                  ↑
"key3		=	hello word      "
"key4								=	value4"
"key5			=			"
"key6			="
int	getKeyByValue(char	*keyvaluebuf,		char	*keybuf,		char	*valuebuf,	int	*
valuebuflen);
int	main(void)
{
//...
getKeyByValue("key1	=	valude1",	"key1",	buf,	&len);
//...
return 0;
}
*/


//"     value buf      "
int trim_space(char *inbuf, char *outbuf)
{
	int i = 0;
	int j = 0;
	int len = 0;

	if (inbuf == NULL || outbuf == NULL)
	{
		printf("inbuf == NULL || outbuf == NULL\n");
		return -1;
	}

	i = 0;
	//从左边向右移动
	while (isspace(inbuf[i]) && inbuf[i] != '\0')
	{
		i++;
	}

	j = strlen(inbuf) - 1;
	//从右边向左移动
	while (isspace(inbuf[j]) && j > i) {
		j--;
	}

	len = j - i + 1;

	strncpy(outbuf, inbuf + i, len);

	outbuf[len] = '\0';

	return 0;
}



/*
   功能：
          解析类似
		  "key1	=	value1"
		  "     key2	=							value2       "
		                  ↑
		  "key3		=	hello word      "
		  "key4								=	value4"
		  "key5			=			"
		  "key6			="
		  以下风格字符串，通过key，得到value

	key_value_buf  IN ： 要解析的源字符串
	key_buf            IN  :  要查找的key值
	value_buf        OUT: 得到的最终value值
	value_buf_len  OUT: 得到的value的长度

return   0  成功  -1 失败
*/
int get_key_by_value(char *key_value_buf, char *key_buf, char *value_buf, int *value_buf_len)
{
	char *p = key_value_buf; //源字符串
	char *key = key_buf; //需要查找的key
	//char *dst_buf = value_buf;
	int value_len = 0;

	if (key_value_buf == NULL || key_buf == NULL || value_buf == NULL || value_buf_len == NULL)
	{
		printf("key_value_buf == NULL || key_buf == NULL || value_buf == NULL || value_buf_len == NULL\n");
		return -1;
	}

	//写具体的过程
	//查找源字符串中是否有key
	p = strstr(p, key);
	if (p == NULL)
	{
		//没找到key 
		printf("未找到 %s\n", key);
		return -1;
	}

	//判断源字符串中 是否有 =
	p = strstr(p, "=");
	if (p == NULL)
	{
		//没找到=
		printf("未找到 = \n");
		return -1;
	}

	p += strlen("=");


	//将= 右边的有空白字符的字符串，进行两边的空白去掉
	if (trim_space(p, value_buf) < 0)
	{
		printf("trim_space error\n");
		return -1;
	}

	value_len = strlen(value_buf);

	*value_buf_len = value_len;

	return 0;
}

int main(void)
{
	char *str = "        key1 =      ";
	char *key = "key1";
	char value_buf[64] = { 0 };
	int value_buf_len = 0;

	int retn = 0;

	retn = get_key_by_value(str, key, value_buf, &value_buf_len);
	if (retn < 0) {
		printf("get_key_by_value error\n");
		return -1;
	}


	printf("value_buf:[%s]\n", value_buf);
	printf("value_buf_len=%d\n", value_buf_len);

	return 0;
}
