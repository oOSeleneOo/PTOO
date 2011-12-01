#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <string>

class Document
{
    public:

        /**
         * \brief Add a new document in the class
         * \param string the title of the document
         * \param string the autor of the document
        */
        Document(std::string, std::string);

        /**
         * \brief Destructor
        */
        virtual ~Document();

        /**
         * \brief Set the title of the document
         * \param string the new title
        */
        void setTitle(const std::string&);

        /**
         * \brief Set the autor of the document
         * \param string the new autor
        */
        void setAutor(const std::string&);

        /**
         * \brief Return the title
         * \return string the title of the document
        */
        std::string getTitle() const;

        /**
         * \brief Return the autor
         * \return string the autor of the document
        */
        std::string getAutor() const;

    protected:
        std::string _title;
        std::string _autor;
};

#endif // DOCUMENT_H
