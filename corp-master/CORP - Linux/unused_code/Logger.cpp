#include "Logger.h"
#include "stdexcept"

const std::string Logger::fileName = "log.txt";
Logger* Logger::pointMainLog = nullptr;

Logger& Logger::mainLog()		//creates new Logger object
{ 
	static Reset cleanup;
	if (pointMainLog == nullptr)
		pointMainLog = new Logger();
	return *pointMainLog;
}

Logger::Reset::~Reset()
{
	delete Logger::pointMainLog;
	Logger::pointMainLog == nullptr;
}

Logger::~Logger()				//close the log object
{
	outputStream.close();
}

Logger::Logger()				//Initialize the log object
{
	outputStream.open(fileName);
	if (!outputStream.good()) {
		throw std::runtime_error("Unable to initialize the log!");
	}
}

void Logger::log(const std::string& message)
								//Writes the given log message to the file
{
	//std::lock_guard<std::mutex> guard(logMutex);
	logHelper(message);
}

void Logger::logHelper(const std::string& inMessage)
{
	outputStream << "Log: " << inMessage << std::endl;
}