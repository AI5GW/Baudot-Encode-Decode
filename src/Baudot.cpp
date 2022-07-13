/*
 * Baudot.cpp - Baudot code (ITA-2 5 bit) encoder / decoder library for Arduino
 *
 * Copyright (C) 2022 Sebastian Westerhold (AI5GW) <sebastian@baltic-lab.com>
 * 
 * Web (EN): https://baltic-lab.com
 * Web (DE): https://baltic-labor.de/
 * YouTube (EN): https://www.youtube.com/c/BalticLab
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <Baudot.h>

#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__) || defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega16U4__)
#include <avr/pgmspace.h>
#endif

#include "Arduino.h"


/* Public Class Members */

BAUDOT::BAUDOT(void)
{
	bool BAUDOT_MODE = 1; 
	bool OLD_MODE = 0;
}

uint8_t BAUDOT::Encode(char c)
{

      switch (c)
      {       
        // Letters cases
        case 'A': { BAUDOT_MODE=1; return B00011; }  
        case 'B': { BAUDOT_MODE=1; return B11001; }
        case 'C': { BAUDOT_MODE=1; return B01110; }
        case 'D': { BAUDOT_MODE=1; return B01001; }
        case 'E': { BAUDOT_MODE=1; return B00001; }
        case 'F': { BAUDOT_MODE=1; return B01101; }
        case 'G': { BAUDOT_MODE=1; return B11010; }
        case 'H': { BAUDOT_MODE=1; return B10100; }
        case 'I': { BAUDOT_MODE=1; return B00110; }
        case 'J': { BAUDOT_MODE=1; return B01011; }
        case 'K': { BAUDOT_MODE=1; return B01111; }
        case 'L': { BAUDOT_MODE=1; return B10010; }
        case 'M': { BAUDOT_MODE=1; return B11100; }
        case 'N': { BAUDOT_MODE=1; return B01100; }
        case 'O': { BAUDOT_MODE=1; return B11000; }
        case 'P': { BAUDOT_MODE=1; return B10110; }
        case 'Q': { BAUDOT_MODE=1; return B10111; }
        case 'R': { BAUDOT_MODE=1; return B01010; }
        case 'S': { BAUDOT_MODE=1; return B00101; }
        case 'T': { BAUDOT_MODE=1; return B10000; }
        case 'U': { BAUDOT_MODE=1; return B00111; }
        case 'V': { BAUDOT_MODE=1; return B11110; }
        case 'W': { BAUDOT_MODE=1; return B10011; }
        case 'X': { BAUDOT_MODE=1; return B11101; }
        case 'Y': { BAUDOT_MODE=1; return B10101; }
        case 'Z': { BAUDOT_MODE=1; return B10001; }  


	// CF, LF and SP leave mode unchanged
        case 13: { return B01000; }   // CR
        case 10: { return B00010; }   // LF
        case 32: { return B00100; }   // SP

        // Figures cases
        case '0': { BAUDOT_MODE=0; return B10110; }
        case '1': { BAUDOT_MODE=0; return B10111; }
        case '2': { BAUDOT_MODE=0; return B10011; }
        case '3': { BAUDOT_MODE=0; return B00001; }
        case '4': { BAUDOT_MODE=0; return B01010; }
        case '5': { BAUDOT_MODE=0; return B10000; }
        case '6': { BAUDOT_MODE=0; return B10101; }
        case '7': { BAUDOT_MODE=0; return B00111; }
        case '8': { BAUDOT_MODE=0; return B00110; }
        case '9': { BAUDOT_MODE=0; return B11000; }                 
        case '\'': { BAUDOT_MODE=0; return B00101; }      
        case ':': { BAUDOT_MODE=0; return B01110; }
        case '(': { BAUDOT_MODE=0; return B01111; }
        case '.': { BAUDOT_MODE=0; return B11100; }
        case '/': { BAUDOT_MODE=0; return B11101; }
        case '=': { BAUDOT_MODE=0; return B11110; }
        case '-': { BAUDOT_MODE=0; return B00011; }
        case ',': { BAUDOT_MODE=0; return B01100; }
        case '+': { BAUDOT_MODE=0; return B10001; }
        case ')': { BAUDOT_MODE=0; return B10010; }
        case '?': { BAUDOT_MODE=0; return B11001; }

        default: { return B00000; }
      }    
	
}

