#ifndef COMPONENT_H
#define COMPONENT_H

#include <QList>
#include <QString>
#include <QStringList>
#include "pin.h"

class Component
{
public:
    Component(const QString &name=QString());

    QString name() const;
    void setName(const QString &name);

    QList<Pin> pins() const;
    void addPin(const Pin &pin);

    QString prefixe() const;
    void setPrefixe(const QString &prefixe);

    const QStringList &alias() const;
    void addAlias(const QString &alias);

    const QStringList &footPrints() const;
    void addFootPrints(const QString &footprint);

    void reorganizeToPackageStyle();
    void reorganizeUnderRules(const QList<QRegExp> &rules);

    friend QTextStream& operator<<(QTextStream &stream, const Component &component);

private:
    QList<Pin> _pins;
    QString _name;
    QString _prefixe;
    QStringList _alias;
    QStringList _footPrints;
};

#endif // COMPONENT_H
