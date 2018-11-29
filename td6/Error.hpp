#include "iostream"
#include "exception"

class Error : public std::exception
{
	private:
		int _niveau;
		int _code;
		std::string _file;
		int _line;
		std::string _message;

	public:
		Error();
		Error(const int n, const int c, std::string f, int l, const char *m);
		virtual ~Error();
		
		inline int getNiveau() {
			return _niveau;
		}

		inline int getCode() {
			return _code;
		}

		inline std::string getFile() {
			return _file;
		}

		inline int getLine() {
			return _line;
		}

		const char* what() const noexcept;

};