#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
template <typename T>
class RoundRobin
{
	public:
		//Client can give a hint as to the number of expected elements for
		//increased efficiency.
		RoundRobin(int numExpected=0);
		virtual ~RoundRobin();
		//Appends elem to the end of the list..May be called
		//between calls to getNext().
		void add(const T& elem);
		//Removes the first (and only the first) element
		//int the list that is equal (with operator==) to elem.
		//May be called between calls to getNext().
		void remove(const T& elem);
		//Returns the next element in the list. starting with the first,
		//and cycling back to the first when the end of the list is
		//reached, taking into account elements that are added or removed.
		T& getNext()throw(std::out_of_range);
	protected:
		std::vector<T> mElems;
		typename std::vector<T>::iterator mCurElem;
	private:
		//Prevent assignment and pass-by-value.
		RoundRobin(const RoundRobin& src);
		RoundRobin& operator=(const RoundRobin& rhs);
};
template<typename T>
RoundRobin<T>::RoundRobin(int numExpected)
{
	//if the client give a guideline,resurve that much space.
	mElems.reserve(numExpected);
	//Initialize mCurElem even though it isn't used until
	//there's at least one element
	mCurElem=mElems.begin();
}
template<typename T>
RoundRobin<T>::~RoundRobin()
{
	//nothing ot do here -- the vector will delete all the elements
}
//Always add the new element at the end
template<typename T>
void RoundRobin<T>::add(const T& elem)
{
	//Even though we add the element at the end, the vector could
	//reallocate and invalidate the iterator with the push_back call.
	//Take advantage of the random access iterator features to save our
	//spot.
	int pos=mCurElem-mElems.begin();
	//add the elememt
	mElems.push_back(elem);
	//Reset our iterator to make sure it is valid.
	mCurElem=mElems.begin()+pos;
}
template<typename T>
void RoundRobin<T>::remove(const T& elem)
{
	for(auto it=mElems.begin();it!=mElems.end();++it){
		if(*it==elem){
			//Removing 	an element will ivalidate our mCurElem iterator if
			//it refers to an element past the point of the removal.
			//Take advantage of the random access features of the iterator
			//to track the position of the current element after removal.
			int newPos;
			//If current iterator is before or at the one we're removing,
			//the new position is the same as before.
			if(mCurElem<=it){
				newPos=mCurElem-mElems.begin();
			}else{
				//otherwise,it's one less than before
				newPos=mCurElem-mElems.begin()-1;
			}
			//erase the element (and ignore the return value)
			mElems.erase(it);
			//Now reset our iterator to make sure it is valid.
			mCurElem=mElems.begin()+newPos;
			//If we were pointing ot the last element and it was removed,
			//we need to loop back to the first.
			if(mCurElem==mElems.end()){
				mCurElem=mElems.begin();
			}
			return;
		}
	}
}
template<typename T>
T& RoundRobin<T>::getNext()throw(std::out_of_range)
{
	//First, make sure there are any elements.
	if(mElems.empty()){
		throw std::out_of_range("No elements in the list");
	}
	//retrieve a reference to return 
	T& retVal=*mCurElem;
	//Increment the iterator modulo the number of elements
	++mCurElem;
	if(mCurElem==mElems.end()){
		mCurElem=mElems.begin();
	}
	//return the reference
	return retVal;
}
//Simple Process class
class Process
{
	public:
		//Constructor accepting the name of the process.
		Process(const string& name):mName(name){}
		//Implementation of doWorkDuringTimeSlice would let the process
		//perform its work for the duration of a time slice.
		//Actual implementation omitted.
		void doWorkDuringTimeSlice(){
			cout<<"Process "<<mName
				<<" performing work during time slice."<<endl;
		}
		//Needed for the RoundRobin::remove method to work.
		bool operator==(const Process& rhs){
			return mName==rhs.mName;
		}
	protected:
		string mName;
};
//Simple round-robin based process scheduler.
class Scheduler
{
	public:
		//Constructor takes a vector of process.
		Scheduler(const vector<Process>& processes);
		//Selects the next process using a round-robin scheduling
		//algorithm and allows it to perform some work during
		//this time slice
		void scheduleTimeSlice();
		//Remove the given proces from the list of processes.
		void removeProcess(const Process& process);
	protected:
		RoundRobin<Process> rr;
};
Scheduler::Scheduler(const vector<Process>& processes)
{
	//Add the processes
	for(auto& process:processes){
		rr.add(process);
	}
}
void Scheduler::scheduleTimeSlice()
{
	try{
		rr.getNext().doWorkDuringTimeSlice();
	}catch(const out_of_range){
		cerr<<"No more processes to schedule."<<endl;
	}
}
void Scheduler::removeProcess(const Process& process)
{
	rr.remove(process);
}
int main(void)
{
	vector<Process> processes={Process("1"),Process("2"),Process("3")};
	Scheduler sched(processes);
	for(int i=0;i<4;++i)
			sched.scheduleTimeSlice();
	sched.removeProcess(processes[1]);
	cout<<"Removed second process"<<endl;
	for(int i=0;i<4;++i)
		sched.scheduleTimeSlice();
	return 0;
}
