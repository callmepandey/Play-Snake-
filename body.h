#include <graphics.h>
// ENUMERATION WHICH GLOBALLY SPECIFIES MOVES
enum MOVES {LEFT , UP , RIGHT , DOWN};
// A STRUCTURE WHICH STORES POSITION IN TERMS OF X AND Y in PIXELS
struct location{
    int x , y;
    location(){
        this->x = -50;
        this->y = 0;
    }
};
// CLASS SNAKE WHICH STORES
class snake{
        location body[55];
        int face;
        int length;
    public:
        // CONSTRUCTOR WHICH INITIALISE THE SNAKE
        snake(){
            body[0].x = 30;
            body[0].y = 30;
            length = 2;
            face = RIGHT;
        }
        // FUNCTION DRAW'S SNAKE BODY USING FOR LOOP
        void draw(){
            for(int i = 0;i<this->length;i++){
                setcolor(BLUE);
                rectangle(body[i].x  ,body[i].y , body[i].x + 30 ,body[i].y + 30);
                if(i==0){
                    setfillstyle(SOLID_FILL , WHITE);
                } else {
                    setfillstyle(SOLID_FILL , LIGHTGRAY);
                }
                floodfill(body[i].x + 15 , body[i].y + 15 , BLUE);
            }
        }
        // INCREASES LENGHT OF THE SNAKE WHEN CALLED FROM MAIN.CPP
        void changeLen(){
            if(length <= 34)
                length++;
        }
        // CHANGE THE DIRECTION OF MOVEMENT OF SNAKE
        void changeFace(int newface){
            if((newface==LEFT or newface==RIGHT) and (face==UP or face==DOWN))
            {
                face = newface;
            } else if((newface==UP or newface==DOWN) and (face==LEFT or face==RIGHT)){
                face = newface;
            }
        }
        // CONTROLS ALL THE MOVEMENTS OF SNAKE
        int updateSnake(){
            for(int i = 1;i<this->length;i++){
                if(body[i].x == body[0].x and body[i].y==body[0].y)
                    return 0;
            }
            for(int i = this->length;i;i--){
                body[i].x = body[i-1].x;
                body[i].y = body[i-1].y;
            }
            if(face == LEFT){
                body[0].x -= 30;
                if(body[0].x == 0){
                    body[0].x = 450;
                }
            } else if(face == RIGHT){
                body[0].x += 30;
                if(body[0].x == 480){
                    body[0].x = 30;
                }
            } else if(face == UP){
                body[0].y -= 30;
                if(body[0].y == 0){
                    body[0].y = 450;
                }
            } else if(face == DOWN){
                body[0].y += 30;
                if(body[0].y == 480){
                    body[0].y = 30;
                }
            }
            return 1;
        }
        // RETURNS X POSITION
        int getX(){
            return body[0].x;
        }
        // RETURNS Y POSITION
        int getY(){
            return body[0].y;
        }
        // RETURNS LENGHT OF SNAKE
        int getLen(){
            return length;
        }
};
