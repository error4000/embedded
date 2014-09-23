#include <wiringPi.h>
#include <stdio.h>
int main() 
{
	int i;
	wiringPiSetup () ;

	pinMode(0, OUTPUT);
	for(i=0; i<10; i++)
	{
		digitalWrite(0,HIGH);
		printf("/a");
		delay(500);
		digitalWrite(0, LOW);
		delay(500);
}

return 0;
}
