#include <iostream>
#include <cstdlib>


using namespace std;
bool gameOver;
const int width=20;
const int height=20;
int x, y ,fruitX,fruitY, score;
int tailX[100], tailY[100];// Array
int nTail; 
enum eDirecton {STOP=0, lEFT, RIGHT, UP, DOWN};
eDirecton dir;

void Setup()
{
     gameOver=false;
     dir = STOP;
     x= width/2;
     y=height/2;
     fruitX=rand()%width; // randowm
     fruitY=rand()%height;
     score=0;
}

void Draw()
{
   system("clear"); 
   for (int i=0; i <width+2; i++)
        cout<<"#";
    cout << endl;

   for (int i=0; i< height; i++)
   {
       for(int j=0; j< width;j++)
       {
           if(j==0)
             cout<<"#";
           if(i==y && j==x)
             cout<<"0";
           else if (i==fruitY && j==fruitX)
             cout<< "F";
           else
           {  
              bool print =false;          
              for (int k = 0; k < nTail; k++)
              {
                    if(tailX[k]==j && tailY[k]==i)
                  {
                    cout<<"o";
                    print=true;
                  }                          
              }
              if(!print)
              cout<<" ";
           }
           if(j==width-1)
             cout<<"#";
       }   
       cout<<endl;
   }

   for (int i=0; i <width+2; i++)
        cout<<"#";
    cout << endl;
    cout<<"score:"<<score<< endl;
    

   
} 

void Input()
{
  char key;  
      cin>>key;
        switch (key)
        {
        case 'a':
            dir = lEFT;
            break;
        case 'w':
            dir = UP;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver=true; break;
        }
        
}
void Logic()
{   
    tailX[0]=x;
    tailY[0]=y;
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2X, prev2Y;
    
    for( int i=1; i< nTail; i++)
    {
      prev2X=tailX[i];
      prev2Y=tailY[i];
      tailX[i]=prevX;
      tailY[i]=prevY;
      prevX =prev2X;
      prevY= prev2Y;
    }
    switch(dir)
   {
     case lEFT: x--; break;
     case RIGHT: x++; break;
     case UP: y--;break;
     case DOWN: y++; break;
     default: 
       break;
   }
   if (x>width || x<0 || y> height || y<0)
       gameOver =true;
    
   for (int i=0; i<nTail;i++)
      if(tailX==x && tailY[i]==y)
        gameOver=true;
   if (x==fruitX && y==fruitY)
   {
     score +=10;
     fruitX=rand()%width; // randowm
     fruitY=rand()%height;
     nTail++;
   }
}
int main()
{
    Setup();
    while(!gameOver)
    {
    Draw();
    Input();
    Logic();
    // sleep(10) slow the game
    }
    return 0;
        
}
   
        

    
