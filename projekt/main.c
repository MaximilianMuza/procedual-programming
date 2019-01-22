#include <stdio.h>
#include <locale.h>
#include <ncurses.h>
#include <unistd.h>


#define H 30
#define W 30



bool gameover = false;
typedef enum eDirection { STOP=0, UP, DOWN, LEFT, RIGHT, JUMP} eDirection;
eDirection dir;
int x, y, brickx ,bricky , score;

int brickl[W];

void setup()
{
  initscr();
  clear();
  noecho();
  cbreak();
  curs_set(0);
  printw("Jumping O");

  score = 0;
  x = W/2;
  y = H;



}

void draw()
{
  clear();
  int block[2] = {10,25};
  for(int i = 0 ; i<H+2 ; i++)
  {
    for(int j = 0 ; j < W+2; j++)
    {
        if (j==0 || j == W+1 || i == 0 || i == H+1)
        {
          mvprintw(i,j,"█");
        }
        else if (j == block[0] && i == block[1])
        {
          mvprintw(i,j,"████");
        }
        else if (i == y && j == x)
        {
            mvprintw(i, j, "¶");
        }
    }
  }
  mvprintw(H+3,10,"Score: %d",score);
  refresh();

}



void input()
{
  keypad(stdscr,TRUE);
  halfdelay(1);          //delay after input(speed)

  int c = getch();

  switch(c)
  {
      case KEY_UP: dir = JUMP; break;
      case KEY_LEFT: dir = LEFT; break;
      case ' ': dir = JUMP; break;
      case KEY_RIGHT: dir = RIGHT; break;
      case 113: gameover = true; break;
  }
}


void logic()
{

  switch(dir)
   {
       case LEFT: if(x==1){break;} x--; break;
       case RIGHT: if(x==W){break;} x++; break;
       case JUMP:  for(int i = 0 ; i < 18 ; i++)
                      {
                        if(i < 9){
                          y--;
                          input();
                          if(dir == LEFT) {
                            if(x==1){break;} 
                            x -= 2; 
                            dir = STOP;
                          }
                          if(dir == RIGHT) {
                            if(x==W){break;} 
                            x += 2; 
                            dir = STOP;
                          }
                          draw();
                        }else{
                          y++;
                          input();
                          if(dir == LEFT) {
                            if(x==1){break;} 
                            x -= 2; 
                            dir = STOP;
                          }
                          if(dir == RIGHT) {
                            if(x==W){break;} 
                            x += 2; 
                            dir = STOP;
                          }
                          draw();
                        }
                      }
       default: break;
   }
   dir = STOP;
}




int main(int argc,char * argv[])
{
    setlocale(LC_ALL, "");
    setup();
    while (!gameover)
    {
      draw();
      input();
      logic();
    }


    getch();
    endwin();

  return 0;
}
