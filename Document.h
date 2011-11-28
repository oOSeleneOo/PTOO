#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <string>

class Document
{
    public:
        Document(std::string, std::string);
        virtual ~Document();
        void setTitle(const std::string&);
        void setAutor(const std::string&);
        std::string getTitle() const;
        std::string getAutor() const;

    protected:
        std::string _title;
        std::string _autor;
};

#endif // DOCUMENT_H
