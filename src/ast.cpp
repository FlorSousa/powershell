#include "ast.hpp"

#define TYPE_CHECK(x) try { x } catch(nlohmann::json_abi_v3_11_2::detail::type_error& e) { std::cerr << e.what() << '\n'; }

void convertLocation(nlohmann::json json, Location* out) {

}

void convertExpression(nlohmann::json json, Node* out) {
    std::string kind = json.at("kind").template get<std::string>();

    nlohmann::json locationJson;
    TYPE_CHECK(locationJson = json.at("location").template get<nlohmann::json>();)
    Location l{};
    convertLocation(locationJson, &l);

    if(kind == "Error") {
        // Error error{.full_text};
        // (*out) = error;
    } else if (kind == "Int") {
        Int integer{
            .value=json.at("value").template get<int32_t>(),
            .location=l
            };
        (*out) = integer;
    } else if (kind == "Str") {
        Str str {
            .value=json.at("value").template get<std::string>(),
            .location=l
        };
        (*out) = str;
    } else if (kind == "Call") {
        Call call {
            // .callee=json.at("calee").template get<std::string>(),
            // .arguments=
        };
    } else if (kind == "Binary") {

    } else if (kind == "Function") { 

    } else if (kind == "Let") {

    } else if (kind == "If") {

    } else if (kind == "Print") {

    } else if (kind == "First") {

    } else if (kind == "Second") {

    } else if (kind == "Bool") {

    } else if (kind == "Tuple") {

    }
}

// se retornar -1, não deu certo
int convertToAST(nlohmann::json json, AST* out) {
    std::string name = json.at("name").template get<std::string>();

    nlohmann::json expression = json.at("expression").template get<nlohmann::json>();
    Node* exprNode = new Node{};
    convertExpression(expression, exprNode);

    nlohmann::json location = json.at("location").template get<nlohmann::json>();

    Location locationObj{};
    convertLocation(location, &locationObj);

    out->name = name;
    out->head = exprNode;
    out->location = locationObj;
    return -1;
}

