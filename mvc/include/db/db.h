#include <vector>

template<class T>
class DB
{
public:
	DB();
	~DB();
	bool append(std::string name, int id, T item);
	bool remove(std::string name);

	bool add(T item);
	bool add(std::string name, T item);

	T getItem(int id);
	T getItem(std::string name);
private:
	std::map<std::string, int> mapNameId;
	std::map<int, T> mapIdDna;
};

template<class T>
DB<T>::DB() { }

template<class T>
inline bool DB<T>::append(std::string name, int id, T item)
{
	mapNameId.insert(std::pair<std::string, int>(name, id));
	mapIdDna.insert(std::pair<int, T>(id, item));
	return true;
}

template<class T>
T DB<T>::getItem(int id)
{
	return mapIdDna[id];
}

template<class T>
T DB<T>::getItem(std::string name)
{
	return mapIdDna[(mapNameId[name])];
}

// inline bool DB::remove(std::string name)
// {

// }