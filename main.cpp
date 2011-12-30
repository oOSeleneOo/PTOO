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
#include <fstream>

bool isInteger(std::string chaineSaisie)
{
        bool estUnEntier = true;
        unsigned long carParcouru = 0;

        while (estUnEntier && carParcouru<chaineSaisie.length())
        {
                //si le caractère parcouru est compris entre 48 et 57 inclus (code ascii des chiffres de 0 à 9) ou qu'il est = à 45, code ascii pour le symbole "-", alors on continue
                if ((estUnEntier = (( int(chaineSaisie[carParcouru]) > 47) &&  (int(chaineSaisie[carParcouru]) < 58))) || (int(chaineSaisie[carParcouru]) == 45))
                {
                        carParcouru ++;
                }
        }

        return (estUnEntier);
}

int menu()
{
        int iMenu;
        std::string rep;

        system("clear");
        std::cout<<"\t***********************************\n"<<std::endl;
        std::cout<<"\t**         Ma Bibliothèque       **\n"<<std::endl;
        std::cout<<"\t***********************************\n"<<std::endl;
        std::cout<<"\t** 1) Ajouter un nouveau document **\n"<<std::endl;
        std::cout<<"\t** 2) Retirer un document **\n"<<std::endl;
        std::cout<<"\t** 3) Rechercher un document **\n"<<std::endl;
        std::cout<<"\t** 4) Trier les documents **\n"<<std::endl;
        std::cout<<"\t** 5) Export HTML **\n"<<std::endl;
        std::cout<<"\t** 6) Voir la bibliotheque **\n"<<std::endl;
        std::cout<<"\t** 0) Quitter **\n"<<std::endl;
        std::cout<<"\t***********************************\n"<<std::endl;
        std::cout<<"\tVotre choix : ";
        std::cin>>rep;
        if(isInteger(rep))
        {
                iMenu = atoi(rep.c_str());
                return (iMenu);
        }
        else
        {
                return 0;
        }
}

int menuDoc()
{
    int iMenuDoc;
    std::string rep;
    system("clear");
    std::cout<<"\t** 1) Ajouter un nouveau livre **\n"<<std::endl;
    std::cout<<"\t** 2) Ajouter un nouveau CD **\n"<<std::endl;
    std::cout<<"\t** 3) Ajouter un nouveau film **\n"<<std::endl;
    std::cout<<"\t** 4) Annuler **\n"<<std::endl;
    std::cout<<"\tVotre choix : ";
    std::cin>>rep;
    if(isInteger(rep))
    {
            iMenuDoc = atoi(rep.c_str());
            return (iMenuDoc);
    }
    else
    {
            return 0;
    }
}

int menuSort()
{
    int iMenuSort;
    std::string rep;
    system("clear");
    std::cout<<"\t** 1) Trier uniquement les Livres **\n"<<std::endl;
    std::cout<<"\t** 2) Trier uniquement les CD **\n"<<std::endl;
    std::cout<<"\t** 3) Trier uniquement les Films **\n"<<std::endl;
    std::cout<<"\t** 4) Trier par nom **\n"<<std::endl;
    std::cout<<"\t** 5) Trier par auteur **\n"<<std::endl;
    std::cout<<"\t** 0) Annuler **\n"<<std::endl;
    std::cout<<"\tVotre choix : ";
    std::cin>>rep;
    if(isInteger(rep))
    {
            iMenuSort = atoi(rep.c_str());
            return (iMenuSort);
    }
    else
    {
            return 0;
    }
}

std::vector<std::string> split(std::string chaineInit, std::string chaineSep)
{
    std::vector<std::string> chaineSplit;
    size_t pos;

    //on split tant que l'on est pas arrivé au bout de la chaine
    do{
        //position du séparateur dans la chaine initiale
        pos = chaineInit.find(chaineSep);
        //si ce n'est pas la chaine complete
        if (pos!=std::string::npos){
            //on ajoute tout les caractères du début jusqu'a la position du séparateur
            chaineSplit.push_back(chaineInit.substr(0,pos));
            //on réduit la chaine initiale de l'élément ajouté au vecteur ainsi que de la taille du séparateur
            chaineInit = chaineInit.substr(pos+chaineSep.length());
        }else{
            //on ajoute simplement ce qu'il reste de la chaine initiale (dernier élément)
            chaineSplit.push_back(chaineInit);
        }
    }while(pos!=std::string::npos);

    return (chaineSplit);
}

