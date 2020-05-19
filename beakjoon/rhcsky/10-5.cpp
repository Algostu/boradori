#include <iostream>
#include <vector>
using namespace std;
int cal_eratos(int);

int main()
{
    int test,N;
    cin >> test;

    while (test--)
    {
        scanf("%d", &N);
        cal_eratos(N);
    }
    return 0;
}

int cal_eratos(int N){
    int p1,p2;
    vector<int> numbers;
    int* eratos = new int[N+1];
    for (int i = 2; i <= N; i++)
    {
        eratos[i] = i;
    }

    for (int i = 2; i * i<= N; i++){
        if(eratos[i] == 0) continue;

        for (int j = 2*i; j <= N; j+=i)
        {
            eratos[j] = 0;
        }
    }

    p1 = p2 = N/2;
    while(true){
        if((p1+p2==N)&&eratos[p1]&&eratos[p2]){
            printf("%d %d\n",p1,p2);
            break;
        }
        p1--;
        p2++;
    }
    delete []eratos;
    return 0;
}