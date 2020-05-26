#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, num[13];
int maxi = -1e9, mini = 1e9;
int x,y,z,w;
void DFS(int,int);
//enhanced
int main(){
    cin >> n;
    for (int i = 1; i < n+1; i++)
    {
        cin >> num[i];
    }
    scanf("%d %d %d %d", &x, &y, &z, &w);
    DFS(1,num[1]);
    printf("%d\n%d",maxi,mini);
}

void DFS(int cnt, int sum){
    if(cnt==n){
        if(sum>maxi) maxi = sum;
        if(sum<mini) mini = sum;
    }
    if(x){
        x--;
        DFS(cnt+1,sum+num[cnt+1]);
        x++;
    }
    if(y){
        y--;
        DFS(cnt+1,sum-num[cnt+1]);
        y++;
    }
    if(z){
        z--;
        DFS(cnt+1,sum*num[cnt+1]);
        z++;
    }
    if(w){
        w--;
        DFS(cnt+1,sum/num[cnt+1]);
        w++;
    }
}

int my_main()
{
    int n, input, max = -1000000000, min = 1000000000, sum, operat;
    vector<int> numbers;
    vector<int> operators;
    vector<int> combination;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        numbers.push_back(input);
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> input;
        for (int j = 0; j < input; j++)
        {
            operators.push_back(i);
        }
    }
    for (int i = 0; i < n-1; i++)
    {
        combination.push_back(i);
    }

    do
    {
        sum = numbers[0];
        for (int i = 0; i < n-1; i++)
        {
            operat = operators[combination[i]];
            if(operat == 0) sum += numbers[i+1];
            if(operat == 1) sum -= numbers[i+1];
            if(operat == 2) sum *= numbers[i+1];
            if(operat == 3) sum /= numbers[i+1];
        }
        if(sum > max) max = sum;
        if(sum < min) min = sum;
    } while (next_permutation(combination.begin(),combination.end()));
    
    cout << max << endl;
    cout << min << endl;
    
    return 0;
}