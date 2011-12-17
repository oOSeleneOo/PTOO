#include "Document.h"

Document::Document(std::string title, std::string autor)
{
    _title = title;
    _autor = autor;
}

Document::Document() :
        _title("Inconnu"),
        _autor("Inconnu")
{
}


Document::~Document()
{

}

void Document::setTitle(const std::string& title)
{
    _title = title;
}

void Document::setAutor(const std::string& autor)
{
    _autor = autor;
}

 std::string Document::getTitle() const
 {
     return _title;
 }


std::string Document::getAutor() const
{
    return _autor;
}
