#ifndef CMD_ALTAENTREVISTA_H
#define CMD_ALTAENTREVISTA_H

#include <exception>

class cmdAltaEntrevista : public IComando
{
    public:
        cmdAltaEntrevista();
        void ejecutarComando();
        ~cmdAltaEntrevista();
};

#endif // CMD_ALTAENTREVISTA_H
