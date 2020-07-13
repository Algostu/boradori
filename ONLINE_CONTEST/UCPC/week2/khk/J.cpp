#include <iostream>
#include <cmath>

#define PI 3.141592

using namespace std;

class pot{
	public:
		int contents[5][5];
		int colors[5][5];
		int dir;
		
		pot()
		:angle(0)
		{
			for(int i=0; i<5; i++){
				for(int j=0; j<5; j++){
					contents[i][j] = 0;
					colors[i][j] = 'W';
				}
			}
		}
		
		void change_angle(int dir){
			 
		}
		
		void change_color(int i, int j, int color)
		{
			if(color != 'W') colors[i][j] = 
		}
		
		void rotate(int x1, int y1){
			double	radian = angle * (float)(PI / 180); 
			double x2 = cos(radian) * x1 - sin(radian) * y1; 
			double y2 = sin(radian) * x1 + cos(radian) * y1;
		}
}


int main(void){
	
	
}