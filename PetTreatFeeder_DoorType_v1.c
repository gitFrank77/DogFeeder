#define F_CPU   10000000UL
#define uint8_t         byte

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "servo2.h"

#define MIN_POS 0
#define MID_POS 1000
#define MAX_POS 2000

#define DELAY_TEST 1000
#define DELAY   1
#define DELAY2  15

int
main (void)
{
  //Initialize pinB 1 for servo control and pinB 2 for led
  servoInit();

        OUTPUTS_B |=(1<<2);

        _delay_us(10000);
  while (1)
    {      // uncomment code is you don't want to use the 'servoSweep' function found in PetTreatFeeder_DoorType_v1.h
/*              signed volatile int i;

                if(! (INPUTS_D &(1<<7))){ // enable servo when button IS pressed
                        for( i =0; i <=2000; i++){
                                OCR1A =i;
                                _delay_us(DELAY2);
                                OUTPUTS_B ^= (1<< 2);
                        }
                        for( i <=2000; i=0; i--){
                                OCR1A =i;
                                _delay_us(DELAY2);
                                OUTPUTS_B ^=(1<< 2);

                        }
                        _delay_us(DELAY2);
                }
*/
        if(!(INPUTS_D & (1<<7))){

      servoSweep (2000, DELAY2, 2);
        }
      if (INPUTS_D & (1 << 7))
        {
          OCR1A = 1;

          _delay_us (DELAY);
       OUTPUTS_B &= ~(1 << 2);

        };

    }

  return 0;
}
