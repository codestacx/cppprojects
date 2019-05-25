#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ROW 3
#define COL 3
using namespace std;


class Puzzle{

	int gn = 0;
	vector <int> queue;
	int puzzle_goal[ROW][COL];
	int puzzle_search[ROW][COL];
	
public:
	Puzzle(int p[][3], int s[][3]){

		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				this->puzzle_goal[i][j] = p[i][j];
			}
		}

		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				this->puzzle_search[i][j] = s[i][j];
			}
		}
	}
	
	//function to check if the current state is goal state
   bool isGoalState(){
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				if (this->puzzle_goal[i][j] != this->puzzle_search[i][j])
					return false;
			}
		}
		return true;
	}
	


   // function to increment gn at each step
	void get_gn(){
		this->gn+=1;
	}
	
	
	//function to display array contents after each step
	void dump(int temp[][3]){
	
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				cout << temp[i][j] << " ";
				//cout << this->puzzle_search[i][j] << " ";
			}
			cout << endl;
		}
		
	}
	int moveup()
	{
		int temp[3][3], i, j;
	
		for (i = 0; i<3; i++)  
	
			for (j = 0; j<3; j++)
				temp[i][j] = this->puzzle_search[i][j];
	
		for (i = 1; i<3; i++)   
			for (j = 0; j<3; j++)
				if (this->puzzle_search[i][j] == 0)
				{
					temp[i - 1][j] = 0;
					temp[i][j] = this->puzzle_search[i - 1][j];
				}
		return hn(temp);
	}
	
	int movedown()
	{
		int temp[3][3], i, j;
	
		for (i = 0; i<3; i++)
			for (j = 0; j<3; j++)
				temp[i][j] = this->puzzle_search[i][j];
	
		for (i = 0; i<2; i++)  
			for (j = 0; j<3; j++)
				if (this->puzzle_search[i][j] == 0)
				{
					temp[i + 1][j] = 0;
					temp[i][j] = this->puzzle_search[i + 1][j];
				}
		return hn(temp);
	}
	
	int moveleft()
	{
		int temp[3][3], i, j;
	
		for (i = 0; i<3; i++)
			for (j = 0; j<3; j++)
				temp[i][j] = this->puzzle_search[i][j];
	
		for (i = 0; i<3; i++)  
			for (j = 1; j<3; j++)
				if (this->puzzle_search[i][j] == 0)
				{
					temp[i][j - 1] = 0;
					temp[i][j] = this->puzzle_search[i][j - 1];
				}
		return hn(temp);
	}
	




	int moveright()
	{
		int temp[3][3], i, j;
	
		for (i = 0; i<3; i++)
			for (j = 0; j<3; j++)
				temp[i][j] = this->puzzle_search[i][j];
	
		for (i = 0; i<3; i++)   // swthis->puzzle_searchpping the spthis->puzzle_searchce in the right direction
			for (j = 0; j<2; j++)
				if (this->puzzle_search[i][j] == 0)
				{
					temp[i][j + 1] = 0;
					temp[i][j] = this->puzzle_search[i][j + 1];
				}
		return hn(temp);
	}
	int hn(int temp[][3]){
		int counter = 0;
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				// && this->puzzle_goal[i][j] != 0
				if (temp[i][j] != this->puzzle_goal[i][j] && temp[i][j]!=0 ){
					counter += 1;
				}
			}
		}
		
		return counter;
	}

	int getMin(){
		vector<int>::iterator it;
		int t = this->queue[0];
		it = this->queue.begin();
		this->queue.erase(it);
		return t;

	}
	void sortQueue(){
		bool swapp = true;
		while (swapp){
			swapp = false;
			for (size_t i = 0; i < this->queue.size() - 1; i++) {
				if (queue[i]>queue[i + 1]){
					queue[i] += queue[i + 1];
					queue[i + 1] = queue[i] - queue[i + 1];
					queue[i] -= queue[i + 1];
					swapp = true;
				}
			}
		}
		
	}
	
	int getD(){
		int position = 0;
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){

				if (this->puzzle_search[i][j] == 0){
					return position+1;
					
				}
				else
				{
					position += 1;
				}
				
			}
		}
	}

	int returnBlank(int board[][3]){
		int pos = 1;
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				if (board[i][j] == 0)
					return pos;
				pos += 1;
			}
		}
		return 0;
	}
   



	void BFS(){
		int d;
		int step = 0;
		this->queue.push_back(hn(this->puzzle_search));
			while (!queue.empty())
			{
				sortQueue();     // sort queue in increasing order
				d = getMin();   // pick the minimum cost 
				if (isGoalState())  { 
					cout << "Total steps taken: " << step << endl;
					//cout << "Total heuristics Cost : " << d << endl;
					cout << "Goal state " << endl;
					system("PAUSE"); 
					break;
				}
				step++;
				this->get_gn();
				cout << "Step : " << step << endl;
				BFS_EXECUTE();
				dump(this->puzzle_search);
			
			}
	}

	int minimum(int a, int b, int c, int d)
	{
		int min = a;
		if (b<min)
			min = b;
		if (c<min)
			min = c;
		if (d<min)
			min = d;
	
		return min;
	}

	int BFS_EXECUTE()
	{
	
		int dup, ddown, dleft, dright;
		int temp, i, j, flag = 0, serial = 0;
		char ran[4];
		dup = moveup() + gn; ddown = movedown() + gn;	dleft =moveleft() + gn;
		dright = moveright() + gn;
			this->queue.push_back(dup);this->queue.push_back(ddown);this->queue.push_back(dleft);this->queue.push_back(dright);
		int min = minimum(dup, ddown, dleft, dright);
		
		if (min == dright)
			ran[serial++] = 'r';
		if (min == dleft)
			ran[serial++] = 'l';
		if (min == dup)
			ran[serial++] = 'u';
		if (min == ddown)
			ran[serial++] = 'd';
		
		int sel = rand() % serial;
		
	
		char change = ran[sel];
	
		if (change == 'r'){
			for (i = 0; i<3; i++)
				for (j = 0; j<2; j++)
					if (this->puzzle_search[i][j] == 0) {
						this->puzzle_search[i][j] = this->puzzle_search[i][j + 1];
						this->puzzle_search[i][j + 1] = 0; 
						cout <<"right\n"; 
					return 0; 
				}
		}
	
		else if (change == 'l'){
			for (i = 0; i<3; i++)
				for (j = 1; j<3; j++)
					if (this->puzzle_search[i][j] == 0) {
						this->puzzle_search[i][j] = this->puzzle_search[i][j - 1];
						this->puzzle_search[i][j - 1] = 0;  
						cout <<"left\n";
			return 0; }
		}
	
		else if (change == 'u'){
			for (i = 1; i<3; i++)
				for (j = 0; j<3; j++)
					if (this->puzzle_search[i][j] == 0){ 
						this->puzzle_search[i][j] = this->puzzle_search[i - 1][j];
						this->puzzle_search[i - 1][j] = 0;
						cout << "Up " << endl;
						return 0;
					}
		}
	
		else if (change == 'd')
		{
			for (i = 0; i<2; i++)
				for (j = 0; j<3; j++)
					if (this->puzzle_search[i][j] == 0) {
						this->puzzle_search[i][j] = this->puzzle_search[i + 1][j];
						this->puzzle_search[i + 1][j] = 0;
						cout << "down\n"; return 0; }
		}
		return 0;
	}
};
int main()
{
	
	int puzzle_goal[3][3] = { { 1, 2, 3 }, { 8, 0, 4 }, { 7, 6, 5 } };

	int puzzle_search[3][3] = {
		{ 1, 2, 3 },
		{ 6, 0, 4 },
		{ 8, 7, 5 }
	};
	
	Puzzle obj(puzzle_goal,puzzle_search);
	obj.BFS();
	
	cout.put('\n');
	return 0;
}