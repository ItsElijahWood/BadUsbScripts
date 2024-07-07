#include <Keyboard.h>
#include <KeyboardLayout.h>
#include <Keyboard_da_DK.h>
#include <Keyboard_de_DE.h>
#include <Keyboard_es_ES.h>
#include <Keyboard_fr_FR.h>
#include <Keyboard_hu_HU.h>
#include <Keyboard_it_IT.h>
#include <Keyboard_pt_PT.h>
#include <Keyboard_sv_SE.h>
#include <Mouse.h>
#define KEY_SPACE 0x20

void typeKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

/* Init function */

void setup()
{
  // Begining the Keyboard stream
  Keyboard.begin();
  // Wait 3500ms
  delay(1000);
  typeKey(KEY_LEFT_GUI); // Press Windows Key
  delay(500);
  Keyboard.print("Windows Security"); // Type "Windows Security"
  delay(1000); // Wait for Windows Security search results to appear
  typeKey(KEY_RETURN); // Press Enter
  delay(4000); // Wait for Windows Security to open

  // Use tab and arrow keys to navigate to "Virus & threat protection"
  typeKey(KEY_RETURN); 
  typeKey(KEY_TAB); // Tab to the navigation pane
  delay(500);
  typeKey(KEY_TAB); // Tab to "Virus & threat protection"
  delay(500);
  typeKey(KEY_TAB); // Tab to the navigation pane
  delay(500);
  typeKey(KEY_TAB);
  delay(500);
  typeKey(KEY_RETURN);
  delay(500);
  typeKey(KEY_SPACE);
  delay(1000);
  typeKey(KEY_LEFT_ARROW);
  delay(500);
  typeKey(KEY_RETURN);

  Keyboard.end();
}

/* Unused endless loop */
void loop() {}

