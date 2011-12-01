#ifndef LIBRARY_H
#define LIBRARY_H


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
         * \param Document the document to add
        */
        void addDoc(Document*);

        /**
         * \brief Delete a document
         * \param Document the document to delete
        */
        void deleteDoc(Document*);

        /**
         * \brief Export to HTML file all the documents stored in the class
        */
        void exportHTML();


    protected:
        std::vector<Document*> _biblio;
};

#endif // LIBRARY_H
