//P1000 超级玛丽游戏
#include <stdio.h>
void line(int n,char x){
    while(n>0){printf("%c",x);n--;}
}
void next(){
    printf("\n");
}

int main() {
    line(16,' ');line(8,'*');next();
    line(15,' ');line(12,'*');next();
    line(15,' ');line(4,'#');line(4,'.');line(1,'#');line(1,'.');next();
    line(13,' ');line(1,'#');line(2,'.');line(3,'#');line(5,'.');line(2,'#');line(4,'.');next();
    line(13,' ');line(3,'#');line(7,'.');line(6,'#');line(14,' ');line(3,'#');line(12,' ');line(3,'#');next();
    line(16,' ');line(11,'.');line(15,' ');line(1,'#');line(3,'.');line(1,'#');line(10,' ');line(1,'#');line(3,'.');line(1,'#');next();
    line(15,' ');line(2,'#');line(1,'*');line(7,'#');line(17,' ');line(1,'#');line(1,'.');line(1,'#');line(1,'.');line(1,'#');line(10,' ');line(1,'#');line(1,'.');line(1,'#');line(1,'.');line(1,'#');next();
    line(12,' ');line(4,'#');line(7,'*');line(6,'#');line(13,' ');line(1,'#');line(1,'.');line(1,'#');line(1,'.');line(1,'#');line(10,' ');line(1,'#');line(1,'.');line(1,'#');line(1,'.');line(1,'#');next();
    line(11,' ');line(3,'.');line(1,'#');line(3,'*');line(1,'.');line(4,'*');line(1,'.');line(1,'*');line(3,'#');line(4,'.');line(10,' ');line(1,'#');line(3,'.');line(1,'#');line(10,' ');line(1,'#');line(3,'.');line(1,'#');next();
    line(11,' ');line(4,'.');line(10,'*');line(2,'#');line(5,'.');line(11,' ');line(3,'#');line(12,' ');line(3,'#');next();
    line(11,' ');line(4,'.');line(4,'*');line(4,' ');line(5,'*');line(4,'.');next();
    line(13,' ');line(4,'#');line(8,' ');line(4,'#');next();
    line(11,' ');line(6,'#');line(8,' ');line(6,'#');next();
    line(62,'#');next();
    line(1,'#');line(3,'.');line(1,'#');line(6,'.');line(1,'#');line(1,'.');line(2,'#');line(3,'.');line(1,'#');line(6,'.');line(1,'#');line(1,'.');line(2,'#');line(3,'.');line(1,'#');line(6,'.');line(1,'#');line(1,'.');line(2,'#');line(18,'-');line(1,'#');next();
    line(43,'#');line(18,'-');line(1,'#');next();
    line(1,'#');line(2,'.');line(1,'#');line(4,'.');line(1,'#');line(4,'.');line(2,'#');line(2,'.');line(1,'#');line(4,'.');line(1,'#');line(4,'.');line(2,'#');line(2,'.');line(1,'#');line(4,'.');line(1,'#');line(4,'.');line(21,'#');next();
    line(42,'#');line(4,' ');line(1,'#');line(10,'-');line(1,'#');next();
    line(1,'#');line(5,'.');line(1,'#');line(6,'.');line(2,'#');line(5,'.');line(1,'#');line(6,'.');line(2,'#');line(5,'.');line(1,'#');line(6,'.');line(1,'#');line(4,' ');line(1,'#');line(10,'-');line(1,'#');next();
    line(42,'#');line(4,' ');line(1,'#');line(10,'-');line(1,'#');next();
    line(1,'#');line(1,'.');line(1,'#');line(2,'.');line(1,'#');line(4,'.');line(1,'#');line(2,'.');line(2,'#');line(1,'.');line(1,'#');line(2,'.');line(1,'#');line(4,'.');line(1,'#');line(2,'.');line(2,'#');line(1,'.');line(1,'#');line(2,'.');line(1,'#');line(4,'.');line(1,'#');line(2,'.');line(1,'#');line(4,' ');line(1,'#');line(10,'-');line(1,'#');next();
    line(42,'#');line(4,' ');line(12,'#');next();
    return 0;
}
