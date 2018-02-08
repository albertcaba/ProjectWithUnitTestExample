#ifndef MODULELISTMODEL_H
#define MODULELISTMODEL_H

#include <QAbstractListModel>

class ModuleList;

class ModuleListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(ModuleList *list READ list WRITE setList)

public:
    explicit ModuleListModel(QObject *parent = nullptr);

    enum {
        ModuleNameRole = Qt::UserRole,
        ModuleAppRole,
        ModuleLastConnection
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    ModuleList *list() const;
    void setList(ModuleList *list);

private:
    ModuleList *mList;
};

#endif // MODULELISTMODEL_H
