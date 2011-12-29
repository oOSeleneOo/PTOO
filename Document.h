#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <string>

/**
 * \file    Document.h
 * \author  Dutin Laure & Couradet Vanessa
 * \brief   Definition of Document class
 */

class Document
{
    public:

        /**
        * \brief Add a new document in the class
        * \param title the title of the document
        * \param autor the autor of the document
        */
        Document(std::string title, std::string autor);

        /**
        * \brief Add a new document in the class
        *   is the default constructor
        */
        Document();

        /**
        * \brief Destructor
        */
        virtual ~Document();

        /**
        * \brief Set the title of the document
        * \param title the new title
        */
        void setTitle(const std::string& title);

        /**
        * \brief Set the autor of the document
        * \param autor the new autor
        */
        void setAutor(const std::string& autor);

        /**
        * \brief Return the title
        * \return the title of the document
        */
        std::string getTitle() const;

        /**
        * \brief Return the autor
        * \return the autor of the document
        */
        std::string getAutor() const;

    protected:
        std::string _title;
        std::string _autor;
};

#endif // DOCUMENT_H
