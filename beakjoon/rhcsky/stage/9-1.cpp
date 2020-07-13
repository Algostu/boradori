#include <iostream>
using namespace std;

int main()
{
    int const_cost, manufacture_cost, sale_cost;
    int break_even_point = 1;

    cin >> const_cost >> manufacture_cost >> sale_cost;

    if (manufacture_cost>=sale_cost){
        cout << -1;
        return 0;
    }
    

    cout << const_cost/(sale_cost-manufacture_cost) + 1 ;
    
    return 0;
}