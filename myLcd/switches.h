#ifndef switches_included
#define switches_included

#define SW1 BIT0		/* switch1 is moved ot p2 inputs (green board) */
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define SWITCHES (SW1 | SW2 | SW3 | SW4) /*makes use of four switches*/

void switch_init();
void switch_interrupt_handler();

extern char S1, S2, S3, S4, switch_state_down, switch_state_changed; /* effectively boolean */

#endif // included
