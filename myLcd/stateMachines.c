#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "lcdutils.h"
#include "lcddraw.h"

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
   case 0: buzzer_set_period(14431); red_on = 1; green_on = 1; buzz_state++; break;
   case 1: buzzer_set_period(14431); red_on = 1; green_on = 1; buzz_state++; break;
   case 2: buzzer_set_period(0); red_on = 0; green_on = 0; buzz_state++; break;
   case 3: buzzer_set_period(0); buzz_state++; break;  
   case 4: buzzer_set_period(0); buzz_state = 0; break;   
  default: buzz_state = 0;
    
  }
  led_changed = 1;
  led_update();
}

void buzzer_state_2_advance(){
  static char buzz_state = 0 ;
  switch(buzz_state) {
   case 0: buzzer_set_period(14431); red_on = 1; green_on = 0; buzz_state++; break;
   case 1: buzzer_set_period(14431); buzz_state++; break;
   case 2: buzzer_set_period(0); red_on = 0; green_on = 0; buzz_state++; break;
   case 3: buzzer_set_period(0); buzz_state++; break;  
   case 4: buzzer_set_period(14431); red_on = 1; green_on = 0; buzz_state++; break;
   case 5: buzzer_set_period(0); red_on = 0; green_on = 0; buzz_state++; break;
   case 6: buzzer_set_period(14431); red_on = 1; green_on = 0; buzz_state++; break;
   case 7: buzzer_set_period(0); red_on = 0; green_on = 0; buzz_state++; break;
   case 8: buzzer_set_period(14431); red_on = 1; green_on = 0; buzz_state++; break;
   case 9: buzzer_set_period(14431); buzz_state++; break;
   case 10: buzzer_set_period(14431); buzz_state++; break;  
   case 11: buzzer_set_period(16198); red_on = 0; green_on = 1; buzz_state++; break;
   case 12: buzzer_set_period(0); red_on = 0; green_on = 0; buzz_state++; break;  
   case 13: buzzer_set_period(12139); red_on = 1; green_on = 1; buzz_state++; break;
   case 14: buzzer_set_period(12139); buzz_state++; break;
   case 15: buzzer_set_period(12139); buzz_state++; break;
   case 16: buzzer_set_period(12139); buzz_state++; break;// Pause

   case 17: buzzer_set_period(0); red_on = 0; green_on = 0; buzz_state++; break;
   case 18: buzzer_set_period(0); buzz_state++; break;
   case 19: buzzer_set_period(0); buzz_state++; break;
   case 20: buzzer_set_period(0); buzz_state++; break;
   case 21: buzzer_set_period(0); buzz_state++; break;
   case 22: buzzer_set_period(0); buzz_state++; break;
   case 23: buzzer_set_period(0); buzz_state++; break;
   case 24: buzzer_set_period(0); buzz_state++; break;
   case 25: buzzer_set_period(0); buzz_state++; break;      
   case 26: buzzer_set_period(0); buzz_state = 0; break;   
  default: buzz_state = 0;
    
  }
  led_changed = 1;
  led_update();
}

void buzzer_state_3_advance(){
  static char buzz_state = 0 ;
  switch(buzz_state) {
  case 0: buzzer_set_period(14431); red_on = 1; fillTriangle(3, 1, 40, COLOR_ORANGE); buzz_state++; break;
    
   case 1: buzzer_set_period(0); red_on = 0; fillTriangle(3, 1, 40, COLOR_ORANGE); buzz_state++; break;
     
   case 2: buzzer_set_period(14431); red_on = 1; fillTriangle(3, 1, 40, COLOR_ORANGE); buzz_state++; break;
     
   case 3: buzzer_set_period(0); red_on = 0; green_on = 0; buzz_state++; break;  
   case 4: buzzer_set_period(14431); red_on = 1; green_on = 1; buzz_state++; break;
   case 5: buzzer_set_period(0); red_on = 0; green_on = 0; buzz_state++; break;
   case 6: buzzer_set_period(14431); red_on = 1; green_on = 1; buzz_state++; break;
   case 7: buzzer_set_period(0); buzz_state++; break;
   case 8: buzzer_set_period(0); buzz_state++; break;
   case 9: buzzer_set_period(0); buzz_state++; break;
   case 10: buzzer_set_period(0); buzz_state++; break;  
   case 11: buzzer_set_period(0); buzz_state = 0; break;   
  default: buzz_state = 0;
    
  }
  led_changed = 1;
  led_update();
}

void buzzer_state_4_advance(){
  static char buzz_state = 0 ;
  switch(buzz_state) {
  case 0: buzzer_set_period(16198); red_on = 1; drawString8x12(20,50, "A TEST", COLOR_GREEN, COLOR_BLUE);  buzz_state++; break;
     
  case 1: buzzer_set_period(12139); red_on = 0; drawString8x12(20,50, "A TEST", COLOR_BLUE, COLOR_BLUE); buzz_state++; break;
    
   case 2: buzzer_set_period(0); red_on = 0; drawString8x12(30,70, "A TEST", COLOR_GREEN, COLOR_BLUE);   buzz_state++; break;// pause
     
   case 3: buzzer_set_period(0); drawString8x12(30,70, "A TEST", COLOR_BLUE, COLOR_BLUE); buzz_state = 0; break;
     
  default: buzz_state = 0;
    
  }
  led_changed = 1;
  led_update();
}
