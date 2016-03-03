#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include <unistd.h>
using namespace std;
//业务处理函数
class ServiceHandle{
public:
	void handleService1(){
		cout << "给玩家增加10000钻石!" << endl;
	}
	void handleService2(){
		cout << "给玩家增加1000金币!" << endl;
	}
	void handleService3(){
		cout << "给玩家增加5000资源!" << endl;
	}
};
//请求类
class Request{
public:
	virtual void Handle() = 0;
};
//处理增加钻石的请求
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
//处理增加金币的请求
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
//处理资源的请求
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
//服务器类
class Server{
public:
	void addRequest(Request* request){
		queueReqset.push(request);
	}
	//开始处理各种客户端请求
	void startHandleRequest(){
		cout << "服务器开始处理请求:" << endl;
		while (queueReqset.size() > 0){
			sleep(3); //3秒处理一条请求
			Request* requst =  queueReqset.front(); //拿到队头的请求
			requst->Handle(); //处理请求
			queueReqset.pop(); //请求处理完毕，删除请求
		}
		cout << "服务器处理完所有请求!" << endl;
	}
private:
	queue<Request*> queueReqset; //保存客户端请求
};
void doBussiness(){
	//具体处理业务的类
	ServiceHandle* handle = new ServiceHandle;
	Request* request1 = new RequestAddDiamond(handle); //处理增加钻石的请求
	Request* request2 = new RequestAddGold(handle); //处理增加金币的请求
	Request* request3 = new RequestAddResource(handle); //处理增加资源的请求
	//服务器程序
	Server* server = new Server;
	//把请求放到服务器里，让服务器逐个处理
	server->addRequest(request1);
	server->addRequest(request2);
	server->addRequest(request3);
	//开始处理请求
	server->startHandleRequest();  //开始处理请求
}
int main(){
	doBussiness();
	system("pause");
	return EXIT_SUCCESS;
}
