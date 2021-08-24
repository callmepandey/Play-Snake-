#include<graphics.h>
#include<time.h>        // HELPS IN GENERATING OF RANDOM NUMBERS
class point{
          location current;
     public:
          // PRINT NEW POINT
          void make(){
               setcolor(RED);
               rectangle(current.x , current.y , current.x + 30 , current.y + 30);
               setfillstyle(INTERLEAVE_FILL , RED);
               floodfill(current.x + 15 , current.y + 15 , RED);
          }
          // GENERATES NEW POINT ON RANDOM POSITION
          void newpoint(int notx , int noty){
               current.x = notx , current.y = noty;
               while(current.x == notx and current.y == noty){
                    srand(time(0));
                    current.x = 30*(rand()%15 + 1);
                    srand(time(0));
                    current.y = 30*(rand()%15 + 1);
               }
          }
          // CHECK IF SNAKE HAVE EATEN
          bool eaten(int atx , int aty){
               return (atx==current.x and aty==current.y);
          }
};
