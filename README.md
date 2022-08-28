# Physical-Teachable-Machine-v2.0
### Physical Computing + Machine Learning resources
---
#### An updated repo of Arduino and P5JS resources for teaching machine learning with physical computing tools.<br>  

These resources build on from the [Creative ML repo](https://github.com/j3nsykes/creativeML2020), streamlining the examples and adding further resources that compliment existing developments in Tensorflow Lite models. These templates serve to provide students with a quick prototyping enviornment such as the P5JS Web Editor to generate graphical, audio , image outputs. 


Each example has an accompanying Arduino .ino sketch to make sure the serial data is parsed to P5JS correctly. The P5JS sketches utilise web serial and are ***only compatible with Chrome***.  
Make sure to turn on the [WebSerial API in Chrome](https://codelabs.developers.google.com/codelabs/web-serial/)<br>


***
## Tiny Motion Trainer to P5JS
Google’s Tiny Motion Trainer is a very powerful interface for training gestural data. However, it only captures the data (much like Teachable Machine) and if you want to do more with it you need to transfer the model data to other tools. There are a few directions you could go next after training the data.

🔥 This template allows you to stream your trained model data back into P5JS so you can generate graphics, audio, images with your data. It is also a helpful visualisation tool.<br>
[Tiny Motion Trainer Visualiser in the p5.js Web Editor](https://editor.p5js.org/jen_GSA/sketches/ZbPK2pFHB)

In order to stream the trained data into P5JS we need to format the serial messages in Arduino. 
This [Arduino .ino template](https://github.com/j3nsykes/Physical-Teachable-Machine-v2.0/tree/main/ArduinoSketches/TinyMotionTrainer_toP5JS) does this for you.

In order to make it work with your trained data follow these steps.
* Follow the setup, labelling and training steps via [Tiny Motion Trainer](https://experiments.withgoogle.com/tiny-motion-trainer/view/settings)
* Once training si complete, select Download Model and check the Arduino example box. 
* In order to work with the Tiny Motion Trainer P5 example you need to make two changes to the Arduino template. This is so the data can be parsed correctly and set to P5JS. 

1. Replace the model.h file with your own 
![Alt Text | height = 100px](https://github.com/j3nsykes/Physical-Teachable-Machine-v2.0/blob/main/modelCopyPaste.gif)
2. Replace `lines 45 - 53` with the custom data from your downloaded .ino sketch 
![Alt Text | height = 100px](https://github.com/j3nsykes/Physical-Teachable-Machine-v2.0/blob/main/settingscopypaste.gif)
``` 
// Values from Tiny Motion Trainer
#define MOTION_THRESHOLD 0.122
#define CAPTURE_DELAY 1022 // This is now in milliseconds
#define NUM_SAMPLES 67

// Array to map gesture index to a name
const char *GESTURES[] = {
  "tap", "circle"
}; 
```
3. Upload the edited .ino template to the BLE NANO 33 Sense.
4. Run the P5JS sketch and press connect to see your labels and classify your gestures. 

***
## Physical Teachable Machine v2.0
This is an updated P5JS sketch that utilises the ML5JS Neural Net function. It allows you to send any number of inputs to P5JS and train them. 
This example no longer requires a template per different sensor; allowing changes to the settings variables to adapt to differring inputs. 

[Physical teachable machine v2.0 in the P5JS web editor](https://editor.p5js.org/jen_GSA/sketches/7B1E88Uc4)
<aside>
💡 **Steps**

1. Select your type of input on line 15. There are some preset settings such as `TRILLCRAFT`, `ANALOG`, `CUSTOM`
2. These settings dictate what the maximum data readings will be. You can also change the minimum reading of `0` if required here on line 20. `let dataRange = [0, TRILLCRAFT];`
3. Select the number of inputs you are sending into the sketch on line 23: `const NUM_INPUTS = 24;`
4. Change the labels to what you want them to be on line 24 `const LABLES = ["Square", "Circle", "Triangle"];`
5. Make sure you have the correct Arduino sketch on your microcontroller for the type of sensor in use. If you are using a Trill Craft select that corresponding Arduino sketch. For all other inputs use the sensor array example sketch.
  [Example templates](https://github.com/j3nsykes/Physical-Teachable-Machine-v2.0/tree/main/ArduinoSketches) 
6. That’s it ! Press run and connect your board. 
</aside>

Once you have trained your model you may want to save it then ***pre-load*** it to work with when developing the outputs. The ***[Physical Teachable Machine v2.0 pre-loaded model](https://editor.p5js.org/jen_GSA/sketches/8Em08TM5F)*** template helps you do this. 

***
## Acknowledgements and references:
The code used in the templates above reference work and methods by others in this area before. 
* [Rebecca Fiebrink and Wekinator](http://www.wekinator.org/examples/)
* [Teachable Machine v1.0 Andreas Refsgaard and Lasse Korsgaard](https://teachablemachine.withgoogle.com/v1/)
* [Teachable Machine v2.0](https://teachablemachine.withgoogle.com/)
* [Dan Shiffman and The Coding Train](https://thecodingtrain.com/learning/ml5/)
* [Golan Levin Media PipeLine examples](https://editor.p5js.org/golan/sketches)
* [Bérenger Recoules](https://github.com/b2renger/workshop_ml_PCD2019)
