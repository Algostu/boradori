#include <iostream>
using namespace std;

int main(){
    int n,input,max=0;
    int num[10001] = {0,};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&input);
        num[input]++;
        if(max<input) max=input;
    }
    
    for (int i = 0; i < max+1; i++)
    {
        if(num[i]==0) continue;
        for (int j = 0; j < num[i]; j++)
        {
            printf("%d\n",i);
        }
    }

    return 0;
}