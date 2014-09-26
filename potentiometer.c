/* 
 * File:   main.c
 * Author: t4krha00
 *
 * Created on 26. syyskuuta 2014, 13:32
* k‰ytt‰‰ A/D muunninta (TLC549CP) 
*/

#include <stdio.h>
#include <stdlib.h>
#include <wiringPiSPI.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <unistd.h>

int fd, value;
int channel = 0;
int speed = 500000;
unsigned char *data;


int main(void)
 {


    if ((fd = wiringPiSPISetup(channel, speed)) < 0) {
        return -1;
  
    }
    while(1)
    {
        wiringPiSPIDataRW(channel,&data, 1);
        printf("Value %i\n", data);
        delay(700);
         
    }

  

}
