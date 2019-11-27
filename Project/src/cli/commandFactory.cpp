#include <cli/commandFactory.h>

/* Animal factory constructor.
Register the types of animals here.
*/

FactoryMap CommandFactory::m_FactoryMap = init_map();

FactoryMap CommandFactory::init_map(){
    FactoryMap commands_map;
    commands_map["new"] = new CommandNew();
    return commands_map;
}

ICommand *CommandFactory::CreateCommand(const std::string &commandName)
{
    FactoryMap::iterator it = m_FactoryMap.find(commandName);
    if( it != m_FactoryMap.end() )
    return it->second;
    return NULL;
}