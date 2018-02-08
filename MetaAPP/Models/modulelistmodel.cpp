#include "modulelistmodel.h"
#include "modulelist.h"
#include <QLoggingCategory>

ModuleListModel::ModuleListModel(QObject *parent)
    : QAbstractListModel(parent)
    , mList(nullptr)
{
}

int ModuleListModel::rowCount(const QModelIndex &parent) const
{
   qDebug() << __FUNCTION__;
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid() || !mList)
        return 0;

    qDebug() << " Rows:" << mList->items().size();
    return mList->items().size();
}

QVariant ModuleListModel::data(const QModelIndex &index, int role) const
{
   qDebug() << __FUNCTION__;
    if (!index.isValid() || !mList)
        return QVariant();

    const Module item = mList->items().at(index.row());

    switch (role) {
    case ModuleNameRole:
        return QVariant(item.mName);
    case ModuleAppRole:
        return QVariant(item.mAppName);
    case ModuleLastConnection:
       return QVariant(item.mLastConnection);
    }
    /*
    switch (role) {
    case DoneRole:
        return QVariant(item.done);
    case DescriptionRole:
        return QVariant(item.description);
    }
*/
    return QVariant();
}

bool ModuleListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
   qDebug() << __FUNCTION__;
    if (!mList)
        return false;

    Module item = mList->items().at(index.row());

    switch (role)
    {
    case ModuleAppRole:
        item.mAppName = value.toString();
        break;
    case ModuleNameRole:
        item.mName = value.toString();
        break;
    case ModuleLastConnection:
        item.mLastConnection = value.toString();
       break;
    }

    if (mList->setItemAt(index.row(), item))
    {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags ModuleListModel::flags(const QModelIndex &index) const
{
   qDebug() << __FUNCTION__;
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> ModuleListModel::roleNames() const
{
   qDebug() << __FUNCTION__;
    QHash<int, QByteArray> names;
    names[ModuleNameRole] = "moduleName";
    names[ModuleAppRole] = "moduleApp";
    names[ModuleLastConnection] = "moduleLastConnection";
    //names[DoneRole] = "done";
    //names[DescriptionRole] = "description";
    return names;
}

ModuleList *ModuleListModel::list() const
{
   qDebug() << __FUNCTION__;
    return mList;
}

void ModuleListModel::setList(ModuleList *list)
{
   qDebug() << __FUNCTION__;
    beginResetModel();

    if (mList)
        mList->disconnect(this);

    mList = list;

    if (mList) {
        connect(mList, &ModuleList::preItemAppended, this, [=]() {
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(mList, &ModuleList::postItemAppended, this, [=]() {
            endInsertRows();
        });

        connect(mList, &ModuleList::preItemRemoved, this, [=](int index) {
            beginRemoveRows(QModelIndex(), index, index);
        });
        connect(mList, &ModuleList::postItemRemoved, this, [=]() {
            endRemoveRows();
        });
    }

    endResetModel();
}
