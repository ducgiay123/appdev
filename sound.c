#include <stdio.h>
#include "sound.h"
#include <math.h>
#include "screen.h"
#include "comm.h"

WAVheader readWavHdr(FILE *fp){
	WAVheader myh ;
	fread(&myh, sizeof(myh) , 1 , fp);
	return myh;
}

void displayWavHdr (WAVheader h) {
	setfgcolor(BLUE);
	/*for(int i=0 ; i<4 ; i++){
		printf("%c" , h.chunkID[i]) ;
	} */
	printf("\n") ;
	printf("CHUNK size:%d\n" , h.chunkSize ) ;
	printf("NUmber of channels: %d\n" , h.numChannels) ;
	gotoXY(1,1) ;
	printf("Sample rate: %d\n" , h.sampleRate) ;
	setfgcolor(GREEN);
	//printf("Bits per sample: %d\n" , h.bitsPerSample);
	// ------ to be continued
	double duration;
	duration =(double) h.subchunk2Size/h.byteRate;
	gotoXY(1,75) ;
	printf("Duration: %.2f seconds\n",duration);
	resetcolors();
}
void wavdata(WAVheader h , FILE *fp){
	short samples[SIZE];
	double temp =0 ;
	double dB = 0 ;
	char postdata[100];
	int c=0;
	double max=0 ;
	for(int i=0 ; i<BARS ; i++){ // read 5-sec wave file
		fread(samples,sizeof(samples) , 1  , fp) ;
		double sum = 0.0 ;
		for(int k=0;k<SIZE ; k++){
			sum+= samples[k]*samples[k] ;
		}
		//double dB = sqrt(sum/2000);
		temp = dB;
		dB=20*log10(sqrt(sum/SIZE));
		if(dB>65){
			setfgcolor(RED) ;
		}
		if((dB-temp)>30){
			c++ ; 
		}
		if(dB>=max){
			max=dB ;
		}
#ifdef SDEBUG
		printf("dB[%d] = %f\n",i,dB);
#else 
		drawbar(i+1 , (int)dB/3) ;
#endif 
		resetcolors();
	}
	sprintf(postdata , "Peaks=%d&MaxdB=%f\n" ,  c , max) ;
	sendpost(URL,postdata);
	gotoXY(1,150);
	setfgcolor(MAGENTA);
	printf("Number of peaks: %d",c);
	gotoXY(2,150);
	printf("MAX dB: %f",max);
	resetcolors();
}
