#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main(void) {
		int N;
		std::cin>>N;
		std::vector<int> vec(N);

		std::vector<int> vec2(8001, 0);
		int mean = 0;
		int temp = 0;
		int max = 0;
		for(int i = 0; i < N; i ++){
			std::cin>>vec[i];
			mean += vec[i];
			temp = (vec[i] <= 0) ? abs(vec[i]) : vec[i] + 4000;
			vec2[temp]++;
			if(vec2[temp] > max)
				max = vec2[temp];
		}
		std::sort(vec.begin(), vec.end());

		int mode = 0;
		bool isSecond = false;
		for(int i = -4000; i < 4001; i++){
			temp = i <= 0 ? abs(i) : i+4000;
			if(vec2[temp] == max){
				mode = i;
				if(isSecond) break;
				isSecond = true;
			}
		}

		std::cout<<round(mean/(double)N)<<'\n';
		std::cout<<vec[round(N/2)]<<'\n';
		std::cout<<mode<<'\n';

		int min = vec[0];
		max = vec[vec.size()-1];

		std::cout<<max - min<<'\n';
}
