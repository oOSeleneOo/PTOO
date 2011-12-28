#ifndef LIBRARY_H
#define LIBRARY_H
#include "Document.h"
#include "vector"

class Library
{
    public:

        /**
        * \brief Add a new library in the class
        */
        Library();

        /**
        * \brief Destructor
        */
        virtual ~Library();

        /**
        * \brief Add a document in the library
        * \param doc the document to add
        */
        void addDoc(Document* doc);

        /**
        * \brief Delete a document
        * \param doc the document to delete
        */
        void deleteDoc(Document* doc);

        /**
        * \brief Export to HTML file all the documents stored in the class
        */
        void exportHTML();

        /**
        * \brief Search a document
        * \param title the title of the document
        * \return a Document
        */
        Document& searchDoc(std::string title);

        /**
        * \brief Return the number of documents
        * \return the number of document
        */
        int numberDocument() const;

        /**
        \brief Sort the document stored in the class
        \param f A pointer to the function that will proceed the sort algorithm

        The signature of the function must be bool func(Document*, Document*) to
        allow the sort of the Document.
        */
        void sort(bool (*f)(Document*, Document*));

        /**
        \brief Return a vector including all the document matching the name
        \param name The name of the Document
        \return A vector of Document pointer
        */
        std::vector<Document*>& search(std::string name);


        void showDoc();

    protected:
        std::vector<Document*> _biblio;
};

#endif // LIBRARY_H
