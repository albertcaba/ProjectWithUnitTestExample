#pragma once

#include "suite.hpp"
#include <QtTest/QtTest>


class TestNew: public TestSuite
{
    Q_OBJECT

public:
    using TestSuite::TestSuite;

private slots:
    void testCACA();
    void testCACA2();
};

