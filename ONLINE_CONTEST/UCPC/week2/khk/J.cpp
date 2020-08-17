#include <iostream>
#include <cmath>

#define PI 3.141592

using namespace std;

class pot{
	public:
		int contents[5][5];
		int colors[5][5];
		int ings[3][4][4];
		int dir;

		pot(int ingredients[][4][4])
		:angle(0)
		{
			for(int i=0; i<5; i++){
				for(int j=0; j<5; j++){
					contents[i][j] = 0;
					colors[i][j] = 'W';
				}
			}

			for(int i=0; i<3; i++){
			  for(int j=0; j<4; j++){
			    for(int k=0; k<4; k++){
			      ings[i][j][k] = ingredients[i][j][k];
			    }
			  }
			}
		}

		void clean_pot(){
			for(int i=0; i<5; i++){
				for(int j=0; j<5; j++){
					contents[i][j] = 0;
					colors[i][j] = 'W';
				}
			}
		}

		int get_maximum(){
			int turns[6][3] = {
					{0, 1, 2},{0, 2, 1},{1, 0, 2},{1, 2, 0},{2, 0, 1}, {2, 1, 0}
			}
			vector<tuple<int, int>> stack; // (loc, dir)
			int cur, max=0;

			for(int i=0; i<6; i++){
				cur = turns[i][0];

				for(int k=0; k<4; k++){
				  for(int j=0; j<4; j++){
						// 구현하기 너무 힘들다.
				    stack.push_back(make_tuple(k,j));
				  }
				}

			}

		}

		void change_turn(int a, int b){
			int temp;
			for(int i=0; i<4; i++){
			  for(int j=0; j<4; j++){
			    temp = ings[a][i][j];
					ings[a][i][j]=ings[b][i][j];
					ings[b][i][j]=temp;
			  }
			}
		}

		void change_angle(int diff){
				dir += diff / 4;
		}

		void change_color(int i, int j, int color)
		{
			if(color != 'W') {
				rotate(i, j);
				colors[i][j] = color;
			}
		}

		void change_content(int i, int j, int value){
			rotate(i,j);
			contents[i][j] += value;
			if(contents[i][j] < 0) contents[i][j] = 0;
			if(contents[i][j] > 9) contents[i][j] = 9;
		}

		void rotate(int & x1, int & y1) const {
			double	radian = dir * 90 * (float)(PI / 180);
			double x2 = cos(radian) * x1 - sin(radian) * y1;
			double y2 = sin(radian) * x1 + cos(radian) * y1;
			x1 = x2; y2 = y1;
		}
}


int main(void){


}
