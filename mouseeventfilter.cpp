#include "mouseeventfilter.h"

#include <QEvent>

MouseEventFilter::MouseEventFilter(QObject *parent)
{
    Q_UNUSED(parent);
}

void MouseEventFilter::setBitIndex(int bitIndex)
{
    this->bitIndex = bitIndex;
}

bool MouseEventFilter::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress)
    {
        emit(clickOnBit(bitIndex));
        return true;
    }
    else
    {
        // standard event processing
        return QObject::eventFilter(obj, event);
    }
}
