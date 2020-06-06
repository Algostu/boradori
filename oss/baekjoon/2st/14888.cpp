#include<iostream>
#include<cmath>
 
int N;
int Arr[11];
int Plus, Minus, Multiple, Divide;
int Operator_Num, Max_Value, Min_Value;
 
void Input()
{
    Max_Value = -1000000001;
    Min_Value = 1000000001;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::cin >> Arr[i];
    }
    std::cin >> Plus >> Minus >> Multiple >> Divide;
    Operator_Num = N - 1;
}
 
void DFS(int Pl, int Mi, int Mul, int Div, int Sum, int N_Idx, int Cnt)
{
    if (Cnt == Operator_Num)
    {
        if (Max_Value < Sum) Max_Value = Sum;
        if (Min_Value > Sum) Min_Value = Sum;
        return;
    }
 
    if (Pl < Plus) DFS(Pl + 1, Mi, Mul, Div, Sum + Arr[N_Idx], N_Idx+1, Cnt + 1);
    if (Mi < Minus) DFS(Pl, Mi + 1, Mul, Div, Sum - Arr[N_Idx], N_Idx + 1, Cnt + 1);
    if (Mul < Multiple) DFS(Pl, Mi, Mul + 1, Div, Sum * Arr[N_Idx], N_Idx + 1, Cnt + 1);
    if (Div < Divide) DFS(Pl, Mi, Mul, Div + 1, Sum / Arr[N_Idx], N_Idx + 1, Cnt + 1);
}
 
void Solution()
{
    DFS(0, 0, 0, 0, Arr[0], 1, 0);
    std::cout << Max_Value << std::endl << Min_Value << std::endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    std::cin.tie(NULL);
    cout.tie(NULL);
    
    Solve();
    
    return 0;
}
