#include <iostream>
#include <queue>
using namespace std;
class ServiceHandle{
	public:
		void HandleService1(){
			cout<<"gei wanjiazengjiayiwanzuanshi"<<endl;
		}
		void HandleService2(){
			cout<<"zengjiayiqinajinbin"<<endl;
		}
		void HandleService3(){
			cout<<"zengjiawuqianziyuan"<<endl;
		}
};
class Request{
	public:
		virtual void Handle()=0;
};
class Server{
	public:
		void addRequest(Request* request){
			queueRequest.push(request);
		}
		void startHandleRequest(){
			while(queueRequest.size()>0){
				Request* request.front();
				request->Handle();
				queueRequest.pop();
			}
		}
	private:
		queue<Request*> queueRequest;
};
class RequestAddDiamond:public Request{
	public:
		RequestAddDiamond(
		virtual void Handle(){
			this->service->HandleService1;
		}
	public:
		ServiceHandle* ser:vice;
};
int main(void)
{
	return 0;
}
