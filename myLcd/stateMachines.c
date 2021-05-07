#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "lcdutils.h"
#include "lcddraw.h"

static int locX=0;
static int locY=0;
void state_advance()		/* alternate between toggling red & green */
{
  /*  char changed = 0;  
  static char state = 0;
  switch (state) {
  case 0: red_on = 0; green_on = 0; state++; break;
  case 1: red_on = 0; green_on = 1; state++; break;
  case 2: red_on = 1; green_on = 0; state++; break;
  case 3: red_on = 1; green_on = 1; state = 0; break;

  default: state = 0;
  }

  led_changed = 1;
  led_update(); */
} 

void buzzer_state_advance(){
  if(S1){
    buzzer_state_1_advance();
  }else if(S2){
    buzzer_state_2_advance();
  }else if(S3){
    buzzer_state_3_advance();
  }else if(S4){
    buzzer_state_4_advance();
  }else{
    buzzer_set_period(0);
  }
}

void buzzer_state_1_advance(){
  static char buzz_state = 0 ;
  switch(buzz_state) {
  case 0: buzzer_set_period(14431); fillDiamond(50,50,40,COLOR_GREEN); buzz_state++; break;
  case 1: buzzer_set_period(14431); fillDiamond(60,60,50,COLOR_BLACK); buzz_state++; break;
   case 2: buzzer_set_period(0);  fillDiamond(70,70,40,COLOR_ORANGE); buzz_state++; break;
   case 3: buzzer_set_period(0); fillDiamond(80,80,50,COLOR_WHITE); buzz_state++; break;  
   case 4: buzzer_set_period(0); buzz_state = 0; break;   
  default: buzz_state = 0;
    
  }

}

void buzzer_state_2_advance(){
  static char buzz_state = 0 ;
  switch(buzz_state) {
   case 0: buzzer_set_period(14431); buzz_state++; break;
   case 1: buzzer_set_period(14431); fillTriangle(30, 30, 40, COLOR_GREEN); buzz_state++; break;
   case 2: buzzer_set_period(0); fillTriangle(30, 30, 40, COLOR_BLUE); fillTriangle(30, 40, 40, COLOR_GREEN); buzz_state++; break;
   case 3: buzzer_set_period(0); fillTriangle(30, 40, 40, COLOR_BLUE); fillTriangle(30, 50, 40, COLOR_GREEN); buzz_state++; break;  
   case 4: buzzer_set_period(14431); red_on = 1; fillTriangle(30, 50, 40, COLOR_BLUE); fillTriangle(30, 60, 40, COLOR_GREEN); buzz_state++; break;
   case 5: buzzer_set_period(0); red_on = 0; fillTriangle(30, 60, 40, COLOR_BLUE); fillTriangle(30, 70, 40, COLOR_GREEN); buzz_state++; break;
   case 6: buzzer_set_period(14431); red_on = 1; fillTriangle(30, 70, 40, COLOR_BLUE);fillTriangle(30, 80, 40, COLOR_GREEN); buzz_state++; break;
   case 7: buzzer_set_period(0); red_on = 0;  fillTriangle(30, 80, 40, COLOR_BLUE); buzz_state++; break;
   case 8: buzzer_set_period(14431); red_on = 1; buzz_state=0; break;

  default: buzz_state = 0;
    
  }
  led_changed = 1;
  led_update();
}

void buzzer_state_3_advance(){
  static char buzz_state = 0 ;
  static int locY = 0;
  static int locx = 0;
  
  switch(buzz_state) {
  case 0: buzzer_set_period(14431);  fillRectangle(10,20,100,20,COLOR_ORANGE); buzz_state++; break;
    
   case 1: buzzer_set_period(0); fillRectangle(10,20,100,20,COLOR_BLUE); fillRectangle(10,40,100,20,COLOR_ORANGE); buzz_state++; break;
     
   case 2: buzzer_set_period(14431); fillRectangle(10,40,100,20,COLOR_BLUE); fillRectangle(10,50,100,20,COLOR_ORANGE); buzz_state++; break;
     
   case 3: buzzer_set_period(0); fillRectangle(10,50,100,20,COLOR_BLUE); fillRectangle(10,60,100,20,COLOR_ORANGE); buzz_state++; break;

   case 4: buzzer_set_period(0); fillRectangle(10,60,100,20,COLOR_BLUE); fillRectangle(10,70,100,20,COLOR_ORANGE); buzz_state++; break;
     
   case 5: buzzer_set_period(0); fillRectangle(10,70,100,20,COLOR_BLUE); fillRectangle(10,80,100,20,COLOR_ORANGE); buzz_state++; break;

   case 6: buzzer_set_period(0); fillRectangle(10,80,100,20,COLOR_BLUE); fillRectangle(10,90,100,20,COLOR_ORANGE); buzz_state++; break;

   case 7: buzzer_set_period(0); fillRectangle(10,90,100,20,COLOR_BLUE); fillRectangle(10,100,100,20,COLOR_ORANGE); buzz_state++; break;

   case 8: buzzer_set_period(0); fillRectangle(10,100,100,20,COLOR_BLUE); fillRectangle(10,110,100,20,COLOR_ORANGE); buzz_state++; break;
     
   case 9: buzzer_set_period(0); fillRectangle(10,110,100,20,COLOR_BLUE); fillRectangle(10,120,100,20,COLOR_ORANGE); buzz_state++; break;

  case 10: buzzer_set_period(0); fillRectangle(10,120,100,20,COLOR_BLUE); buzz_state = 0; break;
     
  default: buzz_state = 0;
    
  }
}

void buzzer_state_4_advance(){
  static char buzz_state = 0 ;
  switch(buzz_state) {
    
  case 0: buzzer_set_period(0); drawString8x12(10,10, "test", COLOR_GREEN, COLOR_BLUE); buzz_state++; break;
    
  case 1: buzzer_set_period(0); drawString8x12(10,10,"test", COLOR_BLUE, COLOR_BLUE); drawString8x12(20,20, "test", COLOR_GREEN, COLOR_BLUE); buzz_state++; break;
       
  case 2: buzzer_set_period(0); drawString8x12(20,20, "test", COLOR_BLUE, COLOR_BLUE); drawString8x12(30,30, "test", COLOR_GREEN, COLOR_BLUE); buzz_state++; break;

  case 3: buzzer_set_period(0); drawString8x12(30,30,"test", COLOR_BLUE, COLOR_BLUE); drawString8x12(40,40, "test", COLOR_GREEN, COLOR_BLUE); buzz_state++; break;

  case 4: buzzer_set_period(0); drawString8x12(40,40,"test", COLOR_BLUE, COLOR_BLUE); drawString8x12(50,50, "test", COLOR_GREEN, COLOR_BLUE); buzz_state++; break;

  case 5: buzzer_set_period(0); drawString8x12(50,50,"test", COLOR_BLUE, COLOR_BLUE); drawString8x12(60,60, "test", COLOR_GREEN, COLOR_BLUE); buzz_state++; break;    

  case 6: buzzer_set_period(0); drawString8x12(60,60,"test", COLOR_BLUE, COLOR_BLUE); drawString8x12(70,70, "test", COLOR_GREEN, COLOR_BLUE); buzz_state++; break;

 case 7: buzzer_set_period(0); drawString8x12(70,70,"test", COLOR_BLUE, COLOR_BLUE); drawString8x12(80,80, "test", COLOR_GREEN, COLOR_BLUE); buzz_state++; break;

 case 8: buzzer_set_period(0); drawString8x12(80,80,"test", COLOR_BLUE, COLOR_BLUE); buzz_state = 0; break;    
  }
}
