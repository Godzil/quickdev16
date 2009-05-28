#include <string.h>
#include "data.h"
#include "pad.h"
#include "PPU.h"
#include "ressource.h"

word debugMap[0x400];


void debug_init(void) {
	word i;
	for(i=0; i<0x400; i++) {
		debugMap[i] = 0x00;
	}
}

char hex_chars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

void int2hex(unsigned long number, char *buf,word size)
{
    unsigned long n;
    unsigned char i;
    //unsigned char x;
    for (i = 0; i < size; i++) {
        n = number >> 4;
        //x = (number - (n << 4));
        buf[size-i-1] = hex_chars[(number - (n << 4))]; 
        number = n;    
    }

}

void print_screen(char *buffer,word y){
    char i;
    char l;
    l = strlen(buffer);
    waitForVBlank();
	for(i=0; i<32; i++) {
		if (i<l)
		    VRAMByteWrite((byte) (buffer[i]-32), (word) (0x4000+i+(y*0x20)));
	    else
	        VRAMByteWrite((byte) (' '-32), (word) (0x4000+i+(y*0x20)));
	}
}

void print_console(char *buffer){
	while(*buffer)
	    *(byte*) 0x3000=*buffer++;
}

void debug_enable(void){
	VRAMLoad((word) debugFont_pic, 0x5000, 2048);
	CGRAMLoad((word) debugFont_pal, (byte) 0x00, (word) 16);
	VRAMLoad((word) debugMap, 0x4000, 0x0800);
	setTileMapLocation(0x4000, (byte) 0x00, (byte) 0);
	setCharacterLocation(0x5000, (byte) 0);
	*(byte*) 0x2100 = 0x0f; // enable background
}