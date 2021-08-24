#include <graphics.h> // GRAPHIC ARE IMPORTED THROUGH THIS HEADER FILE
#include "body.h"     // THE SNAKE BODY IS IMPORTED
#include "points.h"   // THE POINT IS IMPORTED
int main()
{
    snake body;  // OBJECT OF SNAKE CLASS
    point pointer;   // OBJECT OF POINT CLASS
    int length ,page = 0; // HELPS US WITH LENGHT AND PAGE SWITCHES
    bool isplaying = true;  // BOOL STORES IF PLAYER IS STILL PLAYING OR HE ALREADY WON
    char printlen[3];         // HELPS IN PRINTING THE SCORE
    pointer.newpoint(body.getX() , body.getY());  //GETS US THE FIRST POINT
    while(1)
    {
            setactivepage(page);
            setvisualpage(1-page);
            cleardevice();
            setcolor(RED);
            setfillstyle(SOLID_FILL, BLUE);
            bool paused = false;
            // THESE ALL IF'S CHECK ALL THE KEY PRESSED AND CALLS FUNCTION RESPECTIVELY
            if(GetAsyncKeyState(VK_LSHIFT)){
                paused = !paused;
            }
            else if(GetAsyncKeyState(VK_LEFT))
            {
                body.changeFace(LEFT);
            }
            else if(GetAsyncKeyState(VK_UP))
            {
                body.changeFace(UP);
            }
            else if(GetAsyncKeyState(VK_RIGHT))
            {
                body.changeFace(RIGHT);
            }
            else if(GetAsyncKeyState(VK_DOWN))
            {
                body.changeFace(DOWN);
            }
            else if(GetAsyncKeyState(VK_ESCAPE))
                  break;
            // CHECKS IF SNAKE HAS COLIDED ITS HEAD WITH ITS BODY OR NOT
            if(!paused && isplaying==true && !body.updateSnake())
            {
                  isplaying = false;
            }
            // DRAW THE CURRENT SNAKE
            body.draw();

            // GENERATES NEW POINT AND INCRESE LENGHT OF SNAKE IN CASE IT ATE A POINT
            if(pointer.eaten(body.getX(), body.getY()))
            {
                 pointer.newpoint(body.getX(), body.getX());
                 body.changeLen();
            }
            // THIS GENERATES ALL THE BOXES OF THE PROGRAM
                 setcolor(DARKGRAY);
                 rectangle(0,0,30,510);
                 rectangle(30,0,480,30);
                 rectangle(480,0,510,510);
                 rectangle(30,480,480,510);
                 rectangle(510,0,800,20);
                 rectangle(510,250,800,270);
                 rectangle(780,20,800,250);
                 rectangle(510,490,800,510);
                 rectangle(780,270,800,490);
                 setfillstyle(SOLID_FILL, DARKGRAY);
                 floodfill(15,250,DARKGRAY);
                 floodfill(250,15,DARKGRAY);
                 floodfill(495,250,DARKGRAY);
                 floodfill(250,495,DARKGRAY);
                 floodfill(550,260,DARKGRAY);
                 floodfill(550,10,DARKGRAY);
                 floodfill(790,150,DARKGRAY);
                 floodfill(550,500,DARKGRAY);
                 floodfill(790,300,DARKGRAY);
                 settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 5);
                 setcolor(GREEN);
                 outtextxy(550, 70, "LENGTH");
                 outtextxy(520, 130, "ACHIEVED");
                 length = body.getLen();
                 printlen[0]=char('0'+length/10);
                 printlen[1]=char('0'+length%10);
                 printlen[2] = '\0';
                 outtextxy(620, 190, printlen);
                 settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
                 outtextxy(520, 300, "STATUS :-");
                 // THE UPCOMING IFS CHECK THE CURRENT STATES OF THE GAME AND PRINT ACCORDINGLY
                 if (body.getLen() == 30)
                 {
                      outtextxy(520, 350, "YOU WON !");
                      isplaying=false;
                 }
                 else if(isplaying)
                 {
                      outtextxy(520, 350, "PLAYING");
                 }
                 else
                 {
                      outtextxy(520, 350, "GAME OVER");
                 }
                 settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
                 outtextxy(520,400,"PRESS 'ESC' to EXIT");
                 if(!paused)
                        outtextxy(520,450,"PRESS 'LEFT SHIFT' to PAUSE");
                 else
                        outtextxy(520,450,"RELEASE 'LEFT SHIFT' to PLAY");



            pointer.make();
            page = 1-page;
            delay(100);
    }

    getch();
    closegraph();
}
