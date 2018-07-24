#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "bwmodel.h"
#include "mouseeventfilter.h"

#include <QGraphicsView>
#include <QMainWindow>

namespace Ui {
class MainWindow;
const int BitOnColor = 0x00cc00;
const int BitOffColor = 0xF4F4F4;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_lineEdit_1_editingFinished();
    void on_pushButton_1_Inv_released();
    void on_pushButton_1_Clear_released();
    void on_pushButton_1_Left_released();
    void on_pushButton_1_Right_released();
    void on_lineEdit_2_editingFinished();
    void on_pushButton_2_Inv_released();
    void on_pushButton_2_Clear_released();
    void on_pushButton_2_Left_released();
    void on_pushButton_2_Right_released();
    void on_radioButton_And_clicked();
    void on_radioButton_Not_clicked();
    void on_radioButton_Or_clicked();
    void on_radioButton_Xor_clicked();
    void on_radioButton_Hex_clicked();
    void on_radioButton_Dec_clicked();
    void on_radioButton_Oct_clicked();
    void on_lineEdit_3_editingFinished();
    void on_pushButton_3_Inv_released();
    void on_pushButton_3_Clear_released();
    void on_pushButton_3_Left_released();
    void on_pushButton_3_Right_released();
    void on_clickBit(int bitIndex);

private:
    Ui::MainWindow *ui;
    BwModel bw;
    QVector<QGraphicsView *> bitView;
    QVector<MouseEventFilter *> mouseEventFilterList;

    void initBitView1();
    void initBitView2();
    void initBitView3();
    void termBitView();

    void initBitScene();
    void termBitScene();

    void initMouseEventFilter();
    void termMouseEventFilter();

    void updateFields();

    QString numberToString(unsigned int number, Bw::Notation view);
    unsigned int stringToNumber(QString str, Bw::Notation view);

    void readSettings();
    void writeSettings();

    void placeWindowToCenterOfScreen();
};

#endif // MAINWINDOW_H
