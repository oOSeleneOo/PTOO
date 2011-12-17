#include "Book.h"

Book::Book() : Document(),
    _resume(NULL),
    _editorYear(0),
    _editor(NULL)
{
}

Book::~Book()
{

}

Book::Book(std::string title, std::string autor, std::string resume, int year, std::string editor) : Document(title, autor),
    _resume(resume),
    _editorYear(year),
    _editor(editor)
 {
 }

void Book::setResume(std::string& resume)
{
    _resume = resume;
}

void Book::setEditorYear(int& year)
{
    _editorYear = year;
}

void Book::setEditor(std::string& editor)
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
