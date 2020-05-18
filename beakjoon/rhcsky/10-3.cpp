#include <iostream>
using namespace std;
int main()
{
    int M,N;
    cin >> M >> N;
    int* eratos = new int[M+1];
    for (int i = 2; i <= N; i++)
    {
        eratos[i] = i;
    }

    for (int i = 2; i <= N; i++){
        if(eratos[i] == 0) continue;

        for (int j = 2*i; j <= N; j+=i)
        {
            eratos[j] = 0;
        }
    }

    for (int i = M; i <= N; i++)
    {
        if(eratos[i]!=0) cout << i << endl;
    }

    delete []eratos;

    return 0;
}