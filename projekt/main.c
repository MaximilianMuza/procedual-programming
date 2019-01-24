#include <stdio.h>
#include <locale.h>
#include <ncurses.h>

#define H 30
#define W 30

bool gameover = false;
typedef enum eDirection { STOP=0, UP, DOWN, LEFT, RIGHT, JUMP} eDirection;
eDirection dir;
int x, y, brickx ,bricky , score;
int brickl[W];
int blockbool = 0;
int block1[2] = {10,25};
int block2[2] = {15,20};
int block3[2] = {4,15};
int block4[2] = {25,7};

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

int checkforBlock() {
  for(int i = 0; i < 5; i++) {
    if(x == block4[0]+i && y == block4[1]-1) {
      return 1;
    } else {
      return 0;
    }
  }
  return 0;
}

void draw()
{
  clear();
  for(int i = 0 ; i < H+2 ; i++)
  {
    for(int j = 0 ; j < W+2; j++)
    {
        if (j==0 || j == W+1 || i == 0 || i == H+1)
        {
          mvprintw(i,j,"█");
        }
        else if (i == y && j == x)
        {
            mvprintw(i, j, "¶");
        }
        if(j == block1[0] && i == block1[1])
        {
          for (int b = 0 ; b < 5 ; b++)
             mvprintw(i,j+b,"█");
        } else if(j == block2[0] && i == block2[1]) 
        {
          for (int b = 0 ; b < 5 ; b++)
             mvprintw(i,j+b,"█");
        } else if(j == block3[0] && i == block3[1]) 
        {
          for (int b = 0 ; b < 5 ; b++)
             mvprintw(i,j+b,"█");
        } else if(j == block4[0] && i == block4[1]) 
        {
          for (int b = 0 ; b < 5 ; b++)
             mvprintw(i,j+b,"█");
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
       case JUMP: if(blockbool){break;}
                  for(int i = 0 ; i < 18 ; i++)
                      {
                        if(i < 9){
                          y--;
                          input();
                          if(dir == LEFT) {
                            if(x==1){break;} 
                            x -= 1; 
                            dir = STOP;
                          }
                          if(dir == RIGHT) {
                            if(x==W){break;} 
                            x += 1; 
                            dir = STOP;
                          }
                          // if(checkforBlock()) {
                          //   dir = STOP;
                          //   break;
                          // }
                          dir = STOP;
                          draw();
                        }else{
                          if(checkflor()){break;}
                          y++;
                          input();
                          if(dir == LEFT) {
                            if(x==1){break;} 
                            x -= 1; 
                            dir = STOP;
                          }
                          if(dir == RIGHT) {
                            if(x==W){break;} 
                            x += 1; 
                            dir = STOP;
                          }
                          // if(checkforBlock()) {
                          //   dir = STOP;
                          //   break;
                          // }
                          dir = STOP;
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
