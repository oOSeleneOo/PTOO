#include "Library.h"

Library::Library()
{

}

Library::~Library()
{

}

void addDoc(Document* doc)
{
    _biblio.push_back(doc);
}

void deleteDoc(Document* doc)
{
    int i;

    for(i=0;i<biblio.length();i++)
    {
        if((biblio[i].getTitle == doc.getTitle()) && (biblio[i].getAutor == doc.getAutor()))
        {
            _biblio.erase(i);
        }
    }
}

void exportHTML()
{

}
