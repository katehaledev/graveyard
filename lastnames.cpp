#include "lastnames.h"

bool LastNames::addName(std::string name)
{
    try
    {
        if (it != names.back())
        {
            it = names.back();
        }
        it = names.insert(it, name);

    }
    catch (const std::exception e)
    {
        // TODO: logger
        std::cout << "There was an error when attempting to add a new last name to LastNames." << std::endl;
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

LastNames::LastNames(std::vector<std::string> v) : names(v)
{
    it = names.begin();
}

LastNames::~LastNames()
{
    names.clear();
    delete &names;
}
