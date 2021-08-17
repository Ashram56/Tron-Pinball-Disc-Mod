# Tron-Pinball-Disc-Mod
Tron pinball Disc mod

This is a repository for my Tron disc mod

Please pay attention to the licence: it is FREE to use, you can also build it and sell

BOM cost is super low: ledring is about 5 dollars, 3D parts are cheap to print. Need to build your own control box, if you use Pinduino see lyonsden shop on Pinside

HOWEVER: Please give credit if you plan to build and sell it, and if you make any modification (SW or HW), remember this is a GPL3 licence and all changes have to be published back, ideally as a fork of this document.

Requires a 24 WS2812 ledring and M3 screws and bolts

Pay attention to the diameter, since otherwise it will not fit. Internal diameter is 35.5, external diameter is 43mm. Anything in between would fit, but if you change number of led you need to adjust the code

Solder wire (5V, ground, data in) Position led ring front side up, with IO pads above the opening. Plan for sufficient lenght to connect to wherever your control box is

I recommend to use Pinduino (I designed my own board, but code should be portable), as on Tron Pinduino should be able to access the motor relays signals. If you use Pinduino, you will need a wire all the way to the backbox. I'm too busy to port the code over to Pinduino, somebody will surely manage to do it (and feed it back here :-) )

Control are essentially the two relays signals