void load_file(Library *lib)
{
    std::ifstream monFichier;   //Déclaration d'un flux permettant d'écrire un fichier.
    std::string extension = "./sauve.txt";
    std::vector<std::string> myLine;
    std::string title, autor, editor, style, resume, actor;
    int piste, editorYear;

    monFichier.open(extension.c_str());

    if(monFichier)    //On teste si on peu ouvrir le fichier
    {
        while(monFichier)    //Tant qu'on n'est pas a la fin
        {
            std::string ligne;
            getline(monFichier, ligne); //On lit une ligne
            myLine = split(ligne, "//");
            if (myLine[0] == "<Book>")
            {
                title = myLine[1];
                autor = myLine[2];
                resume = myLine[3];
                editor = myLine[4];
                editorYear = atoi(myLine[5].c_str());
                Book* book = new Book(title, autor, resume, editorYear, editor);
                lib->addDoc(book);
                myLine.clear();
            }
            else if (myLine[0] == "<CD>")
            {
                title = myLine[1];
                autor = myLine[2];
                style = myLine[3];
                piste = atoi(myLine[4].c_str());
                CD* cd = new CD(title, autor, style, piste);
                lib->addDoc(cd);
                myLine.clear();
            }
            else if (myLine[0] == "<Movie>")
            {
                title = myLine[1];
                autor = myLine[2];
                resume = myLine[3];
                style = myLine[4];
                actor = myLine[5];
                Movie* movie = new Movie(title, autor, resume, style, actor);
                lib->addDoc(movie);
                myLine.clear();
            }
        }
    }
    else
    {
        std::cout<<"ERREUR: Impossible d'ouvrir le fichier "<<extension<<std::endl;
    }
    monFichier.close(); //On finit par refermer le fichier
}

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

