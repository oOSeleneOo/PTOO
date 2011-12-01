#include "CD.h"

CD::CD()
{

}

CD::~CD()
{

}

CD::CD(std::string style, int pisteNumber)
{
    _style = style;
    _pisteNumber = pisteNumber;
}

void CD::setStyle(std::string style)
{
    _style = style;
}

void CD::setPisteNumber(std::string pisteNumber)
{
    _pisteNumber = pisteNumber;
}

std::string CD::getStyle() const
{
    return _style;
}

int CD::getPisteNumber() const
{
    return _pisteNumber;
}
