//// ######################################################### HEADER SECTION 
//#include <iostream>
//#include <string>
//#include<ctime>
//using namespace std;
//
//// ######################################################## USER DEFINED FUNCTIONS AREA 
//bool isGoal(int src[][3], int target[][3]){
//	for (int i = 0; i < 3; i++)
//		for (int j = 0; j < 3; j++)
//			if (src[i][j] != target[i][j])
//				return false;
//	return true;
//}
//void dump(int src[][3]){
//	for (int i = 0; i < 3; i++){
//		for (int j = 0; j < 3; j++){
//			cout <<src[i][j] <<" ";
//		}
//		cout.put('\n');
//	}
//	cout.put('\n');
//
//}
//bool up(int src[][3]){
//	int pos = 1;
//	bool flag = true;
//	for (int i = 0; i < 3; i++){
//		for (int j = 0; j < 3; j++){
//			if (src[i][j] == 0){
//				flag = false; break;
//			}
//				
//			else{
//				pos += 1;
//			}
//				
//		}
//		if (!flag){
//			break;
//		}
//	}
//	if (pos == 1 || pos == 2 || pos == 3){
//		return false;
//	}
//	return true;
//}
//void moveup(int(&src)[3][3]){
//
//
//	for (int i = 0; i < 3; i++){
//		for (int j = 0; j < 3; j++){
//			//cout << src[i][j] << " ";
//			if (src[i][j] == 0){
//				int t = src[i][j];
//				src[i][j] = src[i - 1][j];
//				src[i - 1][j] = t;
//			}
//		}
//		
//	}
//	
//}
//bool down(int src[][3]){
//	int pos = 1;
//	bool flag = true;
//	for (int i = 0; i < 3; i++){
//		for (int j = 0; j < 3; j++){
//			if (src[i][j] == 0){
//				flag = false;
//				break;
//			}
//				
//			else{
//				pos += 1;
//			}
//				
//		}
//		if (!flag){
//			break;
//		}
//	}
//	
//	if (pos == 7 || pos == 8 || pos == 9){
//		return false;
//	}
//	return true;
//}
//void movedown(int(&src)[3][3]){
//
//	for (int i = 0; i < 2; i++){
//
//		for (int j = 0; j < 3; j++){
//			if (src[i][j] == 0) {
//				src[i][j] = src[i + 1][j];
//				src[i + 1][j] = 0;
//
//			}
//		}
//	}
//}
//bool right(int src[][3]){
//	int pos = 1;
//	bool flag = false;
//	for (int i = 0; i < 3; i++){
//		for (int j = 0; j < 3; j++){
//			//cout << src[i][j] << " ";
//			if (src[i][j] == 0){
//				flag = true; break;
//			}
//				
//			else{
//				pos += 1;
//			}
//				
//		}
//		if (flag){
//			break;
//		}
//		
//	}
//	
//	if (pos == 3 || pos == 6 || pos == 9){
//		return false;
//	}
//	return true;
//}
//void moveright(int(&src)[3][3]){
//
//
//	for (int i = 0; i < 3; i++){
//		for (int j = 0; j < 2; j++){
//			//cout << src[i][j] << " ";
//			if (src[i][j] == 0){
//				src[i][j] = src[i][j+1];
//				src[i][j+1] = 0;
//			}
//		}
//
//	}
//
//}
//bool left(int src[][3]){
//	int pos = 1;
//	bool flag = false;
//	for (int i = 0; i < 3; i++){
//		for (int j = 0; j < 3; j++){
//			if (src[i][j] == 0){
//				flag = true; break;
//			}
//			else{
//				pos += 1;
//			}
//				
//		}
//		if (flag){
//			break;
//		}
//	}
//
//	if (pos == 1 || pos == 4 || pos == 7){
//		return false;
//	}
//	return true;
//}
//void moveleft(int(&src)[3][3]){
//
//
//	for (int i = 0; i < 3; i++){
//		for (int j = 0; j < 3; j++){
//			//cout << src[i][j] << " ";
//			if (src[i][j] == 0){
//				src[i][j] = src[i][j - 1];
//				src[i][j - 1] = 0;
//			}
//		}
//
//	}
//
//}
//bool DLS(int src[][3], int target[][3], int limit){
//	if (isGoal(src, target)){
//		return true;
//	}
//	
//	if (limit <= 0){
//		return false;
//	}
//
//		int t1[3][3];int t2[3][3];
//		int t3[3][3];int t4[3][3];
//
//		for (int i = 0; i < 3; i++){
//			for (int j = 0; j < 3; j++){
//				t1[i][j] = src[i][j];
//				t2[i][j] = src[i][j];
//				t3[i][j] = src[i][j]; t4[i][j] = src[i][j];
//			}
//		}
//
//		if (up(t1)){
//			moveup(t1); //dump(t1);
//			if (DLS(t1, target, limit - 1)){
//				return true;
//			}
//		}
//		 if (down(t2)){
//			 movedown(t2); //dump(t2);
//			if (DLS(t2, target, limit - 1)){
//				return true;
//			}
//		}
//		if (right(t3)){
//			moveright(t3); //dump(t3);
//			if (DLS(t3, target, limit - 1)){
//				return true;
//			}
//		}
//		if (left(t4)){
//			
//			moveleft(t4); //dump(t4);
//			if (DLS(t4, target, limit - 1)){
//				return true;
//			}
//		}
//	return false;
//}
//
//bool IDDFS(int (&src)[3][3], int (&target)[3][3], int max_depth){
//	
//	for (int limit = 0; limit <= max_depth; limit++){
//		if (DLS(src, target, limit)){
//			cout << "Goal Founded at depth : " << limit << endl;
//			// ================================================================================
//			return true;
//		}
//	}
//	return false;
//}
////#######################################################      Main Function 
//int main(){
//		cin.sync_with_stdio(0); 
//		cin.tie(0);
//		int puzzle_goal[3][3] = {
//			{ 1, 8, 7 }, { 2, 0, 6 }, { 3, 4, 5 } 
//		};
//		int puzzle_search[3][3] = {
//			{ 8, 6, 7 },
//			{ 2, 5, 4 },
//			{ 3, 0, 1 }
//		};
//		clock_t tStart = clock();
//		int depth;cout << "Enter Depth: ";cin >> depth;
//		if (!IDDFS(puzzle_search, puzzle_goal, depth)){
//			cout << "Goal Not  founded  at depth "<< depth  << endl;
//			return 0;
//		}
//		cout << "Time taken: %.2fs " << (double)(clock() - tStart) / CLOCKS_PER_SEC << endl;
//	return 0;
//}
//
////######################################################       END OF MAIN FUNCTION