#include "modules_manager.h"
#include <QLoggingCategory>
#include <QThread> //#TODO: Delete

Modules_Manager::Modules_Manager(QObject *parent):
   QObject(parent)
{
   //mListModules.appendItem();
}

bool Modules_Manager::ProcessModule(Module &ModuleFound)
{
   qDebug() << __FUNCTION__;
   AddModule(ModuleFound);
}

bool Modules_Manager::AddModule(const Module &ModuleToAdd)
{
   qDebug() << __FUNCTION__ ;
   mListModules.appendItem(ModuleToAdd);
}

ModuleList& Modules_Manager::GetListOfModules()
{
    return mListModules;
}


