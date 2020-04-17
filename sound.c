#include <stdio.h>
#include "sound.h"

WAVheader readWavHdr(FILE *fp){
	WAVheader myh ;
	fread(&myh, sizeof(myh) , 1 , fp);
	return myh;
}

void displayWavHdr (WAVheader h) {
	for(int i=0 ; i<4 ; i++){
		printf("%c" , h.chunkID[i]) ;
	}
	printf("\n") ;
	printf("CHUNK size:%d\n" , h.chunkSize ) ;
	printf("NUmber of channels: %d\n" , h.numChannels) ;
	printf("Sample rate: %d\n" , h.sampleRate) ;
	printf("Bits per sample: %d\n" , h.bitsPerSample);
	// ------ to be continued
	double duration;
	duration =(double) h.subchunk2Size/h.byteRate;
	printf("Duration: %f seconds\n",duration);
}
