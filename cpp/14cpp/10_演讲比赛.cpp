#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<deque>
#include<numeric>
#include<functional>
using namespace std;
//选手类
class Speaker{
	public:
		string name;
		int score[3];
};
/*
	创建选手
	@param mSpeaker 选手信息
	@param v 参赛名单的编号
	*/
void CreateSpeaker(map<int,Speaker>& mSpeaker, vector<int>& v){
	string seedName = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < 24;i++){
		Speaker speaker;
		speaker.name = "选手";
		speaker.name += seedName[i];
		//初始化选手分数
		for (int j = 0; j < 3;j++){
			speaker.score[j] = 0;
		}
		//生成这个选手唯一编号
		int spekerID = 100 + i;
		//保存到MAP容器
		mSpeaker.insert(make_pair(spekerID,speaker));
		//编号存储到v中，作为第一轮比赛的参赛名单
		v.push_back(spekerID);
	}
}
/*
	抽签，随机打乱参赛编号
	@param v1 参赛编号列表
	*/
void PersonByRandom(vector<int>& v1){
	random_shuffle(v1.begin(),v1.end());
}
/*
	开始比赛
	@param index 表示第几轮比赛
	@param mSpeker 选手信息
	@param v1 参赛编号列表
	@param v2 晋级编号列表
	*/
void StartMatch(int index,map<int,Speaker>& mSpeker,vector<int>& v1,vector<int>& v2){
	multimap<int, int, greater<int>> mGroup; //保存分组信息
	int count = 0;
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it ++){
		deque<int> dScore;
		for (int i = 0; i < 10; i ++){
			int score = rand() % 50 + 50;
			dScore.push_back(score);
		}
		//排序
		sort(dScore.begin(),dScore.end());
		//去除最高分和最低分
		dScore.pop_front(); //去除最低分
		dScore.pop_back(); //去除最高分
		//求总分数
		int totalSocre = accumulate(dScore.begin(),dScore.end(),0);
		//求平均分
		int avgScore = totalSocre / dScore.size();
		//存储选手得分
		mSpeker[*it].score[index - 1] = avgScore;
		//当前选手加入分组
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
			mGroup.clear(); //清空分组信息
		}
	}
}
/*
	显示此轮晋级的名单
	@param index 表示当前第几轮
	@param mSpeker 参赛选手信息
	@param v2 晋级编号列表
	*/
void ShowLevelList(int index, map<int, Speaker>& mSpeker, vector<int>& v2){
	cout << "第" << index << "轮晋级名单:" << endl;
	for (vector<int>::iterator it = v2.begin(); it != v2.end();it ++){
		cout << "姓名:" << mSpeker[*it].name << " 分数:" << mSpeker[*it].score[index - 1] << endl;
	}
	cout << "-------------------------------" << endl;
}
int main(){
	map<int, Speaker> mSpeker; //保存参赛选手信息
	vector<int> v1; //第一轮参赛名单
	vector<int> v2; //第二轮参赛名单
	vector<int> v3; //第三轮参赛名单
	vector<int> v4; //最终前三名
	//创建选手
	CreateSpeaker(mSpeker, v1);
	//第一轮比赛
	//抽签
	PersonByRandom(v1);
	//开始比赛
	StartMatch(1,mSpeker,v1,v2);
	//显示当此轮晋级名单
	ShowLevelList(1,mSpeker,v2);
	//第二轮比赛
	//抽签
	PersonByRandom(v2);
	//开始比赛
	StartMatch(2, mSpeker, v2, v3);
	//显示当此轮晋级名单
	ShowLevelList(2, mSpeker, v3);
	//第三轮比赛
	//抽签
	PersonByRandom(v3);
	//开始比赛
	StartMatch(3, mSpeker, v3, v4);
	//显示当此轮晋级名单
	ShowLevelList(3, mSpeker, v4);
	system("pause");
	return 0;
}
