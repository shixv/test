#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
//��һ������ķ���
typedef void(TIPS)(void); //�����ҵĺ������� ���������
//��һ������struct  �������͡�
struct tip
{
	char from[64];//�ý�����˭д��
	char to[64];//�ý���д��˭��
	//���ҵľ�������
	TIPS *tp; //�൱�� ������Ĵ��麯��
};
//��һ�� �򿪽��ҵ� �ܹ�����
void open_tips(struct tip * tip_p)
{
	cout << "���˽���" << endl;
	cout << "�˽������� " << tip_p->from << " д��  " << tip_p->to <<"�ġ�" << endl;
	cout << "������" << endl;
	tip_p->tp();
}
//��������  �����ʵ�ֵ���������
void tips_1(void)
{
	cout << "һ������ݻ��ǹ���" << endl;
}
void tips_2(void)
{
	cout << "˵ �ܲٴ��ѹ���� ȫ������ȥ" << endl;
}
void tips_3(void)
{
	cout << "��� ������" << endl;
}
void tips_4(void)
{
	cout<<"What the fuck!"<<endl;
}
//�������ҵĺ���
struct tip * create_tip(const char *from, const char *to, TIPS *fp)
{
	struct tip * my_tip= (struct tip *)malloc(sizeof(struct tip));
	if (my_tip == NULL) {
		return NULL;
	}
	strcpy(my_tip->from, from );
	strcpy(my_tip->to, to);
	//�����һ���ṹ���һ������ָ�븳ֵ��  �ֽ�����ע��һ���ص�����
	my_tip->tp = fp;
	return my_tip;
}
void destory_tip(struct tip* tip_p)
{
	if (tip_p != NULL) {
		free(tip_p);
	}
}
int main(void)
{
	//���������3������
	struct tip *tip1 = create_tip("����", "����", tips_1);
	struct tip *tip2 = create_tip("����", "����", tips_2);
	struct tip *tip3 = create_tip("����", "����", tips_3);
	//���ƿ�ʼ������
	cout << "���������⣬ �򿪵�һ������" << endl;
	open_tips(tip1);
	cout << " -------" << endl;
	cout << "�����ֲ�˼�� �򿪵ڶ�������" << endl;
	open_tips(tip2);
	cout << "------" << endl;
	cout << "��Ȩ׷ɱ������ �򲻹��ˣ� �򿪵���������" << endl;
	open_tips(tip3);
	destory_tip(tip1);
	destory_tip(tip2);
	destory_tip(tip3);
	struct tip *tip4 = create_tip("sihyuan","zilong",tips_4);
	cout<<"da kai di si ge jin nang"<<endl;
	open_tips(tip4);
	destory_tip(tip4);
	return 0;
}
