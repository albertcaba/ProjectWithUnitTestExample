#ifndef APP_H
#define APP_H

#include <QString>

class App
{
   public:
   enum AppType
   {
      LEDS = 0,
      SECURITY,
      SECURITY_LEDS,
      LAST_INVALID_VALUE
   };

   App(AppType App);
   QString getAppName();

   private:
   QString AppTypeToString(AppType App);

   private:
   AppType mApp;
   //AppConfig* mAppConfig;
};

#endif // APP_H
