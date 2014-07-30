/*
Simple test program for an XMega.
Blink LEDs attached to Port A in sequence.

Hardware required:
LEDs (+ current limiting resistor) attached to each pin on Port E.

Port E is built in LEDs

It uses the default 2Mhz clock.
*/
#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 50

int main( void )
{
  PORTE.DIRSET = 0b11111111 ; // Set all pins on port A to be output.
  
  uint8_t bitpattern = 0b00000001 ;
  while(1){ // loop forever
    PORTE.OUT = bitpattern ;
    _delay_ms( BLINK_DELAY_MS ) ;
    bitpattern <<= 1 ; // shift the pattern left one bit
    
    // now check if the pattern is empty. If so, restart the pattern.
    if (bitpattern == 0) bitpattern = 0b00000001 ;
  }
}


