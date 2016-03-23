#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <regex>
using namespace std;
void printHighChangeables(const map<string,vector<string>>& adjWords,ofstream& fs,
		unsigned int minWords=15)
{
	map<string,vector<string>>::const_iterator itr;
	for(itr=adjWords.begin();itr!=adjWords.end();++itr)
	{
		const pair<string,vector<string>>& entry=*itr;
		const vector<string>& words=entry.second;
		if(words.size()>=minWords)
		{
			fs<<entry.first<<"("<<words.size()<<"):";
			for(unsigned int i=0;i<words.size();i++)
				fs<<" "<<words[i];
			fs<<endl;
		}
	}
}
/*
bool oneCharOff(const string& word1,const string& word2)
{
	if(word1.length()!=word2.length())
		return false;
	int diffs=0;
	for(unsigned int i=0;i<word1.length();i++)
		if(word1[i]!=word2[i])
			if(++diffs>1)
				return false;
	return diffs==1;
}
map<string,vector<string>> computeAdjacentWords(const vector<string>& words)
{
	map<string,vector<string>> adjWords;
	for(unsigned int i=0;i<words.size();i++)
		for(unsigned int j=i+1;j<words.size();j++)
			if(oneCharOff(words[i],words[j]))
			{
				adjWords[words[i]].push_back(words[j]);
				adjWords[words[j]].push_back(words[i]);
			}
	return adjWords;
}
map<string,vector<string>> computeAdjacentWords1(const vector<string>& words)
{
	map<string,vector<string>> adjWords;
	map<int,vector<string>> wordsByLength;
	for(unsigned int i=0;i<words.size();i++)
		wordsByLength[words[i].length()].push_back(words[i]);
	map<int,vector<string>>::const_iterator itr;
	for(itr=wordsByLength.begin();itr!=wordsByLength.end();++itr)
	{
		const vector<string>& groupsWords=itr->second;
		for(unsigned int i=0;i<groupsWords.size();i++)
			for(unsigned int j=i+1;j<groupsWords.size();j++)
				if(oneCharOff(groupsWords[i],groupsWords[j]))
				{
					adjWords[groupsWords[i]].push_back(groupsWords[j]);
					adjWords[groupsWords[j]].push_back(groupsWords[i]);
				}
	}
	return adjWords;
}
*/
map<string,vector<string>> computeAdjacentWords2(const vector<string>& words)
{
	map<string,vector<string>> adjWords;
	map<int,vector<string>> wordsByLength;
	for(unsigned int i=0;i<words.size();i++)
		wordsByLength[words[i].length()].push_back(words[i]);
	map<int,vector<string>>::const_iterator itr;
	for(itr=wordsByLength.begin();itr!=wordsByLength.end();++itr)
	{
		const vector<string>& groupsWords=itr->second;
		int groupNum=itr->first;
		for(int i=0;i<groupNum;i++)
		{
			map<string,vector<string>> repToWord;
			for(unsigned int j=0;j<groupsWords.size();j++)
			{
				string rep=groupsWords[j];
				rep.erase(i,1);
				repToWord[rep].push_back(groupsWords[j]);
			}
			map<string,vector<string>>::const_iterator itr2;
			for(itr2=repToWord.begin();itr2!=repToWord.end();++itr2)
			{
				const vector<string>& clique=itr2->second;
				if(clique.size()>=2)
					for(unsigned int p=0;p<clique.size();p++)
						for(unsigned int q=p+1;q<clique.size();q++)
						{
							adjWords[clique[p]].push_back(clique[q]);
							adjWords[clique[q]].push_back(clique[p]);
						}
			}
		}
	}
	return adjWords;
}
int main(void)
{
	ifstream ifs("dict.txt");
	string buf;
	char ch;
	while(ifs.readsome(&ch,1)==1)buf+=ch;
	regex r1(R"(Trans:[^\n\r]*\r\n)");	
	regex r2(R"(\r?\n?#[^a-zA-Z][^\r\n]*\r?\n?)");
	regex r3(R"(#)");
	regex r4(R"(\r)");
	const string format("");
	buf=regex_replace(buf,r1,format);
	buf=regex_replace(buf,r2,format);
	buf=regex_replace(buf,r3,format);
	buf=regex_replace(buf,r4,format);
	ifs.close();	
	ofstream ofs("dict.txt");
	ofs<<buf;
	ofs.close();

	vector<string> temp;
//	string buf;
	ifstream fs("dict.txt");
	while(getline(fs,buf)){
//		buf.back()='\0';
		temp.push_back(buf);
	}
	fs.close();
	ofstream test("dict.txt");
	printHighChangeables(computeAdjacentWords2(temp),test);
//	for(auto& i:temp)
//		cout<<i<<" ";
//	cout<<temp[0];
	return 0;
}
