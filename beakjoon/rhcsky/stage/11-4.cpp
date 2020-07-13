#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> v;

void HanoiTop(int n, int from, int by, int to){
    if (n==1) v.push_back(pair<int,int>(from,to));
    else{
        HanoiTop(n-1,from,to,by);
        v.push_back(pair<int,int>(from,to));
        HanoiTop(n-1,by,from,to);
    }
}


int main()
{
    v.clear();
    int num;
    cin >> num;
    HanoiTop(num,1,2,3);
    cout << v.size() << endl;
    
    // vector<pair<int,int>>::iterator iter;
    // for(iter = v.begin(); iter !=v.end(); iter++){
    //     printf("%d %d\n",iter->first,iter->second);
    // }


    for (auto &&i : v)
    {
        printf("%d %d\n",i.first,i.second);
    } 
    

    return 0;
}