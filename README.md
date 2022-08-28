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

🔥 This template allows you to stream your trained model data back into P5JS so you can generate graphics, audio, images with your data. It is also a helpful visualisation tool.
[Tiny Motion Trainer Visualiser in the p5.js Web Editor](https://editor.p5js.org/jen_GSA/sketches/ZbPK2pFHB)

In order to stream the trained data into P5JS we need to format the serial messages in Arduino. This template does this for you. [Arduino Create link]

In order to make it work with your trained data follow these steps.
* Follow the setup, labelling and training steps via [Tiny Motion Trainer](https://experiments.withgoogle.com/tiny-motion-trainer/view/settings)
* Once training si complete, select Download Model and check the Arduino example box. 
* In order to work with the Tiny Motion Trainer P5 example you need to make two changes to the Arduino template. This is so the data can be parsed correctly and set to P5JS. 

1. Replace the model.h file with your own [insert GIF]
2. Replace `lines 45 - 53` with the custom data from your downloaded .ino sketch [insert GIF]
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
