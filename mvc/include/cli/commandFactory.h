#include <cli/command.h>
#include <map>

typedef std::map<std::string , ICommand*> FactoryMap;

// Factory for creating instances of ICommand
class CommandFactory
{
public:
    ~CommandFactory();
    static ICommand *CreateCommand(const std::string &commandName);
private:
    static FactoryMap m_FactoryMap;
    static FactoryMap init_map();
    CommandFactory();
};

inline CommandFactory::~CommandFactory() { m_FactoryMap.clear(); }