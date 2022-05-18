#ifndef THEREGULATORS_REGULATOR_H
#define THEREGULATORS_REGULATOR_H

#include "pomieszczenie.h"
#include "heater.h"


struct InvalidRoomPtr : public std::exception{
    const char * what () const throw (){
        return "roomPtr is null or nullptr";
    }
};
struct InvalidHeaterPtr : public std::exception{
    const char * what () const throw (){
        return "heaterPtr is null or nullptr";
    }
};




class Regulator{
public:
//    enable creating without valid pointers, may be vulnerable
    Regulator(float desiredTemp,Pomieszczenie* roomPtr= nullptr,Heater* heaterPtr= nullptr)
    : setTemp_(desiredTemp),roomPtr_(roomPtr),heaterPtr_(heaterPtr){}

    Regulator() = default;

    void setParameters(float desiredTemp,Pomieszczenie* roomPtr,Heater* heaterPtr){
        setTemp_ =desiredTemp;
        roomPtr_=roomPtr;
        roomPtr_=roomPtr;
    }

    virtual float control(float dt) = 0;

protected:
    float setTemp_;
    Pomieszczenie* roomPtr_;
    Heater* heaterPtr_;
};
#endif //THEREGULATORS_REGULATOR_H
