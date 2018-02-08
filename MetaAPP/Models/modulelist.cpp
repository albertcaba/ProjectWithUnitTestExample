#include "modulelist.h"

ModuleList::ModuleList(QObject *parent) : QObject(parent)
{
    //mItems.append(Module());
    //mItems.append({ false, QStringLiteral("Fix the sink") });
}

QVector<Module> ModuleList::items() const
{
    return mItems;
}

bool ModuleList::setItemAt(int index, const Module &item)
{
    if (index < 0 || index >= mItems.size())
        return false;

    const Module &oldItem = mItems.at(index);
    /*
    if ( oldItem == item)
        return false;
        */

    mItems[index] = item;
    return true;
}

/*
void ModuleList::appendItem()
{
    emit preItemAppended();

    Module item;
    mItems.append(item);

    emit postItemAppended();
}
*/
void ModuleList::appendItem(const Module& ModuleToAdd)
{
   emit preItemAppended();

   mItems.append(ModuleToAdd);

   emit postItemAppended();
}


void ModuleList::removeCompletedItems()
{
/*
    for (int i = 0; i < mItems.size(); ) {
        if (mItems.at(i).done) {
            emit preItemRemoved(i);

            mItems.removeAt(i);

            emit postItemRemoved();
        } else {
            ++i;
        }

   }
   */
}
