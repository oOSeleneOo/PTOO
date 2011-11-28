#include "Document.h"

Document::Document(std::string title, std::string autor)
{
    _title = title;
    _autor = autor;
}

Document::~Document()
{

}

void Document::setTitre(const std::string& t)
{
    _title = t;
}

 std::string Document::getTitle() const
 {
     return _title;
 }


std::string Document::getAutor() const
{
    retrun _autor;
}
