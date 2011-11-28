#ifndef BOOK_H
#define BOOK_H


class Book : public Document
{

    public:

        /**
         * \brief Add a new book in the class
        */
        Book();

        /**
         * \brief Add a new book in the class
         * \param string A resume of the book
         * \param int the year of parution
         * \param string the editor of the book
        */
        Book(std::string, int, std::string);

        /**
         * \brief Set the resume
         * \param string the new resume
        */
        void setResume(std::string);

        /**
         * \brief Set the editor year
         * \param int the new editor year
        */
        void setEditorYear(int);

        /**
         * \brief Set the editor
         * \param string the new editor
        */
        void setEditor(std::string);

        /**
         * \brief Return the resume
         * \return string the resume of the book
        */
        std::string getResume() const;

        /**
         * \brief Return the editor year
         * \return int the editor year
        */
        int getEditoYear() const;

        /**
         * \brief Return the editor
         * \return string the editor
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
