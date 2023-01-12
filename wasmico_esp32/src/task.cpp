#include <ArduinoJSON.h>
#include <map>
#include "SPIFFS.h"

#include "utils.hpp"
#include "task.hpp"

#define MIN_STACK_SIZE configMINIMAL_STACK_SIZE
#define MIN_MEMORY_LIMIT configMINIMAL_STACK_SIZE
#define MIN_INITIAL_MEMORY 128 * 19

std::map<String, WasmTaskDetails> taskDetailsMap;

void addTaskDetails(String filename, int reservedStackSize, int reservedInitialMemory, int memoryLimit)
{
    WasmTaskDetails taskDetails;
    // taskDetails.reservedStackSize = max(reservedStackSize, MIN_STACK_SIZE);
    taskDetails.reservedStackSize = 128 * 19;
    // taskDetails.reservedInitialMemory = max(reservedInitialMemory, MIN_INITIAL_MEMORY);
    taskDetails.reservedInitialMemory = 128 * 19;
    // taskDetails.memoryLimit = max(memoryLimit, MIN_MEMORY_LIMIT);
    taskDetails.memoryLimit = 128 * 19;
    taskDetailsMap[filename] = taskDetails;
}

WasmTaskDetails &getTaskDetails(String filename)
{
    return taskDetailsMap[filename];
}

bool doesTaskDetailsExist(String filename)
{
    return taskDetailsMap.count(filename);
}

bool taskStartIsPossible(String filename)
{
    return getTaskDetails(filename).reservedStackSize < getAvailableStackSizeForTask();
}

void deleteWasmFile(String filename)
{
    SPIFFS.remove(filename);
    taskDetailsMap.erase(filename);
}

String listTaskDetailsJson()
{
    const size_t numFiles = taskDetailsMap.size();
    const size_t capacity = JSON_ARRAY_SIZE(numFiles) + numFiles * JSON_OBJECT_SIZE(4) + JSON_OBJECT_SIZE(2);
    DynamicJsonDocument jsonDocument(capacity);

    JsonArray files = jsonDocument.createNestedArray("files");
    std::map<String, WasmTaskDetails>::iterator it;
    for (it = taskDetailsMap.begin(); it != taskDetailsMap.end(); it++)
    {
        JsonObject taskDetailsObj = files.createNestedObject();
        taskDetailsObj["filename"] = it->first.c_str();
        taskDetailsObj["reserved_stack_size"] = it->second.reservedStackSize;
        taskDetailsObj["reserved_initial_memory"] = it->second.reservedInitialMemory;
        taskDetailsObj["memory_limit"] = it->second.memoryLimit;
    }
    jsonDocument["status_code"] = 0;

    String res;
    serializeJson(jsonDocument, res);
    return res;
}