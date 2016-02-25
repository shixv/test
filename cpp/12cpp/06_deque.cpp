#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
//��ί��ְ���(sort �㷨����)
//���� 5 ��ѡ��(�������÷�)��10 ����ί�� 5 ��ѡ�ֽ��д��
//�÷ֹ���ȥ����߷֣�ȥ����ͷ֣�ȡ��ƽ����
//���÷ֶ� 5 ��ѡ�ֽ�������
//����ѡ����
class Player{
	public:
		string m_name;
		int m_score;
};
//����ѡ��
void CreatePlayer(vector<Player>& v){
	string seedName = "ABCDE";
	for (int i = 0; i < 5; i++){
		//����ѡ��
		Player p;
		p.m_name = "ѡ��";
		p.m_name += seedName[i];
		p.m_score = 0;
		//��ѡ����Ϣ����
		v.push_back(p);
	}
}
//��ί���
void SetScore(vector<Player>& v){
	//����ÿ��ѡ�֣���ÿ��ѡ�ִ��
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it ++){
		//��ÿ��ѡ�ִ��
		deque<int> dScore;
		for (int i = 0; i < 10; i ++){
			int score = rand() % 50 + 50;
			dScore.push_back(score);
		}
		//���� Ĭ�ϴ�С��������
		sort(dScore.begin(), dScore.end());
		//ȥ����߷֣�ȥ����ͷ�
		dScore.pop_back();
		dScore.pop_front();
		int totalScore = 0;
		for (deque<int>::iterator dit = dScore.begin(); dit != dScore.end(); dit ++){
			totalScore += *dit;
		}
		int avgScore = totalScore / dScore.size();
		//��ѡ�ֵ÷�
		(*it).m_score = avgScore;
	}
}
//�Ƚϻص�
bool myCompare(Player p1, Player p2){
	if (p1.m_score > p2.m_score){
		return true;
	}
	else{
		return false;
	}
}
//���ݵ÷�����
void SetRank(vector<Player>& v){
	//��������
	sort(v.begin(), v.end(), myCompare);
	//��ӡѡ����Ϣ
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it ++){
		cout << "Name: " << (*it).m_name << " Score:" << (*it).m_score << endl;
	}
}
int main(){
	//���ѡ����Ϣ
	vector<Player> vPlayer; 
	//����ѡ��
	CreatePlayer(vPlayer);
	//��ѡ�ִ��
	SetScore(vPlayer);
	//��ӡѡ����Ϣ
	SetRank(vPlayer);
	return EXIT_SUCCESS;
}
