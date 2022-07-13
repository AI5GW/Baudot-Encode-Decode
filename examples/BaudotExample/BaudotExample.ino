/*
 * Baudot (ITA2) encoder and decoder library for Arduino Example
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
 
// Include Library
#include "Baudot.h"

BAUDOT Baudot;

int CODE;

void setup() {
  Serial.begin(9600);

}

void loop() {

  // Encode the letter 'A' and print result
  CODE = Baudot.Encode('A');
  Serial.println(CODE);

  // Check if 'A' is a letter and print result (true)
  Serial.println(Baudot.isLetter('A'));

  // Encode the letter '!' and print result
  CODE = Baudot.Encode('?');
  Serial.println(CODE);

  // Check if '?' is a letter and print result (false)
  Serial.println(Baudot.isLetter('?'));

  delay(1000);

  // Encode the letter 'Z', decode it again and print the result
  Serial.println(Baudot.Decode(Baudot.Encode('Z'), Baudot.isLetter('Z')));
  delay(1000);

  // Encode the character '?', decode it again and print the result
  Serial.println(Baudot.Decode(Baudot.Encode('?'), Baudot.isLetter('?')));
  delay(1000);

   // *** Detect mode automatically from control symbols ***
  Serial.println("Detect Mode automatically...");

  // Decode letters mode control symbol (B11111)
  Serial.println("Set letters mode through B11111 control symbol. ");
  Baudot.Decode(BAUDOT_LETTERS);

  // Check if the letter / figures mode has changed. Will return '1' if changed (or on first call), '0' if not changed.
  Serial.print("Baudot Mode: ");
  Serial.println(Baudot.ModeChanged());

  // Decode B00011 ('A' in Letter mode, '-' in figures mode). Should return 'A'
  Serial.println(Baudot.Decode(B00011));

  // Decode figures mode control symbol (B11011)
  Serial.println("Set figures mode through B11011 control symbol. ");
  Baudot.Decode(BAUDOT_FIGURES);

  // Check if the letter / figures mode has changed. Will return '1' if changed (or on first call), '0' if not changed.
  Serial.print("Baudot Mode: ");
  Serial.println(Baudot.ModeChanged());

  // Decode B00011 ('A' in Letter mode, '-' in figures mode). Will now return '-'
  Serial.println(Baudot.Decode(B00011));

  delay(1000);

}
