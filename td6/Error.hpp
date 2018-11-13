#include "iostream"
#include "exception"

class Error : public std::exception
{
	private:
		int _niveau;
		int _code;
		std::string _message;

	public:
		Error();
		Error(const int n, const int c, const char *m);
		virtual ~Error();
		
		inline int getNiveau() {
			return _niveau;
		}

		inline int getCode() {
			return _code;
		}

		const char* what() const noexcept;


};