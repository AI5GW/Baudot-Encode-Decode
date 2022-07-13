Baudot (ITA2 5-Bit) encoder and decoder library for Arduino
==========================
This library offers an easy way to encode and decode Baudot (ITA2 5-Bit) symbols on your Arduino for RTTY message encoding and decoding.

Library Installation
---------------------
The best way to install the library is via the Arduino Library Manager, which is available if you are using Arduino IDE version 1.6.2 or greater. To install it this way, simply go to the menu Sketch > Include Library > Manage Libraries..., and then in the search box at the upper-right, type "BaudotCode". Click on the entry in the list below, then click on the provided "Install" button. By installing the library this way, you will always have notifications of future library updates, and can easily switch between library versions.

If you need to or would like to install the library the old-fashioned was, you can download a copy of the library in a ZIP file. Download a ZIP file of the library from the GitHub repository by using the "Download ZIP" button at the right of the main repository page. Extract the ZIP file, then rename the unzipped folder as "BaudotCode". Finally, open the Arduino IDE, select menu Sketch > Import Library... > Add Library..., and select the renamed folder that you just downloaded. Restart the IDE and you should have access to the new library.

Hardware Requirements
-------------------------------
This library has been written for the Arduino platform and has been successfully tested on the Arduino Uno, Arduino Nano and Arduino Mega 2560 Rev 3.

Available Functions and Constants
-------

here is a simple example named **BaudotExample.ino** that is placed in your examples menu under the BaudotCode Arduino folder. 

First of all, the **Baudot.h** header file need to be included and the Baudot class needs to be instantiated.

    #include <CBaudot.h>
    BAUDOT Baudot;
    
After instantiating the Baudot class, important Radioteletype (RTTY) control symbols are available through the following constant names:
    
  #define BAUDOT_LETTERS                  B11111  // Letters mode control symbol
  #define BAUDOT_FIGURES                  B11011  // Figures mode control symbol
  #define BAUDOT_CR     	                B01000  // CR
  #define BAUDOT_LF                       B00010  // LF
  #define BAUDOT_SP                       B00100  // SP
    
 After instantiating the Baudot class, there are 3 functions available:
 
 - bool getMode();
 - setMode(bool);
 - bool ModeChanged(void);
 - bool isLetter(char)
 - int Encode(char)
 - char Decode(int, bool mode)
 - char Decode(int)
 
Baudot.bool getMode() returns boolean '1' for letter mode, boolean '0' for figures mode. 
 
    Baudot.bool getMode();
    
Baudot.bool setMode() sets the mode of the CCIR476 class either to letters (parameter: boolean 1) or figures (parameter: boolean 0)

    Baudot.setMode(bool);
    
Baudot.ModeChanged() will check if the mode (letters / figures) has changed from the last time this function was called. This is important to determine whether or not a letters / figures control symbol needs to be transmitted before sending the next symbol. 
    
    Baudot.ModeChanged();
    
 Baudot.isLetter() returns a bolean 'true' if the character supplied through the function's argument is a letter. This function is necessary because CCIR476 allocates the same number twice in the corresponding look-up table; Once for a character and once for a figure. The switching between letters mode and figures mode is done by control symbols. 
    
    Baudot.isLetter('A')
 
 Baudot.Encode() returns the Baudot (ITA2 5-Bit) encoded number corresponding to the character supplied in the function's argument. 
    
    CODE = Baudot.Encode('A')
    
Baudot.Decode(int) returns the decoded character. If the Baudot.Decode() funtion detects control symbols for letters (B11111) or figures (B11011) mode, the current decoding mode for the entore class will be switched accordingly. This change can be detected by using the Baudot.ModeChanged() function. 
    
    // Decode B00011 ('A' in Letter mode, '-' in figures mode).
    Baudot.Decode(B00011);
    
    // Will detect figures mode control symbol and switch the decoding mode accordingly
    Baudot.Decode(B11111);
    
    // Alternative letters mode change using inbuilt constant
    Baudot.Decode(BAUDOT_LETTERS);
    
Baudot.Decode(int, bool mode) returns the decoded character. The first parameter passed to the function is the encoded symbol. The second parameter is true if the encoded symbol is a letter. If it is false, the figures look-up table will be used.
    
    Serial.println(Baudot.Decode(Baudot.Encode('?'), Baudot.isLetter('?')));
    
Links & Contact
---------------------
If you have any questions or comments, feel free to contact me through the email address provided in the project files. Additionally, feel free to check out my blogs and YouTube channel for additional information, examples and feedback:


[Blog (EN): https://baltic-lab.com](https://baltic-lab.com)

[Blog (DE): https://baltic-labor.de/](https://baltic-labor.de/)

[YouTube (EN): https://www.youtube.com/c/BalticLab](https://www.youtube.com/c/BalticLab)

Arduino Lint Status
-------------------
[![arduino-lint Actions Status](https://github.com/AI5GW/Baudot-Encode-Decode/workflows/arduino-lint/badge.svg)](https://github.com/AI5GW/Baudot-Encode-Decode/actions)

Changelog
---------
    
* v1.0.0

    * Initial release
    
License
-------
BaudotCode is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

BaudotCode is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with JTEncode.  If not, see <http://www.gnu.org/licenses/>.
