#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<deque>
#include<numeric>
#include<functional>
using namespace std;
//ѡ����
class Speaker{
	public:
		string name;
		int score[3];
};
/*
	����ѡ��
	@param mSpeaker ѡ����Ϣ
	@param v ���������ı��
	*/
void CreateSpeaker(map<int,Speaker>& mSpeaker, vector<int>& v){
	string seedName = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < 24;i++){
		Speaker speaker;
		speaker.name = "ѡ��";
		speaker.name += seedName[i];
		//��ʼ��ѡ�ַ���
		for (int j = 0; j < 3;j++){
			speaker.score[j] = 0;
		}
		//�������ѡ��Ψһ���
		int spekerID = 100 + i;
		//���浽MAP����
		mSpeaker.insert(make_pair(spekerID,speaker));
		//��Ŵ洢��v�У���Ϊ��һ�ֱ����Ĳ�������
		v.push_back(spekerID);
	}
}
/*
	��ǩ��������Ҳ������
	@param v1 ��������б�
	*/
void PersonByRandom(vector<int>& v1){
	random_shuffle(v1.begin(),v1.end());
}
/*
	��ʼ����
	@param index ��ʾ�ڼ��ֱ���
	@param mSpeker ѡ����Ϣ
	@param v1 ��������б�
	@param v2 ��������б�
	*/
void StartMatch(int index,map<int,Speaker>& mSpeker,vector<int>& v1,vector<int>& v2){
	multimap<int, int, greater<int>> mGroup; //���������Ϣ
	int count = 0;
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it ++){
		deque<int> dScore;
		for (int i = 0; i < 10; i ++){
			int score = rand() % 50 + 50;
			dScore.push_back(score);
		}
		//����
		sort(dScore.begin(),dScore.end());
		//ȥ����߷ֺ���ͷ�
		dScore.pop_front(); //ȥ����ͷ�
		dScore.pop_back(); //ȥ����߷�
		//���ܷ���
		int totalSocre = accumulate(dScore.begin(),dScore.end(),0);
		//��ƽ����
		int avgScore = totalSocre / dScore.size();
		//�洢ѡ�ֵ÷�
		mSpeker[*it].score[index - 1] = avgScore;
		//��ǰѡ�ּ������
		mGroup.insert(make_pair(avgScore,*it));
		count++;
		if (count % 6 == 0){
			int cnt = 0;
			for (multimap<int, int, greater<int>>::iterator mit = mGroup.begin(); mit != mGroup.end(); mit ++){
				cnt++;
				v2.push_back((*mit).second);
				if (cnt >= 3){
					break;
				}
			}
			mGroup.clear(); //��շ�����Ϣ
		}
	}
}
/*
	��ʾ���ֽ���������
	@param index ��ʾ��ǰ�ڼ���
	@param mSpeker ����ѡ����Ϣ
	@param v2 ��������б�
	*/
void ShowLevelList(int index, map<int, Speaker>& mSpeker, vector<int>& v2){
	cout << "��" << index << "�ֽ�������:" << endl;
	for (vector<int>::iterator it = v2.begin(); it != v2.end();it ++){
		cout << "����:" << mSpeker[*it].name << " ����:" << mSpeker[*it].score[index - 1] << endl;
	}
	cout << "-------------------------------" << endl;
}
int main(){
	map<int, Speaker> mSpeker; //�������ѡ����Ϣ
	vector<int> v1; //��һ�ֲ�������
	vector<int> v2; //�ڶ��ֲ�������
	vector<int> v3; //�����ֲ�������
	vector<int> v4; //����ǰ����
	//����ѡ��
	CreateSpeaker(mSpeker, v1);
	//��һ�ֱ���
	//��ǩ
	PersonByRandom(v1);
	//��ʼ����
	StartMatch(1,mSpeker,v1,v2);
	//��ʾ�����ֽ�������
	ShowLevelList(1,mSpeker,v2);
	//�ڶ��ֱ���
	//��ǩ
	PersonByRandom(v2);
	//��ʼ����
	StartMatch(2, mSpeker, v2, v3);
	//��ʾ�����ֽ�������
	ShowLevelList(2, mSpeker, v3);
	//�����ֱ���
	//��ǩ
	PersonByRandom(v3);
	//��ʼ����
	StartMatch(3, mSpeker, v3, v4);
	//��ʾ�����ֽ�������
	ShowLevelList(3, mSpeker, v4);
	system("pause");
	return 0;
}
