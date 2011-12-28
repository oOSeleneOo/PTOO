#include "CD.h"

CD::CD() : Document(),
    _style("Inconnu"),
    _pisteNumber(0)
{
}

CD::~CD()
{

}

CD::CD(std::string title, std::string autor, std::string style, int pisteNumber) : Document(title, autor)
{
    _style = style;
    _pisteNumber = pisteNumber;
}

void CD::setStyle(const std::string& style)
{
    _style = style;
}

void CD::setPisteNumber(int pisteNumber)
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
