#include <iostream>
using namespace std;
int main()
{
    int input = 1, M, N, cnt;
    do
    {
        scanf("%d", &input);
        if(input == 1){
            printf("%d\n",1);
            continue;
        }
        if(input == 0) break;
        cnt = 0;
        M = input, N = 2*input;
        int* eratos = new int[N+1];
        for (int i = 2; i <= N; i++)
        {
            eratos[i] = i;
        }

        for (int i = 2; i * i<= N; i++){
            if(eratos[i] == 0) continue;

            for (int j = i*i; j <= N; j+=i)
            {
                eratos[j] = 0;
            }
        }

        for (int i = M+1; i <= N; i++)
        {
            if(eratos[i]!=0) cnt++;
        }
        printf("%d\n",cnt);

        delete []eratos;
    }while(true);

    return 0;
}