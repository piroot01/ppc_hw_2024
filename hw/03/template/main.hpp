#include <complex>
#include <ostream>
#include <vector>
#include <string>
#include <cstdint>
#include <iomanip>

#ifndef __MAIN_HPP__
#define __MAIN_HPP__

struct sort_name;

class Database;

class Item 
{
protected:
    int ID;
    std::string name = {};
    std::string year = {};

public:
    Item(const std::string& name, const std::string& year);

    virtual ~Item () = default;

    virtual void getAsStr(std::string& str) const = 0;

    virtual void getData(std::string& name, std::string& info) const = 0;

    virtual bool contains(const std::string& str) const = 0;

public:
    friend sort_name;
    friend Database;

};

// Book related to the Database
class Book : public Item
{
public:
    Book(const std::string& name, const std::string& author, const std::string& year);

    void getAsStr(std::string& str) const override;

    void getData(std::string& name, std::string& info) const override;

    bool contains(const std::string& str) const override;

private:
    std::string m_author;

};

// Journal related to the Database
class Journal : public Item
{
public:
    Journal(const std::string& name, const std::string& volume, const std::string& issue, const std::string& year);

    void getAsStr(std::string& str) const override;

    void getData(std::string& name, std::string& info) const override;

    bool contains(const std::string& str) const override;

private:
    std::string m_volume;
    std::string m_issue;

};

class Printer;

class Database {
private:
    std::vector<const Item*> m_db;

public:
    Database() = default;

    ~Database();

    void add(const Item* const item);

    void list() const;

    void removeItem(const uint32_t id);

    void find(const std::string& text);

    void sort(const std::string& key, bool asc);

    void erase(const std::string& text);

    inline uint32_t getSize() const;

};


uint32_t Database::getSize() const
{
    return m_db.size();
}


class Printer
{
public:
    static void printItem(std::ostream& os, const uint32_t id, const std::string& name, const std::string& info);

    static void printLine(std::ostream& os, const uint32_t len);

    static void printSeparator(std::ostream& os);

    static void printFooter(std::ostream& os, const uint32_t count);

    static void printHeader(std::ostream& os, const std::string& message);

    static void printBox(std::ostream& os, const std::string& message);
};


class Processor
{
public:
    Processor(Database& db);

    void interpret(const std::string& command);

    void execute(const std::string& commandName, const std::string& commandOpt);

private:
    Database& m_rDb;

};

#endif // __MAIN_HPP__
