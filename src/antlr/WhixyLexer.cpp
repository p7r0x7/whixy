
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
            "WHITESPACE",
            "COMMA",
            "SEMICOLON",
            "DOLLAR_OPENPARENTHESIS",
            "OPENPARENTHESIS",
            "CLOSEDPARENTHESIS",
            "OPENBRACE",
            "CLOSEDBRACE",
            "OPENBRACKET",
            "CLOSEDBRACKET",
            "DOT_TYPE",
            "DOT_LEN",
            "DOT_ASTERISK",
            "DOT_AMPERSAND",
            "QUESTION",
            "EXCLAMATION",
            "DOT",
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
            "NEWLINE",
            "TOKEN"
        },
        std::vector<std::string>{"DEFAULT_TOKEN_CHANNEL", "HIDDEN"}, std::vector<std::string>{"DEFAULT_MODE"},
        std::vector<std::string>{"",           "",         "",         "",           "",
                                 "",           "",         "','",      "';'",        "'$('",
                                 "'('",        "')'",      "'{'",      "'}'",        "'['",
                                 "']'",        "'.type'",  "'.len'",   "'.*'",       "'.&'",
                                 "'\\u003F'",  "'!'",      "'.'",      "'>>%='",     "'>>%'",
                                 "'>>='",      "'>>'",     "'>='",     "'>'",        "'<<%='",
                                 "'<<%'",      "'<<='",    "'<<'",     "'<='",       "'<'",
                                 "'*%='",      "'*%'",     "'*='",     "'**'",       "'*'",
                                 "'+%='",      "'+%'",     "'+='",     "'++'",       "'+'",
                                 "'-%='",      "'-%'",     "'-='",     "'-'",        "'~='",
                                 "'~'",        "'&='",     "'&'",      "'%='",       "'%'",
                                 "'^='",       "'^'",      "'/='",     "'/'",        "'=='",
                                 "'='",        "'|='",     "'|'",      "'this'",     "'auto'",
                                 "'mut'",      "'inline'", "'return'", "'continue'", "'break'",
                                 "'goto'",     "'while'",  "'for'",    "'if'",       "'elseif'",
                                 "'else'",     "'where'",  "'defer'",  "'errdefer'", "'fast'",
                                 "'bare'",     "'import'", "'align'",  "'threadl'",  "'unreachable'",
                                 "'volatile'", "'unroll'", "'compt'",  "'test'",     "'enum'",
                                 "'union'",    "'std'",    "'orelse'", "'catch'",    "'as'"},
        std::vector<std::string>{
            "",
            "DOUBLEQUOTESTRING",
            "BACKTICKSTRING",
            "DOCCOMMENT",
            "COMMENT",
            "RUNE",
            "WHITESPACE",
            "COMMA",
            "SEMICOLON",
            "DOLLAR_OPENPARENTHESIS",
            "OPENPARENTHESIS",
            "CLOSEDPARENTHESIS",
            "OPENBRACE",
            "CLOSEDBRACE",
            "OPENBRACKET",
            "CLOSEDBRACKET",
            "DOT_TYPE",
            "DOT_LEN",
            "DOT_ASTERISK",
            "DOT_AMPERSAND",
            "QUESTION",
            "EXCLAMATION",
            "DOT",
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
            "NEWLINE",
            "TOKEN"
        }
    );
    static const int32_t serializedATNSegment[] = {
        4,   0,   96,  615, 6,   -1,  2,   0,   7,   0,   2,   1,   7,   1,   2,   2,   7,   2,   2,   3,   7,   3,
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
        2,   92,  7,   92,  2,   93,  7,   93,  2,   94,  7,   94,  2,   95,  7,   95,  1,   0,   1,   0,   1,   0,
        1,   0,   5,   0,   198, 8,   0,   10,  0,   12,  0,   201, 9,   0,   1,   0,   1,   0,   1,   1,   1,   1,
        1,   1,   1,   1,   5,   1,   209, 8,   1,   10,  1,   12,  1,   212, 9,   1,   1,   1,   1,   1,   1,   2,
        1,   2,   1,   2,   1,   2,   1,   2,   5,   2,   221, 8,   2,   10,  2,   12,  2,   224, 9,   2,   1,   3,
        1,   3,   5,   3,   228, 8,   3,   10,  3,   12,  3,   231, 9,   3,   1,   3,   1,   3,   1,   4,   1,   4,
        1,   4,   1,   4,   3,   4,   239, 8,   4,   1,   4,   1,   4,   1,   5,   4,   5,   244, 8,   5,   11,  5,
        12,  5,   245, 1,   5,   1,   5,   1,   6,   1,   6,   1,   7,   1,   7,   1,   8,   1,   8,   1,   8,   1,
        9,   1,   9,   1,   10,  1,   10,  1,   11,  1,   11,  1,   12,  1,   12,  1,   13,  1,   13,  1,   14,  1,
        14,  1,   15,  1,   15,  1,   15,  1,   15,  1,   15,  1,   15,  1,   16,  1,   16,  1,   16,  1,   16,  1,
        16,  1,   17,  1,   17,  1,   17,  1,   18,  1,   18,  1,   18,  1,   19,  1,   19,  1,   20,  1,   20,  1,
        21,  1,   21,  1,   22,  1,   22,  1,   22,  1,   22,  1,   22,  1,   23,  1,   23,  1,   23,  1,   23,  1,
        24,  1,   24,  1,   24,  1,   24,  1,   25,  1,   25,  1,   25,  1,   26,  1,   26,  1,   26,  1,   27,  1,
        27,  1,   28,  1,   28,  1,   28,  1,   28,  1,   28,  1,   29,  1,   29,  1,   29,  1,   29,  1,   30,  1,
        30,  1,   30,  1,   30,  1,   31,  1,   31,  1,   31,  1,   32,  1,   32,  1,   32,  1,   33,  1,   33,  1,
        34,  1,   34,  1,   34,  1,   34,  1,   35,  1,   35,  1,   35,  1,   36,  1,   36,  1,   36,  1,   37,  1,
        37,  1,   37,  1,   38,  1,   38,  1,   39,  1,   39,  1,   39,  1,   39,  1,   40,  1,   40,  1,   40,  1,
        41,  1,   41,  1,   41,  1,   42,  1,   42,  1,   42,  1,   43,  1,   43,  1,   44,  1,   44,  1,   44,  1,
        44,  1,   45,  1,   45,  1,   45,  1,   46,  1,   46,  1,   46,  1,   47,  1,   47,  1,   48,  1,   48,  1,
        48,  1,   49,  1,   49,  1,   50,  1,   50,  1,   50,  1,   51,  1,   51,  1,   52,  1,   52,  1,   52,  1,
        53,  1,   53,  1,   54,  1,   54,  1,   54,  1,   55,  1,   55,  1,   56,  1,   56,  1,   56,  1,   57,  1,
        57,  1,   58,  1,   58,  1,   58,  1,   59,  1,   59,  1,   60,  1,   60,  1,   60,  1,   61,  1,   61,  1,
        62,  1,   62,  1,   62,  1,   62,  1,   62,  1,   63,  1,   63,  1,   63,  1,   63,  1,   63,  1,   64,  1,
        64,  1,   64,  1,   64,  1,   65,  1,   65,  1,   65,  1,   65,  1,   65,  1,   65,  1,   65,  1,   66,  1,
        66,  1,   66,  1,   66,  1,   66,  1,   66,  1,   66,  1,   67,  1,   67,  1,   67,  1,   67,  1,   67,  1,
        67,  1,   67,  1,   67,  1,   67,  1,   68,  1,   68,  1,   68,  1,   68,  1,   68,  1,   68,  1,   69,  1,
        69,  1,   69,  1,   69,  1,   69,  1,   70,  1,   70,  1,   70,  1,   70,  1,   70,  1,   70,  1,   71,  1,
        71,  1,   71,  1,   71,  1,   72,  1,   72,  1,   72,  1,   73,  1,   73,  1,   73,  1,   73,  1,   73,  1,
        73,  1,   73,  1,   74,  1,   74,  1,   74,  1,   74,  1,   74,  1,   75,  1,   75,  1,   75,  1,   75,  1,
        75,  1,   75,  1,   76,  1,   76,  1,   76,  1,   76,  1,   76,  1,   76,  1,   77,  1,   77,  1,   77,  1,
        77,  1,   77,  1,   77,  1,   77,  1,   77,  1,   77,  1,   78,  1,   78,  1,   78,  1,   78,  1,   78,  1,
        79,  1,   79,  1,   79,  1,   79,  1,   79,  1,   80,  1,   80,  1,   80,  1,   80,  1,   80,  1,   80,  1,
        80,  1,   81,  1,   81,  1,   81,  1,   81,  1,   81,  1,   81,  1,   82,  1,   82,  1,   82,  1,   82,  1,
        82,  1,   82,  1,   82,  1,   82,  1,   83,  1,   83,  1,   83,  1,   83,  1,   83,  1,   83,  1,   83,  1,
        83,  1,   83,  1,   83,  1,   83,  1,   83,  1,   84,  1,   84,  1,   84,  1,   84,  1,   84,  1,   84,  1,
        84,  1,   84,  1,   84,  1,   85,  1,   85,  1,   85,  1,   85,  1,   85,  1,   85,  1,   85,  1,   86,  1,
        86,  1,   86,  1,   86,  1,   86,  1,   86,  1,   87,  1,   87,  1,   87,  1,   87,  1,   87,  1,   88,  1,
        88,  1,   88,  1,   88,  1,   88,  1,   89,  1,   89,  1,   89,  1,   89,  1,   89,  1,   89,  1,   90,  1,
        90,  1,   90,  1,   90,  1,   91,  1,   91,  1,   91,  1,   91,  1,   91,  1,   91,  1,   91,  1,   92,  1,
        92,  1,   92,  1,   92,  1,   92,  1,   92,  1,   93,  1,   93,  1,   93,  1,   94,  4,   94,  607, 8,   94,
        11,  94,  12,  94,  608, 1,   95,  4,   95,  612, 8,   95,  11,  95,  12,  95,  613, 3,   199, 210, 613, 0,
        96,  1,   1,   3,   2,   5,   3,   7,   4,   9,   5,   11,  6,   13,  7,   15,  8,   17,  9,   19,  10,  21,
        11,  23,  12,  25,  13,  27,  14,  29,  15,  31,  16,  33,  17,  35,  18,  37,  19,  39,  20,  41,  21,  43,
        22,  45,  23,  47,  24,  49,  25,  51,  26,  53,  27,  55,  28,  57,  29,  59,  30,  61,  31,  63,  32,  65,
        33,  67,  34,  69,  35,  71,  36,  73,  37,  75,  38,  77,  39,  79,  40,  81,  41,  83,  42,  85,  43,  87,
        44,  89,  45,  91,  46,  93,  47,  95,  48,  97,  49,  99,  50,  101, 51,  103, 52,  105, 53,  107, 54,  109,
        55,  111, 56,  113, 57,  115, 58,  117, 59,  119, 60,  121, 61,  123, 62,  125, 63,  127, 64,  129, 65,  131,
        66,  133, 67,  135, 68,  137, 69,  139, 70,  141, 71,  143, 72,  145, 73,  147, 74,  149, 75,  151, 76,  153,
        77,  155, 78,  157, 79,  159, 80,  161, 81,  163, 82,  165, 83,  167, 84,  169, 85,  171, 86,  173, 87,  175,
        88,  177, 89,  179, 90,  181, 91,  183, 92,  185, 93,  187, 94,  189, 95,  191, 96,  1,   0,   2,   2,   0,
        10,  10,  13,  13,  2,   0,   9,   9,   32,  32,  624, 0,   1,   1,   0,   0,   0,   0,   3,   1,   0,   0,
        0,   0,   5,   1,   0,   0,   0,   0,   7,   1,   0,   0,   0,   0,   9,   1,   0,   0,   0,   0,   11,  1,
        0,   0,   0,   0,   13,  1,   0,   0,   0,   0,   15,  1,   0,   0,   0,   0,   17,  1,   0,   0,   0,   0,
        19,  1,   0,   0,   0,   0,   21,  1,   0,   0,   0,   0,   23,  1,   0,   0,   0,   0,   25,  1,   0,   0,
        0,   0,   27,  1,   0,   0,   0,   0,   29,  1,   0,   0,   0,   0,   31,  1,   0,   0,   0,   0,   33,  1,
        0,   0,   0,   0,   35,  1,   0,   0,   0,   0,   37,  1,   0,   0,   0,   0,   39,  1,   0,   0,   0,   0,
        41,  1,   0,   0,   0,   0,   43,  1,   0,   0,   0,   0,   45,  1,   0,   0,   0,   0,   47,  1,   0,   0,
        0,   0,   49,  1,   0,   0,   0,   0,   51,  1,   0,   0,   0,   0,   53,  1,   0,   0,   0,   0,   55,  1,
        0,   0,   0,   0,   57,  1,   0,   0,   0,   0,   59,  1,   0,   0,   0,   0,   61,  1,   0,   0,   0,   0,
        63,  1,   0,   0,   0,   0,   65,  1,   0,   0,   0,   0,   67,  1,   0,   0,   0,   0,   69,  1,   0,   0,
        0,   0,   71,  1,   0,   0,   0,   0,   73,  1,   0,   0,   0,   0,   75,  1,   0,   0,   0,   0,   77,  1,
        0,   0,   0,   0,   79,  1,   0,   0,   0,   0,   81,  1,   0,   0,   0,   0,   83,  1,   0,   0,   0,   0,
        85,  1,   0,   0,   0,   0,   87,  1,   0,   0,   0,   0,   89,  1,   0,   0,   0,   0,   91,  1,   0,   0,
        0,   0,   93,  1,   0,   0,   0,   0,   95,  1,   0,   0,   0,   0,   97,  1,   0,   0,   0,   0,   99,  1,
        0,   0,   0,   0,   101, 1,   0,   0,   0,   0,   103, 1,   0,   0,   0,   0,   105, 1,   0,   0,   0,   0,
        107, 1,   0,   0,   0,   0,   109, 1,   0,   0,   0,   0,   111, 1,   0,   0,   0,   0,   113, 1,   0,   0,
        0,   0,   115, 1,   0,   0,   0,   0,   117, 1,   0,   0,   0,   0,   119, 1,   0,   0,   0,   0,   121, 1,
        0,   0,   0,   0,   123, 1,   0,   0,   0,   0,   125, 1,   0,   0,   0,   0,   127, 1,   0,   0,   0,   0,
        129, 1,   0,   0,   0,   0,   131, 1,   0,   0,   0,   0,   133, 1,   0,   0,   0,   0,   135, 1,   0,   0,
        0,   0,   137, 1,   0,   0,   0,   0,   139, 1,   0,   0,   0,   0,   141, 1,   0,   0,   0,   0,   143, 1,
        0,   0,   0,   0,   145, 1,   0,   0,   0,   0,   147, 1,   0,   0,   0,   0,   149, 1,   0,   0,   0,   0,
        151, 1,   0,   0,   0,   0,   153, 1,   0,   0,   0,   0,   155, 1,   0,   0,   0,   0,   157, 1,   0,   0,
        0,   0,   159, 1,   0,   0,   0,   0,   161, 1,   0,   0,   0,   0,   163, 1,   0,   0,   0,   0,   165, 1,
        0,   0,   0,   0,   167, 1,   0,   0,   0,   0,   169, 1,   0,   0,   0,   0,   171, 1,   0,   0,   0,   0,
        173, 1,   0,   0,   0,   0,   175, 1,   0,   0,   0,   0,   177, 1,   0,   0,   0,   0,   179, 1,   0,   0,
        0,   0,   181, 1,   0,   0,   0,   0,   183, 1,   0,   0,   0,   0,   185, 1,   0,   0,   0,   0,   187, 1,
        0,   0,   0,   0,   189, 1,   0,   0,   0,   0,   191, 1,   0,   0,   0,   1,   193, 1,   0,   0,   0,   3,
        204, 1,   0,   0,   0,   5,   215, 1,   0,   0,   0,   7,   225, 1,   0,   0,   0,   9,   234, 1,   0,   0,
        0,   11,  243, 1,   0,   0,   0,   13,  249, 1,   0,   0,   0,   15,  251, 1,   0,   0,   0,   17,  253, 1,
        0,   0,   0,   19,  256, 1,   0,   0,   0,   21,  258, 1,   0,   0,   0,   23,  260, 1,   0,   0,   0,   25,
        262, 1,   0,   0,   0,   27,  264, 1,   0,   0,   0,   29,  266, 1,   0,   0,   0,   31,  268, 1,   0,   0,
        0,   33,  274, 1,   0,   0,   0,   35,  279, 1,   0,   0,   0,   37,  282, 1,   0,   0,   0,   39,  285, 1,
        0,   0,   0,   41,  287, 1,   0,   0,   0,   43,  289, 1,   0,   0,   0,   45,  291, 1,   0,   0,   0,   47,
        296, 1,   0,   0,   0,   49,  300, 1,   0,   0,   0,   51,  304, 1,   0,   0,   0,   53,  307, 1,   0,   0,
        0,   55,  310, 1,   0,   0,   0,   57,  312, 1,   0,   0,   0,   59,  317, 1,   0,   0,   0,   61,  321, 1,
        0,   0,   0,   63,  325, 1,   0,   0,   0,   65,  328, 1,   0,   0,   0,   67,  331, 1,   0,   0,   0,   69,
        333, 1,   0,   0,   0,   71,  337, 1,   0,   0,   0,   73,  340, 1,   0,   0,   0,   75,  343, 1,   0,   0,
        0,   77,  346, 1,   0,   0,   0,   79,  348, 1,   0,   0,   0,   81,  352, 1,   0,   0,   0,   83,  355, 1,
        0,   0,   0,   85,  358, 1,   0,   0,   0,   87,  361, 1,   0,   0,   0,   89,  363, 1,   0,   0,   0,   91,
        367, 1,   0,   0,   0,   93,  370, 1,   0,   0,   0,   95,  373, 1,   0,   0,   0,   97,  375, 1,   0,   0,
        0,   99,  378, 1,   0,   0,   0,   101, 380, 1,   0,   0,   0,   103, 383, 1,   0,   0,   0,   105, 385, 1,
        0,   0,   0,   107, 388, 1,   0,   0,   0,   109, 390, 1,   0,   0,   0,   111, 393, 1,   0,   0,   0,   113,
        395, 1,   0,   0,   0,   115, 398, 1,   0,   0,   0,   117, 400, 1,   0,   0,   0,   119, 403, 1,   0,   0,
        0,   121, 405, 1,   0,   0,   0,   123, 408, 1,   0,   0,   0,   125, 410, 1,   0,   0,   0,   127, 415, 1,
        0,   0,   0,   129, 420, 1,   0,   0,   0,   131, 424, 1,   0,   0,   0,   133, 431, 1,   0,   0,   0,   135,
        438, 1,   0,   0,   0,   137, 447, 1,   0,   0,   0,   139, 453, 1,   0,   0,   0,   141, 458, 1,   0,   0,
        0,   143, 464, 1,   0,   0,   0,   145, 468, 1,   0,   0,   0,   147, 471, 1,   0,   0,   0,   149, 478, 1,
        0,   0,   0,   151, 483, 1,   0,   0,   0,   153, 489, 1,   0,   0,   0,   155, 495, 1,   0,   0,   0,   157,
        504, 1,   0,   0,   0,   159, 509, 1,   0,   0,   0,   161, 514, 1,   0,   0,   0,   163, 521, 1,   0,   0,
        0,   165, 527, 1,   0,   0,   0,   167, 535, 1,   0,   0,   0,   169, 547, 1,   0,   0,   0,   171, 556, 1,
        0,   0,   0,   173, 563, 1,   0,   0,   0,   175, 569, 1,   0,   0,   0,   177, 574, 1,   0,   0,   0,   179,
        579, 1,   0,   0,   0,   181, 585, 1,   0,   0,   0,   183, 589, 1,   0,   0,   0,   185, 596, 1,   0,   0,
        0,   187, 602, 1,   0,   0,   0,   189, 606, 1,   0,   0,   0,   191, 611, 1,   0,   0,   0,   193, 199, 5,
        34,  0,   0,   194, 195, 5,   92,  0,   0,   195, 198, 5,   34,  0,   0,   196, 198, 9,   0,   0,   0,   197,
        194, 1,   0,   0,   0,   197, 196, 1,   0,   0,   0,   198, 201, 1,   0,   0,   0,   199, 200, 1,   0,   0,
        0,   199, 197, 1,   0,   0,   0,   200, 202, 1,   0,   0,   0,   201, 199, 1,   0,   0,   0,   202, 203, 5,
        34,  0,   0,   203, 2,   1,   0,   0,   0,   204, 210, 5,   96,  0,   0,   205, 206, 5,   92,  0,   0,   206,
        209, 5,   96,  0,   0,   207, 209, 9,   0,   0,   0,   208, 205, 1,   0,   0,   0,   208, 207, 1,   0,   0,
        0,   209, 212, 1,   0,   0,   0,   210, 211, 1,   0,   0,   0,   210, 208, 1,   0,   0,   0,   211, 213, 1,
        0,   0,   0,   212, 210, 1,   0,   0,   0,   213, 214, 5,   96,  0,   0,   214, 4,   1,   0,   0,   0,   215,
        216, 5,   35,  0,   0,   216, 217, 5,   35,  0,   0,   217, 218, 5,   35,  0,   0,   218, 222, 1,   0,   0,
        0,   219, 221, 8,   0,   0,   0,   220, 219, 1,   0,   0,   0,   221, 224, 1,   0,   0,   0,   222, 220, 1,
        0,   0,   0,   222, 223, 1,   0,   0,   0,   223, 6,   1,   0,   0,   0,   224, 222, 1,   0,   0,   0,   225,
        229, 5,   35,  0,   0,   226, 228, 8,   0,   0,   0,   227, 226, 1,   0,   0,   0,   228, 231, 1,   0,   0,
        0,   229, 227, 1,   0,   0,   0,   229, 230, 1,   0,   0,   0,   230, 232, 1,   0,   0,   0,   231, 229, 1,
        0,   0,   0,   232, 233, 6,   3,   0,   0,   233, 8,   1,   0,   0,   0,   234, 238, 5,   39,  0,   0,   235,
        236, 5,   92,  0,   0,   236, 239, 5,   39,  0,   0,   237, 239, 9,   0,   0,   0,   238, 235, 1,   0,   0,
        0,   238, 237, 1,   0,   0,   0,   239, 240, 1,   0,   0,   0,   240, 241, 5,   39,  0,   0,   241, 10,  1,
        0,   0,   0,   242, 244, 7,   1,   0,   0,   243, 242, 1,   0,   0,   0,   244, 245, 1,   0,   0,   0,   245,
        243, 1,   0,   0,   0,   245, 246, 1,   0,   0,   0,   246, 247, 1,   0,   0,   0,   247, 248, 6,   5,   0,
        0,   248, 12,  1,   0,   0,   0,   249, 250, 5,   44,  0,   0,   250, 14,  1,   0,   0,   0,   251, 252, 5,
        59,  0,   0,   252, 16,  1,   0,   0,   0,   253, 254, 5,   36,  0,   0,   254, 255, 5,   40,  0,   0,   255,
        18,  1,   0,   0,   0,   256, 257, 5,   40,  0,   0,   257, 20,  1,   0,   0,   0,   258, 259, 5,   41,  0,
        0,   259, 22,  1,   0,   0,   0,   260, 261, 5,   123, 0,   0,   261, 24,  1,   0,   0,   0,   262, 263, 5,
        125, 0,   0,   263, 26,  1,   0,   0,   0,   264, 265, 5,   91,  0,   0,   265, 28,  1,   0,   0,   0,   266,
        267, 5,   93,  0,   0,   267, 30,  1,   0,   0,   0,   268, 269, 5,   46,  0,   0,   269, 270, 5,   116, 0,
        0,   270, 271, 5,   121, 0,   0,   271, 272, 5,   112, 0,   0,   272, 273, 5,   101, 0,   0,   273, 32,  1,
        0,   0,   0,   274, 275, 5,   46,  0,   0,   275, 276, 5,   108, 0,   0,   276, 277, 5,   101, 0,   0,   277,
        278, 5,   110, 0,   0,   278, 34,  1,   0,   0,   0,   279, 280, 5,   46,  0,   0,   280, 281, 5,   42,  0,
        0,   281, 36,  1,   0,   0,   0,   282, 283, 5,   46,  0,   0,   283, 284, 5,   38,  0,   0,   284, 38,  1,
        0,   0,   0,   285, 286, 5,   63,  0,   0,   286, 40,  1,   0,   0,   0,   287, 288, 5,   33,  0,   0,   288,
        42,  1,   0,   0,   0,   289, 290, 5,   46,  0,   0,   290, 44,  1,   0,   0,   0,   291, 292, 5,   62,  0,
        0,   292, 293, 5,   62,  0,   0,   293, 294, 5,   37,  0,   0,   294, 295, 5,   61,  0,   0,   295, 46,  1,
        0,   0,   0,   296, 297, 5,   62,  0,   0,   297, 298, 5,   62,  0,   0,   298, 299, 5,   37,  0,   0,   299,
        48,  1,   0,   0,   0,   300, 301, 5,   62,  0,   0,   301, 302, 5,   62,  0,   0,   302, 303, 5,   61,  0,
        0,   303, 50,  1,   0,   0,   0,   304, 305, 5,   62,  0,   0,   305, 306, 5,   62,  0,   0,   306, 52,  1,
        0,   0,   0,   307, 308, 5,   62,  0,   0,   308, 309, 5,   61,  0,   0,   309, 54,  1,   0,   0,   0,   310,
        311, 5,   62,  0,   0,   311, 56,  1,   0,   0,   0,   312, 313, 5,   60,  0,   0,   313, 314, 5,   60,  0,
        0,   314, 315, 5,   37,  0,   0,   315, 316, 5,   61,  0,   0,   316, 58,  1,   0,   0,   0,   317, 318, 5,
        60,  0,   0,   318, 319, 5,   60,  0,   0,   319, 320, 5,   37,  0,   0,   320, 60,  1,   0,   0,   0,   321,
        322, 5,   60,  0,   0,   322, 323, 5,   60,  0,   0,   323, 324, 5,   61,  0,   0,   324, 62,  1,   0,   0,
        0,   325, 326, 5,   60,  0,   0,   326, 327, 5,   60,  0,   0,   327, 64,  1,   0,   0,   0,   328, 329, 5,
        60,  0,   0,   329, 330, 5,   61,  0,   0,   330, 66,  1,   0,   0,   0,   331, 332, 5,   60,  0,   0,   332,
        68,  1,   0,   0,   0,   333, 334, 5,   42,  0,   0,   334, 335, 5,   37,  0,   0,   335, 336, 5,   61,  0,
        0,   336, 70,  1,   0,   0,   0,   337, 338, 5,   42,  0,   0,   338, 339, 5,   37,  0,   0,   339, 72,  1,
        0,   0,   0,   340, 341, 5,   42,  0,   0,   341, 342, 5,   61,  0,   0,   342, 74,  1,   0,   0,   0,   343,
        344, 5,   42,  0,   0,   344, 345, 5,   42,  0,   0,   345, 76,  1,   0,   0,   0,   346, 347, 5,   42,  0,
        0,   347, 78,  1,   0,   0,   0,   348, 349, 5,   43,  0,   0,   349, 350, 5,   37,  0,   0,   350, 351, 5,
        61,  0,   0,   351, 80,  1,   0,   0,   0,   352, 353, 5,   43,  0,   0,   353, 354, 5,   37,  0,   0,   354,
        82,  1,   0,   0,   0,   355, 356, 5,   43,  0,   0,   356, 357, 5,   61,  0,   0,   357, 84,  1,   0,   0,
        0,   358, 359, 5,   43,  0,   0,   359, 360, 5,   43,  0,   0,   360, 86,  1,   0,   0,   0,   361, 362, 5,
        43,  0,   0,   362, 88,  1,   0,   0,   0,   363, 364, 5,   45,  0,   0,   364, 365, 5,   37,  0,   0,   365,
        366, 5,   61,  0,   0,   366, 90,  1,   0,   0,   0,   367, 368, 5,   45,  0,   0,   368, 369, 5,   37,  0,
        0,   369, 92,  1,   0,   0,   0,   370, 371, 5,   45,  0,   0,   371, 372, 5,   61,  0,   0,   372, 94,  1,
        0,   0,   0,   373, 374, 5,   45,  0,   0,   374, 96,  1,   0,   0,   0,   375, 376, 5,   126, 0,   0,   376,
        377, 5,   61,  0,   0,   377, 98,  1,   0,   0,   0,   378, 379, 5,   126, 0,   0,   379, 100, 1,   0,   0,
        0,   380, 381, 5,   38,  0,   0,   381, 382, 5,   61,  0,   0,   382, 102, 1,   0,   0,   0,   383, 384, 5,
        38,  0,   0,   384, 104, 1,   0,   0,   0,   385, 386, 5,   37,  0,   0,   386, 387, 5,   61,  0,   0,   387,
        106, 1,   0,   0,   0,   388, 389, 5,   37,  0,   0,   389, 108, 1,   0,   0,   0,   390, 391, 5,   94,  0,
        0,   391, 392, 5,   61,  0,   0,   392, 110, 1,   0,   0,   0,   393, 394, 5,   94,  0,   0,   394, 112, 1,
        0,   0,   0,   395, 396, 5,   47,  0,   0,   396, 397, 5,   61,  0,   0,   397, 114, 1,   0,   0,   0,   398,
        399, 5,   47,  0,   0,   399, 116, 1,   0,   0,   0,   400, 401, 5,   61,  0,   0,   401, 402, 5,   61,  0,
        0,   402, 118, 1,   0,   0,   0,   403, 404, 5,   61,  0,   0,   404, 120, 1,   0,   0,   0,   405, 406, 5,
        124, 0,   0,   406, 407, 5,   61,  0,   0,   407, 122, 1,   0,   0,   0,   408, 409, 5,   124, 0,   0,   409,
        124, 1,   0,   0,   0,   410, 411, 5,   116, 0,   0,   411, 412, 5,   104, 0,   0,   412, 413, 5,   105, 0,
        0,   413, 414, 5,   115, 0,   0,   414, 126, 1,   0,   0,   0,   415, 416, 5,   97,  0,   0,   416, 417, 5,
        117, 0,   0,   417, 418, 5,   116, 0,   0,   418, 419, 5,   111, 0,   0,   419, 128, 1,   0,   0,   0,   420,
        421, 5,   109, 0,   0,   421, 422, 5,   117, 0,   0,   422, 423, 5,   116, 0,   0,   423, 130, 1,   0,   0,
        0,   424, 425, 5,   105, 0,   0,   425, 426, 5,   110, 0,   0,   426, 427, 5,   108, 0,   0,   427, 428, 5,
        105, 0,   0,   428, 429, 5,   110, 0,   0,   429, 430, 5,   101, 0,   0,   430, 132, 1,   0,   0,   0,   431,
        432, 5,   114, 0,   0,   432, 433, 5,   101, 0,   0,   433, 434, 5,   116, 0,   0,   434, 435, 5,   117, 0,
        0,   435, 436, 5,   114, 0,   0,   436, 437, 5,   110, 0,   0,   437, 134, 1,   0,   0,   0,   438, 439, 5,
        99,  0,   0,   439, 440, 5,   111, 0,   0,   440, 441, 5,   110, 0,   0,   441, 442, 5,   116, 0,   0,   442,
        443, 5,   105, 0,   0,   443, 444, 5,   110, 0,   0,   444, 445, 5,   117, 0,   0,   445, 446, 5,   101, 0,
        0,   446, 136, 1,   0,   0,   0,   447, 448, 5,   98,  0,   0,   448, 449, 5,   114, 0,   0,   449, 450, 5,
        101, 0,   0,   450, 451, 5,   97,  0,   0,   451, 452, 5,   107, 0,   0,   452, 138, 1,   0,   0,   0,   453,
        454, 5,   103, 0,   0,   454, 455, 5,   111, 0,   0,   455, 456, 5,   116, 0,   0,   456, 457, 5,   111, 0,
        0,   457, 140, 1,   0,   0,   0,   458, 459, 5,   119, 0,   0,   459, 460, 5,   104, 0,   0,   460, 461, 5,
        105, 0,   0,   461, 462, 5,   108, 0,   0,   462, 463, 5,   101, 0,   0,   463, 142, 1,   0,   0,   0,   464,
        465, 5,   102, 0,   0,   465, 466, 5,   111, 0,   0,   466, 467, 5,   114, 0,   0,   467, 144, 1,   0,   0,
        0,   468, 469, 5,   105, 0,   0,   469, 470, 5,   102, 0,   0,   470, 146, 1,   0,   0,   0,   471, 472, 5,
        101, 0,   0,   472, 473, 5,   108, 0,   0,   473, 474, 5,   115, 0,   0,   474, 475, 5,   101, 0,   0,   475,
        476, 5,   105, 0,   0,   476, 477, 5,   102, 0,   0,   477, 148, 1,   0,   0,   0,   478, 479, 5,   101, 0,
        0,   479, 480, 5,   108, 0,   0,   480, 481, 5,   115, 0,   0,   481, 482, 5,   101, 0,   0,   482, 150, 1,
        0,   0,   0,   483, 484, 5,   119, 0,   0,   484, 485, 5,   104, 0,   0,   485, 486, 5,   101, 0,   0,   486,
        487, 5,   114, 0,   0,   487, 488, 5,   101, 0,   0,   488, 152, 1,   0,   0,   0,   489, 490, 5,   100, 0,
        0,   490, 491, 5,   101, 0,   0,   491, 492, 5,   102, 0,   0,   492, 493, 5,   101, 0,   0,   493, 494, 5,
        114, 0,   0,   494, 154, 1,   0,   0,   0,   495, 496, 5,   101, 0,   0,   496, 497, 5,   114, 0,   0,   497,
        498, 5,   114, 0,   0,   498, 499, 5,   100, 0,   0,   499, 500, 5,   101, 0,   0,   500, 501, 5,   102, 0,
        0,   501, 502, 5,   101, 0,   0,   502, 503, 5,   114, 0,   0,   503, 156, 1,   0,   0,   0,   504, 505, 5,
        102, 0,   0,   505, 506, 5,   97,  0,   0,   506, 507, 5,   115, 0,   0,   507, 508, 5,   116, 0,   0,   508,
        158, 1,   0,   0,   0,   509, 510, 5,   98,  0,   0,   510, 511, 5,   97,  0,   0,   511, 512, 5,   114, 0,
        0,   512, 513, 5,   101, 0,   0,   513, 160, 1,   0,   0,   0,   514, 515, 5,   105, 0,   0,   515, 516, 5,
        109, 0,   0,   516, 517, 5,   112, 0,   0,   517, 518, 5,   111, 0,   0,   518, 519, 5,   114, 0,   0,   519,
        520, 5,   116, 0,   0,   520, 162, 1,   0,   0,   0,   521, 522, 5,   97,  0,   0,   522, 523, 5,   108, 0,
        0,   523, 524, 5,   105, 0,   0,   524, 525, 5,   103, 0,   0,   525, 526, 5,   110, 0,   0,   526, 164, 1,
        0,   0,   0,   527, 528, 5,   116, 0,   0,   528, 529, 5,   104, 0,   0,   529, 530, 5,   114, 0,   0,   530,
        531, 5,   101, 0,   0,   531, 532, 5,   97,  0,   0,   532, 533, 5,   100, 0,   0,   533, 534, 5,   108, 0,
        0,   534, 166, 1,   0,   0,   0,   535, 536, 5,   117, 0,   0,   536, 537, 5,   110, 0,   0,   537, 538, 5,
        114, 0,   0,   538, 539, 5,   101, 0,   0,   539, 540, 5,   97,  0,   0,   540, 541, 5,   99,  0,   0,   541,
        542, 5,   104, 0,   0,   542, 543, 5,   97,  0,   0,   543, 544, 5,   98,  0,   0,   544, 545, 5,   108, 0,
        0,   545, 546, 5,   101, 0,   0,   546, 168, 1,   0,   0,   0,   547, 548, 5,   118, 0,   0,   548, 549, 5,
        111, 0,   0,   549, 550, 5,   108, 0,   0,   550, 551, 5,   97,  0,   0,   551, 552, 5,   116, 0,   0,   552,
        553, 5,   105, 0,   0,   553, 554, 5,   108, 0,   0,   554, 555, 5,   101, 0,   0,   555, 170, 1,   0,   0,
        0,   556, 557, 5,   117, 0,   0,   557, 558, 5,   110, 0,   0,   558, 559, 5,   114, 0,   0,   559, 560, 5,
        111, 0,   0,   560, 561, 5,   108, 0,   0,   561, 562, 5,   108, 0,   0,   562, 172, 1,   0,   0,   0,   563,
        564, 5,   99,  0,   0,   564, 565, 5,   111, 0,   0,   565, 566, 5,   109, 0,   0,   566, 567, 5,   112, 0,
        0,   567, 568, 5,   116, 0,   0,   568, 174, 1,   0,   0,   0,   569, 570, 5,   116, 0,   0,   570, 571, 5,
        101, 0,   0,   571, 572, 5,   115, 0,   0,   572, 573, 5,   116, 0,   0,   573, 176, 1,   0,   0,   0,   574,
        575, 5,   101, 0,   0,   575, 576, 5,   110, 0,   0,   576, 577, 5,   117, 0,   0,   577, 578, 5,   109, 0,
        0,   578, 178, 1,   0,   0,   0,   579, 580, 5,   117, 0,   0,   580, 581, 5,   110, 0,   0,   581, 582, 5,
        105, 0,   0,   582, 583, 5,   111, 0,   0,   583, 584, 5,   110, 0,   0,   584, 180, 1,   0,   0,   0,   585,
        586, 5,   115, 0,   0,   586, 587, 5,   116, 0,   0,   587, 588, 5,   100, 0,   0,   588, 182, 1,   0,   0,
        0,   589, 590, 5,   111, 0,   0,   590, 591, 5,   114, 0,   0,   591, 592, 5,   101, 0,   0,   592, 593, 5,
        108, 0,   0,   593, 594, 5,   115, 0,   0,   594, 595, 5,   101, 0,   0,   595, 184, 1,   0,   0,   0,   596,
        597, 5,   99,  0,   0,   597, 598, 5,   97,  0,   0,   598, 599, 5,   116, 0,   0,   599, 600, 5,   99,  0,
        0,   600, 601, 5,   104, 0,   0,   601, 186, 1,   0,   0,   0,   602, 603, 5,   97,  0,   0,   603, 604, 5,
        115, 0,   0,   604, 188, 1,   0,   0,   0,   605, 607, 7,   0,   0,   0,   606, 605, 1,   0,   0,   0,   607,
        608, 1,   0,   0,   0,   608, 606, 1,   0,   0,   0,   608, 609, 1,   0,   0,   0,   609, 190, 1,   0,   0,
        0,   610, 612, 9,   0,   0,   0,   611, 610, 1,   0,   0,   0,   612, 613, 1,   0,   0,   0,   613, 614, 1,
        0,   0,   0,   613, 611, 1,   0,   0,   0,   614, 192, 1,   0,   0,   0,   11,  0,   197, 199, 208, 210, 222,
        229, 238, 245, 608, 613, 1,   0,   1,   0
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
