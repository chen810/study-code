//铺地毯
#include <stdio.h>
#include <malloc.h>

int top(int x,int y,int dx,int dy,int p,int q){
    int x1,y1;
    x1 = x+dx;
    y1 = y+dy;
    if(x<=p&&p<=x1&&q<=y1&&q>=y){
        return 1;
    }
    return 0;
}
int main() {
    int n;
    scanf("%d",&n);
    int *p = (int *)malloc(sizeof(int)*n*4);
    int count=0,top_num=0;
    while(count<n){
        scanf("%d %d %d %d",p+4*count,p+4*count+1,p+4*count+2,p+4*count+3);
        count++;
    }
    int x,y;
    scanf("%d %d",&x,&y);
    for(int i=0;i<n;i++){
        if(top(*(p+4*i),*(p+4*i+1),*(p+4*i+2),*(p+4*i+3),x,y)){
            top_num=i+1;
        }
    }
    if(top_num!=0){
        printf("%d",top_num);
    } else{
        printf("-1");
    }

    return 0;
}
