#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include <unistd.h>
using namespace std;
//ҵ������
class ServiceHandle{
public:
	void handleService1(){
		cout << "���������10000��ʯ!" << endl;
	}
	void handleService2(){
		cout << "���������1000���!" << endl;
	}
	void handleService3(){
		cout << "���������5000��Դ!" << endl;
	}
};
//������
class Request{
public:
	virtual void Handle() = 0;
};
//����������ʯ������
class RequestAddDiamond : public Request{
public:
	RequestAddDiamond(ServiceHandle* service){
		this->service = service;
	}
	virtual void Handle(){
		this->service->handleService1();
	}
public:
	ServiceHandle* service;
};
//�������ӽ�ҵ�����
class RequestAddGold : public Request{
public:
	RequestAddGold(ServiceHandle* service){
		this->service = service;
	}
	virtual void Handle(){
		this->service->handleService2();
	}
public:
	ServiceHandle* service;
};
//������Դ������
class RequestAddResource : public Request{
public:
	RequestAddResource(ServiceHandle* service){ this->service = service;
	}
	virtual void Handle(){
		this->service->handleService3();
	}
public:
	ServiceHandle* service;
};
//��������
class Server{
public:
	void addRequest(Request* request){
		queueReqset.push(request);
	}
	//��ʼ������ֿͻ�������
	void startHandleRequest(){
		cout << "��������ʼ��������:" << endl;
		while (queueReqset.size() > 0){
			sleep(3); //3�봦��һ������
			Request* requst =  queueReqset.front(); //�õ���ͷ������
			requst->Handle(); //��������
			queueReqset.pop(); //��������ϣ�ɾ������
		}
		cout << "��������������������!" << endl;
	}
private:
	queue<Request*> queueReqset; //����ͻ�������
};
void doBussiness(){
	//���崦��ҵ�����
	ServiceHandle* handle = new ServiceHandle;
	Request* request1 = new RequestAddDiamond(handle); //����������ʯ������
	Request* request2 = new RequestAddGold(handle); //�������ӽ�ҵ�����
	Request* request3 = new RequestAddResource(handle); //����������Դ������
	//����������
	Server* server = new Server;
	//������ŵ���������÷������������
	server->addRequest(request1);
	server->addRequest(request2);
	server->addRequest(request3);
	//��ʼ��������
	server->startHandleRequest();  //��ʼ��������
}
int main(){
	doBussiness();
	system("pause");
	return EXIT_SUCCESS;
}
