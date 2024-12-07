
// Generated from WhixyLexer.g4 by ANTLR 4.13.2

#include "WhixyLexer.h"

using namespace antlr4;

using namespace Whixy;

using namespace antlr4;

namespace {

struct WhixyLexerStaticData final {
    WhixyLexerStaticData(
        std::vector<std::string> ruleNames, std::vector<std::string> channelNames, std::vector<std::string> modeNames,
        std::vector<std::string> literalNames, std::vector<std::string> symbolicNames
    )
        : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)), modeNames(std::move(modeNames)),
          literalNames(std::move(literalNames)), symbolicNames(std::move(symbolicNames)),
          vocabulary(this->literalNames, this->symbolicNames)
    {}

    WhixyLexerStaticData(const WhixyLexerStaticData&) = delete;
    WhixyLexerStaticData(WhixyLexerStaticData&&) = delete;
    WhixyLexerStaticData& operator=(const WhixyLexerStaticData&) = delete;
    WhixyLexerStaticData& operator=(WhixyLexerStaticData&&) = delete;

    std::vector<antlr4::dfa::DFA> decisionToDFA;
    antlr4::atn::PredictionContextCache sharedContextCache;
    const std::vector<std::string> ruleNames;
    const std::vector<std::string> channelNames;
    const std::vector<std::string> modeNames;
    const std::vector<std::string> literalNames;
    const std::vector<std::string> symbolicNames;
    const antlr4::dfa::Vocabulary vocabulary;
    antlr4::atn::SerializedATNView serializedATN;
    std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag whixylexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
    std::unique_ptr<WhixyLexerStaticData>
        whixylexerLexerStaticData = nullptr;

