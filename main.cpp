#include "Library.h"
#include "Document.h"
#include "Book.h"
#include "CD.h"
#include "Movie.h"
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <istream>
#include <algorithm>

bool sortingName(Document* doc1, Document* doc2)
{

    std::string s1 = doc1->getTitle();
    std::string s2 = doc2->getTitle();

    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

    for(unsigned int i = 0; i < s2.size(); ++i) {
         int c1 = s1[i];
         int c2 = s2[i];
         if(c1 != c2) {
              return (c1 < c2);
         }
    }
    return false;
}

int main()
{
    std::cout<<"Creating the Library"<<std::endl;
    Library myLibrary;

    std::cout<<"Adding Books, CDs ans Movies"<<std::endl;
    Book l1("l'épée de vérité tome 1", "Terry Goodkind","un long résumé",2000,"Barcelone");
    Book l2("second livre", "second auteur","encore un resumé",2010, "editeur");
    Book l3("troisieme livre", "troisieme auteur","encore un resumé",2011, "editeur");
    CD c1("mon premier cd", "artiste 1", "rock", 8);
    CD c2("mon second cd", "artiste 1", "classique", 20);
    Movie m1("titanic", "cameron", "un bateau coule", "romantique","di caprio");
    Movie m2("un film", "un realisateur", "un resume", "un style", "un acteur");

    myLibrary.addDoc(&l1);
    myLibrary.addDoc(&l2);
    myLibrary.addDoc(&l3);
    myLibrary.addDoc(&c1);
    myLibrary.addDoc(&c2);
    myLibrary.addDoc(&m1);
    myLibrary.addDoc(&m2);

    std::cout << "\n*** Sorting by name ... " << std::endl;
    myLibrary.sort(&sortingName);
    std::vector<Document*> doc = myLibrary.search("");
    for(unsigned int i =0;i<doc.size();i++)
    {
        std::cout<<" > "<<doc[i]->getTitle()<<std::endl;
    }

    std::cout<<"Number of documents : "<<myLibrary.numberDocument()<<std::endl;
    std::cout<<"Export to html"<<std::endl;
    myLibrary.exportHTML();

    return 0;
}


