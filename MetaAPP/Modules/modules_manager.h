#ifndef MODULES_MANAGER_H
#define MODULES_MANAGER_H

#include <QObject>
#include "module.h"
#include "Models/modulelist.h" //#TODO: Delete this class!

class Modules_Manager: public QObject
{
   Q_OBJECT
   public:
      Modules_Manager(QObject *parent = nullptr);
      ModuleList& GetListOfModules();

   public slots:
      bool ProcessModule(Module& ModuleFound);
      //bool UpdateModule(const QString& ModuleName, );

   private:
      bool AddModule(const Module& ModuleToAdd);
      bool DeleteModule(const Module& ModuleToAdd);

   private:
      //QList<Module> mListModules;
      ModuleList mListModules;

};

#endif // MODULES_MANAGER_H
