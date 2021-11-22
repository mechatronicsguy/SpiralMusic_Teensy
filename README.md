# SpiralMusic_Teensy
A hardware device for visualizing music in a spiral. Uses a teensy with audio sheild, and WS2812 pixels for display. 

For a python only PC version see here: https://github.com/mechatronicsguy/SpiralMusic_python

## Who is this software for?

Anyone (like me) that likes music, but becomes confused by the notation. 

e.g. Take this picture: Are these **three *different* chords**, or is it actually **the *same* chord, but voiced in three different ways**? 

![Musical notation](https://github.com/mechatronicsguy/SpiralMusic_Teensy/blob/main/pics/4tcqogmi_transposed_v01.png?raw=true)

I could stare at this for a couple of minutes and still not be 100% sure. 


But I could tell immediately after seeing this: 

![Same Musical notation in spiral GIF form](https://github.com/mechatronicsguy/SpiralMusic_Teensy/blob/main/pics/4tcqogmi%20animation%20full%20v01.gif?raw=true)

## Features: 
* Simple hardware & low cost
* Synthesis is entirely onboard, does not use PC sound
* Teensy hooks up to PC as a generic MIDI output device, and will play and visualize any data the PC sends to it. 
* Teensy also has an internal USB host port. This is setup to accepts Standard MIDI devices, such as keyboards, any notes played are visualized and heard
* Both MIDI host and MIDI slave work in tandem. You can play a file from the computer and play along on your keyboard. 


## Features of the visualizing method: 
* You can see an entire orchestra "Cooperating" to make a chord, wtihout having to read 6 sets of sheet music. 
* Makes it extremely easy to see transpositions (just rotations)
* Melodic inversion is just a mirror flip
* Notes played stay visible for a time as a 'histogram'. Key signature can be inferred from this
* Different instruments (midi channels) are different colours. Can see contributions of each instrument to the whole

All chords have very simple and recognizable shapes, regardless of key: 

![Chord shapes](https://github.com/mechatronicsguy/SpiralMusic_Teensy/blob/main/pics/Chord%20shapes%20small%20v01.jpg?raw=true)

https://user-images.githubusercontent.com/955307/142712878-9c68f2e3-aa6e-4c0c-95f9-73870babf07c.mp4


(Full video here: https://youtu.be/7xVirr0APKk )

![Setup on desk](https://github.com/mechatronicsguy/SpiralMusic_Teensy/blob/main/pics/Setup%20on%20desk%20v01.jpg?raw=true)

![Hardware overview](https://github.com/mechatronicsguy/SpiralMusic_Teensy/blob/main/pics/Hardware%20closeup%20v01.jpg?raw=true)

Can also work for non-spiral layouts (e.g. Euler's Tonnetz, Accordion, Jancko, etc.) :
![Hex layout video](https://github.com/mechatronicsguy/SpiralMusic_Teensy/blob/main/pics/hex%20layout%20video%20v01.gif?raw=true)


