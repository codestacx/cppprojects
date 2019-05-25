//#include <iostream>
//#include <stdlib.h>
//#include <vector>
//using namespace std;
//class Puzzle{
//	int goal[3][3];
//	int initial[3][3];
//	int gn = 0;
//	vector<int> queue;
//public:
//	Puzzle(int p[][3], int s[][3]){
//
//		for (int i = 0; i < 3; i++){
//			for (int j = 0; j < 3; j++){
//				this->goal[i][j] = p[i][j];
//			}
//		}
//
//
//		for (int i = 0; i < 3; i++){
//			for (int j = 0; j < 3; j++){
//				this->initial[i][j] = s[i][j];
//			}
//		}
//	}
//	void increment_gn(){
//		this->gn += 1;
//	}
//	void dump(){
//		for (int i = 0; i < 3; i++){
//			for (int j = 0; j < 3; j++){
//				cout << this->initial[i][j] << " ";
//			}
//			cout << endl;
//		}
//	}
//	bool isGoalState(){
//		for (int i = 0; i < 3; i++){
//			for (int j = 0; j < 3; j++){
//				if (this->goal[i][j] != this->initial[i][j])
//					return false;
//			}
//		}
//		return true;
//	}
//	int hn(int temp[][3]){
//		int counter = 0;
//		//dump(temp);
//		for (int i = 0; i < 3; i++){
//			for (int j = 0; j < 3; j++){
//				// && this->puzzle_goal[i][j] != 0
//				if (temp[i][j] != this->goal[i][j] && temp[i][j] != 0){
//					counter += 1;
//				}
//			}
//		}
//
//		return counter;
//	}
//	int up(){
//		int temp[3][3], i, j;
//
//		for (i = 0; i<3; i++)   //menyalin array A dalam array untuk pengujian
//			for (j = 0; j<3; j++)
//				temp[i][j] = this->initial[i][j];
//
//		for (i = 1; i<3; i++)   // swapping the space in upward  direction
//			for (j = 0; j<3; j++)
//				if (this->initial[i][j] == 0)
//				{
//					temp[i - 1][j] = 0;
//					temp[i][j] = this->initial[i - 1][j];
//				}
//		return hn(temp);
//	}
//	int down(){
//		int temp[3][3], i, j;
//
//		for (i = 0; i<3; i++)
//			for (j = 0; j<3; j++)
//				temp[i][j] = this->initial[i][j];
//
//		for (i = 0; i<2; i++)   // swapping the space in downward  direction
//			for (j = 0; j<3; j++)
//				if (this->initial[i][j] == 0)
//				{
//					temp[i + 1][j] = 0;
//					temp[i][j] = this->initial[i + 1][j];
//				}
//		return hn(temp);
//	}
//	int left(){
//		int temp[3][3], i, j;
//
//		for (i = 0; i<3; i++)
//			for (j = 0; j<3; j++)
//				temp[i][j] = this->initial[i][j];
//
//		for (i = 0; i<3; i++)   // swapping the space in the left  direction
//			for (j = 1; j<3; j++)
//				if (this->initial[i][j] == 0)
//				{
//					temp[i][j - 1] = 0;
//					temp[i][j] = this->initial[i][j - 1];
//				}
//		return hn(temp);
//	}
//	int right(){
//		int temp[3][3], i, j;
//
//		for (i = 0; i<3; i++)
//			for (j = 0; j<3; j++)
//				temp[i][j] = this->initial[i][j];
//
//		for (i = 0; i<3; i++)   // swapping the space in the right direction
//			for (j = 0; j<2; j++)
//				if (this->initial[i][j] == 0)
//				{
//					temp[i][j + 1] = 0;
//					temp[i][j] = this->initial[i][j + 1];
//				}
//		return hn(temp);
//	}
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
//	int minimum(int a, int b, int c, int d){
//		int min = a;
//		if (b<min)
//			min = b;
//		if (c<min)
//			min = c;
//		if (d<min)
//			min = d;
//
//		return min;
//	}
//	void modify(int u, int d, int r, int l){
//
//		int min = minimum(u, d, l, r);
//		//printf("%d\n", min);
//		char ran[4];
//		int serial = 0;
//		if (min == r)
//			ran[serial++] = 'r';
//		if (min == l)
//			ran[serial++] = 'l';
//		if (min == u)
//			ran[serial++] = 'u';
//		if (min == d)
//			ran[serial++] = 'd';
//
//		int sel = rand() % serial;
//		char change = ran[sel]; int i, j;
//		if (change == 'r')
//		{
//			for (i = 0; i<3; i++)
//				for (j = 0; j<2; j++)
//					if (initial[i][j] == 0) {
//						initial[i][j] = initial[i][j + 1];
//						initial[i][j + 1] = 0;
//
//					}
//		}
//
//		else if (change == 'l')
//		{
//			for (i = 0; i<3; i++)
//				for (j = 1; j<3; j++)
//					if (initial[i][j] == 0) {
//						initial[i][j] = initial[i][j - 1];
//						initial[i][j - 1] = 0;
//					}
//		}
//
//		else if (change == 'u')
//		{
//			for (i = 1; i<3; i++)
//				for (j = 0; j<3; j++)
//					if (initial[i][j] == 0){
//						initial[i][j] = initial[i - 1][j];
//						initial[i - 1][j] = 0;
//
//					}
//		}
//
//		else if (change == 'd')
//		{
//			for (i = 0; i<2; i++)
//				for (j = 0; j<3; j++)
//					if (initial[i][j] == 0){
//						initial[i][j] = initial[i + 1][j];      initial[i + 1][j] = 0;
//					}
//		}
//	}
//	int solver(){
//
//		int gup, gdown, gleft, gright;
//		int serial = 0;
//		char ran[4];
//
//		int steps = 1;
//		this->queue.push_back(this->hn(this->initial) + this->gn);
//		while (!this->queue.empty()){
//
//			this->sortQueue();
//			int m = getMin();
//
//			if (isGoalState()){
//
//				system("pause");
//				system("cls");
//				dump();
//				cout << "Goal state Reached" << endl;
//				cout << "Total steps : " << gn << endl;
//				cout << "Total heuristic Cost : " << m << endl;
//				break;
//			}
//
//			this->increment_gn();
//
//			gup = this->up() + gn;
//			gdown = this->down() + gn;
//			gright = this->right() + gn;
//			gleft = this->left() + gn;
//
//			this->queue.push_back(gup);
//			this->queue.push_back(gdown);
//			this->queue.push_back(gleft);
//			this->queue.push_back(gright);
//
//			steps += 1;
//			modify(gup, gdown, gright, gleft);
//
//			cout << "Step No: " << steps << endl;
//			dump();
//			cout << endl;
//
//			system("pause");
//
//		}
//		return 0;
//	}
//};
//int main(){
//
//	int puzzle_goal[3][3] = { { 1, 2, 3 }, { 8, 0, 4 }, { 7, 6, 5 } };
//	//	//int puzzle_search[3][3] = { { 1, 2, 3 }, { 8, 0, 4 }, { 7, 6, 5 } };
//	int puzzle_search[3][3] = {
//		{ 2, 8, 3 },
//		{ 1, 6, 4 },
//		{ 7, 0, 5 }
//	};
//	Puzzle obj(puzzle_goal, puzzle_search);
//	obj.solver();
//	cout.put('\n');
//
//
//}