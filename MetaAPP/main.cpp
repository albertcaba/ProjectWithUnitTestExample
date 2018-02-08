#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlEngine>
#include <QtQml/QQmlContext>
#include <QtQuick/QQuickItem>
#include <QLoggingCategory>
#include <QStringList>

#include "GUIController/guicontroller.h"
#include "Modules/manager.h"

int main(int argc, char *argv[])
{

   QLoggingCategory::setFilterRules("wapp.*.debug=false");
   QGuiApplication application(argc, argv);

   Manager manager;
   GUIController gUIController(manager.GetConfigMQTT(), manager.GetModuleList());
   if (!gUIController.Init())
   {
      return -1;
   }

   return application.exec();
   qDebug() << "AFTER";
}
