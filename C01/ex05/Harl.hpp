#include <iostream>

class Harl {
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

	public:
		std::string _debugMssg;
		std::string _infoMssg;
		std::string _warningMssg;
		std::string _errorMssg;
		Harl();
		~Harl();
		void complain( std::string level );
		
	typedef void (Harl::*HarlMemberFunction)();
};

struct FunctionMap
{
    const char* name;
    Harl::HarlMemberFunction function;
};