bool sortingAutor(Document* doc1, Document* doc2)
{

    std::string s1 = doc1->getAutor();
    std::string s2 = doc2->getAutor();

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

bool sortingBook(Document* doc1, Document* doc2)
{
    Book* b1 = dynamic_cast<Book*>(doc1);
    Book* b2 = dynamic_cast<Book*>(doc2);

    if(b1 && b2)
    {
        return (b1->getEditorYear() < b2->getEditorYear());
    }

    return true;
}

bool sortingCD(Document* doc1, Document* doc2)
{
    CD* c1 = dynamic_cast<CD*>(doc1);
    CD* c2 = dynamic_cast<CD*>(doc2);

    if(c1 && c2)
    {
        return false;
    }

    return true;
}

bool sortingMovie(Document* doc1, Document* doc2)
{
    Movie* m1 = dynamic_cast<Movie*>(doc1);
    Movie* m2 = dynamic_cast<Movie*>(doc2);

    if(m1 && m2)
    {
        return false;
    }

    return true;
}

void add_book(Book* b)
{
    std::ofstream monFichier("./sauve.txt", std::ios::app);

    if(monFichier)
    {
        monFichier<<"<Book>";
        monFichier<<"//";
        monFichier<<b->getTitle();
        monFichier<<"//";
        monFichier<<b->getAutor();
        monFichier<<"//";
        monFichier<<b->getResume();
        monFichier<<"//";
        monFichier<<b->getEditor();
        monFichier<<"//";
        monFichier<<b->getEditorYear();
        monFichier<<"//"<<std::endl;
    }
    else
    {
        std::cout<<"ERREUR: Impossible d'ouvrir le fichier "<<std::endl;
    }
    monFichier.close();
}

void add_CD(CD* c)
{
    std::ofstream monFichier("./sauve.txt", std::ios::app);

    if(monFichier)
    {
        monFichier<<"<CD>";
        monFichier<<"//";
        monFichier<<c->getTitle();
        monFichier<<"//";
        monFichier<<c->getAutor();
        monFichier<<"//";
        monFichier<<c->getStyle();
        monFichier<<"//";
        monFichier<<c->getPisteNumber();
        monFichier<<"//"<<std::endl;
    }
    else
    {
        std::cout<<"ERREUR: Impossible d'ouvrir le fichier "<<std::endl;
    }
    monFichier.close();
}

void add_movie(Movie* m)
{
    std::ofstream monFichier("./sauve.txt", std::ios::app);

    if(monFichier)
    {
        monFichier<<"<Movie>";
        monFichier<<"//";
        monFichier<<m->getTitle();
        monFichier<<"//";
        monFichier<<m->getAutor();
        monFichier<<"//";
        monFichier<<m->getResume();
        monFichier<<"//";
        monFichier<<m->getStyle();
        monFichier<<"//";
        monFichier<<m->getActor();
        monFichier<<"//"<<std::endl;
    }
    else
    {
        std::cout<<"ERREUR: Impossible d'ouvrir le fichier "<<std::endl;
    }
    monFichier.close();
}

void dell(std::string title)
{
    std::ifstream monFichier;
    std::ofstream newFichier;
    std::string extension = "./sauve.txt";
    std::string newName = "./sauve2.txt";
    std::vector<std::string> myLine;
    std::string ligne;

    monFichier.open(extension.c_str());

    if(monFichier)
    {
        newFichier.open(newName.c_str());
        if(newFichier)
        {
            while(getline(monFichier,ligne))
            {
                myLine = split(ligne, "//");
                if (myLine[1] == title)
                {
                    //c'est le document a supprimer
                }
                else
                {
                    //c'est un document a garder
                    newFichier<<ligne<<std::endl;
                }
            }
        }
        else
        {
             std::cout<<"ERREUR: Impossible d'ouvrir le fichier "<<newName<<std::endl;
        }
        newFichier.close();
        monFichier.close();
        //supression de l'ancien fichier
        remove(extension.c_str());
        //on renomme le nouveau fichier
        rename(newName.c_str(), extension.c_str());
    }
    else
    {
        std::cout<<"ERREUR: Impossible d'ouvrir le fichier "<<extension<<std::endl;
    }
}

int main()
{
    Library* myLibrary = new Library();

    //Adding Books, CDs and Movies
    load_file(myLibrary);

    int iMenu = 20;
    while (iMenu !=0)
    {
        iMenu = menu();
        switch(iMenu)
        {
            case 1 :
                {
                    //*****Ajouter un document*****
                    int iMenuDoc = menuDoc();
                    switch(iMenuDoc)
                    {
                        case 1:
                            {
                                //*****Ajouter un livre*****
                                std::string title, autor, resume, editor, buffer;
                                int editorYear;

                                std::cout<<"Saisir le titre du livre"<<std::endl;
                                std::getline(std::cin,buffer);
                                std::getline(std::cin,title);
                                std::cout<<"Saisir l'auteur du livre"<<std::endl;
                                std::getline(std::cin,autor);
                                std::cout<<"Saisir le résumé du livre"<<std::endl;
                                std::getline(std::cin,resume);
                                std::cout<<"Saisir l'année d'édition du livre"<<std::endl;
                                std::cin>>editorYear;
                                std::cout<<"Saisir l'éditeur du livre"<<std::endl;
                                std::getline(std::cin,buffer);
                                std::getline(std::cin,editor);

                                Book* b = new Book();
                                b->setTitle(title);
                                b->setAutor(autor);
                                b->setResume(resume);
                                b->setEditor(editor);
                                b->setEditorYear(editorYear);
                                add_book(b);
                                myLibrary->addDoc(b);

                                std::cout<<"Votre livre a bien été enregistré"<<std::endl;
                                break;
                            }
                        case 2:
                            {
                                //*****Ajouter un CD*****
                                std::string title, autor, style, buffer;
                                int piste;

                                std::cout<<"Saisir le titre du CD"<<std::endl;
                                std::getline(std::cin,buffer);
                                std::getline(std::cin,title);
                                std::cout<<"Saisir l'artiste du CD"<<std::endl;
                                std::getline(std::cin,autor);
                                std::cout<<"Saisir le style du CD"<<std::endl;
                                std::getline(std::cin,style);
                                std::cout<<"Saisir le nombre de piste de CD"<<std::endl;
                                std::cin>>piste;

                                CD* c = new CD();
                                c->setTitle(title);
                                c->setAutor(autor);
                                c->setStyle(style);
                                c->setPisteNumber(piste);
                                add_CD(c);
                                myLibrary->addDoc(c);

                                std::cout<<"Votre CD a bien été enregistré"<<std::endl;

                                break;
                            }
                        case 3:
                            {
                                //*****Ajouter un film*****
                                std::string title, autor, resume, style, actor, buffer;

                                std::cout<<"Saisir le titre du film"<<std::endl;
                                std::getline(std::cin,buffer);
                                std::getline(std::cin,title);
                                std::cout<<"Saisir le réalisateur du film"<<std::endl;
                                std::getline(std::cin,autor);
                                std::cout<<"Saisir le style du film"<<std::endl;
                                std::getline(std::cin,style);
                                std::cout<<"Saisir le résumé du film"<<std::endl;
                                std::getline(std::cin,resume);
                                std::cout<<"Saisir un ou plusieurs acteurs du film"<<std::endl;
                                std::getline(std::cin,actor);

                                Movie* m = new Movie();
                                m->setTitle(title);
                                m->setAutor(autor);
                                m->setStyle(style);
                                m->setResume(resume);
                                m->setActor(actor);
                                add_movie(m);
                                myLibrary->addDoc(m);

                                std::cout<<"Votre film a bien été enregistré"<<std::endl;

                                break;
                            }
                        default :
                        {
                            //*****On annule*****
                            std::cout<<"Ajout annulé"<<std::endl;
                            break;
                        }
                    }
                    break;
                }
            case 2 :
                {
                    //*****Retirer un document*****
                    std::cout<<"Entrez le titre du document : "<<std::endl;
                    std::string title, buffer;
                    std::getline(std::cin,buffer);
                    std::getline(std::cin,title);
                    Document d;
                    d = myLibrary->searchDoc(title);
                    if(d.getTitle()=="Inconnu")
                    {
                        std::cout<<"Document inconnu, suppression annulée"<<std::endl;
                    }
                    else
                    {
                        myLibrary->deleteDoc(&d); //on le supprime de la bibliotheque
                        dell(d.getTitle()); //on le supprime du fichier
                        std::cout<<"Document supprimé"<<std::endl;
                    }
                    break;
                }
            case 3 :
                {
                    //*****Rechercher un document*****
                    std::cout<<"Donnez le titre du document"<<std::endl;
                    std::string title, buffer;
                    std::getline(std::cin,buffer);
                    std::getline(std::cin,title);
                    Document d;
                    d = myLibrary->searchDoc(title);
                    if(d.getTitle()=="Inconnu")
                    {
                        std::cout<<"Document inconnu"<<std::endl;
                    }
                    else
                    {
                        std::cout<<"Document trouvé"<<std::endl;
                        std::cout<<"Title : "<<d.getAutor()<<std::endl;
                        std::cout<<"Autor : "<<d.getTitle()<<std::endl;
                    }
                    break;
                }
            case 4 :
                {
                    //*****Trier les documents*****
                    int iMenuSort = menuSort();
                    switch(iMenuSort)
                    {
                        case 1:
                            {
                                //*****Trier uniquement les Livres*****
                                 std::cout << "\n*** Sorting Book ***" << std::endl;
                                 myLibrary->sort(&sortingBook);
                                 std::vector<Document*> doc = myLibrary->getDoc();
                                 for(unsigned int i =0;i<doc.size();i++)
                                 {
                                     Book* book = dynamic_cast<Book*>(doc[i]);
                                     if(book)
                                     {
                                         std::cout<<"* "<<book->getTitle()<<" in "<<book->getEditorYear()<<std::endl;
                                     }
                                 }
                                break;
                            }
                        case 2 :
                            {
                                //*****Trier uniquement les CD*****
                                std::cout << "\n*** Sorting CD ***" << std::endl;
                                myLibrary->sort(&sortingCD);
                                myLibrary->sort(&sortingName);
                                std::vector<Document*> doc = myLibrary->getDoc();
                                for(unsigned int i =0;i<doc.size();i++)
                                {
                                    CD* cd = dynamic_cast<CD*>(doc[i]);
                                    if(cd)
                                    {
                                        std::cout<<"* "<<cd->getTitle()<<std::endl;
                                    }
                                }
                                break;
                            }
                        case 3 :
                            {
                                //*****Trier uniquement les Films*****
                                std::cout << "\n*** Sorting Movie ***" << std::endl;
                                myLibrary->sort(&sortingMovie);
                                myLibrary->sort(&sortingName);
                                std::vector<Document*> doc = myLibrary->getDoc();
                                for(unsigned int i =0;i<doc.size();i++)
                                {
                                    Movie* m = dynamic_cast<Movie*>(doc[i]);
                                    if(m)
                                    {
                                        std::cout<<"* "<<m->getTitle()<<std::endl;
                                    }
                                }
                                break;
                            }
                        case 4 :
                            {
                                //*****Trier par nom*****
                                std::cout << "\n*** Sorting by name ***" << std::endl;
                                myLibrary->sort(&sortingName);
                                std::vector<Document*> doc = myLibrary->getDoc();
                                for(unsigned int i =0;i<doc.size();i++)
                                {
                                    std::cout<<"* "<<doc[i]->getTitle()<<std::endl;
                                }
                                break;
                            }
                        case 5 :
                            {
                                //*****Trier par auteur*****
                                std::cout << "\n*** Sorting by autor ***" << std::endl;
                                myLibrary->sort(&sortingAutor);
                                std::vector<Document*> doc = myLibrary->getDoc();
                                for(unsigned int i =0;i<doc.size();i++)
                                {
                                    std::cout<<"* "<<doc[i]->getTitle()<<" by "<<doc[i]->getAutor()<<std::endl;
                                }
                                break;
                            }
                        default :
                            {
                                //*****On annule*****
                                std::cout<<"Tri annulé"<<std::endl;
                                break;
                            }
                    }

                    break;
                }
            case 5 :
                {
                    //*****Export HTML*****
                    myLibrary->exportHTML();
                    std::cout<<"Export effectué : ouvrez le fichier index.html"<<std::endl;
                    break;
                }
            case 6 :
                {
                    myLibrary->showDoc();
                    break;
                }
            case 0 :
                {
                    //*****Quitter*****
                    break;
                }
            default :
            {
                std::cout<<"Nous n'avons pas compris votre demande"<<std::endl;
                std::cout<<"Veuillez saisir un chiffre entre 1 et 5"<<std::endl;
                //sleep(3);
                break;
            }
        }
    }

    return 0;
}
