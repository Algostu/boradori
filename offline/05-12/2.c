#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct __node{
    int x;
    int y;
} node;

typedef struct __edge{
    node n1;
    node n2;
} edge;

int comp_node(node n1, node n2){
    if(n1.x == n2.x && n1.y == n2.y){
        return 1;
    } else return 0;
}

int is_already_exist(edge temp, edge * all_edges, const int answer){
    int i;
    for(i=0;i<answer;i++){
        if(comp_node(temp.n1, all_edges[i].n1) && comp_node(temp.n2, all_edges[i].n2)) return 1;
        else if (comp_node(temp.n1, all_edges[i].n2) && comp_node(temp.n2, all_edges[i].n1)) return 1;
    }
    return 0;
}


void move(int* where, int* new_where, char dir){
    new_where[0] = where[0]; new_where[1] = where[1];

    switch (dir){
        case 'U':
            new_where[1]++;
            break;
        case 'D':
            new_where[1]--;
            break;
        case 'R':
            new_where[0]++;
            break;
        case 'L':
            new_where[0]--;
            break;
    }
    return;
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* dirs) {
    edge temp, all_edges[1000];
    node start, end;
    int visited[11][11] = {0};
    int i, j, answer = 0;
    int where[2] = {5, 5}, new_where[2] = {5,5};

    visited[where[0]][where[1]]++;

    for(i=0;i<strlen(dirs);i++){
        move(where, new_where, dirs[i]);
        if(new_where[0] <= 10 && new_where[0] >= 0 && new_where[1] <= 10 && new_where[1] >= 0){
            temp.n1.x = where[0];
            temp.n1.y = where[1];
            temp.n2.x = new_where[0];
            temp.n2.y = new_where[1];

            if(is_already_exist(temp, all_edges, answer) == 0){
                memcpy(&all_edges[answer], &temp, sizeof(edge));
                answer++;
            }

            where[0] = new_where[0];
            where[1] = new_where[1];
        }
    }

    // for(i=0;i<11;i++){
    //     for(j=0;j<11;j++){
    //         if(visited[i][j] > 0) answer++;
    //     }
    // }

    return answer;
}
