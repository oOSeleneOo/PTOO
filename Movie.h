#ifndef MOVIE_H
#define MOVIE_H
#include "Document.h"

/**
 * \file    Movie.h
 * \author  Dutin Laure & Couradet Vanessa
 * \brief   Definition of Movie class
 */

class Movie : public Document
{

    public:

        /**
        * \brief Add a new Movie in the class
        */
        Movie();

        /**
        * \brief Add a new Movie in the class
        * \param title the title of the movie
        * \param autor the autor of the movie
        * \param resume a resume of the movie
        * \param style the style of the movie
        * \param actor some actors of the movie
        */
        Movie(std::string title, std::string autor, std::string resume, std::string style, std::string actor);

        /**
        * \brief Destructor
        */
        virtual ~Movie();

        /**
        * \brief Set the resume
        * \param resume the new resume
        */
        void setResume(const std::string& resume);

        /**
        * \brief Set the style
        * \param style the new style
        */
        void setStyle(const std::string& style);

        /**
        * \brief Set the actor
        * \param actor the new list of actors
        */
        void setActor(const std::string& actor);

        /**
        * \brief Retrun the resume
        * \return the resume of the movie
        */
        std::string getResume() const;

        /**
        * \brief Return the style
        * \return the style of the movie
        */
        std::string getStyle() const;

        /**
        * \brief Return the actor
        * \return the actors of the movie
        */
        std::string getActor() const;

    protected:
        std::string _resume;
        std::string _style;
        std::string _actor;

};


#endif // MOVIE_H
