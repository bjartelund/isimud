# isimud
d:hack 2022

![Isimud](isimud.png)

# Project goal
 To make a smarter mail-box, that alerts me that the mail box has been opened (with bills and advertisements inserted)

# Starting material
![Nordic Thingy:53](20221208_080010(1).jpg)
* Nordic Thingy:53 
* Nordic nRF52840
* Some random reed-switches 

# Project log
Install the nRF Connect for Desktop, and nRF command line tools to enable VS Code extension.
In parallell, try out nRF Edge Impulse to evaluate some of the inbuilt functionality of Thingy 53

Made attempts to solve the problem using the ML models generated using Edge Impulse based on the light sensor.
Collected seconds of darkness / light with the built-in light sensor of the Thingy:53, and developed a model that would differentiate between open/closed states of mail-box this way. 
![Screenshot from 2022-12-08 22-01-58](https://user-images.githubusercontent.com/13436038/206566889-c50d8459-aa67-4f9b-b631-5027d9581c9c.png)


However, this failed to solve the issue with actually alterting me to changes.

I also failed to flash the Thingy:53 with new programs, so I abandoned this path.

Luckily, I brought a TTGO T-DISPLAY RP2030 to d:hack and was able to connect the reed-switch to the microcontroller and measure proximity to a magnet as shown in the video.


https://user-images.githubusercontent.com/13436038/206435037-ef604b35-edbe-46b2-b988-164900781b5f.mp4

After making the video, I realized that the RP2030 does not come with its own WIFI/BLE circuits. Ups.
Luckily, Morten had some ESP-8266 laying around and I was eventually able to make it connect to my phones WIFI and trigger a web-hook using IFTTT. 
That marks the end of day 1. Day 2 I hope to either find a suitable ESP-32 or convince the ESP-8266, to combine the achievements of the RP2030 and the 8266 today. That is, measure a change in magnet proximity (as a proxy for a opened mailbox) and report it via wireless to me. 
