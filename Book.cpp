#include "Book.h"

Book::Book()
{

}

Book::~Book()
{

}

 Book::Book(std::string resume, int year, std::string editor)
 {
    _resume = resume;
    _editorYear = year;
    _editor = editor;
 }

void Book::setResume(std::string resume)
{
    _resume = resume;
}

void Book::setEditorYear(int year)
{
    _editorYear = year;
}

void Book::setEditor(std::string editor)
{
    _editor = editor;
}

std::string Book::getResume() const
{
    return _resume;
}

int Book::getEditoYear() const
{
    return _editorYear;
}

std::string Book::getEditor() const
{
    return _editor;
}
