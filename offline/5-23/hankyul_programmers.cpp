#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;

typedef struct __time{
  int start;
  int end;
} my_time;

int comp(const void * a, const void * b){
  return (*(my_time*)a).start - (*(my_time*)b).start;
}

int solution(vector<string> lines) {
  int answer = 0;
  int i, j, q, w, trash, h, m;
  float duration, s;
  my_time logs[2000];

  for(i=0;i<lines.size();i++){
      sscanf(lines[i].c_str(), "%d-%d-%d %d:%d:%f %fs", &trash, &trash, &trash, &h, &m, &s, &duration);
      logs[i].end = s * 1000 + m * 60000 + h * 2400000;
      logs[i].start = logs[i].end - (int)round(duration*1000) + 1;
  }

  //debug
  // for(i=0;i<lines.size();i++){
  //     printf("start : %d end : %d \n", logs[i].start, logs[i].end);
  // }

  //sort
  qsort(logs, lines.size(), sizeof(my_time), comp);


  //debug
  // printf("sorted =============\n");
  // for(i=0;i<lines.size();i++){
  //     printf("start : %d end : %d \n", logs[i].start, logs[i].end);
  // }

  int max = 0;
  int start_count, end_count;
  int start, end;

  for(i=0;i<lines.size();i++){
      start = logs[i].start;
      end = logs[j].end;
      start_count = 0;
      end_count = 0;
      for(j=0;j<lines.size();j++){
          if(logs[i].start > start+999) break;
          else if(logs[i].start < start && logs[i].end >= start) start_count++;
          else if (logs[i].start >= start && logs[i].start <= start+999) start_count++;
      }
      
      if(max < start_count) max = start_count;

      for(j=0;j<lines.size();j++){
          if(logs[i].start < start - 999 && logs[i].end >= start) end_count++;
          else if (logs[i].start >= start - 999 && logs[i].start <= start) end_count++;
      }

      if(max < end_count) max = end_count;
  }

  return max;
}
