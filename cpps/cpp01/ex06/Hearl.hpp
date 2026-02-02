#include <iostream>

class Hearl
{
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
    public:
        Hearl();
        ~Hearl();
        void complain( std::string level );
};