void whixylexerLexerInitialize()
{
#if ANTLR4_USE_THREAD_LOCAL_CACHE
    if (whixylexerLexerStaticData != nullptr) { return; }
#else
    assert(whixylexerLexerStaticData == nullptr);
#endif
    auto staticData = std::make_unique<WhixyLexerStaticData>(
        std::vector<std::string>{
            "DOUBLEQUOTESTRING",
            "BACKTICKSTRING",
            "DOCCOMMENT",
            "COMMENT",
            "RUNE",
            "NEWLINE",
            "WHITESPACE",
            "DOT",
            "COMMA",
            "SEMICOLON",
            "OPENPARENTHESIS",
            "CLOSEDPARENTHESIS",
            "OPENBRACE",
            "CLOSEDBRACE",
            "OPENBRACKET",
            "CLOSEDBRACKET",
            "EXCLAMATION",
            "DOLLAR",
            "QUESTION",
            "GREATERTHAN_GREATERTHAN_PERCENT_EQUAL",
            "GREATERTHAN_GREATERTHAN_PERCENT",
            "GREATERTHAN_GREATERTHAN_EQUAL",
            "GREATERTHAN_GREATERTHAN",
            "GREATERTHAN_EQUAL",
            "GREATERTHAN",
            "LESSTHAN_LESSTHAN_PERCENT_EQUAL",
            "LESSTHAN_LESSTHAN_PERCENT",
            "LESSTHAN_LESSTHAN_EQUAL",
            "LESSTHAN_LESSTHAN",
            "LESSTHAN_EQUAL",
            "LESSTHAN",
            "ASTERISK_PERCENT_EQUAL",
            "ASTERISK_PERCENT",
            "ASTERISK_EQUAL",
            "ASTERISK_ASTERISK",
            "ASTERISK",
            "PLUS_PERCENT_EQUAL",
            "PLUS_PERCENT",
            "PLUS_EQUAL",
            "PLUS_PLUS",
            "PLUS",
            "MINUS_PERCENT_EQUAL",
            "MINUS_PERCENT",
            "MINUS_EQUAL",
            "MINUS",
            "TILDE_EQUAL",
            "TILDE",
            "AMPERSAND_EQUAL",
            "AMPERSAND",
            "PERCENT_EQUAL",
            "PERCENT",
            "CARROT_EQUAL",
            "CARROT",
            "SLASH_EQUAL",
            "SLASH",
            "EQUAL_EQUAL",
            "EQUAL",
            "PIPE_EQUAL",
            "PIPE",
            "TYPE",
            "LEN",
            "THIS",
            "AUTO",
            "MUT",
            "INLINE",
            "RETURN",
            "CONTINUE",
            "BREAK",
            "GOTO",
            "WHILE",
            "FOR",
            "IF",
            "ELSEIF",
            "ELSE",
            "WHERE",
            "DEFER",
            "ERRDEFER",
            "FAST",
            "BARE",
            "IMPORT",
            "ALIGN",
            "THREADL",
            "UNREACHABLE",
            "VOLATILE",
            "UNROLL",
            "COMPT",
            "TEST",
            "ENUM",
            "UNION",
            "STD",
            "ORELSE",
            "CATCH",
            "AS",
            "TOKEN"
        },
        std::vector<std::string>{"DEFAULT_TOKEN_CHANNEL", "HIDDEN"}, std::vector<std::string>{"DEFAULT_MODE"},
        std::vector<std::string>{"",           "",           "",         "",        "",          "",
                                 "",           "",           "'.'",      "','",     "';'",       "'('",
                                 "')'",        "'{'",        "'}'",      "'['",     "']'",       "'!'",
                                 "'$'",        "'\\u003F'",  "'>>%='",   "'>>%'",   "'>>='",     "'>>'",
                                 "'>='",       "'>'",        "'<<%='",   "'<<%'",   "'<<='",     "'<<'",
                                 "'<='",       "'<'",        "'*%='",    "'*%'",    "'*='",      "'**'",
                                 "'*'",        "'+%='",      "'+%'",     "'+='",    "'++'",      "'+'",
                                 "'-%='",      "'-%'",       "'-='",     "'-'",     "'~='",      "'~'",
                                 "'&='",       "'&'",        "'%='",     "'%'",     "'^='",      "'^'",
                                 "'/='",       "'/'",        "'=='",     "'='",     "'|='",      "'|'",
                                 "'type'",     "'len'",      "'this'",   "'auto'",  "'mut'",     "'inline'",
                                 "'return'",   "'continue'", "'break'",  "'goto'",  "'while'",   "'for'",
                                 "'if'",       "'elseif'",   "'else'",   "'where'", "'defer'",   "'errdefer'",
                                 "'fast'",     "'bare'",     "'import'", "'align'", "'threadl'", "'unreachable'",
                                 "'volatile'", "'unroll'",   "'compt'",  "'test'",  "'enum'",    "'union'",
                                 "'std'",      "'orelse'",   "'catch'",  "'as'"},
        std::vector<std::string>{
            "",
            "DOUBLEQUOTESTRING",
            "BACKTICKSTRING",
            "DOCCOMMENT",
            "COMMENT",
            "RUNE",
            "NEWLINE",
            "WHITESPACE",
            "DOT",
            "COMMA",
            "SEMICOLON",
            "OPENPARENTHESIS",
            "CLOSEDPARENTHESIS",
            "OPENBRACE",
            "CLOSEDBRACE",
            "OPENBRACKET",
            "CLOSEDBRACKET",
            "EXCLAMATION",
            "DOLLAR",
            "QUESTION",
            "GREATERTHAN_GREATERTHAN_PERCENT_EQUAL",
            "GREATERTHAN_GREATERTHAN_PERCENT",
            "GREATERTHAN_GREATERTHAN_EQUAL",
            "GREATERTHAN_GREATERTHAN",
            "GREATERTHAN_EQUAL",
            "GREATERTHAN",
            "LESSTHAN_LESSTHAN_PERCENT_EQUAL",
            "LESSTHAN_LESSTHAN_PERCENT",
            "LESSTHAN_LESSTHAN_EQUAL",
            "LESSTHAN_LESSTHAN",
            "LESSTHAN_EQUAL",
            "LESSTHAN",
            "ASTERISK_PERCENT_EQUAL",
            "ASTERISK_PERCENT",
            "ASTERISK_EQUAL",
            "ASTERISK_ASTERISK",
            "ASTERISK",
            "PLUS_PERCENT_EQUAL",
            "PLUS_PERCENT",
            "PLUS_EQUAL",
            "PLUS_PLUS",
            "PLUS",
            "MINUS_PERCENT_EQUAL",
            "MINUS_PERCENT",
            "MINUS_EQUAL",
            "MINUS",
            "TILDE_EQUAL",
            "TILDE",
            "AMPERSAND_EQUAL",
            "AMPERSAND",
            "PERCENT_EQUAL",
            "PERCENT",
            "CARROT_EQUAL",
            "CARROT",
            "SLASH_EQUAL",
            "SLASH",
            "EQUAL_EQUAL",
            "EQUAL",
            "PIPE_EQUAL",
            "PIPE",
            "TYPE",
            "LEN",
            "THIS",
            "AUTO",
            "MUT",
            "INLINE",
            "RETURN",
            "CONTINUE",
            "BREAK",
            "GOTO",
            "WHILE",
            "FOR",
            "IF",
            "ELSEIF",
            "ELSE",
            "WHERE",
            "DEFER",
            "ERRDEFER",
            "FAST",
            "BARE",
            "IMPORT",
            "ALIGN",
            "THREADL",
            "UNREACHABLE",
            "VOLATILE",
            "UNROLL",
            "COMPT",
            "TEST",
            "ENUM",
            "UNION",
            "STD",
            "ORELSE",
            "CATCH",
            "AS",
            "TOKEN"
        }
    );
    static const int32_t serializedATNSegment[] = {
        4,   0,   94,  602, 6,   -1,  2,   0,   7,   0,   2,   1,   7,   1,   2,   2,   7,   2,   2,   3,   7,   3,
        2,   4,   7,   4,   2,   5,   7,   5,   2,   6,   7,   6,   2,   7,   7,   7,   2,   8,   7,   8,   2,   9,
        7,   9,   2,   10,  7,   10,  2,   11,  7,   11,  2,   12,  7,   12,  2,   13,  7,   13,  2,   14,  7,   14,
        2,   15,  7,   15,  2,   16,  7,   16,  2,   17,  7,   17,  2,   18,  7,   18,  2,   19,  7,   19,  2,   20,
        7,   20,  2,   21,  7,   21,  2,   22,  7,   22,  2,   23,  7,   23,  2,   24,  7,   24,  2,   25,  7,   25,
        2,   26,  7,   26,  2,   27,  7,   27,  2,   28,  7,   28,  2,   29,  7,   29,  2,   30,  7,   30,  2,   31,
        7,   31,  2,   32,  7,   32,  2,   33,  7,   33,  2,   34,  7,   34,  2,   35,  7,   35,  2,   36,  7,   36,
        2,   37,  7,   37,  2,   38,  7,   38,  2,   39,  7,   39,  2,   40,  7,   40,  2,   41,  7,   41,  2,   42,
        7,   42,  2,   43,  7,   43,  2,   44,  7,   44,  2,   45,  7,   45,  2,   46,  7,   46,  2,   47,  7,   47,
        2,   48,  7,   48,  2,   49,  7,   49,  2,   50,  7,   50,  2,   51,  7,   51,  2,   52,  7,   52,  2,   53,
        7,   53,  2,   54,  7,   54,  2,   55,  7,   55,  2,   56,  7,   56,  2,   57,  7,   57,  2,   58,  7,   58,
        2,   59,  7,   59,  2,   60,  7,   60,  2,   61,  7,   61,  2,   62,  7,   62,  2,   63,  7,   63,  2,   64,
        7,   64,  2,   65,  7,   65,  2,   66,  7,   66,  2,   67,  7,   67,  2,   68,  7,   68,  2,   69,  7,   69,
        2,   70,  7,   70,  2,   71,  7,   71,  2,   72,  7,   72,  2,   73,  7,   73,  2,   74,  7,   74,  2,   75,
        7,   75,  2,   76,  7,   76,  2,   77,  7,   77,  2,   78,  7,   78,  2,   79,  7,   79,  2,   80,  7,   80,
        2,   81,  7,   81,  2,   82,  7,   82,  2,   83,  7,   83,  2,   84,  7,   84,  2,   85,  7,   85,  2,   86,
        7,   86,  2,   87,  7,   87,  2,   88,  7,   88,  2,   89,  7,   89,  2,   90,  7,   90,  2,   91,  7,   91,
        2,   92,  7,   92,  2,   93,  7,   93,  1,   0,   1,   0,   1,   0,   1,   0,   5,   0,   194, 8,   0,   10,
        0,   12,  0,   197, 9,   0,   1,   0,   1,   0,   1,   1,   1,   1,   1,   1,   1,   1,   5,   1,   205, 8,
        1,   10,  1,   12,  1,   208, 9,   1,   1,   1,   1,   1,   1,   2,   1,   2,   1,   2,   1,   2,   1,   2,
        5,   2,   217, 8,   2,   10,  2,   12,  2,   220, 9,   2,   1,   3,   1,   3,   5,   3,   224, 8,   3,   10,
        3,   12,  3,   227, 9,   3,   1,   3,   1,   3,   1,   4,   1,   4,   1,   4,   1,   4,   3,   4,   235, 8,
        4,   1,   4,   1,   4,   1,   5,   4,   5,   240, 8,   5,   11,  5,   12,  5,   241, 1,   6,   4,   6,   245,
        8,   6,   11,  6,   12,  6,   246, 1,   6,   1,   6,   1,   7,   1,   7,   1,   8,   1,   8,   1,   9,   1,
        9,   1,   10,  1,   10,  1,   11,  1,   11,  1,   12,  1,   12,  1,   13,  1,   13,  1,   14,  1,   14,  1,
        15,  1,   15,  1,   16,  1,   16,  1,   17,  1,   17,  1,   18,  1,   18,  1,   19,  1,   19,  1,   19,  1,
        19,  1,   19,  1,   20,  1,   20,  1,   20,  1,   20,  1,   21,  1,   21,  1,   21,  1,   21,  1,   22,  1,
        22,  1,   22,  1,   23,  1,   23,  1,   23,  1,   24,  1,   24,  1,   25,  1,   25,  1,   25,  1,   25,  1,
        25,  1,   26,  1,   26,  1,   26,  1,   26,  1,   27,  1,   27,  1,   27,  1,   27,  1,   28,  1,   28,  1,
        28,  1,   29,  1,   29,  1,   29,  1,   30,  1,   30,  1,   31,  1,   31,  1,   31,  1,   31,  1,   32,  1,
        32,  1,   32,  1,   33,  1,   33,  1,   33,  1,   34,  1,   34,  1,   34,  1,   35,  1,   35,  1,   36,  1,
        36,  1,   36,  1,   36,  1,   37,  1,   37,  1,   37,  1,   38,  1,   38,  1,   38,  1,   39,  1,   39,  1,
        39,  1,   40,  1,   40,  1,   41,  1,   41,  1,   41,  1,   41,  1,   42,  1,   42,  1,   42,  1,   43,  1,
        43,  1,   43,  1,   44,  1,   44,  1,   45,  1,   45,  1,   45,  1,   46,  1,   46,  1,   47,  1,   47,  1,
        47,  1,   48,  1,   48,  1,   49,  1,   49,  1,   49,  1,   50,  1,   50,  1,   51,  1,   51,  1,   51,  1,
        52,  1,   52,  1,   53,  1,   53,  1,   53,  1,   54,  1,   54,  1,   55,  1,   55,  1,   55,  1,   56,  1,
        56,  1,   57,  1,   57,  1,   57,  1,   58,  1,   58,  1,   59,  1,   59,  1,   59,  1,   59,  1,   59,  1,
        60,  1,   60,  1,   60,  1,   60,  1,   61,  1,   61,  1,   61,  1,   61,  1,   61,  1,   62,  1,   62,  1,
        62,  1,   62,  1,   62,  1,   63,  1,   63,  1,   63,  1,   63,  1,   64,  1,   64,  1,   64,  1,   64,  1,
        64,  1,   64,  1,   64,  1,   65,  1,   65,  1,   65,  1,   65,  1,   65,  1,   65,  1,   65,  1,   66,  1,
        66,  1,   66,  1,   66,  1,   66,  1,   66,  1,   66,  1,   66,  1,   66,  1,   67,  1,   67,  1,   67,  1,
        67,  1,   67,  1,   67,  1,   68,  1,   68,  1,   68,  1,   68,  1,   68,  1,   69,  1,   69,  1,   69,  1,
        69,  1,   69,  1,   69,  1,   70,  1,   70,  1,   70,  1,   70,  1,   71,  1,   71,  1,   71,  1,   72,  1,
        72,  1,   72,  1,   72,  1,   72,  1,   72,  1,   72,  1,   73,  1,   73,  1,   73,  1,   73,  1,   73,  1,
        74,  1,   74,  1,   74,  1,   74,  1,   74,  1,   74,  1,   75,  1,   75,  1,   75,  1,   75,  1,   75,  1,
        75,  1,   76,  1,   76,  1,   76,  1,   76,  1,   76,  1,   76,  1,   76,  1,   76,  1,   76,  1,   77,  1,
        77,  1,   77,  1,   77,  1,   77,  1,   78,  1,   78,  1,   78,  1,   78,  1,   78,  1,   79,  1,   79,  1,
        79,  1,   79,  1,   79,  1,   79,  1,   79,  1,   80,  1,   80,  1,   80,  1,   80,  1,   80,  1,   80,  1,
        81,  1,   81,  1,   81,  1,   81,  1,   81,  1,   81,  1,   81,  1,   81,  1,   82,  1,   82,  1,   82,  1,
        82,  1,   82,  1,   82,  1,   82,  1,   82,  1,   82,  1,   82,  1,   82,  1,   82,  1,   83,  1,   83,  1,
        83,  1,   83,  1,   83,  1,   83,  1,   83,  1,   83,  1,   83,  1,   84,  1,   84,  1,   84,  1,   84,  1,
        84,  1,   84,  1,   84,  1,   85,  1,   85,  1,   85,  1,   85,  1,   85,  1,   85,  1,   86,  1,   86,  1,
        86,  1,   86,  1,   86,  1,   87,  1,   87,  1,   87,  1,   87,  1,   87,  1,   88,  1,   88,  1,   88,  1,
        88,  1,   88,  1,   88,  1,   89,  1,   89,  1,   89,  1,   89,  1,   90,  1,   90,  1,   90,  1,   90,  1,
        90,  1,   90,  1,   90,  1,   91,  1,   91,  1,   91,  1,   91,  1,   91,  1,   91,  1,   92,  1,   92,  1,
        92,  1,   93,  4,   93,  599, 8,   93,  11,  93,  12,  93,  600, 3,   195, 206, 600, 0,   94,  1,   1,   3,
        2,   5,   3,   7,   4,   9,   5,   11,  6,   13,  7,   15,  8,   17,  9,   19,  10,  21,  11,  23,  12,  25,
        13,  27,  14,  29,  15,  31,  16,  33,  17,  35,  18,  37,  19,  39,  20,  41,  21,  43,  22,  45,  23,  47,
        24,  49,  25,  51,  26,  53,  27,  55,  28,  57,  29,  59,  30,  61,  31,  63,  32,  65,  33,  67,  34,  69,
        35,  71,  36,  73,  37,  75,  38,  77,  39,  79,  40,  81,  41,  83,  42,  85,  43,  87,  44,  89,  45,  91,
        46,  93,  47,  95,  48,  97,  49,  99,  50,  101, 51,  103, 52,  105, 53,  107, 54,  109, 55,  111, 56,  113,
        57,  115, 58,  117, 59,  119, 60,  121, 61,  123, 62,  125, 63,  127, 64,  129, 65,  131, 66,  133, 67,  135,
        68,  137, 69,  139, 70,  141, 71,  143, 72,  145, 73,  147, 74,  149, 75,  151, 76,  153, 77,  155, 78,  157,
        79,  159, 80,  161, 81,  163, 82,  165, 83,  167, 84,  169, 85,  171, 86,  173, 87,  175, 88,  177, 89,  179,
        90,  181, 91,  183, 92,  185, 93,  187, 94,  1,   0,   2,   2,   0,   10,  10,  13,  13,  2,   0,   9,   9,
        32,  32,  611, 0,   1,   1,   0,   0,   0,   0,   3,   1,   0,   0,   0,   0,   5,   1,   0,   0,   0,   0,
        7,   1,   0,   0,   0,   0,   9,   1,   0,   0,   0,   0,   11,  1,   0,   0,   0,   0,   13,  1,   0,   0,
        0,   0,   15,  1,   0,   0,   0,   0,   17,  1,   0,   0,   0,   0,   19,  1,   0,   0,   0,   0,   21,  1,
        0,   0,   0,   0,   23,  1,   0,   0,   0,   0,   25,  1,   0,   0,   0,   0,   27,  1,   0,   0,   0,   0,
        29,  1,   0,   0,   0,   0,   31,  1,   0,   0,   0,   0,   33,  1,   0,   0,   0,   0,   35,  1,   0,   0,
        0,   0,   37,  1,   0,   0,   0,   0,   39,  1,   0,   0,   0,   0,   41,  1,   0,   0,   0,   0,   43,  1,
        0,   0,   0,   0,   45,  1,   0,   0,   0,   0,   47,  1,   0,   0,   0,   0,   49,  1,   0,   0,   0,   0,
        51,  1,   0,   0,   0,   0,   53,  1,   0,   0,   0,   0,   55,  1,   0,   0,   0,   0,   57,  1,   0,   0,
        0,   0,   59,  1,   0,   0,   0,   0,   61,  1,   0,   0,   0,   0,   63,  1,   0,   0,   0,   0,   65,  1,
        0,   0,   0,   0,   67,  1,   0,   0,   0,   0,   69,  1,   0,   0,   0,   0,   71,  1,   0,   0,   0,   0,
        73,  1,   0,   0,   0,   0,   75,  1,   0,   0,   0,   0,   77,  1,   0,   0,   0,   0,   79,  1,   0,   0,
        0,   0,   81,  1,   0,   0,   0,   0,   83,  1,   0,   0,   0,   0,   85,  1,   0,   0,   0,   0,   87,  1,
        0,   0,   0,   0,   89,  1,   0,   0,   0,   0,   91,  1,   0,   0,   0,   0,   93,  1,   0,   0,   0,   0,
        95,  1,   0,   0,   0,   0,   97,  1,   0,   0,   0,   0,   99,  1,   0,   0,   0,   0,   101, 1,   0,   0,
        0,   0,   103, 1,   0,   0,   0,   0,   105, 1,   0,   0,   0,   0,   107, 1,   0,   0,   0,   0,   109, 1,
        0,   0,   0,   0,   111, 1,   0,   0,   0,   0,   113, 1,   0,   0,   0,   0,   115, 1,   0,   0,   0,   0,
        117, 1,   0,   0,   0,   0,   119, 1,   0,   0,   0,   0,   121, 1,   0,   0,   0,   0,   123, 1,   0,   0,
        0,   0,   125, 1,   0,   0,   0,   0,   127, 1,   0,   0,   0,   0,   129, 1,   0,   0,   0,   0,   131, 1,
        0,   0,   0,   0,   133, 1,   0,   0,   0,   0,   135, 1,   0,   0,   0,   0,   137, 1,   0,   0,   0,   0,
        139, 1,   0,   0,   0,   0,   141, 1,   0,   0,   0,   0,   143, 1,   0,   0,   0,   0,   145, 1,   0,   0,
        0,   0,   147, 1,   0,   0,   0,   0,   149, 1,   0,   0,   0,   0,   151, 1,   0,   0,   0,   0,   153, 1,
        0,   0,   0,   0,   155, 1,   0,   0,   0,   0,   157, 1,   0,   0,   0,   0,   159, 1,   0,   0,   0,   0,
        161, 1,   0,   0,   0,   0,   163, 1,   0,   0,   0,   0,   165, 1,   0,   0,   0,   0,   167, 1,   0,   0,
        0,   0,   169, 1,   0,   0,   0,   0,   171, 1,   0,   0,   0,   0,   173, 1,   0,   0,   0,   0,   175, 1,
        0,   0,   0,   0,   177, 1,   0,   0,   0,   0,   179, 1,   0,   0,   0,   0,   181, 1,   0,   0,   0,   0,
        183, 1,   0,   0,   0,   0,   185, 1,   0,   0,   0,   0,   187, 1,   0,   0,   0,   1,   189, 1,   0,   0,
        0,   3,   200, 1,   0,   0,   0,   5,   211, 1,   0,   0,   0,   7,   221, 1,   0,   0,   0,   9,   230, 1,
        0,   0,   0,   11,  239, 1,   0,   0,   0,   13,  244, 1,   0,   0,   0,   15,  250, 1,   0,   0,   0,   17,
        252, 1,   0,   0,   0,   19,  254, 1,   0,   0,   0,   21,  256, 1,   0,   0,   0,   23,  258, 1,   0,   0,
        0,   25,  260, 1,   0,   0,   0,   27,  262, 1,   0,   0,   0,   29,  264, 1,   0,   0,   0,   31,  266, 1,
        0,   0,   0,   33,  268, 1,   0,   0,   0,   35,  270, 1,   0,   0,   0,   37,  272, 1,   0,   0,   0,   39,
        274, 1,   0,   0,   0,   41,  279, 1,   0,   0,   0,   43,  283, 1,   0,   0,   0,   45,  287, 1,   0,   0,
        0,   47,  290, 1,   0,   0,   0,   49,  293, 1,   0,   0,   0,   51,  295, 1,   0,   0,   0,   53,  300, 1,
        0,   0,   0,   55,  304, 1,   0,   0,   0,   57,  308, 1,   0,   0,   0,   59,  311, 1,   0,   0,   0,   61,
        314, 1,   0,   0,   0,   63,  316, 1,   0,   0,   0,   65,  320, 1,   0,   0,   0,   67,  323, 1,   0,   0,
        0,   69,  326, 1,   0,   0,   0,   71,  329, 1,   0,   0,   0,   73,  331, 1,   0,   0,   0,   75,  335, 1,
        0,   0,   0,   77,  338, 1,   0,   0,   0,   79,  341, 1,   0,   0,   0,   81,  344, 1,   0,   0,   0,   83,
        346, 1,   0,   0,   0,   85,  350, 1,   0,   0,   0,   87,  353, 1,   0,   0,   0,   89,  356, 1,   0,   0,
        0,   91,  358, 1,   0,   0,   0,   93,  361, 1,   0,   0,   0,   95,  363, 1,   0,   0,   0,   97,  366, 1,
        0,   0,   0,   99,  368, 1,   0,   0,   0,   101, 371, 1,   0,   0,   0,   103, 373, 1,   0,   0,   0,   105,
        376, 1,   0,   0,   0,   107, 378, 1,   0,   0,   0,   109, 381, 1,   0,   0,   0,   111, 383, 1,   0,   0,
        0,   113, 386, 1,   0,   0,   0,   115, 388, 1,   0,   0,   0,   117, 391, 1,   0,   0,   0,   119, 393, 1,
        0,   0,   0,   121, 398, 1,   0,   0,   0,   123, 402, 1,   0,   0,   0,   125, 407, 1,   0,   0,   0,   127,
        412, 1,   0,   0,   0,   129, 416, 1,   0,   0,   0,   131, 423, 1,   0,   0,   0,   133, 430, 1,   0,   0,
        0,   135, 439, 1,   0,   0,   0,   137, 445, 1,   0,   0,   0,   139, 450, 1,   0,   0,   0,   141, 456, 1,
        0,   0,   0,   143, 460, 1,   0,   0,   0,   145, 463, 1,   0,   0,   0,   147, 470, 1,   0,   0,   0,   149,
        475, 1,   0,   0,   0,   151, 481, 1,   0,   0,   0,   153, 487, 1,   0,   0,   0,   155, 496, 1,   0,   0,
        0,   157, 501, 1,   0,   0,   0,   159, 506, 1,   0,   0,   0,   161, 513, 1,   0,   0,   0,   163, 519, 1,
        0,   0,   0,   165, 527, 1,   0,   0,   0,   167, 539, 1,   0,   0,   0,   169, 548, 1,   0,   0,   0,   171,
        555, 1,   0,   0,   0,   173, 561, 1,   0,   0,   0,   175, 566, 1,   0,   0,   0,   177, 571, 1,   0,   0,
        0,   179, 577, 1,   0,   0,   0,   181, 581, 1,   0,   0,   0,   183, 588, 1,   0,   0,   0,   185, 594, 1,
        0,   0,   0,   187, 598, 1,   0,   0,   0,   189, 195, 5,   34,  0,   0,   190, 191, 5,   92,  0,   0,   191,
        194, 5,   34,  0,   0,   192, 194, 9,   0,   0,   0,   193, 190, 1,   0,   0,   0,   193, 192, 1,   0,   0,
        0,   194, 197, 1,   0,   0,   0,   195, 196, 1,   0,   0,   0,   195, 193, 1,   0,   0,   0,   196, 198, 1,
        0,   0,   0,   197, 195, 1,   0,   0,   0,   198, 199, 5,   34,  0,   0,   199, 2,   1,   0,   0,   0,   200,
        206, 5,   96,  0,   0,   201, 202, 5,   92,  0,   0,   202, 205, 5,   96,  0,   0,   203, 205, 9,   0,   0,
        0,   204, 201, 1,   0,   0,   0,   204, 203, 1,   0,   0,   0,   205, 208, 1,   0,   0,   0,   206, 207, 1,
        0,   0,   0,   206, 204, 1,   0,   0,   0,   207, 209, 1,   0,   0,   0,   208, 206, 1,   0,   0,   0,   209,
        210, 5,   96,  0,   0,   210, 4,   1,   0,   0,   0,   211, 212, 5,   35,  0,   0,   212, 213, 5,   35,  0,
        0,   213, 214, 5,   35,  0,   0,   214, 218, 1,   0,   0,   0,   215, 217, 8,   0,   0,   0,   216, 215, 1,
        0,   0,   0,   217, 220, 1,   0,   0,   0,   218, 216, 1,   0,   0,   0,   218, 219, 1,   0,   0,   0,   219,
        6,   1,   0,   0,   0,   220, 218, 1,   0,   0,   0,   221, 225, 5,   35,  0,   0,   222, 224, 8,   0,   0,
        0,   223, 222, 1,   0,   0,   0,   224, 227, 1,   0,   0,   0,   225, 223, 1,   0,   0,   0,   225, 226, 1,
        0,   0,   0,   226, 228, 1,   0,   0,   0,   227, 225, 1,   0,   0,   0,   228, 229, 6,   3,   0,   0,   229,
        8,   1,   0,   0,   0,   230, 234, 5,   39,  0,   0,   231, 232, 5,   92,  0,   0,   232, 235, 5,   39,  0,
        0,   233, 235, 9,   0,   0,   0,   234, 231, 1,   0,   0,   0,   234, 233, 1,   0,   0,   0,   235, 236, 1,
        0,   0,   0,   236, 237, 5,   39,  0,   0,   237, 10,  1,   0,   0,   0,   238, 240, 7,   0,   0,   0,   239,
        238, 1,   0,   0,   0,   240, 241, 1,   0,   0,   0,   241, 239, 1,   0,   0,   0,   241, 242, 1,   0,   0,
        0,   242, 12,  1,   0,   0,   0,   243, 245, 7,   1,   0,   0,   244, 243, 1,   0,   0,   0,   245, 246, 1,
        0,   0,   0,   246, 244, 1,   0,   0,   0,   246, 247, 1,   0,   0,   0,   247, 248, 1,   0,   0,   0,   248,
        249, 6,   6,   0,   0,   249, 14,  1,   0,   0,   0,   250, 251, 5,   46,  0,   0,   251, 16,  1,   0,   0,
        0,   252, 253, 5,   44,  0,   0,   253, 18,  1,   0,   0,   0,   254, 255, 5,   59,  0,   0,   255, 20,  1,
        0,   0,   0,   256, 257, 5,   40,  0,   0,   257, 22,  1,   0,   0,   0,   258, 259, 5,   41,  0,   0,   259,
        24,  1,   0,   0,   0,   260, 261, 5,   123, 0,   0,   261, 26,  1,   0,   0,   0,   262, 263, 5,   125, 0,
        0,   263, 28,  1,   0,   0,   0,   264, 265, 5,   91,  0,   0,   265, 30,  1,   0,   0,   0,   266, 267, 5,
        93,  0,   0,   267, 32,  1,   0,   0,   0,   268, 269, 5,   33,  0,   0,   269, 34,  1,   0,   0,   0,   270,
        271, 5,   36,  0,   0,   271, 36,  1,   0,   0,   0,   272, 273, 5,   63,  0,   0,   273, 38,  1,   0,   0,
        0,   274, 275, 5,   62,  0,   0,   275, 276, 5,   62,  0,   0,   276, 277, 5,   37,  0,   0,   277, 278, 5,
        61,  0,   0,   278, 40,  1,   0,   0,   0,   279, 280, 5,   62,  0,   0,   280, 281, 5,   62,  0,   0,   281,
        282, 5,   37,  0,   0,   282, 42,  1,   0,   0,   0,   283, 284, 5,   62,  0,   0,   284, 285, 5,   62,  0,
        0,   285, 286, 5,   61,  0,   0,   286, 44,  1,   0,   0,   0,   287, 288, 5,   62,  0,   0,   288, 289, 5,
        62,  0,   0,   289, 46,  1,   0,   0,   0,   290, 291, 5,   62,  0,   0,   291, 292, 5,   61,  0,   0,   292,
        48,  1,   0,   0,   0,   293, 294, 5,   62,  0,   0,   294, 50,  1,   0,   0,   0,   295, 296, 5,   60,  0,
        0,   296, 297, 5,   60,  0,   0,   297, 298, 5,   37,  0,   0,   298, 299, 5,   61,  0,   0,   299, 52,  1,
        0,   0,   0,   300, 301, 5,   60,  0,   0,   301, 302, 5,   60,  0,   0,   302, 303, 5,   37,  0,   0,   303,
        54,  1,   0,   0,   0,   304, 305, 5,   60,  0,   0,   305, 306, 5,   60,  0,   0,   306, 307, 5,   61,  0,
        0,   307, 56,  1,   0,   0,   0,   308, 309, 5,   60,  0,   0,   309, 310, 5,   60,  0,   0,   310, 58,  1,
        0,   0,   0,   311, 312, 5,   60,  0,   0,   312, 313, 5,   61,  0,   0,   313, 60,  1,   0,   0,   0,   314,
        315, 5,   60,  0,   0,   315, 62,  1,   0,   0,   0,   316, 317, 5,   42,  0,   0,   317, 318, 5,   37,  0,
        0,   318, 319, 5,   61,  0,   0,   319, 64,  1,   0,   0,   0,   320, 321, 5,   42,  0,   0,   321, 322, 5,
        37,  0,   0,   322, 66,  1,   0,   0,   0,   323, 324, 5,   42,  0,   0,   324, 325, 5,   61,  0,   0,   325,
        68,  1,   0,   0,   0,   326, 327, 5,   42,  0,   0,   327, 328, 5,   42,  0,   0,   328, 70,  1,   0,   0,
        0,   329, 330, 5,   42,  0,   0,   330, 72,  1,   0,   0,   0,   331, 332, 5,   43,  0,   0,   332, 333, 5,
        37,  0,   0,   333, 334, 5,   61,  0,   0,   334, 74,  1,   0,   0,   0,   335, 336, 5,   43,  0,   0,   336,
        337, 5,   37,  0,   0,   337, 76,  1,   0,   0,   0,   338, 339, 5,   43,  0,   0,   339, 340, 5,   61,  0,
        0,   340, 78,  1,   0,   0,   0,   341, 342, 5,   43,  0,   0,   342, 343, 5,   43,  0,   0,   343, 80,  1,
        0,   0,   0,   344, 345, 5,   43,  0,   0,   345, 82,  1,   0,   0,   0,   346, 347, 5,   45,  0,   0,   347,
        348, 5,   37,  0,   0,   348, 349, 5,   61,  0,   0,   349, 84,  1,   0,   0,   0,   350, 351, 5,   45,  0,
        0,   351, 352, 5,   37,  0,   0,   352, 86,  1,   0,   0,   0,   353, 354, 5,   45,  0,   0,   354, 355, 5,
        61,  0,   0,   355, 88,  1,   0,   0,   0,   356, 357, 5,   45,  0,   0,   357, 90,  1,   0,   0,   0,   358,
        359, 5,   126, 0,   0,   359, 360, 5,   61,  0,   0,   360, 92,  1,   0,   0,   0,   361, 362, 5,   126, 0,
        0,   362, 94,  1,   0,   0,   0,   363, 364, 5,   38,  0,   0,   364, 365, 5,   61,  0,   0,   365, 96,  1,
        0,   0,   0,   366, 367, 5,   38,  0,   0,   367, 98,  1,   0,   0,   0,   368, 369, 5,   37,  0,   0,   369,
        370, 5,   61,  0,   0,   370, 100, 1,   0,   0,   0,   371, 372, 5,   37,  0,   0,   372, 102, 1,   0,   0,
        0,   373, 374, 5,   94,  0,   0,   374, 375, 5,   61,  0,   0,   375, 104, 1,   0,   0,   0,   376, 377, 5,
        94,  0,   0,   377, 106, 1,   0,   0,   0,   378, 379, 5,   47,  0,   0,   379, 380, 5,   61,  0,   0,   380,
        108, 1,   0,   0,   0,   381, 382, 5,   47,  0,   0,   382, 110, 1,   0,   0,   0,   383, 384, 5,   61,  0,
        0,   384, 385, 5,   61,  0,   0,   385, 112, 1,   0,   0,   0,   386, 387, 5,   61,  0,   0,   387, 114, 1,
        0,   0,   0,   388, 389, 5,   124, 0,   0,   389, 390, 5,   61,  0,   0,   390, 116, 1,   0,   0,   0,   391,
        392, 5,   124, 0,   0,   392, 118, 1,   0,   0,   0,   393, 394, 5,   116, 0,   0,   394, 395, 5,   121, 0,
        0,   395, 396, 5,   112, 0,   0,   396, 397, 5,   101, 0,   0,   397, 120, 1,   0,   0,   0,   398, 399, 5,
        108, 0,   0,   399, 400, 5,   101, 0,   0,   400, 401, 5,   110, 0,   0,   401, 122, 1,   0,   0,   0,   402,
        403, 5,   116, 0,   0,   403, 404, 5,   104, 0,   0,   404, 405, 5,   105, 0,   0,   405, 406, 5,   115, 0,
        0,   406, 124, 1,   0,   0,   0,   407, 408, 5,   97,  0,   0,   408, 409, 5,   117, 0,   0,   409, 410, 5,
        116, 0,   0,   410, 411, 5,   111, 0,   0,   411, 126, 1,   0,   0,   0,   412, 413, 5,   109, 0,   0,   413,
        414, 5,   117, 0,   0,   414, 415, 5,   116, 0,   0,   415, 128, 1,   0,   0,   0,   416, 417, 5,   105, 0,
        0,   417, 418, 5,   110, 0,   0,   418, 419, 5,   108, 0,   0,   419, 420, 5,   105, 0,   0,   420, 421, 5,
        110, 0,   0,   421, 422, 5,   101, 0,   0,   422, 130, 1,   0,   0,   0,   423, 424, 5,   114, 0,   0,   424,
        425, 5,   101, 0,   0,   425, 426, 5,   116, 0,   0,   426, 427, 5,   117, 0,   0,   427, 428, 5,   114, 0,
        0,   428, 429, 5,   110, 0,   0,   429, 132, 1,   0,   0,   0,   430, 431, 5,   99,  0,   0,   431, 432, 5,
        111, 0,   0,   432, 433, 5,   110, 0,   0,   433, 434, 5,   116, 0,   0,   434, 435, 5,   105, 0,   0,   435,
        436, 5,   110, 0,   0,   436, 437, 5,   117, 0,   0,   437, 438, 5,   101, 0,   0,   438, 134, 1,   0,   0,
        0,   439, 440, 5,   98,  0,   0,   440, 441, 5,   114, 0,   0,   441, 442, 5,   101, 0,   0,   442, 443, 5,
        97,  0,   0,   443, 444, 5,   107, 0,   0,   444, 136, 1,   0,   0,   0,   445, 446, 5,   103, 0,   0,   446,
        447, 5,   111, 0,   0,   447, 448, 5,   116, 0,   0,   448, 449, 5,   111, 0,   0,   449, 138, 1,   0,   0,
        0,   450, 451, 5,   119, 0,   0,   451, 452, 5,   104, 0,   0,   452, 453, 5,   105, 0,   0,   453, 454, 5,
        108, 0,   0,   454, 455, 5,   101, 0,   0,   455, 140, 1,   0,   0,   0,   456, 457, 5,   102, 0,   0,   457,
        458, 5,   111, 0,   0,   458, 459, 5,   114, 0,   0,   459, 142, 1,   0,   0,   0,   460, 461, 5,   105, 0,
        0,   461, 462, 5,   102, 0,   0,   462, 144, 1,   0,   0,   0,   463, 464, 5,   101, 0,   0,   464, 465, 5,
        108, 0,   0,   465, 466, 5,   115, 0,   0,   466, 467, 5,   101, 0,   0,   467, 468, 5,   105, 0,   0,   468,
        469, 5,   102, 0,   0,   469, 146, 1,   0,   0,   0,   470, 471, 5,   101, 0,   0,   471, 472, 5,   108, 0,
        0,   472, 473, 5,   115, 0,   0,   473, 474, 5,   101, 0,   0,   474, 148, 1,   0,   0,   0,   475, 476, 5,
        119, 0,   0,   476, 477, 5,   104, 0,   0,   477, 478, 5,   101, 0,   0,   478, 479, 5,   114, 0,   0,   479,
        480, 5,   101, 0,   0,   480, 150, 1,   0,   0,   0,   481, 482, 5,   100, 0,   0,   482, 483, 5,   101, 0,
        0,   483, 484, 5,   102, 0,   0,   484, 485, 5,   101, 0,   0,   485, 486, 5,   114, 0,   0,   486, 152, 1,
        0,   0,   0,   487, 488, 5,   101, 0,   0,   488, 489, 5,   114, 0,   0,   489, 490, 5,   114, 0,   0,   490,
        491, 5,   100, 0,   0,   491, 492, 5,   101, 0,   0,   492, 493, 5,   102, 0,   0,   493, 494, 5,   101, 0,
        0,   494, 495, 5,   114, 0,   0,   495, 154, 1,   0,   0,   0,   496, 497, 5,   102, 0,   0,   497, 498, 5,
        97,  0,   0,   498, 499, 5,   115, 0,   0,   499, 500, 5,   116, 0,   0,   500, 156, 1,   0,   0,   0,   501,
        502, 5,   98,  0,   0,   502, 503, 5,   97,  0,   0,   503, 504, 5,   114, 0,   0,   504, 505, 5,   101, 0,
        0,   505, 158, 1,   0,   0,   0,   506, 507, 5,   105, 0,   0,   507, 508, 5,   109, 0,   0,   508, 509, 5,
        112, 0,   0,   509, 510, 5,   111, 0,   0,   510, 511, 5,   114, 0,   0,   511, 512, 5,   116, 0,   0,   512,
        160, 1,   0,   0,   0,   513, 514, 5,   97,  0,   0,   514, 515, 5,   108, 0,   0,   515, 516, 5,   105, 0,
        0,   516, 517, 5,   103, 0,   0,   517, 518, 5,   110, 0,   0,   518, 162, 1,   0,   0,   0,   519, 520, 5,
        116, 0,   0,   520, 521, 5,   104, 0,   0,   521, 522, 5,   114, 0,   0,   522, 523, 5,   101, 0,   0,   523,
        524, 5,   97,  0,   0,   524, 525, 5,   100, 0,   0,   525, 526, 5,   108, 0,   0,   526, 164, 1,   0,   0,
        0,   527, 528, 5,   117, 0,   0,   528, 529, 5,   110, 0,   0,   529, 530, 5,   114, 0,   0,   530, 531, 5,
        101, 0,   0,   531, 532, 5,   97,  0,   0,   532, 533, 5,   99,  0,   0,   533, 534, 5,   104, 0,   0,   534,
        535, 5,   97,  0,   0,   535, 536, 5,   98,  0,   0,   536, 537, 5,   108, 0,   0,   537, 538, 5,   101, 0,
        0,   538, 166, 1,   0,   0,   0,   539, 540, 5,   118, 0,   0,   540, 541, 5,   111, 0,   0,   541, 542, 5,
        108, 0,   0,   542, 543, 5,   97,  0,   0,   543, 544, 5,   116, 0,   0,   544, 545, 5,   105, 0,   0,   545,
        546, 5,   108, 0,   0,   546, 547, 5,   101, 0,   0,   547, 168, 1,   0,   0,   0,   548, 549, 5,   117, 0,
        0,   549, 550, 5,   110, 0,   0,   550, 551, 5,   114, 0,   0,   551, 552, 5,   111, 0,   0,   552, 553, 5,
        108, 0,   0,   553, 554, 5,   108, 0,   0,   554, 170, 1,   0,   0,   0,   555, 556, 5,   99,  0,   0,   556,
        557, 5,   111, 0,   0,   557, 558, 5,   109, 0,   0,   558, 559, 5,   112, 0,   0,   559, 560, 5,   116, 0,
        0,   560, 172, 1,   0,   0,   0,   561, 562, 5,   116, 0,   0,   562, 563, 5,   101, 0,   0,   563, 564, 5,
        115, 0,   0,   564, 565, 5,   116, 0,   0,   565, 174, 1,   0,   0,   0,   566, 567, 5,   101, 0,   0,   567,
        568, 5,   110, 0,   0,   568, 569, 5,   117, 0,   0,   569, 570, 5,   109, 0,   0,   570, 176, 1,   0,   0,
        0,   571, 572, 5,   117, 0,   0,   572, 573, 5,   110, 0,   0,   573, 574, 5,   105, 0,   0,   574, 575, 5,
        111, 0,   0,   575, 576, 5,   110, 0,   0,   576, 178, 1,   0,   0,   0,   577, 578, 5,   115, 0,   0,   578,
        579, 5,   116, 0,   0,   579, 580, 5,   100, 0,   0,   580, 180, 1,   0,   0,   0,   581, 582, 5,   111, 0,
        0,   582, 583, 5,   114, 0,   0,   583, 584, 5,   101, 0,   0,   584, 585, 5,   108, 0,   0,   585, 586, 5,
        115, 0,   0,   586, 587, 5,   101, 0,   0,   587, 182, 1,   0,   0,   0,   588, 589, 5,   99,  0,   0,   589,
        590, 5,   97,  0,   0,   590, 591, 5,   116, 0,   0,   591, 592, 5,   99,  0,   0,   592, 593, 5,   104, 0,
        0,   593, 184, 1,   0,   0,   0,   594, 595, 5,   97,  0,   0,   595, 596, 5,   115, 0,   0,   596, 186, 1,
        0,   0,   0,   597, 599, 9,   0,   0,   0,   598, 597, 1,   0,   0,   0,   599, 600, 1,   0,   0,   0,   600,
        601, 1,   0,   0,   0,   600, 598, 1,   0,   0,   0,   601, 188, 1,   0,   0,   0,   11,  0,   193, 195, 204,
        206, 218, 225, 234, 241, 246, 600, 1,   0,   1,   0
    };
    staticData->serializedATN = antlr4::atn::SerializedATNView(
        serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0])
    );

    antlr4::atn::ATNDeserializer deserializer;
    staticData->atn = deserializer.deserialize(staticData->serializedATN);

    const size_t count = staticData->atn->getNumberOfDecisions();
    staticData->decisionToDFA.reserve(count);
    for (size_t i = 0; i < count; i++) {
        staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
    }
    whixylexerLexerStaticData = std::move(staticData);
}

} // namespace

