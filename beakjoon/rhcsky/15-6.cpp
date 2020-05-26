#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MAX = 45;
int number[10];
vector<int> board[9];
vector<pair<int,int>> empty_vector;

void input();
void sdokuDFS(int);
bool Check(int,int,int);

int main()
{
    input();
    cout << "--------" << endl;
    sdokuDFS(0);
    return 0;
}

void input(){
    int x;
    for (int i = 0; i < 9; i++)
    {
        int sum = 0;
        int cnt = 0;
        int pnt = 0;
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &x);
            if(x==0){
                cnt++;
                pnt = j;
                empty_vector.push_back(make_pair(i,j));
            }
            sum += x;
            board[i].push_back(x);
        }
        if(cnt == 1){ //만약 가로 한 줄에 0이 한개라면
           board[i][pnt] = MAX - sum;
           empty_vector.pop_back();
        }      
    }
}

void sdokuDFS(int idx){
    if(idx == empty_vector.size()){
        for (int i = 0; i < 9; i++)
        {
            for (auto &&e : board[i])
            {
                printf("%d ",e);
            }
            printf("\n");
        }
        exit(0);
    }
    for (int i = 1; i < 10; i++)
    {
        int x = empty_vector[idx].first;
        int y = empty_vector[idx].second;
        if(Check(x,y,i)){
            board[x][y] = i;
            sdokuDFS(idx+1);
            board[x][y] = 0;
        }
    }
}

bool Check(int x, int y, int i){
    //x 확인
    if(find(board[x].begin(),board[x].end(),i) != board[x].end()) return false;

    //y 확인
    for (int j = 0; j < 9; j++)
    {
        if(board[j][y] == i) return false;
    }

    //3X3 확인
    x = x/3 * 3;
    y = y/3 * 3;
    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            if(board[x+j][y+k] == i) return false;
        }
    }
    return true;
}