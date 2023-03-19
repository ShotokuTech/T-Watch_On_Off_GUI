#include "config.h"

TTGOClass *ttgo;
String message;
String message2;
char buf[128];

void setup()
{
    ttgo = TTGOClass::getWatch();
    ttgo->begin();
    ttgo->openBL();
    ttgo->tft->fillScreen(TFT_BLACK);
    ttgo->tft->setTextFont(2);
    ttgo->tft->setTextColor(TFT_WHITE, TFT_BLACK);
    ttgo->tft->drawLine(0,120,240,120,TFT_WHITE);
    ttgo->tft->drawLine(120,120,120,240,TFT_WHITE);        
    ttgo->tft->drawString("ON", 50, 180);
    ttgo->tft->drawString("OFF", 170, 180);

}

void loop()
{
    int16_t x, y;
    if (ttgo->getTouch(x, y)){
      if(y>120){
        if(x<120){
        message="on";
        ttgo->tft->drawString("Sent: ", 80, 60);
        ttgo->tft->drawString("ON  ", 120, 60);

      }
      if(x>120){
        message="off";
        ttgo->tft->drawString("Sent: ", 80, 60);
        ttgo->tft->drawString("OFF ", 120, 60);        

      }
      }
    }
    delay(5);

}
