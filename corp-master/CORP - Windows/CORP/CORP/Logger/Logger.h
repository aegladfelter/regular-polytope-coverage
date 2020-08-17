#ifndef _LOGGER_GUARD
#define _LOGGER_GUARD

#include <fstream>
#include <iostream>
#include <string>

class Logger
{

public:
	
							//reference to the main Logger object
	static Logger& mainLog();

							//Logs the message to the output file
	void log(const std::string& message);

protected:
							//Pointer to the Log object
	static Logger* pointMainLog;
	
	friend class Reset;
	class Reset
	{
	public:
		~Reset();
	};

	static const std::string fileName;

							//OutputStream can't be static, apparently
	std::ofstream outputStream;
	void logHelper(const std::string& message);

private:
							//Default Constructor
	Logger();
// ? virtual ?
	virtual ~Logger();

	Logger(const Logger&);
	Logger& operator=(const Logger&);
};

#endif // !_LOGGER_GUARD