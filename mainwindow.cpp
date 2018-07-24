#include "mainwindow.h"
#include "mouseeventfilter.h"
#include "ui_mainwindow.h"

#include <QMouseEvent>
#include <QSettings>
#include <qstyle.h>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QCoreApplication::setOrganizationName("sergey-untilov");
    QCoreApplication::setOrganizationDomain("sergey-untilov.com");
    QCoreApplication::setApplicationName("qBitWise");

    ui->setupUi(this);
    initBitView1();
    initBitView2();
    initBitView3();
    initBitScene();
    initMouseEventFilter();
    readSettings();
    bw.calculate();
    updateFields();
}

MainWindow::~MainWindow()
{
    termBitScene();
    termBitView();
    delete ui;
    termMouseEventFilter();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    writeSettings();
    event->accept();
}

void MainWindow::initBitView1()
{
    bitView.append(ui->graphicsView_100);
    bitView.append(ui->graphicsView_101);
    bitView.append(ui->graphicsView_102);
    bitView.append(ui->graphicsView_103);
    bitView.append(ui->graphicsView_104);
    bitView.append(ui->graphicsView_105);
    bitView.append(ui->graphicsView_106);
    bitView.append(ui->graphicsView_107);
    bitView.append(ui->graphicsView_108);
    bitView.append(ui->graphicsView_109);
    bitView.append(ui->graphicsView_110);
    bitView.append(ui->graphicsView_111);
    bitView.append(ui->graphicsView_112);
    bitView.append(ui->graphicsView_113);
    bitView.append(ui->graphicsView_114);
    bitView.append(ui->graphicsView_115);
    bitView.append(ui->graphicsView_116);
    bitView.append(ui->graphicsView_117);
    bitView.append(ui->graphicsView_118);
    bitView.append(ui->graphicsView_119);
    bitView.append(ui->graphicsView_120);
    bitView.append(ui->graphicsView_121);
    bitView.append(ui->graphicsView_122);
    bitView.append(ui->graphicsView_123);
    bitView.append(ui->graphicsView_124);
    bitView.append(ui->graphicsView_125);
    bitView.append(ui->graphicsView_126);
    bitView.append(ui->graphicsView_127);
    bitView.append(ui->graphicsView_128);
    bitView.append(ui->graphicsView_129);
    bitView.append(ui->graphicsView_130);
    bitView.append(ui->graphicsView_131);
}

void MainWindow::initBitView2()
{
    bitView.append(ui->graphicsView_200);
    bitView.append(ui->graphicsView_201);
    bitView.append(ui->graphicsView_202);
    bitView.append(ui->graphicsView_203);
    bitView.append(ui->graphicsView_204);
    bitView.append(ui->graphicsView_205);
    bitView.append(ui->graphicsView_206);
    bitView.append(ui->graphicsView_207);
    bitView.append(ui->graphicsView_208);
    bitView.append(ui->graphicsView_209);
    bitView.append(ui->graphicsView_210);
    bitView.append(ui->graphicsView_211);
    bitView.append(ui->graphicsView_212);
    bitView.append(ui->graphicsView_213);
    bitView.append(ui->graphicsView_214);
    bitView.append(ui->graphicsView_215);
    bitView.append(ui->graphicsView_216);
    bitView.append(ui->graphicsView_217);
    bitView.append(ui->graphicsView_218);
    bitView.append(ui->graphicsView_219);
    bitView.append(ui->graphicsView_220);
    bitView.append(ui->graphicsView_221);
    bitView.append(ui->graphicsView_222);
    bitView.append(ui->graphicsView_223);
    bitView.append(ui->graphicsView_224);
    bitView.append(ui->graphicsView_225);
    bitView.append(ui->graphicsView_226);
    bitView.append(ui->graphicsView_227);
    bitView.append(ui->graphicsView_228);
    bitView.append(ui->graphicsView_229);
    bitView.append(ui->graphicsView_230);
    bitView.append(ui->graphicsView_231);
}

