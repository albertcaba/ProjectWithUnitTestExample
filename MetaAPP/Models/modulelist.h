#ifndef MODULELIST_H
#define MODULELIST_H

#include <QObject>
#include <QVector>
#include "Modules/module.h"

class ModuleList : public QObject
{
    Q_OBJECT
public:
    explicit ModuleList(QObject *parent = nullptr);

    QVector<Module> items() const;

    bool setItemAt(int index, const Module &item);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

public slots:
    void appendItem(const Module& ModuleToAdd);
    void removeCompletedItems();

private:
    QVector<Module> mItems;
};

#endif // TODOLIST_H
