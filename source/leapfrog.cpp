#include "geometry.hpp"

using namespace std;
using namespace arma;

//  Standard leapfrog:
//  K/2
//  for (Nt-1) times:
//    S
//    K
//  S
//  K/2
void Geom24::leapfrog(const int& Nt, const double& dt)
{
    for(int i=0; i<nHL; ++i)
        mat[i] += (dt/2.)*mom[i];

    for(int j=0; j<Nt-1; ++j)
    {
        for(int i=0; i<nHL; ++i)
            mom[i] += -dt*der_dirac4(i, true);
        for(int i=0; i<nHL; ++i)
            mat[i] += dt*mom[i];
    }
    
    for(int i=0; i<nHL; ++i)
        mom[i] += -dt*der_dirac24(i, true);
    for(int i=0; i<nHL; ++i)
        mat[i] += (dt/2.)*mom[i];
}
