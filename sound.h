// this header file contains constants definition and function decalarations
// for processing sound , specifically .wav files .

typedef struct {
	char chunkID[4] ;			// should be always "RIFF"
	int  chunkSize ; 			// indicates how big sound data is
	char format[4] ;			// should be always "WAVE"
	char subchunk1ID[4] ;		// shoulb be always "fmt"
	int  subchunk1Size ;		// should be 16 for PCM data
	short audioFormat ; 		// should be 1 for Lenear samples
	short numChannels ;			// 1 for mono , 2  for stereo
	int sampleRate ; 			// could be 44100 , 16000 , 8000
	int byteRate ; 				// can be caculated
	short blockAlign ; 			//
	short bitsPerSample ; 		// how many bits in one sample
	char subchunk2ID[4] ;		//
	int  subchunk2Size ;		// how many bytes exactly for data part
	
}WAVheader ;

//function declarations

WAVheader readWavHdr(FILE *) ;
void displayWavHdr(WAVheader) ;
