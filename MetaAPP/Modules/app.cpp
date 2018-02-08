#include "app.h"

App::App(App::AppType App):
   mApp(App)
{

}

QString App::getAppName()
{
   return AppTypeToString(mApp);
}

QString App::AppTypeToString(AppType App)
{
   switch (App)
   {
      case LEDS:           return "Leds"; break;
      case SECURITY:       return "Security"; break;
      case SECURITY_LEDS:  return "SecurityLeds"; break;
      default:             return "Invalid App";break;
   }
}



