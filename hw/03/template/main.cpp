#include <cmath>
#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdint>
#include <string>
#include <type_traits>
#include <utility>

#include "main.hpp"


Item::Item(const std::string& name, const std::string& year) :
    name(name), year(year)
{
    static uint32_t id = 1;
    this->ID = id++;
}

Book::Book(const std::string& name, const std::string& author, const std::string& year) :
    Item(name, year), m_author(author)
{
}

void Book::getAsStr(std::string& str) const
{
    str += (std::to_string(ID) + ": " + name + ", "+ m_author + ", " + year);
}


void Book::getData(std::string& name, std::string& info) const
{
    name = this->name;
    info = this->year + ", " + m_author;
}


bool Book::contains(const std::string& str) const
{
    for (const auto& token : {m_author, name, year})
    {
        if (token.find(str) != std::string::npos)
            return true;
    }
    return false;
}

Journal::Journal(const std::string& name, const std::string& volume, const std::string& issue, const std::string& year) :
    Item(name, year), m_volume(volume), m_issue(issue)
{
}


void Journal::getAsStr(std::string& str) const
{
    str += (std::to_string(ID) + ": " + name + ", "+ m_volume + ", " + m_issue + ", " + year);
}


void Journal::getData(std::string& name, std::string& info) const
{
    name = this->name;
    info = this->year + ", " + m_volume + '(' + m_issue + ')';
}

bool Journal::contains(const std::string& str) const
{
    for (const auto& token : {m_volume, m_issue, name, year})
    {
        if (token.find(str) != std::string::npos)
            return true;
    }
    return false;
}

Database::Database(){
	// Database constructor
}

// add item to the database
void Database::add(const Item* const item)
{
    m_db.push_back(item);
}

void Database::list() const
{
    DatabasePrinter::printHeader(std::cout, "List of all records");
    DatabasePrinter::printSeparator(std::cout);
    for (const auto& item : m_db)
    {
        std::string name, info;
        item->getData(name, info);
        DatabasePrinter::printItem(std::cout, item->ID, name, info);
        DatabasePrinter::printSeparator(std::cout);
    }
    DatabasePrinter::printFooter(std::cout, this->getSize());
}

void Database::removeItem(const uint32_t id)
{
    auto match = std::find_if(m_db.begin(), m_db.end(), [&](const Item* item) { return (uint32_t)item->ID == id; });

    if (match != m_db.end())
        m_db.erase(match);
    else
        ProcessorPrinter::printBox(std::cout, "ID = " + std::to_string(id) + " is not in the database");
}

void Database::find(const std::string& str)
{
    uint32_t count = 0;
    DatabasePrinter::printHeader(std::cout, "List of all records");
    DatabasePrinter::printSeparator(std::cout);
    for (const auto& item : m_db)
    {
        if (item->contains(str))
        {
            std::string name, info;
            item->getData(name, info);
            DatabasePrinter::printItem(std::cout, item->ID, name, info);
            DatabasePrinter::printSeparator(std::cout);
            count++;
        }
    }
    DatabasePrinter::printFooter(std::cout, count);
}

void Database::erase(const std::string& text)
{
    auto newEnd = std::remove_if(m_db.begin(), m_db.end(), [&](const Item* item) { return item->contains(text); });
    m_db.erase(newEnd, m_db.end());
}

void Database::sort(const std::string& key, bool asc)
{
    auto compareItems = [&](const Item* lhs, const Item* rhs) {
        if (key == "name")
        {
            if (lhs->name == rhs->name)
                return (asc) ? lhs->ID < rhs->ID : lhs->ID > rhs->ID;
            return lhs->name < rhs->name;
        } 
        else if (key == "year")
        {
            if (lhs->year == rhs->year)
                return (asc) ? lhs->ID < rhs->ID : lhs->ID > rhs->ID;
            return lhs->year < rhs->year;
        }
        else
        {
            return lhs->ID < rhs->ID;
        }
    };

    if (asc)
        std::sort(m_db.begin(), m_db.end(), compareItems);
    else
        std::sort(m_db.rbegin(), m_db.rend(), compareItems);
}

// definition of the sort function according to name
// bool sort_name::operator()(const Item *a, const Item * b){

//}

Database::~Database(){
    for (auto i = m_db.begin(); i != m_db.end(); i++)
        delete *i;
    m_db.clear();
}

