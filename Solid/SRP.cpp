/*SRP - Single Responsibility Principle*/

#include <string>
#include <vector>
#include <fstream>

struct Journal
{
	std::string title;
	std::vector <std::string> entries;

	explicit Journal(const std::string& title) : title {title}
	{

	}

	void add(const std::string& entry)
	{
		entries.push_back(entry);
	}

	// Not a function of Journal. Move to PersistenceManager
	/*void save(const std::string& filename)
	{
		std::ofstream ofs(filename);
		for(auto& s : entries)
			ofs << s << std::endl;
	}*/
};

struct PersistanceManager
{
	static void save(const Journal& j, const std::string& filename)
	{
		std::ofstream ofs(filename);
		for(auto& s : j.entries)
			ofs << s << std::endl;
	}
};
