#ifndef LASTNAMES_H
#define LASTNAMES_H

#include <string>
#include <vector>
#include <iostream>

/**
 * @brief The LastNames class A class that allows for the tracking of last names - such as for maiden names or
 * previous married names.
 */
class LastNames
{
public:
    LastNames(std::vector<std::string> v);
    ~LastNames();

    /**
     * @brief addName Add a single last name to a Sim's last name history.
     * @param name the name to add
     * @return if successful, return True. False otherwise.
     */
    bool addName(std::string name);

    /**
     * @brief numberOfNames Get the number of last names a Sim has had.
     * @return the number of names, or -1 if there was an issue
     */
    size_t numberOfNames();


    /**
     * @brief removeName Remove a name. Useful for spelling errors or mistakes.
     * @param index where the name is in the list of names
     * @return the name that was removed
     */
    std::string removeName(int index);

    /**
     * @brief removeAllNames Clear out all names
     * @return True if successful, False otherwise
     */
    bool removeAllNames();

    /**
     * @brief mostRecentLastName Get the last name added to the names list.
     * @return the last name, without removing it from the lis. Or an empty string if unsuccessful.
     */
    std::string mostRecentLastName();

    /**
     * @brief getAllNames
     * @return A vector of all names. Returns an empty vector is unsuccessful.
     */
    std::vector<std::string> getAllNames();

private:
    std::vector<std::string> names;
    std::vector<std::string>::iterator it;
};

#endif // LASTNAMES_H
