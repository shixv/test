#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
//评委打分案例(sort 算法排序)
//创建 5 个选手(姓名，得分)，10 个评委对 5 个选手进行打分
//得分规则：去除最高分，去除最低分，取出平均分
//按得分对 5 名选手进行排名
//定义选手类
class Player{
	public:
		string m_name;
		int m_score;
};
//创建选手
void CreatePlayer(vector<Player>& v){
	string seedName = "ABCDE";
	for (int i = 0; i < 5; i++){
		//创建选手
		Player p;
		p.m_name = "选手";
		p.m_name += seedName[i];
		p.m_score = 0;
		//将选手信息保存
		v.push_back(p);
	}
}
//评委打分
void SetScore(vector<Player>& v){
	//遍历每个选手，给每个选手打分
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it ++){
		//给每个选手打分
		deque<int> dScore;
		for (int i = 0; i < 10; i ++){
			int score = rand() % 50 + 50;
			dScore.push_back(score);
		}
		//排序 默认从小到大排序
		sort(dScore.begin(), dScore.end());
		//去除最高分，去除最低分
		dScore.pop_back();
		dScore.pop_front();
		int totalScore = 0;
		for (deque<int>::iterator dit = dScore.begin(); dit != dScore.end(); dit ++){
			totalScore += *dit;
		}
		int avgScore = totalScore / dScore.size();
		//给选手得分
		(*it).m_score = avgScore;
	}
}
//比较回调
bool myCompare(Player p1, Player p2){
	if (p1.m_score > p2.m_score){
		return true;
	}
	else{
		return false;
	}
}
//根据得分排名
void SetRank(vector<Player>& v){
	//进行排序
	sort(v.begin(), v.end(), myCompare);
	//打印选手信息
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it ++){
		cout << "Name: " << (*it).m_name << " Score:" << (*it).m_score << endl;
	}
}
int main(){
	//存放选手信息
	vector<Player> vPlayer; 
	//创建选手
	CreatePlayer(vPlayer);
	//给选手打分
	SetScore(vPlayer);
	//打印选手信息
	SetRank(vPlayer);
	return EXIT_SUCCESS;
}
