#ifndef TEST_H
#define TEST_H

#include <QMainWindow>
#include "ui_test.h"

class QHexEdit;
class QHexEditData;

class Test : public QMainWindow
{
    Q_OBJECT

public:
    Test(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    ~Test();

private:
    Ui::TestClass ui;

    QHexEdit *m_hexedit;
    QHexEditData *m_hexEditData;
    QByteArray m_HexEditByteArray;


};

#endif // TEST_H
