#ifndef MOUSEEVENTFILTER_H
#define MOUSEEVENTFILTER_H

#include <QObject>

class MouseEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit MouseEventFilter(QObject *parent = nullptr);

    void setBitIndex(int bitIndex);

protected:
    bool eventFilter(QObject *obj, QEvent *event);

signals:
    void clickOnBit(int bitIndex);

public slots:


private:
    int bitIndex;
};

#endif // MOUSEEVENTFILTER_H
