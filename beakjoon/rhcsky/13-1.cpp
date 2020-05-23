#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Combination(vector<int>, int, int);

int main()
{
    vector<int> cards;
    vector<int> ind = {1,1,1};
    int card_number, sum, card, max=0;
    cin >> card_number >> sum;
    for (int i = 0; i < card_number; i++)
    {
        cin >> card;
        cards.push_back(card);
    }

    cout << Combination(cards,3,sum);
       
    return 0;
}


int Combination(vector<int> numbers, int n, int max){
    vector<int> ind;
    int sum, temp=0;
    for (int i = 0; i < numbers.size()-n; i++)
    {
        ind.push_back(0);
    }
    for (int i = 0; i < n; i++)
    {
        ind.push_back(1);
    }
    
    do
    {
        sum = 0;
        for (int i = 0; i < ind.size(); i++)
        {
            if(ind[i]==1){
                sum += numbers[i];
            }
        }
        if(sum>temp && sum<=max) temp = sum;
    } while (next_permutation(ind.begin(),ind.end()));

    return temp;   
}