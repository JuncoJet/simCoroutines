#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
DWORD xc[2];

delay(int t,int x){
	xc[x]=(xc[x]?xc[x]:timeGetTime())+t;
}
block1(){
    puts("block1 delay 1000");
    delay(1000,0);
}
block2(){
    puts("block2 delay 2000");
    delay(2000,1);
}
setup(){
	
}
loop(){
	DWORD t=timeGetTime();
	if(t>=xc[0]||!xc[0])block1();
	if(t>=xc[1]||!xc[1])block2();
	Sleep(1);
}
main(){
	setup();
    for(;;)loop();
}
