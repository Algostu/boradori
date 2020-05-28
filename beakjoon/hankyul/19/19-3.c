#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define _USE_MATH_DEFINES

#define COMPARE(X, Y) (X) > (Y) ? (X) : ((X) == (Y) ? (X) : (Y))

#define SWAP(X, Y, T) T = (X); (X) = (Y); (Y) = T;

#define MALLOC(X, Y) \
if(((X) = malloc((Y)))==NULL){\
  fprintf(stderr, "mallc error"); exit(EXIT_FAILURE);\
}

/*
  깨알 상식
  1은 소수일까? Nope! 소수의 정의는 1과 자기자신으로만 나누어 떨어지는 수이다.
  이 정의에 의하면 1은 소수이나 결론적으로 말하면 1은 소수가 아니다. 왜냐하면,
  정수론에는 "1이외의 정수는 항상 소인수 분해를 할 수 있으며 그 순서를 생각하지
  않는다면 한 가지 방법밖에 없다."라는 정의가 있다. 만약 여기서 1이 소수가
  된다면, 소인수 분해 할 방법이 매우 여러가지가 되고 따라서 이는 위 정의와 어긋
  나게 된다.
*/
bool* Eratos(int n)
{
  bool* PrimeArray = NULL;
  MALLOC(PrimeArray, sizeof(bool)*(n+1))

  PrimeArray[1] = false;

	for (int i = 2; i <= n; i++)
	    PrimeArray[i] = true;

	for (int i = 2; i * i <= n; i++)
	{
		if (PrimeArray[i])
			for (int j = i * i; j <= n; j += i)
			    PrimeArray[j] = false;
	}
  return PrimeArray;
}

void solve(int test_num){
  int N, index = 2, i;
  bool * prime_array = NULL;

  scanf("%d", &N);

  prime_array = Eratos(N);

  while(N != 1){
    if(prime_array[index] == true && N % index == 0){
      printf("%d\n", index);
      N /= index;
    } else index++;
  }

}

int main(){
  // int i, N;
  // scanf("%d", &N);
  // for(i=0;i<N;i++){
  //     solve(i+1);
  // }

  solve(0);

	return 0;
}
