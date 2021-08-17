
#include <WS2812FX.h>

#define LED_PIN 14                       // 0 = GPIO0
#define LED_COUNT 24

#define DEFAULT_COLOR 0x0000FF
#define DEFAULT_BRIGHTNESS 255
#define DEFAULT_SPEED 750
#define DEFAULT_MODE FX_MODE_COMET

WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int inpin1 = 12;
int inpin2 = 13;
int val1 = 0;
int val2 = 0;
int MODE = 0; // 0 = idle, 1 = clockwise rotation, 2 = counter clockwise rotation
int PREVIOUS_MODE = 0;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
  delay(500);
  Serial.println("\n\nStarting...");

pinMode(inpin1,INPUT);
pinMode(inpin2,INPUT);

ws2812fx.init();


ws2812fx.setSegment(0,0,LED_COUNT-1,43,ORANGE,DEFAULT_SPEED*2,false);
ws2812fx.setSegment(1,0,LED_COUNT-1,43,ORANGE,DEFAULT_SPEED*2,true);

ws2812fx.setIdleSegment(2,0,LED_COUNT/2-1,DEFAULT_MODE,RED,DEFAULT_SPEED,REVERSE);
ws2812fx.setIdleSegment(3,LED_COUNT/2,LED_COUNT-1,DEFAULT_MODE,RED,DEFAULT_SPEED,REVERSE);

ws2812fx.setIdleSegment(4,0,LED_COUNT/2-1,DEFAULT_MODE,BLUE,DEFAULT_SPEED,FADE_SLOW);
ws2812fx.setIdleSegment(5,LED_COUNT/2,LED_COUNT-1,DEFAULT_MODE,BLUE,DEFAULT_SPEED,FADE_SLOW);

ws2812fx.setBrightness(DEFAULT_BRIGHTNESS);


//  ws2812fx.setMode(DEFAULT_MODE);
//  ws2812fx.setColor(DEFAULT_COLOR);
//  ws2812fx.setSpeed(DEFAULT_SPEED);
//  ws2812fx.setBrightness(DEFAULT_BRIGHTNESS);

ws2812fx.start();


}

void loop() {
  // put your main code here, to run repeatedly:

ws2812fx.service();

val1 = digitalRead(inpin1);
val2 = digitalRead(inpin2);

if (val1==0) MODE=0;
if (val1==1 && val2==0) MODE=1;
if (val1==1 && val2==1) MODE=2;


if (MODE==0)
		{
		if (ws2812fx.isActiveSegment(2))
			{
			ws2812fx.swapActiveSegment(2,0);
			ws2812fx.swapActiveSegment(3,1);
			Serial.println("MODE 0 From 2 to 0");
			}
		else
			if (ws2812fx.isActiveSegment(4))
				{
				ws2812fx.swapActiveSegment(4,0);
				ws2812fx.swapActiveSegment(5,1);
				Serial.println("MODE 0 From 4 to 0");
				}
		}

if (MODE==1)
		{
		if (ws2812fx.isActiveSegment(0))
			{
			ws2812fx.swapActiveSegment(0,2);
			ws2812fx.swapActiveSegment(1,3);
			Serial.println("MODE 1 From 0 to 2");
			}
		else
			if (ws2812fx.isActiveSegment(4))
				{
				ws2812fx.swapActiveSegment(4,2);
				ws2812fx.swapActiveSegment(5,3);
				Serial.println("MODE 1 From 4 to 2");
				}
		}

if (MODE==2)
		{
				if (ws2812fx.isActiveSegment(0))
					{
					ws2812fx.swapActiveSegment(0,4);
					ws2812fx.swapActiveSegment(1,5);
					Serial.println("MODE 2 From 0 to 4");
					}
				else
					if (ws2812fx.isActiveSegment(2))
						{
						ws2812fx.swapActiveSegment(2,4);
						ws2812fx.swapActiveSegment(3,5);
						Serial.println("MODE 2 From 2 to 4");
						}
				}


}
