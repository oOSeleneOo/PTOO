#include "Movie.h"

Movie::Movie() : Document(),
    _resume(NULL),
    _style(NULL),
    _actor(NULL)
{

}

Movie::Movie(std::string title, std::string autor, std::string resume, std::string style, std::string actor) : Document(title, autor),
    _resume(resume),
    _style(style),
    _actor(actor)
{

}

Movie::~Movie()
{

}

void Movie::setResume(std::string& resume)
{
    _resume = resume;
}

void Movie::setStyle(std::string& style)
{
    _style = style;
}

void Movie::setActor(std::string& actor)
{
    _actor = actor;
}

std::string Movie::getResume() const
{
    return _resume;
}

std::string Movie::getStyle() const
{
    return _style;
}

std::string Movie::getActor() const
{
    return _actor;
}