WhixyLexer::WhixyLexer(CharStream* input): Lexer(input)
{
    WhixyLexer::initialize();
    _interpreter = new atn::LexerATNSimulator(
        this, *whixylexerLexerStaticData->atn, whixylexerLexerStaticData->decisionToDFA,
        whixylexerLexerStaticData->sharedContextCache
    );
}

WhixyLexer::~WhixyLexer() { delete _interpreter; }

std::string WhixyLexer::getGrammarFileName() const { return "WhixyLexer.g4"; }

const std::vector<std::string>& WhixyLexer::getRuleNames() const { return whixylexerLexerStaticData->ruleNames; }

const std::vector<std::string>& WhixyLexer::getChannelNames() const { return whixylexerLexerStaticData->channelNames; }

const std::vector<std::string>& WhixyLexer::getModeNames() const { return whixylexerLexerStaticData->modeNames; }

const dfa::Vocabulary& WhixyLexer::getVocabulary() const { return whixylexerLexerStaticData->vocabulary; }

antlr4::atn::SerializedATNView WhixyLexer::getSerializedATN() const { return whixylexerLexerStaticData->serializedATN; }

const atn::ATN& WhixyLexer::getATN() const { return *whixylexerLexerStaticData->atn; }

void WhixyLexer::initialize()
{
#if ANTLR4_USE_THREAD_LOCAL_CACHE
    whixylexerLexerInitialize();
#else
    ::antlr4::internal::call_once(whixylexerLexerOnceFlag, whixylexerLexerInitialize);
#endif
}
