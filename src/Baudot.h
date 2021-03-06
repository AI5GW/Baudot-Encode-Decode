/*
 * Baudot.h - Baudot code (ITA-2 5 bit) encoder / decoder library for Arduino
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


#include "Arduino.h"

#include <stdint.h>

#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__) || defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega16U4__)
#include <avr/pgmspace.h>
#endif

#define BAUDOT_LETTERS                  B11111
#define BAUDOT_FIGURES                  B11011
#define BAUDOT_CR     	                B01000
#define BAUDOT_LF                       B00010
#define BAUDOT_SP                       B00100


class BAUDOT
{
public:
  BAUDOT(void);
  uint8_t Encode(char);
  char Decode(uint8_t, bool);
  char Decode(uint8_t);
  bool getMode(void);
  bool setMode(bool);
  bool isLetter(char);
  bool ModeChanged(void);

private:
bool BAUDOT_MODE;
bool OLD_MODE;
};
