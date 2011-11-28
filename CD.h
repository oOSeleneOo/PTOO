#ifndef CD_H
#define CD_H


class CD : public Document
{
    public:
        CD();
        CD(std::string, int);
        void setStyle(std::string);
        void setPisteNumber(std::string);
        std::string getStyle() const;
        int getPisteNumber() const;
        virtual ~CD();

    protected:
        std::string _style;
        int _pisteNumber;
};

#endif // CD_H
