#ifndef BOOK_H
#define BOOK_H
#include "Document.h"

class Book : public Document
{

    public:

        /**
        * \brief Add a new book in the class
        */
        Book();

        /**
        * \brief Add a new book in the class
        * \param resume A resume of the book
        * \param editorYear the year of parution
        * \param editor the editor of the book
        */
        Book(std::string title, std::string autor, std::string resume, int editorYear, std::string editor);

        /**
        * \brief Set the resume
        * \param resume the new resume
        */
        void setResume(std::string& resume);

        /**
        * \brief Set the editor year
        * \param year the new editor year
        */
        void setEditorYear(int& year);

        /**
        * \brief Set the editor
        * \param editor the new editor
        */
        void setEditor(std::string& editor);

        /**
        * \brief Return the resume
        * \return the resume of the book
        */
        std::string getResume() const;

        /**
        * \brief Return the editor year
        * \return the editor year
        */
        int getEditoYear() const;

        /**
        * \brief Return the editor
        * \return the editor
        */
        std::string getEditor() const;

        /**
        * \brief Destructor
        */
        virtual ~Book();

    protected:
        std::string _resume;
        int _editorYear;
        std::string _editor;
};

#endif // BOOK_H
