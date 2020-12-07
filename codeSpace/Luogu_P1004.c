#include <stdio.h>
#include <malloc.h>

int sp(int **p,int x,int y,int size,int *l,int lc){
    int n1=0,n2=0,sum=*(*(p+x)+y);
    if(x==size-1&&y==size-1){
        *(*(l+2*(size-1)))
        return sum;
    }
    if(x<size-1){
        n1 = sp(p,x+1,y,size);
    }
    if(y<size-1){
        n2 = sp(p,x,y+1,size);
    }
    if(n1 < n2){
        sum += n2;
    }else{
        sum += n1;
    }
    return sum;
}
int main() {
    int n;
    scanf("%d",&n);
    int **p = (int **)malloc(sizeof(int *)*n);
    for(int i=0;i<n;i++){
        p[i] = (int *)malloc(sizeof(int)*n);
    }
    int *l = (int *)malloc(sizeof(int)*2*(n-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            *(*(p+i)+j) = 0;
            printf("%3d",*(*(p+i)+j));
        }
        printf("\n");
    }
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    while(a!=0&&b!=0&&c!=0){
        *(*(p+a-1)+b-1) = c;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%3d",*(*(p+i)+j));
            }
            printf("\n");
        }
        scanf("%d %d %d",&a,&b,&c);
    }
    int sum=0;
    sum += sp(p,0,0,n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%3d",*(*(p+i)+j));
        }
        printf("\n");
    }
    printf("%d\n",sum);
    return 0;
}
