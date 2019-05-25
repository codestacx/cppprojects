//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//#define ROW 3
//#define COL 3
//using namespace std;
//
//
//class Puzzle{
//	
//	int goal[3][3]; // goal to be found
//
//	int src[3][3]; // src to be compared 
//	
//
//public:
//	Puzzle(int goal[][3], int target[][3]){
//		for (int i = 0; i < 3; i++){
//			for (int j = 0; j < 3; j++){
//				this->goal[i][j] = goal[i][j];
//				this->src[i][j] = src[i][j];
//			}
//		}
//	}
//	bool isGoalState(){
//		for (int i = 0; i < 3; i++){
//			for (int j = 0; j < 3; j++){
//				if (this->goal[i][j] != this->src[i][j])
//					return false;
//			}
//		}
//		return true;
//	}
//		
//	
//	
//		//function to display array contents after each step
//		void dump(int temp[][3]){
//	
//			for (int i = 0; i < 3; i++){
//				for (int j = 0; j < 3; j++){
//					cout << temp[i][j] << " ";
//					//cout << this->src[i][j] << " ";
//				}
//				cout << endl;
//			}
//	
//		}
//		bool diffup(){
//			int temp[3][3], i, j;
//	
//			for (i = 0; i<3; i++)
//	
//				for (j = 0; j<3; j++)
//					temp[i][j] = this->src[i][j];
//	
//			for (i = 1; i<3; i++)
//				for (j = 0; j<3; j++)
//					if (this->src[i][j] == 0)
//					{
//						temp[i - 1][j] = 0;
//						temp[i][j] = this->src[i - 1][j];
//					}
//			return true;
//		}
//	
//		bool diffdown()
//		{
//			int temp[3][3], i, j;
//	
//			for (i = 0; i<3; i++)
//				for (j = 0; j<3; j++)
//					temp[i][j] = this->src[i][j];
//	
//			for (i = 0; i<2; i++)
//				for (j = 0; j<3; j++)
//					if (this->src[i][j] == 0)
//					{
//						temp[i + 1][j] = 0;
//						temp[i][j] = this->src[i + 1][j];
//					}
//			return true;
//		}
//	
//		bool diffleft()
//		{
//			int temp[3][3], i, j;
//	
//			for (i = 0; i<3; i++)
//				for (j = 0; j<3; j++)
//					temp[i][j] = this->src[i][j];
//	
//			for (i = 0; i<3; i++)
//				for (j = 1; j<3; j++)
//					if (this->src[i][j] == 0)
//					{
//						temp[i][j - 1] = 0;
//						temp[i][j] = this->src[i][j - 1];
//					}
//			return true;
//		}
//	
//		bool diffright(int temp[][3]){
//			int  i, j;
//	
//			for (i = 0; i<3; i++)
//				for (j = 0; j<3; j++)
//					temp[i][j] = this->src[i][j];
//	
//			for (i = 0; i<3; i++)   // swthis->srcpping the spthis->srcce in the right direction
//				for (j = 0; j<2; j++)
//					if (this->src[i][j] == 0)
//					{
//						temp[i][j + 1] = 0;
//						temp[i][j] = this->src[i][j + 1];
//					}
//			
//		
//		}
//		
//		
//		
//		int countMoves(int temp[][3]){
//			int position = 0;
//			for (int i = 0; i < 3; i++)
//				for (int j = 0; j < 3; j++)
//					if (temp[i][j] == 0){
//						position += 1;
//						break;
//					}
//					else{
//						position += 1;
//					}
//						
//					
//						
//
//					if (position == 5){
//						return 4;
//					}
//					else if (position == 0 || position == 3 || position == 7 || position == 9){
//						return 2;
//					}
//					else{
//						return 3;
//					}
//		}
//	
//		
//		bool shiftRight(int temp[][3]){
//			for (int i = 0; i<3; i++)
//				for (int j = 0; j<2; j++)
//					if (temp[i][j] == 0) {
//						temp[i][j] = this->src[i][j + 1];
//						temp[i][j + 1] = 0;
//						return 0;
//					}
//
//		}
//		int  getPosition(int temp[][3]){
//			int position = 0;
//			for (int i = 0; i < 3; i++){
//				for (int j = 0; j < 3; j++){
//					if (position == 0){
//						position += 1;
//						break;
//					}
//					position += 1;
//				}
//			}
//			if (position == 5){
//				return 0;
//			}
//			else if (position == 0 || position == 3 || position == 7 || position == 9){
//				return 1;
//			}
//			else {
//				return 2;
//			}
//		}
//		bool shiftUp(int temp[][], int a[][]){
//			int i, j;
//			
//			for (i = 1; i < 3; i++){
//				for (j = 0; j < 3; j++){
//					if (this->puzzle_search[i][j] == 0){
//						this->puzzle_search[i][j] = this->puzzle_search[i - 1][j];
//						this->puzzle_search[i - 1][j] = 0;
//						cout << "Up " << endl;
//						return 0;
//					}
//				}
//			}
//				
//						
//		}
//		bool DLS(int source[][3],int target[][3],int limit){
//
//			if (isGoalState()){
//				return true;
//			}
//			if (limit <= 0){
//				return false;
//			}
//
//			// create a temporary array 
//			int temp[3][3], i, j;
//
//
//			// make a copy of the source array 
//			
//
//
//			int a[3][3], b[3][3], c[3][3], d[3][3];
//			if (getPosition(temp)==0){
//				//for center position
//				for (int i = 0; i < 3; i++){
//					for (int j = 0; j < 3; j++){
//						a[i][j] = source[i][j];
//						b[i][j] = source[i][j];
//						c[i][j] = source[i][j];
//						d[i][j] = source[i][j];
//					}
//				}S
//
//
//				// = ========= = = == = = == == = = = = = = 
//
//				//DLS();
//				
//
//			}
//			else if (getPosition(temp) == 1){
//				//for corner sides 
//			}
//			else {
//				//for top/bottom rows 
//			}
//
//
//			/*
//			
//			if(atCenter){
//				
//				int[][] arr1 = new int[][];
//				DLS(arr1,target,limit-1);
//				int[][] arr2 = new int[][];
//
//				int[][] arr3 = new int[][];
//				int[][] arr4 = new int[][];
//
//				
//			}
//			
//			
//			
//			*/
//
//
//			cout << countMoves(temp);
//			for (int i = 0; i < countMoves(temp); i++){
//
//			}
//
//
//			
//						
//
//			
//				
//			
//
//		}
//
//		bool IDDFS(int max_depth){
//			for (int limit = 0; limit <= max_depth; limit++){
//
//				/*
//				if(DLS(this->src,this->target,limit)
//				return true;
//				return false;
//
//				*/
//			}
//		}
//
//
//
//		
//	
//		
//};
//
//int main()
//{
//	int puzzle_goal[3][3] = { 
//			{ 1, 2, 3 }, 
//			{8, 0, 4 }, 
//			{ 7, 6, 5 } 
//	};
//
//	int puzzle_search[3][3] = {
//		{ 2, 8, 3 },
//		{ 1, 6, 4 },
//		{ 7, 0, 5 }
//	};
//	Puzzle obj(puzzle_goal, puzzle_search);
//	
//	//obj.DLS(puzzle_search,puzzle_goal,3);
//	//obj.showpq();
//	//obj.solver();
//	cout.put('\n');
//	return 0;
//}