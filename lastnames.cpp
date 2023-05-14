#include "lastnames.h"

bool LastNames::addName(std::string name)
{
    bool result = false;
    try
    {
        it = names.insert(names.end(), name);
        result = true;

    }
    catch (const std::exception e)
    {
        // TODO: logger
        std::cout << "There was an error when attempting to add a new last name to LastNames." << std::endl;
        std::cout << "Exception: " << e.what() << std::endl;

        result = false;
    }

    return result;

}

size_t LastNames::numberOfNames()
{
    size_t result = -1;
    try
    {
        result = names.size();
    }
    catch (const std::exception e)
    {
        std::cout << "There was an error when attempting get the number of names from LastNames" << std::endl;
        std::cout << "Exception: " << e.what() << std::endl;

        result = -1;
    }

    return result;
}

std::string LastNames::removeName(int index)
{
    std::string result = "";
    try
    {
        result = names.at(index);
        names.erase(names.begin() + index);
        names.shrink_to_fit();
    }
    catch (const std::exception e)
    {
        std::cout << "There was an error when attempting remove a name from LastNames" << std::endl;
        std::cout << "Exception: " << e.what() << std::endl;

        result = "";
    }

    return result;
}

bool LastNames::removeAllNames()
{
    bool result = false;

    try
    {
        names.clear();
        result = true;
    }
    catch(std::exception e)
    {
        std::cout << "There was an error when attempting remove all names from LastNames" << std::endl;
        std::cout << "Exception: " << e.what() << std::endl;

        result = false;
    }

    return result;
}

std::string LastNames::mostRecentLastName()
{
    std::string result = "";

    try
    {
        result = names.back();
        names.pop_back();

    }
    catch (std::exception e)
    {
        std::cout << "There was an error when attempting to remove the most recent name from LastNames" << std::endl;
        std::cout << "Exception: " << e.what() << std::endl;

        result = "";
    }

    return result;
}

std::vector<std::string> LastNames::getAllNames()
{
    std::vector<std::string> result;

    try
    {
        result = names;

    }
    catch (std::exception e)
    {
        std::cout << "There was an error when attempting to grab all names from LastNames" << std::endl;
        std::cout << "Exception: " << e.what() << std::endl;

        result = {};
    }

    return result;
}

LastNames::LastNames(std::vector<std::string> v) : names(v)
{
    // Make an iterator to make life easier
    it = names.begin();
}

LastNames::~LastNames()
{
    names.clear();
    names.shrink_to_fit();
    delete &names;
}
