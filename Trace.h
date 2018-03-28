/**
*\file Trace.h
*\author Salvatore Muoio
*/
#ifndef __TRACE_H__
#define __TRACE_H__
#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>


namespace trace
{
	typedef enum
	{
		basic,    /*< basic level*/
		verbose,  /*< verbose level*/
		warning,  /*< warning level*/
		info  = 4,     /*< info level*/
		error = 8,    /*< error level*/
	}e_tracelevel;

	template <class TraceString, class TraceType> void TraceInfo(TraceString &string, TraceType info)
	{
		std::cout<<string;
		std::cout<<" "<<info<<std::endl;
	}

}//namespace

extern std::ofstream logfile;

class Trace
{
  private:
		std::ostringstream _buffer;
		//std::ofstream logfile ("log_shared_memory.txt", std::ofstream::out);
		trace::e_tracelevel lTracelevel;
	public:
	Trace(trace::e_tracelevel tracelevel = trace::basic)
	{
		_buffer << tracelevel <<":"
		        <<std::string(1,' ');
		//logfile << tracelevel<< ":"<<std::endl;

	}
	template <typename T> Trace &operator<<(T const & value)
	{
		std::time_t t = std::time(0);
		char *dt = ctime(&t);
		_buffer << value;
		logfile << value<<dt<<std::endl;
		return(*this);
	}
	~Trace(void)
	{
		_buffer <<std::endl;
		std::cerr<<_buffer.str();
		logfile.close();
	};
	void TraceSetLevel(trace::e_tracelevel tracelevel)
	{
		lTracelevel = tracelevel;
	}
};

extern trace::e_tracelevel leveltrace;
#define log(level)\
         Trace(level)


#endif
