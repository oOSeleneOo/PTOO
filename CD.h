#ifndef CD_H
#define CD_H


class CD : public Document
{
    public:

        /**
         * \brief Add a new CD in the class
        */
        CD();

        /**
         * \brief Add a new book in the class
         * \param string style of the CD
         * \param int the number of piste
        */
        CD(std::string, int);

        /**
         * \brief Set the style
         * \param string the new style
        */
        void setStyle(std::string);

        /**
         * \brief Set the pisteNumber
         * \param int the new number of piste
        */
        void setPisteNumber(std::string);

        /**
         * \brief Return the style
         * \return string the style of the CD
        */
        std::string getStyle() const;

        /**
         * \brief Return the number of piste
         * \return int the number of piste
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
