#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3
class Block
{
	private:
		int center[2];
		int border[3];
		int direct;
		int type;
		
	public:
		Block(int ceterl,int centerc,int d,int t,int lborder,int rborder,int bborder)
			:center[0](centerl),center[1](centerc),direct(d),type(t),border[0](lborder),border[1](rborder),border[2](bborder)
		{
		}
		~Block();
		bool rotate(void){
			if(direct<3){
				direct+=1;
				return true;
			}
			else if(direct==3){
				direct=0;
				return true;
			}
			else{
				return false;
			}
		}
		vector<pair<int,int>> &operator()();
		bool mover(void){
			++center.second;
		}
		bool movel(void){
			--center.second;
		}
		bool fall(void){
			++center.first;
		}
}
