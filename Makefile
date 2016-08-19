blinker = Second_Assignment
source = Blink.c
File = Blink
compiler = avr-gcc
MC = atmega328p
port = /dev/ttyUSB*
$(blinker):
			$(compiler) -g -Os -mmcu=$(MC) -c $(source)
			$(compiler) -g -mmcu=$(MC) -Wall -Os -o $(File).elf $(source)
			avr-objcopy -j .text -j .data -O ihex $(File).elf $(File).hex
load:
		sudo avrdude -F -c arduino -p m328 -P $(port) -b 57600 -U flash:w:$(File).hex
clean: 
		rm -f $(File).elf $(File).hex	$(File).o
