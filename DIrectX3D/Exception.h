#pragma once
#include <exception>
#include <string>

class Exception : public std::exception
{
protected:
    std::string m_sMessage;
    std::string m_sName;
    std::string m_sBuffer;
    std::string m_sFile;
    int m_nLine;
public:
    Exception(std::string msg, int line, const char* file, std::string name = "Exception") noexcept;
    Exception(DWORD errCode, int line, const char* file, std::string name = "Exception") noexcept;
    virtual ~Exception() noexcept {}
    virtual const char* what() const noexcept;
    std::string name() const noexcept;
    std::string message() const noexcept;
    std::string file() const noexcept;

    // Translate error code returned from GetLastError() to string
    static std::string TranslateErrorCode(DWORD errorCode) noexcept;
    static void Assert(HRESULT hr, std::string msg, int line, const char* file, std::string name = "Exception");
    static void Assert(BOOL condition, std::string msg, int line, const char* file, std::string name = "Exception");
};

#define ASSERT(condition, msg) if(!(condition)) throw Exception(msg, __LINE__, __FILE__, "Assertion Failed")
#define THROW_IF_FALED(hr) if(FAILED(hr)) throw Exception(Exception::TranslateErrorCode(GetLastError()), __LINE__, __FILE__)
#define THROW_EXCEPTION(msg) throw Exception(msg, __LINE__, __FILE__)