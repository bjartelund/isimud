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
However, this failed to solve the issue with actually alterting me to changes.

I also failed to flash the Thingy:53 with new programs, so I abandoned this path.

Luckily, I brought a TTGO T-DISPLAY RP2030 to d:hack and was able to connect the reed-switch to the microcontroller and measure proximity to a magnet as shown in the video.
<video src="https://github.com/bjartelund/isimud/blob/main/20221208_121421~3.mp4"></video>
