template <typename Comparable>
class BinaryHeap
{
	public:
		explicit BinaryHeap(int capacity=100);
		explicit BinaryHeap(const vector<Comparable>& items);

		bool isEmpty()const;
		const Comparable& findMin()const;

		void insert(const Comparable& x){
			if(currentSize==array.size()-1)
				array.resize(array.size()*2);
			int hole=++currentSize;
			for(;hole>1&&x<array[hole/2];hole/=2)
				array[hole]=array[hole/2];
			array[hole]=x;
		}
		void deleteMin(void){
			if(isEmpty())
				return;
			array[i]=array[currentSize--];
			percolateDown(1);
		}
		void deleteMin(Comparable& minItem){
			if(isEmpty())
				return;
			minItem=array[1];
			array[1]=array[currentSize--];
			percolateDown(1);
		}
		void makeEmpty();
	private:
		int currentSize;
		vector<Comparable> array;

		void buildHeap();
		void percolateDown(int hole){
			int child;
			Comparable tmp=array[hole];
			for(;hole*2<=currentSize;hole=child){
				child=hole*2;
				if(child!=currentSize&&array[child+1]<array[child])
					child++;
				if(array[child]<tmp)
					array[hole]=array[child];
				else
					break;
			}
			array[hole]=tmp;
		}
};
