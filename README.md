# Mouse Droid - Random Sounds w/ Arduino

## About
Random sounds played by an Arduino and Sparkfun MP3 WaveShield for Mouse Droid to chrirp chirp away. Built at Saint Louis R2 Builders Build Day 2014-31-05. Built for the Mouse Droid Builders Club. You know, the little robot car Chewbaca growls at on the Death Star in Star Wars. The club builds replicas of these and drives them around with Remote Control.

![image](http://img3.wikia.nocookie.net/__cb20080318141837/starwars/images/b/b7/MSE-6_btm.jpg)

## Hardware
- Arduino Uno
- [Sparkfun MP3 WaveShield](https://www.sparkfun.com/products/10628) **NOTE:** This is explicitly for the WaveShield, NOT the MP3 Trigger. The Waveshield is a little cheaper, and a bit less robust, and a bit more cumbersome to program with. This code will NOT work with the MP3 Trigger.

## Usage
Sketch assumes you have files as sequentially numbered track001.mp3 format on the SD card. This repo does not provide the MP3s. You can find them online or get them from the Mouse Droid Builder's Club.

Set the volume in the sketch

    //volume control - 0 is loudest, set negative number to step it down

    int volume = 0;`
    
Then, you'll want to enter how many files are on the SD Card by editing this bit.

     //random number between 1 and 18. There are 18 sound files on the sheild.
     
     //So let's just pick a random one.
     int randNumber = random(1,19);

If you don't like the delay, you can adjust this. Default is playback of a random sound between 10 and 60 seconds

    int randDelay = random(10,60);

Upload the code to the Arduino. 

Plug in the Waveshield. 

Connect an 1/8" audio cable from the shield to your speakers.

Power everything up and you should be good. Arduino takes 5v-12v. Depending on your speaker, you may need an amp, or maybe you have one of those mini portable things that have a built in amp and take aux input. That's for you to figure out ;)

## Contributing

This is about as simple as it gets but if you want something added, send a pull request.