
#include "iGraphics.h"
#include <string.h>
#include <stdbool.h>
#include<ctype.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

int home=1;
int level2 = 0; // if it is set to one level 2 will display
char str[300], str2[300], encrypt[300]; // for storing the input
char entry[300];
int len = 0;
int mode = 1; // level 2 round 1 is mode 1 
int levels=0 ;// all level page
bool musicon=true;
int flagmusic=1;
int instruction =0;





// Function prototypes
void alllevels();// alllevels
void alllevelsmouse (int button,int state,int mx,int my);

 
void game2(); // declaring for whole game 2



void game2keyboard(unsigned char key); // controlling keyboard
void cipher(char *text, int key); // encrpyting declaration
void game2imouse(int button,int state,int mx,int my);// controlling mouse event for level 2
void homepagemouse(int button,int state,int mx,int my);//controlling mouse event for homepage
void instructionmouse(int button,int state,int mx,int my);// controlling mouse event for instruction page
void playClickSound() {
    mciSendString("open \"click.wav\" type waveaudio alias click", NULL, 0, NULL);
    mciSendString("play click from 0", NULL, 0, NULL);
}





void iDraw()
{   
    if(home==1)
    {
        iShowBMP2(0,0,"homepage\\menu.bmp",0);
        
    }
    if(instruction==1)
    {
        iShowBMP2(0,0,"homepage\\instruction.bmp",0);
    }
    
    if(levels ==1)
    {
       alllevels();
    }

    if (level2 == 1)
    {
        game2(); // call 
    } 

    
        
    
}

void iMouseMove(int mx, int my)
{
}

void iMouse(int button, int state, int mx, int my)
{          
          if(home==1)
          {
            homepagemouse(button,state,mx,my);   
          }
          if(instruction==1)
          {
            instructionmouse(button,state,mx,my);
          }
          if(levels==1)
          {
            alllevelsmouse(button,state,mx,my);
          }
          if(level2==1)
          {
            game2imouse(button,state,mx,my);
          }
          

}

  


void iKeyboard(unsigned char key)
{   
    
    if (level2 == 1)
    {
        game2keyboard(key);
    }
}

void iSpecialKeyboard(unsigned char key)
{
}

void cipher(char *text, int key) // encrypting the text
{
    int i;
    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            encrypt[i] = 'a' + (text[i] - 'a' + key) % 26;
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            encrypt[i] = 'A' + (text[i] - 'A' + key) % 26;
        }
    }
    encrypt[i]='\0';
}
void alllevels()
{
    iShowBMP2(0,0,"all levels.bmp",0);
}
void namentry()
{
    iShowBMP2(0,0,"homepage\\name entry.bmp",0);
}