char BAUDOT::Decode(uint8_t CODE, bool Mode)
{

	if (CODE == BAUDOT_LETTERS){BAUDOT_MODE = 1; return (char)0;} // Letters mode control symbol
	if (CODE == BAUDOT_FIGURES){BAUDOT_MODE = 0; return (char)0;} // Figures mode control symbol
      	if (CODE == BAUDOT_CR) { return (char)13; }   // CR
      	if (CODE == BAUDOT_LF) { return (char)10; }   // LF
      	if (CODE == BAUDOT_SP) { return (char)32; }   // SP


if (Mode)
      {
        switch (CODE)
        {                      
          	case B00011: {return 'A';}
          	case B11001: {return 'B';}
          	case B01110: {return 'C';}
          	case B01001: {return 'D';}
          	case B00001: {return 'E';}
          	case B01101: {return 'F';}
          	case B11010: {return 'G';}
          	case B10100: {return 'H';}
          	case B00110: {return 'I';}
          	case B01011: {return 'J';}
          	case B01111: {return 'K';}
          	case B10010: {return 'L';}
          	case B11100: {return 'M';}
          	case B01100: {return 'N';}
          	case B11000: {return 'O';}
          	case B10110: {return 'P';}
          	case B10111: {return 'Q';}
          	case B01010: {return 'R';}
          	case B00101: {return 'S';}
          	case B10000: {return 'T';}
          	case B00111: {return 'U';}
          	case B11110: {return 'V';}
          	case B10011: {return 'W';}
          	case B11101: {return 'X';}
          	case B10101: {return 'Y';}
          	case B10001: {return 'Z';}  
          	default: { return (char)0; }
        }        
      }
      else
      {
        switch (CODE)
        {             
		case B10110: 	{ return '0'; }
        	case B10111: 	{ return '1'; }
        	case B10011: 	{ return '2';}
       		case B00001: 	{ return '3'; }
        	case B01010: 	{ return '4'; }
        	case B10000: 	{ return '5'; }
        	case B10101: 	{ return '6'; }
        	case B00111: 	{ return '7'; }
        	case B00110: 	{ return '8'; }
        	case B11000: 	{ return '9'; }  
        	case B00101: 	{ return '\''; }
        	case B11100: 	{ return '.'; }
        	case B01110: 	{ return ':'; }
        	case B01111: 	{ return '('; }
        	case B11101: 	{ return '/'; }
        	case B11110: 	{ return '='; }
        	case B00011: 	{ return '-'; }
        	case B01100: 	{ return ','; }
        	case B10001: 	{ return '+'; }
        	case B10010: 	{ return ')'; }
        	case B11001: 	{ return '?'; }
          	default: { return (char)0; }
        }        
      }     
     
}

char BAUDOT::Decode(uint8_t CODE)
{
	return Decode(CODE, BAUDOT_MODE);
}

bool BAUDOT::isLetter(char c)
{
      if (((c == 10) || (c == 13) || (c == 32)) == false)
      {
        // test for letter:
        if ((c >= 65)&&(c <= 90))
        {
          return 1;
        }
        else
        {
	  return 0;
        }
      }
      else
	{
	return 0;
	}
}

bool BAUDOT::getMode(void)
{
	return BAUDOT_MODE;
}

bool BAUDOT::setMode(bool NewMode)
{

	BAUDOT_MODE = NewMode;
	return 1;
}


bool BAUDOT::ModeChanged(void)
{
	if (BAUDOT_MODE != OLD_MODE)
	{

		OLD_MODE = BAUDOT_MODE;
		return 1;
	}
	else
	{
		return 0;
	}
}
