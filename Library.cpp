#include "Library.h"
#include "Document.h"
#include <fstream>
#include <iostream>
#include <algorithm>

Library::Library()
{

}

Library::~Library()
{

}

void Library::addDoc(Document* doc)
{
    _biblio.push_back(doc);
}

void Library::deleteDoc(Document* doc)
{
    for(unsigned int i = 0;i<_biblio.size();i++)
    {
        if((_biblio[i]->getTitle() == doc->getTitle()) && (_biblio[i]->getAutor() == doc->getAutor()))
        {
            _biblio.erase(_biblio.begin()+i);
        }
    }
}

void Library::exportHTML()
{
    std::ofstream f("index.html");
    if(f)
    {
        f << "<!DOCTYPE html>" << std::endl;
        f << "<html>" << std::endl;
        f << "<head>" << "<h1>Liste des Documents</h1>" << "</head>" << std::endl;
        f << "<body>" << std::endl;
        f << "<table border=\"1\";>" << std::endl;

        for(unsigned int i = 0;i<_biblio.size();i++)
        {
            f << "<tr><th>" << _biblio[i]->getTitle() << "</th><th>" << _biblio[i]->getAutor() << "</th></tr>" << std::endl;
        }

        f << "</table>" << std::endl;
        f << "</body>" << std::endl;
        f << "</html>" << std::endl;
        f.close();
    }
}

Document& Library::searchDoc(std::string title)
{
    bool ok = false;
    Document doc("Inconnu", "Inconnu");
    for(unsigned int i =0;i<_biblio.size();i++)
    {
        if(_biblio[i]->getTitle() == title)
        {
            return *_biblio[i];
            ok = true;
        }
    }

    if(ok == false)
    {
        return doc;
    }
}

int Library::numberDocument() const
{
    return _biblio.size();
}

void Library::sort(bool (*f)(Document*, Document*))
{
     std::sort(_biblio.begin(), _biblio.end(), f);
}

std::vector<Document*>& Library::search(std::string)
{
     return _biblio;
}

void Library::showDoc()
{
    std::cout<<"\n*** Liste of Documents ***"<<std::endl;
    for(unsigned int i=0;i<_biblio.size();i++)
    {
        std::cout<<"* "<<_biblio[i]->getTitle()<<std::endl;
    }
}
