#ifndef CD_H
#define CD_H
#include "Document.h"

class CD : public Document
{
    public:

        /**
        * \brief Add a new CD in the class
        */
        CD();

        /**
        * \brief Add a new book in the class
        * \param style style of the CD
        * \param pisteNumber the number of piste
        */
        CD(std::string title, std::string autor, std::string style, int pisteNumber);

        /**
        * \brief Set the style
        * \param style the new style
        */
        void setStyle(std::string& style);

        /**
        * \brief Set the pisteNumber
        * \param pisteNumber the new number of piste
        */
        void setPisteNumber(int& pisteNumber);

        /**
        * \brief Return the style
        * \return the style of the CD
        */
        std::string getStyle() const;

        /**
        * \brief Return the number of piste
        * \return the number of piste
        */
        int getPisteNumber() const;

        /**
        * \brief Destructor
        */
        virtual ~CD();

    protected:
        std::string _style;
        int _pisteNumber;
};

#endif // CD_H
