#include <iostream>
using namespace std;

//Enhanced
int main(){
    int sugar, max;
    cin >> sugar;
    max = sugar/5;
    for (int i = max; i >= 0; i--)
    {
        if((sugar-5*i)%3 == 0){
            cout << i+(sugar-5*i)/3;
            return 0;
        }
    }
    cout << -1;
    return 0;
}



int my_main()
{
    int sugar, ans=0;
    cin >> sugar;

    while (true)
    {
        if(sugar%5==0){
            ans += sugar/5;
            cout << ans;
            return 0;
        }
        sugar -= 3;
        ans++;

        if (sugar<0)
        {
            cout << -1;
            return 0;
        }
        
    }   

    return 0;
}