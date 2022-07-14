
#ifndef __SERVO2_H
#define __SERVO2_H


#define DATA_B          *((volatile byte*)(0x24))
#define DATA_D          *((volatile byte*)(0x2B))
#define INPUTS_D        *((volatile byte*)(0x29))
#define INPUTS_B        *((volatile byte*)(0x23))
#define OUTPUTS_B       *((volatile byte*)(0x25))



static inline void servoSweep (int steps, int delay,
                               int outputPin);

static inline void
servoInit (void)
{
  TCCR1A |= (1 << WGM11) | (1 << COM1A1);
  TCCR1B |= (1 << WGM12) | (1 << WGM13) | (1 << CS10);
  ICR1 = 2000;

  //IO config
  DATA_B |= (1 << 1) | (1 << 2);        // servo sig. & led status sig. (all outputs)
  DATA_D &= ~(1 << 7);          // button sig. (input)
  INPUTS_D |= (1 << 7);         // pinD7 pullup (enabled)

}

static inline void
servoSweep (int steps, int delay, int outputPin)
{
  signed volatile int i;
  for (i = 0; i <= steps; i++)
    {
      OCR1A = i;
      _delay_us (delay);
      OUTPUTS_B ^= (1 << 2);

    }

  for (i <= steps; i = 0; i--)
    {
      OCR1A = i;
      _delay_us (delay);
      OUTPUTS_B ^= (1 << 2);


    }
  _delay_us (delay);
  }

#endif
