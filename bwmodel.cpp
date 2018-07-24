#include "bwmodel.h"

BwModel::BwModel() : operation(Bw::OR), notation(Bw::DEC)
{
    number[Bw::FIRST] = 0;
    number[Bw::SECOND] = 0;
    number[Bw::RESULT] = 0;
}

void BwModel::setOperation(const Bw::Operation operation)
{
    this->operation = operation;
    calculate();
}

void BwModel::setNotation(const Bw::Notation notation)
{
    this->notation = notation;
}

void BwModel::setNumber(const Bw::Index index, const unsigned int value)
{
    number[index] = value;
}

void BwModel::invert(const Bw::Index index)
{
    number[index] = ~(number[index]);
}

void BwModel::clear(const Bw::Index index)
{
    number[index] = 0;
}

void BwModel::shiftLeft(const Bw::Index index)
{
    number[index] = number[index] << 1;
}

void BwModel::shiftRight(const Bw::Index index)
{
    number[index] = number[index] >> 1;
}

void BwModel::setBit(const Bw::Index index, const int bit, const bool value)
{
    if (value)
        number[index] |= (1 << bit);
    else
        number[index] &= ~(1 << bit);
}


unsigned int BwModel::getNumber(const Bw::Index index) const
{
    return number[index];
}

bool BwModel::getBit(const Bw::Index index, const int bit) const
{
    return number[index] & (1 << bit) ? true : false;
}

unsigned int BwModel::calculator(unsigned int a, unsigned int b, Bw::Operation operation)
{
    switch (operation)
    {
        case Bw::NOT:
            return a &= (~b);
        case Bw::AND:
            return a & b;
        case Bw::OR:
            return a | b;
        case Bw::XOR:
            return a ^ b;
    }
    return 0;
}

void BwModel::calculate()
{
    number[Bw::RESULT] = calculator(number[Bw::FIRST], number[Bw::SECOND], operation);
}

Bw::Operation BwModel::getOperation() const
{
    return operation;
}

Bw::Notation BwModel::getNotation() const
{
    return notation;
}

void BwModel::read(QSettings & settings)
{
    settings.beginGroup("Model");
    number[Bw::FIRST] = settings.value("number1", 0).toUInt();
    number[Bw::SECOND] = settings.value("number2", 0).toUInt();
    operation = static_cast<Bw::Operation>(settings.value("operation", 0).toInt());
    notation = static_cast<Bw::Notation>(settings.value("notation", 0).toInt());
    settings.endGroup();
}

void BwModel::write(QSettings & settings) const
{
    settings.beginGroup("Model");
    settings.setValue("number1", number[Bw::FIRST]);
    settings.setValue("number2", number[Bw::SECOND]);
    settings.setValue("operation", operation);
    settings.setValue("notation", notation);
    settings.endGroup();
}
