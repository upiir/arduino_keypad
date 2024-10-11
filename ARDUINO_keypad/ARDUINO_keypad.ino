// simple project using Arduino UNO and 128x64 SSD1306 IIC OLED Display 

// created by upir, 2024
// youtube channel: https://www.youtube.com/upir_upir

// YOUTUBE VIDEO: https://youtu.be/eVH5z8sqCOc

// Links from the video:
// 128x64 SSD1306 OLED Display 1.54": https://s.click.aliexpress.com/e/_DCYdWXb
// 128x64 SSD1306 OLED Display 0.96": https://s.click.aliexpress.com/e/_DCKdvnh
// 128x64 SSD1306 OLED Display 2.42": https://s.click.aliexpress.com/e/_DFdMoTh
// Arduino UNO: https://s.click.aliexpress.com/e/_AXDw1h
// Arduino breadboard prototyping shield: https://s.click.aliexpress.com/e/_ApbCwx
// Image2cpp (convert array to image): https://javl.github.io/image2cpp/
// Photopea (online graphics editor like Photoshop): https://www.photopea.com/

// Related videos with Arduino UNO and 128x64 OLED screen:
// Arduino OLED menu: https://youtu.be/HVHVkKt-ldc
// U8g vs U8g2: https://youtu.be/K5e0lFRvZ2E
// Arduino Parking Sensor - https://youtu.be/sEWw087KOj0
// Turbo pressure gauge with Arduino and OLED display - https://youtu.be/JXmw1xOlBdk
// Arduino Car Cluster with OLED Display - https://youtu.be/El5SJelwV_0
// Knob over OLED Display - https://youtu.be/SmbcNx7tbX8
// Arduino + OLED = 3D ? - https://youtu.be/kBAcaA7NAlA
// Arduino OLED Gauge - https://youtu.be/xI6dXTA02UQ
// Smaller & Faster Arduino - https://youtu.be/4GfPQoIRqW8
// Save Image from OLED Display to PC - https://youtu.be/Ft2pRMVm44E


#include <Arduino.h>
#include <U8g2lib.h> // u8g2 library is used to draw on the OLED screen
#include <Wire.h> // library requires for IIC communication
#include "Adafruit_Keypad.h" // Adafruit keypad library for matrix 4x4 button keypad

U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); // initialization for the used OLED display

