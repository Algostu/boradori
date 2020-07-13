#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class AbsNode{
    private:
        int value, sign;
    public:
        AbsNode(int v){
            if (v<0)
            {
                this->value = -v;
                this->sign = 0;
            }
            else{
                this->value = v;
                this->sign = 1;
            }
        }
        ~AbsNode(){}
        bool operator > (const AbsNode &a) const{
            if(value == a.value) return sign > a.sign;
            return value > a.value;
        }
        int GetValue(){
            if(sign==0) return -value;
            else return value;
        }
};

int main()
{
    int N,input;
    AbsNode a(10);
    
    priority_queue<AbsNode, vector<AbsNode>, greater<AbsNode>> heap;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &input);
        if(input == 0){
            if(heap.size() == 0) printf("0\n");
            else {printf("%d\n",((AbsNode)heap.top()).GetValue()); heap.pop();}
        }
        else heap.push(AbsNode(input));
    }
    
    return 0;
}