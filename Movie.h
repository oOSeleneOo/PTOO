#ifndef MOVIE_H
#define MOVIE_H
#include "Document.h"

class Movie : public Document
{

public:
    Movie();
    Movie(std::string title, std::string autor, std::string resume, std::string style, std::string actor);
    virtual ~Movie();
    void setResume(std::string& resume);
    void setStyle(std::string& style);
    void setActor(std::string& actor);
    std::string getResume() const;
    std::string getStyle() const;
    std::string getActor() const;


protected:
    std::string _resume;
    std::string _style;
    std::string _actor;

};


#endif // MOVIE_H