// 'image_to_oled', 128x64px
// generated from the image2cpp website
const unsigned char epd_bitmap_image_to_oled [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xc0, 0x01, 0x38, 0x00, 0x02,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x20, 0x02, 0x44, 0x00, 0x05,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x02, 0x40, 0x00, 0x05,
  0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x01, 0x30, 0x80, 0x08,
  0x00, 0x00, 0x40, 0x08, 0x3c, 0x5f, 0x04, 0x00, 0x00, 0x00, 0x04, 0x80, 0x00, 0x40, 0x80, 0x0f,
  0x00, 0xe0, 0x3f, 0x13, 0x44, 0xc4, 0x04, 0x00, 0x00, 0x00, 0x04, 0x40, 0x00, 0x44, 0x80, 0x08,
  0x00, 0x10, 0x80, 0x17, 0x44, 0x44, 0x05, 0x00, 0x00, 0x00, 0x1f, 0xe0, 0x03, 0x38, 0x80, 0x08,
  0x00, 0xd0, 0xbd, 0x17, 0x3c, 0x44, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x50, 0x25, 0x13, 0x04, 0x44, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x50, 0x45, 0x08, 0x04, 0x44, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x20, 0x82, 0x07, 0x04, 0x5f, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0xe0, 0x03, 0x38, 0x80, 0x07,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x20, 0x00, 0x04, 0x80, 0x08,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0xe0, 0x01, 0x3c, 0x80, 0x08,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x00, 0x02, 0x44, 0x80, 0x07,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x02, 0x44, 0x80, 0x08,
  0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x08, 0x20, 0x02, 0x44, 0x80, 0x08,
  0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x1c, 0xc0, 0x01, 0x38, 0x80, 0x07,
  0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0c, 0x60, 0x80, 0x1f, 0xf8, 0x01, 0x18, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0c, 0x70, 0xc0, 0x3f, 0xfc, 0x03, 0x1c, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0c, 0x7c, 0xe0, 0x70, 0x0e, 0x07, 0x1e, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0c, 0x7c, 0x60, 0x60, 0x06, 0x06, 0x1f, 0x30, 0x00, 0x00, 0x1f, 0xc0, 0x01, 0x38, 0x00, 0x07,
  0x0c, 0x60, 0x00, 0x60, 0x00, 0x86, 0x1b, 0x30, 0x00, 0x00, 0x10, 0x20, 0x02, 0x44, 0x80, 0x08,
  0x0c, 0x60, 0x00, 0x70, 0x00, 0xc7, 0x19, 0x30, 0x00, 0x00, 0x10, 0x20, 0x02, 0x44, 0x80, 0x00,
  0x0c, 0x60, 0x00, 0x38, 0xe0, 0xe3, 0x18, 0x30, 0x00, 0x00, 0x08, 0xc0, 0x01, 0x44, 0x80, 0x00,
  0x0c, 0x60, 0x00, 0x1c, 0xe0, 0x63, 0x18, 0x30, 0x00, 0x00, 0x04, 0x20, 0x02, 0x78, 0x80, 0x00,
  0x0c, 0x60, 0x00, 0x0e, 0x00, 0xe7, 0x7f, 0x30, 0x00, 0x00, 0x04, 0x20, 0x02, 0x40, 0x80, 0x08,
  0x0c, 0x60, 0x00, 0x07, 0x00, 0xe6, 0x7f, 0x30, 0x00, 0x00, 0x04, 0xc0, 0x01, 0x38, 0x00, 0x07,
  0x0c, 0x60, 0x80, 0x03, 0x06, 0x06, 0x18, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0c, 0x60, 0xc0, 0x01, 0x0e, 0x07, 0x18, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0c, 0xfe, 0xe7, 0x7f, 0xfc, 0x03, 0x7e, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0c, 0xfe, 0xe7, 0x7f, 0xf8, 0x01, 0x7e, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x04, 0xc0, 0x01, 0x28, 0x80, 0x07,
  0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x1f, 0x20, 0x02, 0x7c, 0x80, 0x08,
  0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x0e, 0x20, 0x03, 0x28, 0x80, 0x08,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xa0, 0x02, 0x7c, 0x80, 0x08,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x60, 0x02, 0x28, 0x80, 0x08,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x02, 0x00, 0x80, 0x08,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x01, 0x00, 0x80, 0x07,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// initialize the keypad
const byte ROWS = 4; // rows
const byte COLS = 4; // columns
//define the symbols on the buttons of the keypads
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad
byte btn_states[ROWS][COLS];

//initialize an instance of class NewKeypad
Adafruit_Keypad customKeypad = Adafruit_Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// 'key_icon', 17x8px, generated from image2cpp website
const unsigned char epd_bitmap_key_icon [] PROGMEM = {
  0x00, 0x78, 0x00, 0x00, 0x84, 0x00, 0xfe, 0x33, 0x01, 0x01, 0x78, 0x01, 0xdd, 0x7b, 0x01, 0x55,
  0x32, 0x01, 0x55, 0x84, 0x00, 0x22, 0x78, 0x00
};


void setup(void) {
  u8g2.begin(); // start the u8g2 library
  Serial.begin(9600); // start the serial communication (for debugging only)
  customKeypad.begin(); // begin code for keypad
}

char pincode_label[5] = "----"; // big label with pin code
char btn_label[2];
byte pincode_label_pos = 0; // which digit of the pin code we want to set (0-4)

void loop(void) {

  customKeypad.tick(); // get the state of buttons inside keypad

  while (customKeypad.available()) {
    keypadEvent e = customKeypad.read();
    Serial.print((char)e.bit.KEY);
    if (e.bit.EVENT == KEY_JUST_PRESSED) {
		  // button is pressed 
			Serial.println(" pressed");
			btn_states[e.bit.ROW][e.bit.COL] = 1;
		}
    else if (e.bit.EVENT == KEY_JUST_RELEASED) { 
			// button was released
      Serial.println(" released");
			btn_states[e.bit.ROW][e.bit.COL] = 0;

      // set one of the digits of the pin code
      pincode_label[pincode_label_pos] = (char)e.bit.KEY; 
      pincode_label_pos++; // increase the currently changing digit

      if (pincode_label_pos > 4) { // position bigger than 4 = reset everything, set code back to "----"
        pincode_label_pos = 0; // reset the position
        pincode_label[0] = '-';
        pincode_label[1] = '-';
        pincode_label[2] = '-';
        pincode_label[3] = '-';
        pincode_label[4] = 0; // 0 = null character to set the end of the string
      }

    }
  }


  u8g2.firstPage(); // page loop for u8g2 library
  do {

    u8g2.setDrawColor(1); // set draw color to white

    // draw the keypad visulazation on the right side of the display
    for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {

				int xpos = 80 + (i * 13); // calculate the x position, spacing between characters is 13px
				int ypos = 16 + (j * 13); // calculate the y position, spacing between characters is 13px

        if (btn_states[j][i] == 1) { // if the button is pressed, draw background rounded filled box
				  u8g2.setDrawColor(1);
					u8g2.drawRBox(xpos - 3, ypos - 9, 11, 11, 2);
				}
    
				u8g2.setFont(u8g2_font_profont11_tr); // set the smaller font
				btn_label[0] = keys[j][i]; // set the button label based on the character from the "keys" array
				u8g2.setFontMode(1);  /* activate transparent font mode */
				u8g2.setDrawColor(2);
				u8g2.drawStr(xpos, ypos, btn_label); // draw the label
			}
		}

    u8g2.setDrawColor(1);


    // print label "PIN"
    u8g2.setFont(u8g2_font_profont11_tr);
    u8g2.drawStr(34, 20, "PIN");

    // draw the key icon next to the pin label
    u8g2.drawXBMP(12, 12, 17, 8, epd_bitmap_key_icon);

    // pring the big pin code label
    u8g2.setFont(u8g2_font_profont22_tr);
    u8g2.drawStr(9, 46, pincode_label);

    // draw the 2px rounded frame around the big pin code label
    u8g2.drawRFrame(2, 27, 60, 24, 2);
    u8g2.drawFrame(3, 28, 58, 22);

  } while ( u8g2.nextPage() ); // u8g2 page drawing loop

}




