#ifndef GENDER_H
#define GENDER_H

#include <map>
#include <string>
#include <exception>
#include <iostream>

class Gender final
{
public:
    Gender();
    ~Gender();

    /**
     * @brief addAGender, Adds a custom gender to the list.
     * @param gen a gender, such as "Zie"
     * @param pronouns, such as "zie/zim"
     * @return
     */
    std::string addAGender(std::string gen, std::string pronouns);

    /**
     * @brief removeAGender, Remove a gender from the list.
     * @param g_key, the gender to remove (i.e. "female")
     * @return the number of removed items (1 or 0), or -1 if there was an error
     */
    size_t removeAGender(const std::string g_key);

    /**
     * @brief removeAllGenders, clear out the list of genders (default AND custom)
     * @return the number of removed items, or -1 if there was an error
     */
    size_t removeAllGenders();

    /**
     * @brief getPronouns, get the pronouns of a gender
     * @param gen, the gender to look up (i.e. "male")
     * @return the pronouns used for said gender
     */
    std::string getPronouns(const std::string gen);

    /**
     * @brief reset, reset back to the default genders of "male", "female", and "nonbinary"
     * @return the number of items removed, or -1 if there was an error
     */
    size_t reset();

private:
    /**
     * @brief genders
     * Key = gender (i.e. female, male, nonbinary)
     * Value = pronoun (i.e. she/her, him/he, they/them)
     */
    std::map<std::string, std::string> genders;

    /**
     * @brief setDefaultGenders A basic list of genders, including female, male, and nonbinary with matching
     * pronons
     */
    void setDefaultGenders();
};

#endif // GENDER_H
