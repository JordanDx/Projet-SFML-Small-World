#ifndef PEUPLES_H
#define PEUPLES_H


class Peuples
{
    public:
        Peuples();
        virtual ~Peuples();
        void ajouterPeuple();

    protected:

    private:
        vector<Peuple> peuples;

};

#endif // PEUPLES_H
