#include <iostream>
#include <cstring>
using namespace std;

int ROW,COL,M,MAX=102;

struct Shark{
    int speed, direction, size;
}shark[102][102];

void MoveShark(){
    Shark temp[MAX][MAX];
    memset(temp,0,sizeof(temp));
    
    for (int i = 1; i < ROW+1; i++)
    {
        for (int j = 1; j < COL+1; j++)
        {
            Shark s = shark[i][j];
            if(s.size){
                int r = i, c = j, speed;
                if(s.direction==1 || s.direction==2){
                    speed = s.speed % ((ROW-1)*2);
                    for (int k = 0; k < speed; k++)
                    {
                        if(s.direction==1) r -= 1;
                        else r += 1;
                        if(r>ROW){s.direction=1;r-=2;}
                        if(r<1){s.direction=2,r+=2;}
                    }
                }
                else{
                    speed = s.speed % ((COL-1)*2);
                    for (int k = 0; k < speed; k++)
                    {
                        if(s.direction==3) c += 1;
                        else c -= 1;
                        if(c>COL){s.direction=4;c-=2;}
                        if(c<1){s.direction=3;c+=2;}
                    }
                }
                if(temp[r][c].size == 0 || temp[r][c].size < s.size) temp[r][c] = s;
            }
        }
    }

    for (int i = 1; i < ROW+1; i++)
    {
        for (int j = 1; j < COL+1; j++)
        {
            shark[i][j] = temp[i][j];
        }
    }
}

int FindShark(int human){
    for (int i = 1; i < ROW+1; i++)
    {
        if(shark[i][human].size){
            int res = shark[i][human].size;
            shark[i][human] = {0,0,0};
            return res;
        }
    }
    return 0;
}

int main(){
    scanf("%d %d %d",&ROW,&COL,&M);
    for (int i = 0; i < M; i++)
    {
        int r, c, s, d, z;
        scanf("%d %d %d %d %d",&r,&c,&s,&d,&z);
        shark[r][c] = {s,d,z};
    }

    int sum = 0;
    for (int human = 1; human < COL+1; human++)
    {
        sum += FindShark(human);
        MoveShark();
    }

    printf("%d",sum);
    return 0;
}

