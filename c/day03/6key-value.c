#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//p = strstr(ĸ���� key);
//p = strstr(ĸ��, =);

/*
2����ֵ�ԣ���key = value�����ַ������ڿ����о���ʹ��.
Ҫ��1�����Լ�����һ���ӿڣ�ʵ�ָ���key��ȡ.
Ҫ��2����д����������
Ҫ��3����ֵ���м������n��ո���ȥ���ո�
ע�⣺��ֵ���ַ�����ʽ�������£�
"key1	=	value1"
"     key2	=							value2       "
                  ��
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
	//����������ƶ�
	while (isspace(inbuf[i]) && inbuf[i] != '\0')
	{
		i++;
	}

	j = strlen(inbuf) - 1;
	//���ұ������ƶ�
	while (isspace(inbuf[j]) && j > i) {
		j--;
	}

	len = j - i + 1;

	strncpy(outbuf, inbuf + i, len);

	outbuf[len] = '\0';

	return 0;
}



/*
   ���ܣ�
          ��������
		  "key1	=	value1"
		  "     key2	=							value2       "
		                  ��
		  "key3		=	hello word      "
		  "key4								=	value4"
		  "key5			=			"
		  "key6			="
		  ���·���ַ�����ͨ��key���õ�value

	key_value_buf  IN �� Ҫ������Դ�ַ���
	key_buf            IN  :  Ҫ���ҵ�keyֵ
	value_buf        OUT: �õ�������valueֵ
	value_buf_len  OUT: �õ���value�ĳ���

return   0  �ɹ�  -1 ʧ��
*/
int get_key_by_value(char *key_value_buf, char *key_buf, char *value_buf, int *value_buf_len)
{
	char *p = key_value_buf; //Դ�ַ���
	char *key = key_buf; //��Ҫ���ҵ�key
	//char *dst_buf = value_buf;
	int value_len = 0;

	if (key_value_buf == NULL || key_buf == NULL || value_buf == NULL || value_buf_len == NULL)
	{
		printf("key_value_buf == NULL || key_buf == NULL || value_buf == NULL || value_buf_len == NULL\n");
		return -1;
	}

	//д����Ĺ���
	//����Դ�ַ������Ƿ���key
	p = strstr(p, key);
	if (p == NULL)
	{
		//û�ҵ�key 
		printf("δ�ҵ� %s\n", key);
		return -1;
	}

	//�ж�Դ�ַ����� �Ƿ��� =
	p = strstr(p, "=");
	if (p == NULL)
	{
		//û�ҵ�=
		printf("δ�ҵ� = \n");
		return -1;
	}

	p += strlen("=");


	//��= �ұߵ��пհ��ַ����ַ������������ߵĿհ�ȥ��
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
