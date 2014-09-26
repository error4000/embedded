#include <stdio.h>
#include <wiringPiI2C.h>
#include <unistd.h>
#include <wiringPi.h>
#include <sys/types.h>

#define dID 0x70

int range1,range2,range3;
int i,fd;
int rng;

int main(void)
{
    
    

   
   wiringPiSetup();
   pinMode(0, OUTPUT);
   pinMode(2, OUTPUT);
   
   if((fd=wiringPiI2CSetup(dID))<0)
   {
        return -1;
   }

   while(1)
   {
        wiringPiI2CWriteReg8 (fd, 0, 0x51) ;
        delay(700);
        rng = range();
        printf("Range %i \n", rng);
        
        if(range() > 41 && range() < 100) {digitalWrite(0,HIGH);}
            else {digitalWrite(0,LOW);}
            
        if(range() < 40){digitalWrite(2,HIGH);}
            else{digitalWrite(2,LOW);}
       
        if(range() > 100)
        {

               digitalWrite(0,HIGH);
               digitalWrite(2,HIGH);
               delay(400);
               digitalWrite(0,LOW);
               digitalWrite(2,LOW);
            
            
        }
       
}
   return 0;
   
   }

   int range(void)
   {
         range1 =  wiringPiI2CReadReg8 (fd, 2) ;
         range2 =  wiringPiI2CReadReg8 (fd, 3) ;
         range3 = (range1 << 8) + range2;
         return range3;
   }
