#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int FindPosition(int,int);

vector<pair<int,int>> que; // index, value
vector<int> numbers[10];
vector<int> res;

int main()
{
    int head, cnt;
    int N, num, index, input;
    scanf("%d", &N);
    while (N--)
    {
        que.clear();
        for(int i=0; i<10; i++) numbers[i].clear();
        cnt = 0;

        scanf("%d %d", &num, &index);
        for (int i = 0; i < num; i++)
        {
            scanf("%d", &input);
            que.push_back({i,input});
            numbers[input].push_back(i);
        }

        for (int i = 9; i >= 0; i--)
        {   
            if(numbers[i].size()> 0){
                head = numbers[i].back();
                if(i == que[index].second) head = 0;
                break;
            }
        }
        
        for (int i = 9; i > que[index].second; i--)
        {
            if(numbers[i].size() == 0) continue;
            head = FindPosition(i,head);
        }
        
        for (int i = head; i < que.size(); i++)
        {
            if(que[index].second == que[i].second){
                cnt++;
                if(que[i].first == index) break;
            }
        }

        if(index < head){
            for (int i = 0; i < head; i++)
            {
                if(que[index].second == que[i].second){
                    cnt++;
                    if(que[i].first == index) break;
                }
            }
        }

        for (int i = 9; i > que[index].second; i--)
        {
            cnt += numbers[i].size();
        }   

        res.push_back(cnt);
    }

    for (auto &&i : res)
    {
        cout << i << endl;
    }
    
    return 0;
}

int FindPosition(int cnt, int position){
    int pre = numbers[cnt].back();
    for (auto &&i : numbers[cnt])
    {
        if(position < i) return pre;
        pre = i;
    }
    return pre;
}