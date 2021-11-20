const int note_buffer_size = 256;
int note_status[note_buffer_size];
bool note_seal[note_buffer_size];


#define NUMPIXELS_1 100 // Number of LEDs in strip
#define DATAPIN_1    4
#define CLOCKPIN_1   5

#define NUMPIXELS_2 106 // Number of LEDs in strip
#define DATAPIN_2    16
#define CLOCKPIN_2   17


// This is in order of LED wiring, and the number is the number of semitones:
//int true_ordering_1[] = {72, 60, 48, 36, 24, 12,
//                         11, 23, 35, 47, 59, 71,
//                         70, 58, 46, 34, 22, 10,
//                         9, 21, 33, 45, 57, 69,
//                         68, 56, 44, 32, 20, 8,
//                         7, 19, 31, 43, 55, 67,
//                         66, 54, 42, 30, 18, 6,
//                         5, 17, 29, 41, 53, 65,
//                         64, 52, 40, 28, 16, 4,
//                         3, 15, 27, 39, 51, 63,
//                         62, 50, 38, 26, 14, 2,
//                         1, 13, 25, 37, 49, 61
//                        };

int true_ordering_1[] = {72, 60, 48, 36, 24, 12, 
                          1, 13, 25, 37, 49, 61, 
                          62, 50, 38, 26, 14, 2, 
                          3, 15, 27, 39, 51, 63, 
                          64, 52, 40, 28, 16, 4, 
                          5, 17, 29, 41, 53, 65, 
                          66, 54, 42, 30, 18, 6, 
                          7, 19, 31, 43, 55, 67, 
                          68, 56, 44, 32, 20, 8, 
                          9, 21, 33, 45, 57, 69, 
                          70, 58, 46, 34, 22, 10,
                          11, 23, 35, 47, 59, 71
                          
                        };
const int note_offset_1 = 12 * 2;

//int true_ordering_2[] = { 56, 49, 42, 35, 28, 21, 14, 7, 0, // Tonnetz Layout:
//                          4, 11, 18, 25, 32, 39, 46, 53,
//                          50, 43, 36, 29, 22, 15, 8, 1,
//                          5, 12, 19, 26, 33, 40, 47, 54, 61,
//                          58, 51, 44, 37, 30, 23, 16, 9, 2,
//                          6, 13, 20, 27, 34, 41, 48, 55, 62,
//                          59, 52, 45, 38, 31, 24, 17, 10, 3,
//                          7, 14, 21, 28, 35, 42, 49, 56, 63,
//                          60, 53, 46, 39, 32, 25, 18, 11, 4,
//                          8, 15, 22, 29, 36, 43, 50, 57, 64,
//                          61, 54, 47, 40, 33, 26, 18, 12, 5,
//                          9, 16, 23, 30, 37, 44, 51, 58
//                        };

//
//int true_ordering_2[] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, // Wicki-Hayden layout:
//                          21, 19, 17, 15, 13, 11, 9, 7,
//                          14, 16, 18, 20, 22, 24, 26, 28,
//                          33, 31, 29, 27, 25, 23, 21, 19, 17,
//                          24, 26, 28, 30, 32, 34, 36, 38, 40,
//                          45, 43, 41, 39, 37, 35, 33, 31, 29,
//                          36, 38, 40, 42, 44, 46, 48, 50, 52,
//                          57, 55, 53, 51, 49, 47, 45, 43, 41,
//                          48, 50, 52, 54, 56, 58, 60, 62, 64,
//                          69, 67, 65, 63, 61, 59, 57, 55, 53,
//                          60, 62, 64, 66, 68, 70, 72, 74, 76,
//                          81, 79, 77, 75, 73, 71, 69, 67
//                          };
//const int note_offset_2 = 12 * 3;

int true_ordering_2[] = { 40, 35, 30, 25, 20, 15, 10, 5, 0,
                          3, 8, 13, 18, 23, 28, 33, 38,
                          36, 31, 26, 21, 16, 11, 6, 1,
                          4, 9, 14, 19, 24, 29, 34, 39, 44,
                          42, 37, 32, 27, 22, 17, 12, 7, 2,
                          5, 10, 15, 20, 25, 30, 35, 40 , 45,
                          43, 38, 33, 28, 23, 18, 13, 8, 3,
                          6, 11, 16, 21, 26, 31, 36, 41, 46,
                          44, 39, 34, 29, 24, 19, 14, 9, 4,
                          7, 12, 17, 22, 27, 32, 37, 42, 47,
                          45, 40, 35, 30, 25, 20, 15, 10, 5,
                          8, 13, 18, 23, 28, 33, 38, 43
                        };
