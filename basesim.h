#ifndef BASESIM_H
#define BASESIM_H

#include "lastnames.h"
#include "gender.h"

#include <string>
#include <iostream>
#include <map>

enum Sex { male, female};

class BaseSim
{
public:
    BaseSim(const std::string* firstName, const std::string* lastName);
   virtual ~BaseSim();

    // Setters
    virtual void setFirstName(std::string* fn);
    virtual void setLastName(std::string* ln);
    virtual void setBioParent1(BaseSim* p);
    virtual void setSex();
    virtual void addToLastNameHistory(std::string aLastname);
    virtual void setGender();

    // Getters
    virtual std::string* getFirstName() = 0;
    virtual std::string* getLastName() = 0;
    virtual BaseSim* getBioParent1() = 0;
    virtual std::string* getPreviousLastName() = 0;
    virtual LastNames::LastNames* getLastNameHistory() = 0;
    virtual std::map<std::string, std::string> getGender() = 0;

private:
    std::string* firstName;
    std::string* lastName;
    BaseSim* bioParent1;
    Sex sex;

};

#endif // BASESIM_H
