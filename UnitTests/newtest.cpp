#include "newtest.h"

void TestNew::testCACA()
{
    std::string str("Hello");
    auto qstr = QString::fromUtf8(str.data());
    QCOMPARE(qstr, QString("Hello"));
}

void TestNew::testCACA2()
{
    QString qstr("Hello");
    std::string str(qstr.toUtf8().data());
    QCOMPARE(str, std::string("Hello"));
}

static TestNew TEST_NEW;