void game2()
{
    if (mode == 1)  // The beginning screen will appear
    {   
        
        
        iShowBMP2(0, 0, "round 2 images\\level2-1.bmp", 0);
        iSetColor(255,255,255);
        iText(450,50,"ROUND 1",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(92, 64, 51);
        iText(500, 275, str, GLUT_BITMAP_TIMES_ROMAN_24);
          // the user input show in brown color
    }
    else if (mode == 2)
    {
        iSetColor(255, 255, 255); // activate for showing encrpt message for round 1
        iText(480, 220, encrypt, GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,255,255);
        iText(450,180,"Correct answer",GLUT_BITMAP_TIMES_ROMAN_24);
        mode=3; // update to go to next page
        
        
    }
    else if (mode == -1) // wrong answer game over show
    {
        iShowBMP2(0, 0, "round 2 images\\game over.bmp", 0);
    }
    else if(mode==4) //round 2 begin and showing user input
    {
        iShowBMP2(0,0,"round 2 images\\level2-2.bmp",0);
        iSetColor(255,255,255);
        iText(450,50,"ROUND 2",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(92,64,51);
        iText(500,275,str,GLUT_BITMAP_TIMES_ROMAN_24);
        
    }
    else if(mode==5) //round 2 encrypt text
    {
        iSetColor(255,255,255);
        iText(480,220,encrypt,GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,255,255);
        iText(450,180,"Correct answer",GLUT_BITMAP_TIMES_ROMAN_24);
        mode=6;

    }
    else if(mode==7)// round 3 begin answer && user input
    {
        iShowBMP2(0,0,"round 2 images\\level2-3.bmp",0);
        iSetColor(255,255,255);
        iText(450,50,"ROUND 3",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(92,64,51);
        iText(500,220,str,GLUT_BITMAP_TIMES_ROMAN_24);
        
    }
    else if(mode==8) //round 3 encrypt text
    {
        iSetColor(255,255,255);
        iText(480,180,encrypt,GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,255,255);
        iText(450,130,"Correct answer",GLUT_BITMAP_TIMES_ROMAN_24);
        mode=9;
    }
    else if(mode==10) //round 4 begin image && user input
    {
        iShowBMP2(0,0,"round 2 images\\level2-4.bmp",0);
        iSetColor(255,255,255);
        iText(450,50,"ROUND 4",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(92,64,51);
        iText(500,220,str,GLUT_BITMAP_TIMES_ROMAN_24);
        
    }
    else if(mode==11) // round 4  encrypt text
    {    
        iSetColor(255,255,255);
        iText(480,180,encrypt,GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,255,255);
        iText(450,130,"Correct answer",GLUT_BITMAP_TIMES_ROMAN_24);
        mode=12;
    }

    

    
}

void game2keyboard(unsigned char key)
{
    int i;
	if(mode == 1) // round 1 user input
	{
        if(key == '\r')
		{
			mode = 0;
			strcpy(str2, str);
            if(strcmp(str,"12")==0)
            {
                 cipher("gibgvwbs",12);
                 mode=2;
            }
            else
            {
                mode=-1;
            }
			printf("%s\n", str2);
			for(i = 0; i < len; i++)
				str[i] = 0;
			len = 0;
		}
        else if(key=='\b') //backspace key
        {
            if(len>0)
            {
                len--;
                str[len]='\0';
            }
        }
		else
		{
			str[len] = key;
			len++;
		}
    }
    if(mode==4) // round 2 user input
    {
        if(key=='\r')
        {
            mode=0;
            strcpy(str2,str);
            if(strcmp(str,"6")==0)
            {
                cipher("pifuncfy",6);
                mode=5;
            }
            else 
            {
                mode=-1;
            }
            printf("%s\n",str2);
            for(i=0;i<len;i++)
            str[i]=0;
            len=0;
        }
        else if(key=='\b')
        {
            len--;
            str[len]='\0';
        }
        else
        {
            str[len]=key;
            len++;
        }
    }
    
    if(mode==7) // round 3 user input
    {
        if(key=='\r')
        {
            
            strcpy(str2,str);
        
         if(strcmp(str,"3")==0) 
         {
            cipher("bkbodv",3);
            mode=8;
         }
         else
         {
            mode=-1;
         }
         printf("%s\n",str);
         for(i=0;i<len;i++) 
         str[i]=0;
         len=0;
        }
        else if(key=='\b')
        {
            len--;
            str[len]='\0';
        }
        else
        {
            str[len]=key;
            len++;
        }
    }
     if(mode==10) // round 4 user input
     {
        if(key=='\r')
        {
            mode=0;
            strcpy(str2,str);
            if(strcmp(str,"2")==0)
            {
                cipher("bcapwnr",2);
                mode=11;
            }
            else
            {
                mode=-1;
            }
            for(i=0;i<len;i++)
            str[i]=0;
            len=0;
        }
        else if(key=='\b')
        {
            len--;
            str[len]='\0';
        }
        else
        {
            str[len]=key;
            len++;
        }
     }
     if(key=='x')
     {
        level2=0;
        home=1;
        mode=1;
        for(i=0;i<len;i++)
        {
            str[i]=0;
            len=0;
        }
     } // for exiting game


    
        
}
void alllevelsmouse(int button,int state,int mx,int my)
{
       if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
       { 
            
          
          if(levels==1 && (mx>=115 && mx <= 457) && (my>=403))
          {
            //level1=1;
            //levels=0;
             playClickSound();
          }
          if(levels==1 && (mx>=116 &&mx<=458) && (my>=189 && my<=263))
          {  
             playClickSound();
             level2=1;
             levels=0;
          }
          if(levels==1 && (mx>=116 && mx <=452) && (my>=62 && my<=140))
          {
            //level3=1;
            //levels=0;
            playClickSound();
          }
          if(levels==1 && (mx>=119 && mx<=218) && (my>=453 && my<=558))
          {
            home=1;
            levels=0;
            playClickSound();
          }
       }

}
void homepagemouse(int button,int state,int mx,int my)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        if(home==1 &&(mx>=752&& mx<=959)&& (my>=239&&my<=274))
        {
            levels=1;;
            home=0;
            playClickSound();
        }
        if(home==1 &&(mx>=751 &&mx<=963)&&(my>=147 &&my<=197))
        {
            instruction=1;
            home=0;
            playClickSound();
        }
        if(home==1 &&(mx>=750 && mx<=959)&&(my>=70 && my<=120))
        {
            //scoreboard
            playClickSound();
        }
        
       
    }
}


        
         

        




void game2imouse(int button,int state,int mx,int my)
{
       if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
       {
        if(mode==3)
        {   
            playClickSound();
            mode=4;
        }
        else if(mode==6)
        {   
            playClickSound();
            mode=7;
        }
       else  if(mode==9)
        {   
            playClickSound();
            mode=10;
        }
       
       }
       
} 
void instructionmouse(int button,int state,int mx,int my)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        if(instruction==1 &&(mx>=757&&mx<=960)&&(my>=45&&my<=132))
        {
            instruction=0;
            home=1;
            playClickSound();
        }
    }
}





    

        
int main()
{   
     if(musicon&&flagmusic==1)
     {
     PlaySound("music.wav", NULL, SND_LOOP | SND_ASYNC);
     
     }
     iInitialize(1024,600,"Brain Code: Renovo");
    return 0;
}
    
        
       
        
        
        
       



    
    
    
        
    
        
        




    
        
        
    
        
    
   
    