/****************************************************************************
**
** Copyright (C) 2012 Digia Plc
** All rights reserved.
** For any questions to Digia, please use contact form at http://qt.digia.com
**
** This file is part of the Qt Commercial Charts Add-on.
**
** $QT_BEGIN_LICENSE$
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.
**
** If you have questions regarding the use of this file, please use
** contact form at http://qt.digia.com
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtTest/QtTest>
#include <qhorizontalstackedbarseries.h>
#include <qbarset.h>
#include <qchartview.h>
#include <qchart.h>
#include "tst_definitions.h"

QTCOMMERCIALCHART_USE_NAMESPACE

Q_DECLARE_METATYPE(QBarSet*)

class tst_QHorizontalStackedBarSeries : public QObject
{
    Q_OBJECT

public slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

private slots:
    void qhorizontalstackedbarseries_data();
    void qhorizontalstackedbarseries();
    void type_data();
    void type();
    void mouseclicked_data();
    void mouseclicked();
    void mousehovered_data();
    void mousehovered();

private:
    QHorizontalStackedBarSeries* m_barseries;
};

void tst_QHorizontalStackedBarSeries::initTestCase()
{
    qRegisterMetaType<QBarSet*>("QBarSet*");
}

void tst_QHorizontalStackedBarSeries::cleanupTestCase()
{
}

void tst_QHorizontalStackedBarSeries::init()
{
    m_barseries = new QHorizontalStackedBarSeries();
}

void tst_QHorizontalStackedBarSeries::cleanup()
{
    delete m_barseries;
    m_barseries = 0;
}

void tst_QHorizontalStackedBarSeries::qhorizontalstackedbarseries_data()
{
}

void tst_QHorizontalStackedBarSeries::qhorizontalstackedbarseries()
{
    QHorizontalStackedBarSeries *barseries = new QHorizontalStackedBarSeries();
    QVERIFY(barseries != 0);
}

void tst_QHorizontalStackedBarSeries::type_data()
{

}

void tst_QHorizontalStackedBarSeries::type()
{
    QVERIFY(m_barseries->type() == QAbstractSeries::SeriesTypeHorizontalStackedBar);
}

void tst_QHorizontalStackedBarSeries::mouseclicked_data()
{

}

void tst_QHorizontalStackedBarSeries::mouseclicked()
{
    SKIP_IF_CANNOT_TEST_MOUSE_EVENTS();

    QHorizontalStackedBarSeries* series = new QHorizontalStackedBarSeries();

    QBarSet* set1 = new QBarSet(QString("set 1"));
    *set1 << 10 << 10 << 10;
    series->append(set1);

    QBarSet* set2 = new QBarSet(QString("set 2"));
    *set2 << 10 << 10 << 10;
    series->append(set2);

    QSignalSpy seriesSpy(series,SIGNAL(clicked(int, QBarSet*)));

    QChartView view(new QChart());
    view.resize(400,300);
    view.chart()->addSeries(series);
    view.show();
    QTest::qWaitForWindowShown(&view);

//====================================================================================
// barset 1, category test1
    QTest::mouseClick(view.viewport(), Qt::LeftButton, 0, QPoint(115,231));
    QCoreApplication::processEvents(QEventLoop::AllEvents, 1000);

    QCOMPARE(seriesSpy.count(), 1);

    QList<QVariant> seriesSpyArg = seriesSpy.takeFirst();
    QCOMPARE(qvariant_cast<QBarSet*>(seriesSpyArg.at(1)), set1);
    QVERIFY(seriesSpyArg.at(0).type() == QVariant::Int);
    QVERIFY(seriesSpyArg.at(0).toInt() == 0);

//====================================================================================
// barset 1, category test2
    QTest::mouseClick(view.viewport(), Qt::LeftButton, 0, QPoint(115,150));
    QCoreApplication::processEvents(QEventLoop::AllEvents, 1000);

    QCOMPARE(seriesSpy.count(), 1);

    seriesSpyArg = seriesSpy.takeFirst();
    QCOMPARE(qvariant_cast<QBarSet*>(seriesSpyArg.at(1)), set1);
    QVERIFY(seriesSpyArg.at(0).type() == QVariant::Int);
    QVERIFY(seriesSpyArg.at(0).toInt() == 1);

//====================================================================================
// barset 1, category test3
    QTest::mouseClick(view.viewport(), Qt::LeftButton, 0, QPoint(115,69));
    QCoreApplication::processEvents(QEventLoop::AllEvents, 1000);

    QCOMPARE(seriesSpy.count(), 1);

    seriesSpyArg = seriesSpy.takeFirst();
    QCOMPARE(qvariant_cast<QBarSet*>(seriesSpyArg.at(1)), set1);
    QVERIFY(seriesSpyArg.at(0).type() == QVariant::Int);
    QVERIFY(seriesSpyArg.at(0).toInt() == 2);

//====================================================================================
// barset 2, category test1
    QTest::mouseClick(view.viewport(), Qt::LeftButton, 0, QPoint(285,230));
    QCoreApplication::processEvents(QEventLoop::AllEvents, 1000);

    QCOMPARE(seriesSpy.count(), 1);

    seriesSpyArg = seriesSpy.takeFirst();
    QCOMPARE(qvariant_cast<QBarSet*>(seriesSpyArg.at(1)), set2);
    QVERIFY(seriesSpyArg.at(0).type() == QVariant::Int);
    QVERIFY(seriesSpyArg.at(0).toInt() == 0);

//====================================================================================
// barset 2, category test2
    QTest::mouseClick(view.viewport(), Qt::LeftButton, 0, QPoint(285,150));
    QCoreApplication::processEvents(QEventLoop::AllEvents, 1000);

    QCOMPARE(seriesSpy.count(), 1);

    seriesSpyArg = seriesSpy.takeFirst();
    QCOMPARE(qvariant_cast<QBarSet*>(seriesSpyArg.at(1)), set2);
    QVERIFY(seriesSpyArg.at(0).type() == QVariant::Int);
    QVERIFY(seriesSpyArg.at(0).toInt() == 1);

//====================================================================================
// barset 2, category test3
    QTest::mouseClick(view.viewport(), Qt::LeftButton, 0, QPoint(285,69));
    QCoreApplication::processEvents(QEventLoop::AllEvents, 1000);

    QCOMPARE(seriesSpy.count(), 1);

    seriesSpyArg = seriesSpy.takeFirst();
    QCOMPARE(qvariant_cast<QBarSet*>(seriesSpyArg.at(1)), set2);
    QVERIFY(seriesSpyArg.at(0).type() == QVariant::Int);
    QVERIFY(seriesSpyArg.at(0).toInt() == 2);
}

void tst_QHorizontalStackedBarSeries::mousehovered_data()
{

}

void tst_QHorizontalStackedBarSeries::mousehovered()
{
    SKIP_IF_CANNOT_TEST_MOUSE_EVENTS();

    QHorizontalStackedBarSeries* series = new QHorizontalStackedBarSeries();

    QBarSet* set1 = new QBarSet(QString("set 1"));
    *set1 << 10 << 10 << 10;
    series->append(set1);

    QBarSet* set2 = new QBarSet(QString("set 2"));
    *set2 << 10 << 10 << 10;
    series->append(set2);

    QSignalSpy seriesSpy(series,SIGNAL(hovered(bool, QBarSet*)));

    QChartView view(new QChart());
    view.resize(400,300);
    view.chart()->addSeries(series);
    view.show();
    QTest::qWaitForWindowShown(&view);

    //this is hack since view does not get events otherwise
    view.setMouseTracking(true);

//=======================================================================
// move mouse to left border
    QTest::mouseMove(view.viewport(), QPoint(0, 231));
    QCoreApplication::processEvents(QEventLoop::AllEvents, 10000);
    TRY_COMPARE(seriesSpy.count(), 0);

//=======================================================================
// move mouse on top of set1
    QTest::mouseMove(view.viewport(), QPoint(115,231));
    TRY_COMPARE(seriesSpy.count(), 1);

    QList<QVariant> seriesSpyArg = seriesSpy.takeFirst();
    QCOMPARE(qvariant_cast<QBarSet*>(seriesSpyArg.at(1)), set1);
    QVERIFY(seriesSpyArg.at(0).type() == QVariant::Bool);
    QVERIFY(seriesSpyArg.at(0).toBool() == true);

//=======================================================================
// move mouse from top of set1 to top of set2
    QTest::mouseMove(view.viewport(), QPoint(285,231));
    TRY_COMPARE(seriesSpy.count(), 2);

    // should leave set1
    seriesSpyArg = seriesSpy.takeFirst();
    QCOMPARE(qvariant_cast<QBarSet*>(seriesSpyArg.at(1)), set1);
    QVERIFY(seriesSpyArg.at(0).type() == QVariant::Bool);
    QVERIFY(seriesSpyArg.at(0).toBool() == false);

    // should enter set2
    seriesSpyArg = seriesSpy.takeFirst();
    QCOMPARE(qvariant_cast<QBarSet*>(seriesSpyArg.at(1)), set2);
    QVERIFY(seriesSpyArg.at(0).type() == QVariant::Bool);
    QVERIFY(seriesSpyArg.at(0).toBool() == true);

//=======================================================================
// move mouse from top of set2 to background
    QTest::mouseMove(view.viewport(), QPoint(285,300));
    TRY_COMPARE(seriesSpy.count(), 1);

    // should leave set2
    seriesSpyArg = seriesSpy.takeFirst();
    QCOMPARE(qvariant_cast<QBarSet*>(seriesSpyArg.at(1)), set2);
    QVERIFY(seriesSpyArg.at(0).type() == QVariant::Bool);
    QVERIFY(seriesSpyArg.at(0).toBool() == false);
}

QTEST_MAIN(tst_QHorizontalStackedBarSeries)

#include "tst_qhorizontalstackedbarseries.moc"

