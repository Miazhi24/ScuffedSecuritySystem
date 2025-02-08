CFLAGS ?= -Os -DF_APU=16000000UL -mmcu=atmega328p
LDFLAGS ?= -mmcu=atmega328p
ARDUINO_USB ?= /dev/ttyUSB0

all: main.hex

main.hex: main
	avr-objcopy -O ihex -R .eeprom main main.hex

main: main.o
	avr-gcc $(CFLAGS) -c -o $@ $<

deploy: main.hex
	avrdude -F -V -c arduino -p ATMEGA328p -P ${ARDUINO_USB} -b 115200 -U flash.w:main.hex

clean: FRC
	rm -f main.elf main.hex main.o main

FRC: