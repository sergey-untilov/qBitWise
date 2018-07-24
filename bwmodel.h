#ifndef MODEL_H
#define MODEL_H

#include <QJsonObject>
#include <QSettings>

namespace Bw {
class BwModel;
enum Operation {OR, NOT, AND, XOR};
enum Notation {DEC, HEX, OCT};
enum Index {FIRST, SECOND, RESULT};
}

class BwModel
{
public:
    BwModel();

    void setOperation(const Bw::Operation);
    void setNotation(const Bw::Notation);

    void setNumber(const Bw::Index index, const unsigned int value);
    void invert(const Bw::Index index);
    void clear(const Bw::Index index);
    void shiftLeft(const Bw::Index index);
    void shiftRight(const Bw::Index index);
    void setBit(const Bw::Index index, const int bit, const bool value);

    void calculate();

    unsigned int getNumber(const Bw::Index index) const;
    bool getBit(const Bw::Index index, const int bit) const;
    Bw::Operation getOperation() const;
    Bw::Notation getNotation() const;

    void read(QSettings & settings);
    void write(QSettings & settings) const;

private:
    unsigned int number[3];
    Bw::Operation operation;
    Bw::Notation notation;

    static unsigned int calculator(unsigned int a, unsigned int b, Bw::Operation operation);
};

#endif // MODEL_H
