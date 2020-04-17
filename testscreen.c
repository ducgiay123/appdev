//This file will be used to test functions in screen.c

#include <stdio.h>
#include "screen.h"
#include <unistd.h>
#include "comm.h"
#include "sound.h"
int main(void){
	Position cur = getscreensize() ;
	char postdata[100];
	sprintf(postdata , "row=%d&col=%d&id=e1900297" ,  cur.row , cur.col) ;
	sendpost(URL , postdata) ;
	gotoXY(1,1) ;
	printf("screen size: row=%d ,col =%d\n", cur.row , cur.col);
	getchar();
	getchar() ;
	int ff , bb;
	float step = (float)cur.col/cur.row;
	for (int i=1 ; i<= cur.row ; i++){
		ff =(i+1)%8+BLACK ;
		bb =(i+1)%8+BLACK ;
		setcolors(ff , bg(bb)) ;
		clearscreen() ;
		drawrect(10 ,10 , 5 , 30) ;
		gotoXY(cur.row - i ,(i-1)*step +1 );
		printf("Hello\n");
		usleep(200000) ;
}
	getchar() ;
	resetcolors();
	clearscreen();
	printf("color is set back to default\n");
	getchar() ;
	FILE *fp = fopen("test.wav" , "r") ;
	WAVheader h = readWavHdr(fp) ;
	fclose(fp);
	displayWavHdr(h) ;
/*	printf("Today we will make some animation.  Press any key to continue\n");
	getchar();	//wait for user to press a key
	int ff, bb;
	for(int  i=1; i<21; i++){
		ff = (i+1)%8+BLACK;
		bb = (i+2)%8+BLACK;
		setcolors(ff, bg(bb));
		clearscreen();

		drawrect(1, 1, 2, 4);
		gotoXY(21-i, (i-1)*4+1);
		printf("HELLO\n");
		sleep(1);
	}

	for(int i=1; i<=18; i++){
		clearscreen();
		gotoXY(19-i,3* i);
		setfgcolor(GREEN);
		printf("HELLO\n");
		setfgcolor(RED);
		drawrect(i,3* i, 2, 4);
		usleep(200000);
	}
	getchar();
	 for(int i=1; i<=18; i++){
		clearscreen();
		gotoXY(i, 51+3*i);
		setfgcolor(GREEN);
		printf("HELLO\n");
		setfgcolor(RED);
		drawrect(19-i, 51+3*i, 2, 4);
		usleep(200000);
	}

	getchar();
	resetcolors();
	clearscreen();
 	printf("Color is set back to default\n");
 	getchar();

	setfgcolor(GREEN);
	gotoXY(14, 35);
	printf("HEllO, WORLD!\n");
	getchar();	//wait for user to press a key
	drawbar(30, 30);
	drawbar(50, 30);
	getchar();	//after drawing bars, wait for key
	resetcolors();
	printf("This text is displayed in default color \n");
*/
}
