#pragma once
#include "json/json.hpp"

using json = nlohmann::json;

json read_json(char* fileName);