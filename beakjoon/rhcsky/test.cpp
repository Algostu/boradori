#include <iostream>
#include <vector>
using namespace std;
int ROW = 4, COL = 6;

class Shark
{
private:
    int r, c, s, d, z;
public:
    Shark(int row, int column,int speed, int direct, int size):r(row),c(column),s(speed),d(direct),z(size){}
    ~Shark(){}

    int getRow(){return r;}
    int getCol() {return c;}
    int getSpeed() {return s;}
    int getDirect() {return d;}
    int getSize() {return z;}
    void setPosition(int ROW, int COL){
        if(d==1 || d==2){
            int temp = s%((ROW-1)*2);
            for (int i = 0; i < temp; i++)
            {
                if(d==1) r -= 1;
                if(d==2) r += 1;
                if(r>ROW){
                    d = 1;
                    r -= 2;
                }
                if(r<1){
                    d = 2;
                    r += 2;
                }
            }
        }
        else{
            int temp = s%((COL-1)*2);
            cout << "Temp speed is " << temp << endl;
            for (int i = 0; i < temp; i++)
            {
                cout << c << " ";
                if(d==3) c += 1;
                if(d==4) c -= 1;
                if(c>COL){
                    d = 4;
                    c -= 2;
                }
                if(c<1){
                    d = 3;
                    c += 2;
                }
            }
            cout << endl;
        }
    }
};

void RemoveShark(vector<Shark*>*);
void PrintShark(vector<Shark*>);
void MoveShark(vector<Shark*>,int,int);

int main()
{
    Shark a(2,3,5,1,9);
    Shark b(4,3,1,2,7);
    Shark c(1,6,8,3,3);
    vector<Shark*> sharks;
    // sharks.push_back(&a);
    // sharks.push_back(&b);
    sharks.push_back(&c);
    PrintShark(sharks);
    // cout << "-----Remove Shark-------" << endl;
    // RemoveShark(&sharks);
    cout << "-------Move Shark--------" << endl;
    MoveShark(sharks,4,6);
    // MoveShark(sharks,4,6);
    PrintShark(sharks);
}

void RemoveShark(vector<Shark*>* sharks){
    vector<int> position;
    bool possible = false;
    for (int i = 0; i < (*sharks).size(); i++)
    {
        for (int j = i+1; j < (*sharks).size(); j++)
        {
            if((*sharks)[i]->getCol()== (*sharks)[j]->getCol()){
                possible = true;
                if((*sharks)[i]->getSize() > (*sharks)[j]->getSize()) position.push_back(j);
                else position.push_back(i);
            }
        }
    }
    if (position.size()){
        for (auto &&i : position)
        {   
            (*sharks).erase((*sharks).begin()+i,(*sharks).begin()+i+1);
        }
    }
}

void PrintShark(vector<Shark*> sharks){
    for (auto &&shark : sharks)
    {
        printf("Shark : %d %d %d %d %d\n",shark->getRow(),shark->getCol(),shark->getSpeed(),shark->getDirect(),shark->getSize());
    }
}

void MoveShark(vector<Shark*> sharks,int row, int col){
    for (auto &&shark : sharks)
    {   
        shark->setPosition(row,col);
        // printf("Moving shark : %d %d %d %d %d\n",shark->getRow(),shark->getCol(),shark->getSpeed(),shark->getDirect(),shark->getSize());            
    }
}