void MainWindow::initBitView3()
{
    bitView.append(ui->graphicsView_300);
    bitView.append(ui->graphicsView_301);
    bitView.append(ui->graphicsView_302);
    bitView.append(ui->graphicsView_303);
    bitView.append(ui->graphicsView_304);
    bitView.append(ui->graphicsView_305);
    bitView.append(ui->graphicsView_306);
    bitView.append(ui->graphicsView_307);
    bitView.append(ui->graphicsView_308);
    bitView.append(ui->graphicsView_309);
    bitView.append(ui->graphicsView_310);
    bitView.append(ui->graphicsView_311);
    bitView.append(ui->graphicsView_312);
    bitView.append(ui->graphicsView_313);
    bitView.append(ui->graphicsView_314);
    bitView.append(ui->graphicsView_315);
    bitView.append(ui->graphicsView_316);
    bitView.append(ui->graphicsView_317);
    bitView.append(ui->graphicsView_318);
    bitView.append(ui->graphicsView_319);
    bitView.append(ui->graphicsView_320);
    bitView.append(ui->graphicsView_321);
    bitView.append(ui->graphicsView_322);
    bitView.append(ui->graphicsView_323);
    bitView.append(ui->graphicsView_324);
    bitView.append(ui->graphicsView_325);
    bitView.append(ui->graphicsView_326);
    bitView.append(ui->graphicsView_327);
    bitView.append(ui->graphicsView_328);
    bitView.append(ui->graphicsView_329);
    bitView.append(ui->graphicsView_330);
    bitView.append(ui->graphicsView_331);
}

void MainWindow::termBitView()
{
    bitView.clear();
}

void MainWindow::initBitScene()
{
    foreach(auto view, bitView)
    {
        QGraphicsScene * scene = new QGraphicsScene();
        view->setScene(scene);
    }
}

void MainWindow::termBitScene()
{
    foreach(auto view, bitView)
    {
        auto scene = view->scene();
        view->setScene(nullptr);
        delete scene;
    }
}

void MainWindow::initMouseEventFilter()
{
    for(int i = 0; i < bitView.size(); ++i)
    {
        auto filter = new MouseEventFilter();
        bitView[i]->installEventFilter(filter);
        mouseEventFilterList.append(filter);
        QObject::connect(filter, SIGNAL(clickOnBit(int)), this, SLOT(on_clickBit(int)));
        filter->setBitIndex(i);
    }
}

void MainWindow::termMouseEventFilter()
{
    foreach(auto filter, mouseEventFilterList)
        delete filter;
    mouseEventFilterList.clear();
}

QString MainWindow::numberToString(unsigned int number, Bw::Notation notation)
{
    int base = notation == Bw::HEX ? 16 : notation == Bw::OCT ? 8 : 10;
    return QString::number(number, base).toUpper();
}

unsigned int MainWindow::stringToNumber(QString str, Bw::Notation notation)
{
    str.replace(" ", "");
    str = str.toUpper();
    int base = notation == Bw::HEX ? 16 : notation == Bw::OCT ? 8 : 10;
    return str.toUInt(nullptr, base);
}

void MainWindow::updateFields()
{
    Bw::Operation operation = bw.getOperation();
    Bw::Notation view = bw.getNotation();

    ui->radioButton_And->setChecked(operation == Bw::AND);
    ui->radioButton_Not->setChecked(operation == Bw::NOT);
    ui->radioButton_Or->setChecked(operation == Bw::OR);
    ui->radioButton_Xor->setChecked(operation == Bw::XOR);

    ui->radioButton_Hex->setChecked(view == Bw::HEX);
    ui->radioButton_Dec->setChecked(view == Bw::DEC);
    ui->radioButton_Oct->setChecked(view == Bw::OCT);

    ui->lineEdit_1->setText(numberToString(bw.getNumber(Bw::FIRST), view));
    ui->lineEdit_2->setText(numberToString(bw.getNumber(Bw::SECOND), view));
    ui->lineEdit_3->setText(numberToString(bw.getNumber(Bw::RESULT), view));

    for(int n = 0; n < bitView.size(); ++n)
    {
        Bw::Index index = static_cast<Bw::Index>(n / 32);
        int bit = n % 32;
        QBrush brush = bw.getBit(index, bit)
                ? QColor(QRgb(Ui::BitOnColor))
                : QColor(QRgb(Ui::BitOffColor));
        bitView[n]->setForegroundBrush(brush);
    }
}

void MainWindow::on_lineEdit_1_editingFinished()
{
    QLineEdit *lineEdit = dynamic_cast<QLineEdit*>(sender());
    unsigned int value = stringToNumber(lineEdit->text(), bw.getNotation());
    bw.setNumber(Bw::FIRST, value);
    bw.calculate();
    updateFields();
}

void MainWindow::on_pushButton_1_Inv_released()
{
    bw.invert(Bw::FIRST);
    bw.calculate();
    updateFields();
}

