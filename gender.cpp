#include "gender.h"

std::string Gender::addAGender(std::string gen, std::string pronouns){
    std::string result = "";
    try
    {
        genders.insert(genders.end(), {gen, pronouns});
        result = gen;
    }
    catch(std::exception e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
        result = "";
    }

    return result;
}

size_t Gender::removeAGender(const std::string g_key)
{
    auto result = 0;
    try
    {
        result = genders.erase(g_key);

    }
    catch(std::exception e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
        result = -1;
    }

    return result;
}

size_t Gender::removeAllGenders()
{
    auto result = -1;
    try
    {
        result = genders.size();
        genders.clear();

    }
    catch(std::exception e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
        result = -1;
    }

    return result;
}

std::string Gender::getPronouns(const std::string gen)
{
    std::string result;
    try
    {
        result = genders.at(gen);

    }
    catch(std::exception e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
        result = "";
    }

    return result;
}

size_t Gender::reset()
{
    auto result = -1;
    try
    {
        size_t total = removeAllGenders();
        if (total > 0)
        {
            setDefaultGenders();
            result = total - genders.size();
        }

    }
    catch(std::exception e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
        result = -1;
    }

    return result;
}

void Gender::setDefaultGenders()
{
    // Set all of the genders
    genders.insert(genders.end(), {"female", "she/her"});
    genders.insert(genders.end(), {"male", "he/him"});
    genders.insert(genders.end(), {"nonbinary", "they/them"});
}

Gender::Gender()
{
    setDefaultGenders();
}

Gender::~Gender()
{
    genders.clear();
    delete &genders;
}
