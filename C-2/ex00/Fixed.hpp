#include <iostream>

class Fixed{
    public:
        Fixed(void);
        Fixed(Fixed const &copy);
        Fixed &operator=(const Fixed &copy);
        ~Fixed(void);
        int     getFixedValue(void) const;
        void    setFixedValue(const int raw);
    private:
        int                 _fixedpointvalue;
        static const int    _bits = 8;
};