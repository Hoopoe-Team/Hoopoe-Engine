#ifndef __HOOPOE_ENGINE_TESTREPORTER_H__
#define __HOOPOE_ENGINE_TESTREPORTER_H__

#include <list>
#include <memory>
#include <algorithm>
#include <iterator>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include "../../Core/include/CoreHeaders.h"

namespace Hoopoe { namespace Test {

class TestReporter 
{
public:
    struct TestResult
    {
        TestResult(
                const String &unitName, 
                const String &testName, 
                const bool result
            ) : 
                unitName(unitName),
                testName(testName), 
                result(result)
        {}

        String unitName;
        String testName;
        bool result;
    }; // TestResult

    TestReporter(const String suiteName);
    ~TestReporter();

    void saveResult(const String &unitName, const String &testName, const bool result);
    void printResults(); // print to the console
    String getSuiteName() const;
    static std::shared_ptr<spdlog::logger> getReportLogger();

private:
    String mSuiteName;
    std::list<TestResult *> mTestResults;

    static std::shared_ptr<spdlog::logger> sReportLogger;
}; // TestReporter

} // Test
} // Hoopoe

#endif // __HOOPOE_ENGINE_TESTREPORTER_H__