const int note_offset_2 = 12 * 4;

#include <FastLED.h>

int PWM_BRIGHT = 255  ; //160; //100
int PWM_DIM = 2; //15; //9
int PWN_SPLASH = 30;

CRGB leds1[NUMPIXELS_1];
CRGB leds2[NUMPIXELS_2];

void led_setup() {
  FastLED.addLeds<APA102, DATAPIN_1, CLOCKPIN_1, BGR>(leds1, NUMPIXELS_1).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness( 255 );
  FastLED.addLeds<APA102, DATAPIN_2, CLOCKPIN_2, BGR>(leds2, NUMPIXELS_2).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness( 255 );

  FastLED.showColor(CRGB(PWN_SPLASH, 0, 0));
  delay(500);
  FastLED.showColor(CRGB(0, PWN_SPLASH, 0));
  delay(500);
  FastLED.showColor(CRGB(0, 0, PWN_SPLASH));
  delay(500);
  FastLED.showColor(CRGB(0, 0, 0));
  FastLED.show();
  delay(1000);
}



CRGB note_off_color = CRGB(0,   0,  0);
CRGB note_used_color =  CRGB(PWM_DIM,   PWM_DIM,  PWM_DIM);

bool update_1_turn = true;
void display_update() {
  if (update_1_turn) {
    display_update_1();
    FastLED[0].showLeds(255);
  } else {
    display_update_2();
    FastLED[1].showLeds(255);
  }
  update_1_turn = ! update_1_turn;

  //  FastLED.show();
}


void display_update_1() {
  for (unsigned int ledNum = 0; ledNum < (sizeof(true_ordering_1) / sizeof(int)); ledNum++) {
    int semitone_num = true_ordering_1[ledNum];
    if ((semitone_num < 0) or (( semitone_num + note_offset_1) >= note_buffer_size) or ((semitone_num + note_offset_1) < 0)) {
      continue;
    }
    int single_note_status = note_status[semitone_num + note_offset_1];
    bool single_note_seal = note_seal[semitone_num + note_offset_1];
    if (single_note_status <= 0) {
      if (single_note_seal) {
        leds1[ledNum] = note_used_color;
      } else {
        leds1[ledNum] = note_off_color;
      }
    } else {
      switch (single_note_status % 6) {
        case 1:
          leds1[ledNum] = CRGB(0, PWM_BRIGHT, PWM_BRIGHT); // Aqua
          break;
        case 2:
          leds1[ledNum] = CRGB(PWM_BRIGHT, PWM_BRIGHT, 0); // Orange
          break;
        case 3:
          leds1[ledNum] = CRGB(0, 0, PWM_BRIGHT); // Blue
          break;
        case 4:
          leds1[ledNum] = CRGB(0, PWM_BRIGHT,  0); // Green
          break;
        case 5:
          leds1[ledNum] = CRGB(PWM_BRIGHT, 0, 0); // Red
          break;
        default:
          leds1[ledNum] = CRGB(PWM_BRIGHT, PWM_BRIGHT, PWM_BRIGHT); // White
          break;
      }
    }
  }
}


void display_update_2() {
  for (unsigned int ledNum = 0; ledNum < (sizeof(true_ordering_2) / sizeof(int)); ledNum++) {
    int semitone_num = true_ordering_2[ledNum];
    if ((semitone_num < 0) or (( semitone_num + note_offset_2) >= note_buffer_size) or ((semitone_num + note_offset_2) < 0)) {
      continue;
    }
    int single_note_status = note_status[semitone_num + note_offset_2];
    bool single_note_seal = note_seal[semitone_num + note_offset_2];
    if (single_note_status <= 0) {
      if (single_note_seal) {
        leds2[ledNum] = note_used_color;
      } else {
        leds2[ledNum] = note_off_color;
      }
    } else {
      switch (single_note_status % 6) {
        case 1:
          leds2[ledNum] = CRGB(0, PWM_BRIGHT, PWM_BRIGHT); // Aqua
          break;
        case 2:
          leds2[ledNum] = CRGB(PWM_BRIGHT, PWM_BRIGHT, 0); // Orange
          break;
        case 3:
          leds2[ledNum] = CRGB(0, 0, PWM_BRIGHT); // Blue
          break;
        case 4:
          leds2[ledNum] = CRGB(0, PWM_BRIGHT,  0); // Green
          break;
        case 5:
          leds2[ledNum] = CRGB(PWM_BRIGHT, 0, 0); // Red
          break;
        default:
          leds2[ledNum] = CRGB(PWM_BRIGHT, PWM_BRIGHT, PWM_BRIGHT); // White
          break;
      }
    }
  }
}
