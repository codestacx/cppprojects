//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//#define ROW 3
//#define COL 3
//using namespace std;
//
//class Puzzle{
//
//	
//	vector <int> queue;
//	int puzzle_goal[ROW][COL];
//	int puzzle_search[ROW][COL];
//
//	int c = 0;
//
//public:
//	Puzzle(int p[][3], int s[][3]){
//
//		for (int i = 0; i < 3; i++){
//			for (int j = 0; j < 3; j++){
//				this->puzzle_goal[i][j] = p[i][j];
//			}
//		}
//
//		for (int i = 0; i < 3; i++){
//			for (int j = 0; j < 3; j++){
//				this->puzzle_search[i][j] = s[i][j];
//			}
//		}
//	}
//
//	//function to check if the current state is goal state
//	bool isGoalState(){
//		for (int i = 0; i < 3; i++){
//			for (int j = 0; j < 3; j++){
//				if (this->puzzle_goal[i][j] != this->puzzle_search[i][j])
//					return false;
//			}
//		}
//		return true;
//	}
//
//	bool isGoalState(int temp[][3]){
//		for (int i = 0; i < 3; i++){
//			for (int j = 0; j < 3; j++){
//				if (this->puzzle_goal[i][j] != temp[i][j])
//					return false;
//			}
//		}
//		return true;
//	}
//	
//	
//	bool up(int src[][3]){
//		int pos = 1;
//		bool flag = true;
//		for (int i = 0; i < 3; i++){
//			for (int j = 0; j < 3; j++){
//				if (src[i][j] == 0){
//					flag = false; break;
//				}
//					else{
//					pos += 1;
//				}
//					
//			}
//			if (!flag){
//				break;
//			}
//		}
//		if (pos == 1 || pos == 2 || pos == 3){
//			return false;
//		}
//		return true;
//	}
//		bool down(int src[][3]){
//		int pos = 1;
//		bool flag = true;
//		for (int i = 0; i < 3; i++){
//			for (int j = 0; j < 3; j++){
//				if (src[i][j] == 0){
//					flag = false;
//					break;
//				}
//					
//				else{
//					pos += 1;
//				}
//					
//			}
//			if (!flag){
//				break;
//			}
//		}
//		
//		if (pos == 7 || pos == 8 || pos == 9){
//			return false;
//		}
//		return true;
//	}
//	bool right(int src[][3]){
//		int pos = 1;
//		bool flag = false;
//		for (int i = 0; i < 3; i++){
//			for (int j = 0; j < 3; j++){
//				//cout << src[i][j] << " ";
//				if (src[i][j] == 0){
//					flag = true; break;
//				}
//					
//				else{
//					pos += 1;
//				}
//					
//			}
//			if (flag){
//				break;
//			}
//			
//		}
//		
//		if (pos == 3 || pos == 6 || pos == 9){
//			return false;
//		}
//		return true;
//	}
//	
//	bool left(int src[][3]){
//		int pos = 1;
//		bool flag = false;
//		for (int i = 0; i < 3; i++){
//			for (int j = 0; j < 3; j++){
//				if (src[i][j] == 0){
//					flag = true; break;
//				}
//				else{
//					pos += 1;
//				}
//					
//			}
//			if (flag){
//				break;
//			}
//		}
//	
//		if (pos == 1 || pos == 4 || pos == 7){
//			return false;
//		}
//		return true;
//	}
//	
//	void dump(int temp[][3]){
//
//		for (int i = 0; i < 3; i++){
//			for (int j = 0; j < 3; j++){
//				cout << temp[i][j] << " ";
//				//cout << this->puzzle_search[i][j] << " ";
//			}
//			cout << endl;
//		}
//
//	}
//	int moveup()
//	{
//		int temp[3][3], i, j;
//		for (i = 0; i < 3; i++){
//			for (j = 0; j < 3; j++){
//				temp[i][j] = this->puzzle_search[i][j];
//			}
//		}
//
//		for (i = 1; i < 3; i++){
//			for (j = 0; j < 3; j++){
//				if (this->puzzle_search[i][j] == 0)
//				{
//					temp[i - 1][j] = 0;
//					temp[i][j] = this->puzzle_search[i - 1][j];
//				}
//			}
//		}
//		return gashing(temp);
//	}
//
//	int movedown()
//	{
//		int temp[3][3], i, j;
//
//		for (i = 0; i<3; i++)
//			for (j = 0; j<3; j++)
//				temp[i][j] = this->puzzle_search[i][j];
//
//		for (i = 0; i<2; i++)
//			for (j = 0; j<3; j++)
//				if (this->puzzle_search[i][j] == 0)
//				{
//					temp[i + 1][j] = 0;
//					temp[i][j] = this->puzzle_search[i + 1][j];
//				}
//		return gashing(temp);
//		
//	}
//
//	int moveleft()
//	{
//		int temp[3][3], i, j;
//		for (i = 0; i<3; i++)
//			for (j = 0; j<3; j++)
//				temp[i][j] = this->puzzle_search[i][j];
//
//		for (i = 0; i<3; i++)
//			for (j = 1; j<3; j++)
//				if (this->puzzle_search[i][j] == 0)
//				{
//					temp[i][j - 1] = 0;
//					temp[i][j] = this->puzzle_search[i][j - 1];
//				}
//		return gashing(temp);
//		
//	}
//	int moveright()
//	{
//		int temp[3][3], i, j;
//
//		for (i = 0; i<3; i++)
//			for (j = 0; j<3; j++)
//				temp[i][j] = this->puzzle_search[i][j];
//
//		for (i = 0; i<3; i++)   // swthis->puzzle_searchpping the spthis->puzzle_searchce in the right direction
//			for (j = 0; j<2; j++)
//				if (this->puzzle_search[i][j] == 0)
//				{
//					temp[i][j + 1] = 0;
//					temp[i][j] = this->puzzle_search[i][j + 1];
//				}
//		return gashing(temp);
//		
//	}
//	
//
//	int getMin(){
//		vector<int>::iterator it;
//		int t = this->queue[0];
//		it = this->queue.begin();
//		this->queue.erase(it);
//		return t;
//
//	}
//	void sortQueue(){
//		bool swapp = true;
//		while (swapp){
//			swapp = false;
//			for (size_t i = 0; i < this->queue.size() - 1; i++) {
//				if (queue[i]>queue[i + 1]){
//					queue[i] += queue[i + 1];
//					queue[i + 1] = queue[i] - queue[i + 1];
//					queue[i] -= queue[i + 1];
//					swapp = true;
//				}
//			}
//		}
//
//	}
//	bool BlankInGoalPosition(int temp[][3]){
//		for (int x = 0; x < 3; x++)
//			for (int y = 0; y < 3; y++)
//				if (temp[x][y] == 0)
//					if (this->puzzle_goal[x][y] == 0)
//						return true;
//		return false;
//	}
//	void swapWithMisMatch(int (&temp)[3][3],bool c){
//		if (c){
//			bool flag = false;
//			for (int i = 0; i < 3; i++){
//				for (int j = 0; j < 3; j++){
//					if (temp[i][j] != this->puzzle_goal[i][j]){
//						int z = temp[i][j];  // t= 6
//						flag = true;					
//						for (int k = 0; k < 3; k++){
//							for (int t = 0; t < 3; t++){
//								if (temp[k][t] == 0){
//									temp[k][t] = z;
//									// 6
//									break;
//								}
//							}
//						}
//						temp[i][j] = 0;
//						break;
//					}
//				}
//				if (flag){
//					break;
//				}
//			}
//		}
//
//		else{
//			bool u = false;
//			for (int i = 0; i < 3; i++){
//				for (int j = 0; j < 3; j++){
//					if (temp[i][j] == 0){
//						u = true;
//						int z = this->puzzle_goal[i][j]; bool is = false;
//						for (int k = 0; k < 3; k++){
//							for (int t = 0; t < 3; t++){
//								if (temp[k][t] == z){
//									temp[k][t] = 0; is = true;
//									break;
//								}
//								if (is)
//									break;
//							}
//						}
//						temp[i][j] = z;
//						break;
//					}
//				}
//				if (u){
//					break;
//				}
//			}
//
//		}
//	}
//
//	
//	int gashing(int t[][3]){
//		int temp[3][3];
//		int count = 0;
//		for (int i = 0; i < 3; i++)
//			for (int j = 0; j < 3; j++)
//				temp[i][j] = t[i][j];
//
//		while (!isGoalState(temp)){
//			 
//			//system("pause");
//			if (BlankInGoalPosition(temp)){
//				//cout << "mismatch" << endl;
//				swapWithMisMatch(temp, true);
//				//swap blank with any mismatch
//			}
//			else{
//				//swap blank with matched tile
//				swapWithMisMatch(temp, false);
//				//cout << "matched" << endl;
//			}
//			//dump(temp);
//			count += 1;
//		}
//		//cout << "Done: " <<count << endl;
//		return count;
//	}
//	void BFS(){
//		int d;
//		int step = 0;
//		this->queue.push_back(this->gashing(this->puzzle_search));
//		while (!queue.empty())
//		{
//			sortQueue();     // sort queue in increasing order
//			if (isGoalState())  {
//				cout << "Goal state " << endl;
//				cout << "Total steps taken: " << step << endl;
//				system("PAUSE");
//				break;
//			}
//			step++;
//			BFS_EXECUTE();
//		}
//	}
//	int BFS_EXECUTE()
//	{
//		if (this->c == 4){
//			cout.put('\n'); this->c = 0;
//		}
//		this->c += 1;
//		int infinity = 100;
//		int dup=-1, ddown=-1, dleft=-1, dright=-1;
//		int temp, i, j, flag = 0, serial = 0;
//		char ran[4];
//		int min=100;
//		if (up(this->puzzle_search)){
//			dup = moveup(); this->queue.push_back(dup);
//			if (dup < min)
//				min = dup;
//				
//		}
//		if (down(this->puzzle_search)){
//			ddown = movedown(); this->queue.push_back(ddown);
//			if (ddown < min)
//				min = ddown;
//		}
//		if (left(this->puzzle_search)){
//			dleft = moveleft(); this->queue.push_back(dleft);
//			if (dleft < min)
//				min = dleft;
//
//		}
//		if (right(this->puzzle_search)){
//			dright = moveright(); this->queue.push_back(dright);
//			if (dright < min)
//				min = dright;
//		}
//
//		if (min == dright)
//			ran[serial++] = 'r';
//		if (min == dleft)
//			ran[serial++] = 'l';
//		if (min == dup)
//			ran[serial++] = 'u';
//		if (min == ddown)
//			ran[serial++] = 'd';
//		int sel = rand() % serial;
//		char change = ran[sel];
//
//		if (change == 'r'){
//			for (i = 0; i<3; i++)
//				for (j = 0; j<2; j++)
//					if (this->puzzle_search[i][j] == 0) {
//						this->puzzle_search[i][j] = this->puzzle_search[i][j + 1];
//						this->puzzle_search[i][j + 1] = 0;
//						cout << "right ->  ";
//						return 0;
//					}
//		}
//
//		else if (change == 'l'){
//			for (i = 0; i<3; i++)
//				for (j = 1; j<3; j++)
//					if (this->puzzle_search[i][j] == 0) {
//						this->puzzle_search[i][j] = this->puzzle_search[i][j - 1];
//						this->puzzle_search[i][j - 1] = 0;
//						cout << "left ->  ";
//						return 0;
//					}
//		}
//
//		else if (change == 'u'){
//			for (i = 1; i<3; i++)
//				for (j = 0; j<3; j++)
//					if (this->puzzle_search[i][j] == 0){
//						this->puzzle_search[i][j] = this->puzzle_search[i - 1][j];
//						this->puzzle_search[i - 1][j] = 0;
//						cout << "Up ->  " ;
//						return 0;
//					}
//		}
//
//		else if (change == 'd')
//		{
//			for (i = 0; i<2; i++)
//				for (j = 0; j<3; j++)
//					if (this->puzzle_search[i][j] == 0) {
//						this->puzzle_search[i][j] = this->puzzle_search[i + 1][j];
//						this->puzzle_search[i + 1][j] = 0;
//						cout << "down->  "; return 0;
//					}
//		}
//		return 0;
//	}
//};
//int main()
//{
//
//	
//	int puzzle_goal[3][3] = {
//				{ 1, 8, 7 }, { 2, 0, 6 }, { 3, 4, 5 } 
//				};
//	int puzzle_search[3][3] = {
//		{ 2, 1, 8 },
//		{ 3, 6, 7 },
//		{ 4, 5, 0 }
//	};
//
//	Puzzle obj(puzzle_goal, puzzle_search);
//	obj.BFS();
//	cout.put('\n');
//	return 0;
//}