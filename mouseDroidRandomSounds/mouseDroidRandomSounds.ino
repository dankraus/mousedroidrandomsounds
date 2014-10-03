/*
by Dan Kraus - 2014 at R2STL Build Day 2014-31-05

Random sounds for Sparkfun MP3 WaveShield for Mouse Droid to chrirp chirp away

Sketch assumes you have files as track001.mp3 format on the SD card
*/

//volume control - 0 is loudest, set negative number to step it down
int volume = 0;

#include <SPI.h>

//Add the SdFat Libraries
#include <SdFat.h>
#include <SdFatUtil.h>

//and the MP3 Shield Library
#include <SFEMP3Shield.h>

/**
 * \brief Object instancing the SdFat library.
 *
 * principal object for handling all SdCard functions.
 */
SdFat sd;
/**
 * \brief Object instancing the SFEMP3Shield library.
 *
 * principal object for handling all the attributes, members and functions for the library.
 */
SFEMP3Shield MP3player;

void setup(){
  uint8_t result; //result code from some function as to be tested at later time.

  Serial.begin(115200);
  
  //Initialize the SdCard.
  if(!sd.begin(SD_SEL, SPI_FULL_SPEED)) sd.initErrorHalt();
  // depending upon your SdCard environment, SPI_HAVE_SPEED may work better.
  if(!sd.chdir("/")) sd.errorHalt("sd.chdir");
  
  //Initialize the MP3 Player Shield
  result = MP3player.begin();
  
  //0,0 is Max Volume. L,R Channel
  MP3player.setVolume(volume, volume);
  
  //check result, see readme for error codes.
  if(result != 0) {
    Serial.print(F("Error code: "));
    Serial.print(result);
    Serial.println(F(" when trying to start MP3 player"));
    if( result == 6 ) {
      Serial.println(F("Warning: patch file not found, skipping.")); // can be removed for space, if needed.
      Serial.println(F("Use the \"d\" command to verify SdCard can be read")); // can be removed for space, if needed.
    }
  }
  randomSeed(analogRead(0));
}

void loop(){
  uint8_t result;
  uint32_t offset = 0;
  
  //random number between 1 and 18. There are 18 sound files on the sheild.
  //So let's just pick a random one.
  int randNumber = random(1,19);
  int randDelay = random(10,60);
  //int randDelay = random(1000,5000);
  byte trackNumber = (byte)randNumber;
  
  //tell the MP3 Shield to play that file
  result = MP3player.playTrack(trackNumber);
  //check result, see readme for error codes.
  if(result != 0) {
    Serial.print(F("Error code: "));
    Serial.print(result);
    Serial.println(F(" when trying to play track"));
  }
 
  Serial.println(randDelay);
  delay(randDelay*1000);
}
