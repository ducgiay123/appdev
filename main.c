//This file will be used to test functions in screen.c

#include <stdio.h>
#include "screen.h"
#include <unistd.h>
#include "comm.h"
#include "sound.h"
int main(void){
	Position p = getscreensize();
	if (p.col<BARS){
		printf("Your screen is not enough size %d BAR",BARS);
	}
	clearscreen();
	FILE *fp = fopen("test.wav" , "r") ;
	WAVheader h = readWavHdr(fp) ;
	displayWavHdr(h) ;
	getchar();
	wavdata(h,fp);
	fclose(fp);

}
