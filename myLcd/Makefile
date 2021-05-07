# makfile configuration
CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all:wakedemo.elf

#additional rules for files
wakedemo.elf: ${COMMON_OBJECTS} wakedemo.o wdt_handler.o wdt_handler.o font-8x12.o lcdutils.o lcddraw.o buzzer.o led.o p2_interrupt_handler.o stateMachines.o switches.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd

assemblydemo.elf: ${COMMON_OBJECTS} mainAssembly.o wdt_handler.o lcdutils.o lcddraw.o stateAssembly.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd 

load: wakedemo.elf
	msp430loader.sh $^

load2: assemblydemo.elf
	msp430loader.sh $^

buzzer.o: buzzer.c buzzer.h


led.o: led.c led.h


p2_interrupt_handler.o: switches.h


stateMachines.o: led.h stateMachines.h switches.h buzzer.h lcddraw.h  


switches.o: led.h switches.h


lcddraw.o: lcddraw.c lcddraw.h lcdutils.h


lcdutils.o: lcdutils.c lcdutils.h

stateAssembly.o: stateAssembly.h stateAssembly.s

clean:
	rm -f *.o *.elf
