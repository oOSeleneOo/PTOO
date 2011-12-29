#include "Library.h"
#include "Document.h"
#include "Book.h"
#include "CD.h"
#include "Movie.h"
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
        f<<"<!DOCTYPE html>"<<std::endl;
        f<<"<html>"<<std::endl;
        f<<"<head>"<<"<h1>Liste des Documents</h1>"<<"</head>"<<std::endl;
        f<<"<body>"<<std::endl;
        f<<"<table border=\"1\";>"<<std::endl;
        f<<"<tr><th><big>Title</big></th><th><big>Autor</big></th></th><th><big>Type</big></th></tr>"<<std::endl;
        for(unsigned int i = 0;i<_biblio.size();i++)
        {
            Book* b = dynamic_cast<Book*>(_biblio[i]);
            CD* c = dynamic_cast<CD*>(_biblio[i]);

            f<<"<tr><th>"<<_biblio[i]->getTitle()<<"</th><th>"<<_biblio[i]->getAutor()<<"</th>";

            if(b)
            {
                f<<"<th>Book</th></tr>" << std::endl;
            }
            else if (c)
            {
                f<<"<th>CD</th></tr>" << std::endl;
            }
            else
            {
                f<<"<th>Movie</th></tr>" << std::endl;
            }
        }

        f<<"</table>"<<std::endl;
        f<<"</body>"<<std::endl;
        f<<"</html>"<<std::endl;
        f.close();
    }
}

Document& Library::searchDoc(std::string title)
{
    unsigned int i=0;
    bool ok = false;
    Document* doc = new Document("Inconnu", "Inconnu");
    while((i<_biblio.size()) && (ok == false))
    {
        if(_biblio[i]->getTitle() == title)
        {
            ok = true;
        }
        i++;
    }

    if(ok == false)
    {
        return *doc;
    }
    else
    {
        return *_biblio[i-1];
    }
}

void Library::sort(bool (*f)(Document*, Document*))
{
     std::sort(_biblio.begin(), _biblio.end(), f);
}

std::vector<Document*>& Library::getDoc()
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