void DatabasePrinter::printItem(std::ostream& os, const uint32_t id, const std::string& name, const std::string& info)
{
    os << "| "
       << std::right
       << std::setw(2)
       << id
       << " | "
       << std::left
       << std::setw(52)
       << name
       << "|\n"
       << "| "
       << std::right
       << std::setw(2)
       << ""
       << " | "
       << std::left
       << std::setw(52)
       << info
       << "|\n";
}

void DatabasePrinter::printLine(std::ostream& os, const uint32_t len)
{
    os << '+' << std::string(len, '-') << '+';
}

void DatabasePrinter::printSeparator(std::ostream& os)
{
    os << "+----";
    printLine(os, 53);
    os << '\n';
}

void DatabasePrinter::printFooter(std::ostream& os, const uint32_t count)
{
    os << "| "
       << std::left
       << std::setw(57)
       << std::string("Total: " + std::to_string(count))
       << "|\n";
    printLine(os, 58);
    os << '\n';
}

void DatabasePrinter::printHeader(std::ostream& os, const std::string& message)
{
    printLine(os, 58);
    os << '\n';
    os << "| "
       << std::left
       << std::setw(57)
       << message
       << "|\n";
}


void ProcessorPrinter::printBox(std::ostream& os, const std::string& message)
{
    DatabasePrinter::printLine(os, 58);
    os << "\n| "
       << std::left
       << std::setw(57)
       << message
       << "|\n";
    DatabasePrinter::printLine(os, 58);
    os << '\n';
}


Processor::Processor(Database& db) :
    m_rDb(db)
{
}


void Processor::interpret(const std::string& command)
{
    std::size_t position = command.find(':');
    if (position != std::string::npos)
        execute(command.substr(0, position), command.substr(position + 1, command.size()));
    else 
        execute(command, {});
}


void Processor::execute(const std::string& commandName, const std::string& commandOpt)
{
    if (!commandName.compare("list"))
        list();
    else if (!commandName.compare("remove"))
    {
        if (commandOpt.size() == 0)
        {
            ProcessorPrinter::printBox(std::cout, "Command \"remove\" expects some argument");
            return;
        }
        remove(std::stoi(commandOpt));
    }
    else if (!commandName.compare("find"))
    {
        if (commandOpt.size() == 0)
        {
            ProcessorPrinter::printBox(std::cout, "Command \"find\" expects some argument");
            return;
        }
        find(commandOpt);
    }
    else if (!commandName.compare("exit"))
    {
        std::exit(EXIT_SUCCESS);
    }
    else if (!commandName.compare("erase"))
    {
        if (commandOpt.size() == 0)
        {
            ProcessorPrinter::printBox(std::cout, "Command \"erase\" expects some argument");
            return;
        }
        erase(commandOpt);
    }
    else if (!commandName.compare("sort"))
    {
        std::size_t position2 = commandOpt.find(':');
        std::string name = {};
        std::string method = "asc";
        if (position2 != std::string::npos)
        {
            name = commandOpt.substr(0, position2);
            method = commandOpt.substr(position2 + 1, commandOpt.size());
        }
        else
        {
            name = commandOpt;
        }
        if (commandOpt.size() == 0)
        {
            ProcessorPrinter::printBox(std::cout, "Command \"sort\" expects some argument");
            return;
        }
        sort(name, method);
    }
    else
    {
        ProcessorPrinter::printBox(std::cout, "Unknown command \"" + commandName + "\"");
        return;
    }
}

void Processor::list()
{
    m_rDb.list();
}

void Processor::remove(const uint32_t id)
{
    m_rDb.removeItem(id);
}

void Processor::find(const std::string& text)
{
    m_rDb.find(text);
}

void Processor::erase(const std::string& text)
{
    m_rDb.erase(text);
}

void Processor::sort(const std::string& name, const std::string& method)
{
    m_rDb.sort(name, ((!method.compare("asc")) ? true : false));
}


int main() {
    Database db;
    Processor processor(db);

    db.add(new Journal("IEEE Transaction on Computers", "C-35", "10", "1986"));
    db.add(new Journal("IEEE Transaction on Computers", "C-35", "11", "1986"));
    db.add(new Journal("IEEE Transactions on Communications", "28", "8", "1980"));
    db.add(new Book("Dva roky prazdnin", "Jules Verne", "1888"));
    db.add(new Book("Tajuplny ostrov", "Jules Verne", "1874"));
    db.add(new Book("Ocelove mesto", "Jules Verne", "1879"));

    std::string command;
    while (std::getline(std::cin, command))
    {
        processor.interpret(command);
    }
    return 0;
}