void MainWindow::on_pushButton_1_Clear_released()
{
    bw.clear(Bw::FIRST);
    bw.calculate();
    updateFields();
}

void MainWindow::on_pushButton_1_Left_released()
{
    bw.shiftLeft(Bw::FIRST);
    bw.calculate();
    updateFields();
}

void MainWindow::on_pushButton_1_Right_released()
{
    bw.shiftRight(Bw::FIRST);
    bw.calculate();
    updateFields();
}

void MainWindow::on_lineEdit_2_editingFinished()
{
    QLineEdit *lineEdit = dynamic_cast<QLineEdit*>(sender());
    unsigned int value = stringToNumber(lineEdit->text(), bw.getNotation());
    bw.setNumber(Bw::SECOND, value);
    bw.calculate();
    updateFields();
}

void MainWindow::on_pushButton_2_Inv_released()
{
    bw.invert(Bw::SECOND);
    bw.calculate();
    updateFields();
}

void MainWindow::on_pushButton_2_Clear_released()
{
    bw.clear(Bw::SECOND);
    bw.calculate();
    updateFields();
}

void MainWindow::on_pushButton_2_Left_released()
{
    bw.shiftLeft(Bw::SECOND);
    bw.calculate();
    updateFields();
}

void MainWindow::on_pushButton_2_Right_released()
{
    bw.shiftRight(Bw::SECOND);
    bw.calculate();
    updateFields();
}


void MainWindow::on_radioButton_And_clicked()
{
    bw.setOperation(Bw::AND);
    bw.calculate();
    updateFields();
}

void MainWindow::on_radioButton_Not_clicked()
{
    bw.setOperation(Bw::NOT);
    bw.calculate();
    updateFields();
}

void MainWindow::on_radioButton_Or_clicked()
{
    bw.setOperation(Bw::OR);
    bw.calculate();
    updateFields();
}

void MainWindow::on_radioButton_Xor_clicked()
{
    bw.setOperation(Bw::XOR);
    bw.calculate();
    updateFields();
}

void MainWindow::on_radioButton_Hex_clicked()
{
    bw.setNotation(Bw::HEX);
    bw.calculate();
    updateFields();
}

void MainWindow::on_radioButton_Dec_clicked()
{
    bw.setNotation(Bw::DEC);
    bw.calculate();
    updateFields();
}

void MainWindow::on_radioButton_Oct_clicked()
{
    bw.setNotation(Bw::OCT);
    bw.calculate();
    updateFields();
}

void MainWindow::on_lineEdit_3_editingFinished()
{
    QLineEdit *lineEdit = dynamic_cast<QLineEdit*>(sender());
    unsigned int value = stringToNumber(lineEdit->text(), bw.getNotation());
    bw.setNumber(Bw::RESULT, value);
    updateFields();
}

void MainWindow::on_pushButton_3_Inv_released()
{
    bw.invert(Bw::RESULT);
    updateFields();
}

void MainWindow::on_pushButton_3_Clear_released()
{
    bw.clear(Bw::RESULT);
    updateFields();
}

void MainWindow::on_pushButton_3_Left_released()
{
    bw.shiftLeft(Bw::RESULT);
    updateFields();
}

void MainWindow::on_pushButton_3_Right_released()
{
    bw.shiftRight(Bw::RESULT);
    updateFields();
}

void MainWindow::on_clickBit(int bitListIndex)
{
    Bw::Index index = static_cast<Bw::Index>(bitListIndex / 32);
    int bit = bitListIndex % 32;
    bw.setBit(index, bit, !bw.getBit(index, bit));
    if (index != Bw::RESULT)
        bw.calculate();
    updateFields();
}

void MainWindow::placeWindowToCenterOfScreen()
{
    setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            size(),
            qApp->desktop()->availableGeometry()
        )
    );
}

void MainWindow::readSettings()
{
    QSettings settings;

    bool isSettingsOk = settings.value("status").toBool();

    if (isSettingsOk)
    {
        settings.beginGroup("MainWindow");
        resize(settings.value("size", QSize(400, 400)).toSize());
        move(settings.value("pos", QPoint(200, 200)).toPoint());
        settings.endGroup();

        bw.read(settings);
    }
    else
    {
        placeWindowToCenterOfScreen();
    }
}

void MainWindow::writeSettings()
{
    QSettings settings;

    settings.setValue("status", true);

    settings.beginGroup("MainWindow");
    settings.setValue("size", size());
    settings.setValue("pos", pos());
    settings.endGroup();

    bw.write(settings);
}
