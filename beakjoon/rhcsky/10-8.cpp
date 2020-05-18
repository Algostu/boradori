#include <iostream>
using namespace std;

int cal(int x){
    int sum = x;
    for (int i = x-1; i > 1; i--)
    {
        sum += i*2;
    }
    return sum;
}


int main()
{
    int test, front, end;
    scanf("%d",&test); 
    do
    {
        scanf("%d %d", &front, &end);
        cout << front - end;
        if (end-front-2==0)
        {
            cout << "0" << endl;
            cout << 2 << endl;
        }
        else if (end-front-2 <= 2){
            cout << "2" << endl;
            cout << 3 << endl;
        }
        else if (end-front-2 <= 4){
            cout << "4" << endl;
            cout << 4 << endl;
        }
        else{
            cout << "else" << endl;
            int i = 1;
            while (i++)
            {
                if(front-end-2 <= cal(i)) break;
            }
            cout << 2*i-3 << endl;
        }
        
    } while (--test);
    
    
    return 0;
}