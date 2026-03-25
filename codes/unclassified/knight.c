#include <stdio.h>
#define MAX 30

typedef struct {
    int h, w; //크기
    int r, c; //위치
    int k; //체력
    int dmg; //받은 데미지
} Knight;
Knight knight[MAX+1];

typedef struct node{
    int top;
    int data[MAX];
}Stack;
Stack stack;

int rr[4] = {-1, 0, 1, 0};
int cc[4] = {0, 1, 0, -1};

int map[42][42], trap[42][42], loc[42][42]; //map : 맵, trap : 함정의 개수 누적합, loc : 기사들 위치

void init(Stack *s);
void push(Stack *s, int data);
int pop(Stack *s);

int getTrapSum(int r, int c, int h, int w);
int canMove(int knightNum, int dir);
void move(int knightNum, int dir);
void knightDie(int knightNum);
void updateMap(int knightNum, int dir);
void printMap(int l);

int main(){
    int l, n, q;
    scanf("%d %d %d", &l, &n, &q);

    for(int i = 1; i <= l; i++) //벽 설치
        map[i][0] = map[0][i] = map[l+1][i] = map[i][l+1] = 2;
    
    for(int i = 1; i <= l; i++){
        for(int j = 1; j <= l; j++){
            scanf("%d", &map[i][j]);

            if(map[i][j] == 1)
                trap[i][j] = 1;
            
            trap[i][j] += trap[i-1][j] + trap[i][j-1] - trap[i-1][j-1];
        }
    }
    for(int i = 1; i <= n; i++){
        int r, c, h, w, k;
        scanf("%d %d %d %d %d", &r, &c, &h, &w, &k);

        knight[i] = (Knight){h, w, r, c, k, 0};

        for(int j = r; j < r+h; j++)
            for(int k = c; k < c+w; k++)
                loc[j][k] = i;
    }
    printMap(l);
    
    init(&stack);
    for(int i = 0; i < q; i++){
        int knightNum, dir;
        scanf("%d %d", &knightNum, &dir);

        updateMap(knightNum, dir);
        
        printf("\n");
        printMap(l);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(knight[i].k > 0)
            ans += knight[i].dmg;
    
    printf("%d", ans);

    return 0;
}
void init(Stack *s){
    s->top = -1;
}
void push(Stack *s, int data){
    s->data[++(s->top)] = data;
}
int pop(Stack *s){
    return s->data[(s->top)--];
}
int getTrapSum(int r, int c, int h, int w){ //함정의 개수 누적합을 구함
    return trap[r+h-1][c+w-1] - trap[r-1][c+w-1] - trap[r+h-1][c-1] + trap[r-1][c-1];
}
int canMove(int knightNum, int dir){ //기사 이동 확인 0 : 위, 1 : 오른쪽, 2 : 아래, 3 : 왼쪽
    int r = knight[knightNum].r;
    int c = knight[knightNum].c;
    int h = knight[knightNum].h;
    int w = knight[knightNum].w;
    int k = knight[knightNum].k;

    if(dir == 0){ //위
        for(int i = c; i < c+w; i++)  //기사가 이동할 위치에 벽이 있는지 확인
            if(map[r-1][i] == 2)
                return 0;             //이동 불가를 의미하는 0 반환

        for(int i = c; i < c+w; i++)  //기사가 이동할 위치에 다른 기사가 있는지 확인
            if(loc[r-1][i] != 0)
                return loc[r-1][i];   //다른 기사가 있으면 그 기사의 번호 반환
    }
    else if(dir == 1){ //오른쪽
        for(int i = r; i < r+h; i++)
            if(map[i][c+w] == 2)
                return 0;

        for(int i = r; i < r+h; i++)
            if(loc[i][c+w] != 0)
                return loc[i][c+w];
    }
    else if(dir == 2){ //아래
        for(int i = c; i < c+w; i++)  
            if(map[r+h][i] == 2)
                return 0;             
        
        for(int i = c; i < c+w; i++)  
            if(loc[r+h][i] != 0)
                return loc[r+h][i];
    }
    else if(dir == 3){ //왼쪽
        for(int i = r; i < r+h; i++)
            if(map[i][c-1] == 2)
                return 0;

        for(int i = r; i < r+h; i++)
            if(loc[i][c-1] != 0)
                return loc[i][c-1];
    }
    return -1; //이동 가능
}
void move(int knightNum, int dir){ //기사를 이동 0 : 위, 1 : 오른쪽, 2 : 아래, 3 : 왼쪽
    int r = knight[knightNum].r;
    int c = knight[knightNum].c;
    int h = knight[knightNum].h;
    int w = knight[knightNum].w;

    for(int i = r; i < r+h; i++)
        for(int j = c; j < c+w; j++)
            loc[i][j] = 0;

    int nr = r+rr[dir];
    int nc = c+cc[dir];

    for(int i = nr; i < nr+h; i++)
        for(int j = nc; j < nc+w; j++)
            loc[i][j] = knightNum;

    knight[knightNum].r = nr;
    knight[knightNum].c = nc;
}
void knightDie(int knightNum){ //기사 사망 시 loc 배열에서 제거
    int r = knight[knightNum].r;
    int c = knight[knightNum].c;
    int h = knight[knightNum].h;
    int w = knight[knightNum].w;

    for(int i = r; i < r+h; i++)
        for(int j = c; j < c+w; j++)
            loc[i][j] = 0;
}
int chkMove(int kinght, int dir){
    int r = knight[kinght].r;
    int c = knight[kinght].c;
    int h = knight[kinght].h;
    int w = knight[kinght].w;

    if(dir == 0){ //위
        for(int i = c; i < c+w; i++)  //기사가 이동할 위치에 벽이 있는지 확인
            if(map[r-1][i] == 2)
                return 0;             //이동 불가를 의미하는 0 반환

        for(int i = c; i < c+w; i++)  //기사가 이동할 위치에 다른 기사가 있는지 확인
            if(loc[r-1][i] != 0)
                return loc[r-1][i];   //다른 기사가 있으면 그 기사의 번호 반환
    }
    else if(dir == 1){ //오른쪽
        for(int i = r; i < r+h; i++)
            if(map[i][c+w] == 2)
                return 0;

        for(int i = r; i < r+h; i++)
            if(loc[i][c+w] != 0)
                return loc[i][c+w];
    }
    else if(dir == 2){ //아래
        for(int i = c; i < c+w; i++)  
            if(map[r+h][i] == 2)
                return 0;             
        
        for(int i = c; i < c+w; i++)  
            if(loc[r+h][i] != 0)
                return loc[r+h][i];
    }
    else if(dir == 3){ //왼쪽
        for(int i = r; i < r+h; i++)
            if(map[i][c-1] == 2)
                return 0;

        for(int i = r; i < r+h; i++)
            if(loc[i][c-1] != 0)
                return loc[i][c-1];
    }
    return -1; //이동 가능


}
void updateMap(int knightNum, int dir){ //기사의 위치를 업데이트
    while(1){
        int next = canMove(knightNum, dir);
        if(next == -1){ //이동 가능
            move(knightNum, dir);

            if(stack.top == -1) //스택이 비어있으면 -> 명령받은 기사가 이동했을 때, 데미지 받지 않음
                break;

            int k = knightNum;
            int dmg = getTrapSum(knight[k].r, knight[k].c, knight[k].h, knight[k].w); //함정의 개수 누적합
            
            knight[k].k -= dmg; //체력 감소
            knight[k].dmg += dmg; //데미지 증가

            printf("knight : %d, dmg : %d\n", k, dmg);

            if(knight[k].k <= 0) //체력이 0이하이면 죽음
                knightDie(k);
            
            knightNum = pop(&stack);
        }
        else if(next == 0){ //이동 불가능
            init(&stack); //스택 비우기

            return; 
        }
        else{ //다른 기사가 있음
            push(&stack, knightNum);
            knightNum = next;
        }
    }
}
void printMap(int l){
    for(int i = 0; i <= l+1; i++){
        for(int j = 0; j <= l+1; j++)
            printf("%2d ", loc[i][j]);
        printf("\n");
    }
    printf("\n");
}