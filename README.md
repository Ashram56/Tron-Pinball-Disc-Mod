# Tron-Pinball-Disc-Mod
Tron pinball Disc mod

This is a repository for my Tron disc mod

Please see a video of the mod in action here: https://www.youtube.com/watch?v=_S456fI_wDA

Please pay attention to the licence: it is FREE to use, you can also build it and sell

HOWEVER: Please give credit if you plan to build and sell it, and if you make any modification (SW or HW), remember this is a GPL3 licence and all changes have to be published back, ideally as a fork of this document.

BOM cost is sub 10 dollars, aside of the control box

Requires a 24 led WS2812 ledring and M3 screws and bolts

Pay attention to the diameter, since otherwise it will not fit. Internal diameter is 71mm, external diameter is 86mm. Anything in between would fit, but if you change number of led you need to adjust the code

Solder wire (5V, ground, data in) Position led ring front side up, with IO pads above the opening. Plan for sufficient lenght to connect to wherever your control box is

Pictures of the assembly are provided on the github.

Please note that the plastic part I'm using on my unit is not the final one, I had to extend the part to add thickness to compensate for the ring added space

I recommend to use Pinduino (I designed my own board, but code should be portable), as on Tron Pinduino should be able to access the motor relays signals. If you use Pinduino, you will need a wire all the way to the backbox. I'm too busy to port the code over to Pinduino, somebody will surely manage to do it (and feed it back here :-) )

Control are essentially the two relays signals

Note that on my unit I replaced the black rubber ring with a transparent rubber ring to get better visibility on the light effects
